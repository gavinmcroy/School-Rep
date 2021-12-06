#define GL_SILENCE_DEPRECATION

#include "Cartoon.h"

/*! divisor for the smoothing kernel, higher value means darker image, lower means brighter */
int divisorForKernel;

/*! window dimensions if no image */
const int DEFAULT_WIDTH = 512;
const int DEFAULT_HEIGHT = 512;

/*! window width and height */
int WinHeight;
int WinWidth;

/*! image width and height */
int imageHeight;
int imageWidth;

/*! number of channels per image pixel */
int imChannels;

/*! viewport width and height */
int viewPortHeight;
int viewPortWidth;

/*! viewport offset from lower left corner of window */
int xOffset;
int yOffset;

/*! the pixel format used to correctly  draw the image */
int pixelFormat;

/*! the image pixmap used for OpenGL */
Pixel **pixmap;

Pixel **sobelPixmap;
Pixel **pixmapSV;
Pixel **pixmapSH;

/*! Image input filename and image output filename*/
std::string fileInput;
std::string fileOutput;

const int KERNEL_SIZE = 3;
float **intenseMatrix;
float **tempMatrix;
double range[KERNEL_SIZE][KERNEL_SIZE];
double domain[KERNEL_SIZE][KERNEL_SIZE];
double kernel[KERNEL_SIZE][KERNEL_SIZE];

double SOBEL_DATA_H[3][3] = {{1,  2,  1},
                             {0,  0,  0},
                             {-1, -2, -1}};

double SOBEL_DATA_V[3][3] = {{-1, 0, 1},
                             {-2, 0, 2},
                             {-1, 0, 1}};

/*! given a low, and high value, and a input, returns a value that is
 * neither lower nor higher than set boundary if value is in between, then it is unchanged
 */
double clamp(double lo, double hi, double x) {
    return std::max(lo, std::min(x, hi));
}

/*! given a low, and high value, and a input, returns a value that is
 * neither lower nor higher than set boundary if value is in between, then it is unchanged
 */
double clamp(int lo, int hi, int x) {
    return std::max(lo, std::min(x, hi));
}

/*! Call back for OpenGL Display function */
void handleDisplay() {
    // Background to all black
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // only draw the image if it is of a valid size
    if (imageWidth > 0 && imageHeight > 0) {
        displayImage();
    }
    glFlush();
}

/*! Call back for OpenGL Input function */
void handleKey(unsigned char key, int x, int y) {
    switch (key) {
        // 'b' - apply the bilateral filter to the image
        case 'b': {
            applyBilateralFilter();
            glutReshapeWindow(WinWidth, WinHeight); // OpenGL window should match new image
            glutPostRedisplay();
            break;
        }
            // 'w' - write the current image to a file
        case 'w': {
            writeImage(fileOutput);
            break;
        }
            // 's' - apply the sobel operator to the image
        case 's': {
            convolveImage(pixmapSH, SOBEL_DATA_H);
            convolveImage(pixmapSV, SOBEL_DATA_V);
            combineImg();
            combineBilateralSobel();
            glutReshapeWindow(WinWidth, WinHeight);
            glutPostRedisplay();
            break;
        }
            // Pressing 'q' 'Q' or 'ESC' closes the program
        case 'q':
        case 'Q':
        case 27:
            destroy();
            exit(0);

        default:
            return;
    }
}

/*! Call back for OpenGL display function */
void displayImage() {
    // if the window is smaller than the image, scale it down, otherwise do not scale
    if (WinWidth >= imageWidth && WinHeight >= imageHeight) {
        glPixelZoom(1.0, 1.0);
    } else {
        glPixelZoom(float(viewPortWidth) / imageWidth, float(viewPortHeight) / imageHeight);
    }

    glRasterPos2i(0, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glDrawPixels(imageWidth, imageHeight, pixelFormat, GL_UNSIGNED_BYTE, pixmap[0]);
}

/*! Call back for OpenGL Reshape function */
void handleReshape(int w, int h) {
    float imageAspectRatio = (float) imageWidth / (float) imageHeight;
    float newWindowAspectRatio = (float) w / (float) h;

    WinWidth = w;
    WinHeight = h;

    // if the image fits in the window then viewport is the same size as the image
    if (w >= imageWidth && h >= imageHeight) {
        xOffset = (w - imageWidth) / 2;
        yOffset = (h - imageHeight) / 2;
        viewPortWidth = imageWidth;
        viewPortHeight = imageHeight;
    }
        // if the window is wider than the image then use the full window height
        // and size the width to match the image aspect ratio
    else if (newWindowAspectRatio > imageAspectRatio) {
        viewPortHeight = h;
        viewPortWidth = int(imageAspectRatio * viewPortHeight);
        xOffset = int((w - viewPortWidth) / 2);
        yOffset = 0;
    }
        // if the window is narrower than the image then use the full window width
        // and size the height to match the image aspect ratio
    else {
        viewPortWidth = w;
        viewPortHeight = int(viewPortWidth / imageAspectRatio);
        yOffset = int((h - viewPortHeight) / 2);
        xOffset = 0;
    }

    glViewport(xOffset, yOffset, viewPortWidth, viewPortHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, viewPortWidth, 0, viewPortHeight);
    glMatrixMode(GL_MODELVIEW);
}


/*! Determines the intensity values for each pixel of the image */
void intensityImage() {
    // Allocation process for intensity matrix
    intenseMatrix = new float *[imageHeight];
    if (intenseMatrix == nullptr) {}
    else {
        intenseMatrix[0] = new float[imageWidth * imageHeight];
    }
    for (int i = 1; i < imageHeight; i++) {
        intenseMatrix[i] = intenseMatrix[i - 1] + imageWidth;
    }

    //allocation process for temp matrix
    tempMatrix = new float *[imageHeight];
    if (tempMatrix == nullptr) {}
    else {
        tempMatrix[0] = new float[imageWidth * imageHeight];
    }
    for (int i = 1; i < imageHeight; i++) {
        tempMatrix[i] = tempMatrix[i - 1] + imageWidth;
    }

    //calculation for domain kernel
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            double top = pow(row - 1, 2) + pow(col - 1, 2);
            double sigma = 2;
            top /= sigma;
            domain[row][col] = exp(-top);
        }
    }

    // Actual intensity val for each pixel
    for (int row = 0; row < imageHeight; row++) {
        for (int col = 0; col < imageWidth; col++) {
            intenseMatrix[row][col] = (float) ((pixmap[row][col].r * 0.4) + (pixmap[row][col].g * 0.7) +
                                               (pixmap[row][col].b * 0.01));
        }
    }
}

/*! Applies domain * range to kernel */
void domainRange() {
    for (int row = 0; row < KERNEL_SIZE; row++) {
        for (int col = 0; col < KERNEL_SIZE; col++) {
            kernel[row][col] = range[row][col] * domain[row][col];
        }
    }
}

/*! Ensures that the range given is within the range we want) */
void getRange(int i, int j) {
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            double rangeValue = 0.0;
            /* Ensures that the range is within desired range */
            if (j + y < imageWidth) {
                if (i + x >= 0 && i + x < imageHeight && j + y >= 0) {
                    double top = intenseMatrix[i + x][j + y] - intenseMatrix[i][j];
                    top = std::pow(top, 2);
                    // 98 = 2(7)^2 (7 is the standard deviation)
                    top /= 98;
                    rangeValue = exp(-top);
                }
            }
            range[x + 1][y + 1] = rangeValue;
        }
    }
}

/*! Apply final kernel to the intensity img to create a new intensity image */
void applyIntensityKernel(int y, int x) {
    int center = KERNEL_SIZE / 2;
    double s = 0.0;

    // The kernel is centered at k_center loop takes values -1, 0, 1
    for (int j = -center; j <= center; j++) {
        for (int i = -center; i <= center; i++) {
            double modifier = kernel[center + i][center + j];
            if (i + x < 0 || i + x >= imageWidth || j + y < 0 || j + y >= imageHeight) {
                continue;
            }
            s = intenseMatrix[y + j][x + i] * modifier;
        }
    }
    tempMatrix[y][x] = (float) s;
}

void applyBilateralFilter() {
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            getRange(i, j);
            domainRange();
            applyIntensityKernel(i, j);

            float newR = ((float) pixmap[i][j].r / intenseMatrix[i][j] * tempMatrix[i][j]);
            float newG = ((float) pixmap[i][j].g / intenseMatrix[i][j] * tempMatrix[i][j]);
            float newB = ((float) pixmap[i][j].b / intenseMatrix[i][j] * tempMatrix[i][j]);

            //Ensures that the new pixel values are within range by clamping
            pixmap[i][j].r = (unsigned char) clamp(0.0, 255.0, newR);
            pixmap[i][j].g = (unsigned char) clamp(0.0, 255.0, newG);
            pixmap[i][j].b = (unsigned char) clamp(0.0, 255.0, newB);


        }
    }
    /* Helps reduce the severity of artifacts (does not entirely remove them) */
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            double averageR = 0.0;
            double averageG = 0.0;
            double averageB = 0.0;
            if (i - 1 >= 0 && i + 1 < imageHeight && j - 1 >= 0 && j + 1 < imageWidth) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        averageR += pixmap[x][y].r;
                        averageG += pixmap[x][y].g;
                        averageB += pixmap[x][y].b;
                    }
                }
                pixmap[i][j].r = (unsigned char) (averageR / divisorForKernel);
                pixmap[i][j].g = (unsigned char) (averageG / divisorForKernel);
                pixmap[i][j].b = (unsigned char) (averageB / divisorForKernel);
            }
        }
    }
}

/*! Flips kernel vertically and horizontally */
void flipKernel(double kernelTemp[][3]) {
    double val = 0;
    // Preform horizontal flip on kernel
    for (int y = 0; y < KERNEL_SIZE; y++) {
        for (int x = 0; x < KERNEL_SIZE / 2; x++) {
            val = kernelTemp[KERNEL_SIZE - x - 1][y];
            kernelTemp[KERNEL_SIZE - x - 1][y] = kernelTemp[x][y];
            kernelTemp[x][y] = val;
        }
    }

    // Preform vertical flip on kernel
    for (int x = 0; x < KERNEL_SIZE; x++) {
        for (int y = 0; y < KERNEL_SIZE / 2; y++) {
            val = kernelTemp[x][KERNEL_SIZE - y - 1];
            kernelTemp[x][KERNEL_SIZE - y - 1] = kernelTemp[x][y];
            kernelTemp[x][y] = val;
        }
    }
}

/*! Apply the scale factor to the kernel */
void setKernel(double (*temporaryMatrix)[3]) {
    double sum = 0.0;
    int weight;

    for (int row = 0; row < KERNEL_SIZE; row++) {
        for (int col = 0; col < KERNEL_SIZE; col++) {
            weight = (int) temporaryMatrix[row][col];
            if (weight <= 0) {
                continue;
            }
            sum += weight;
        }
    }

    flipKernel(temporaryMatrix);

    for (int row = 0; row < KERNEL_SIZE; row++) {
        for (int col = 0; col < KERNEL_SIZE; col++) {
            temporaryMatrix[row][col] = .25 * (temporaryMatrix[row][col] / sum);
        }
    }
}

/*! The kernel is centered at k_center loop takes values -1, 0, 1. Applies kernel to one pixel */
void applyKernel(Pixel **pixel, Pixel **tempPixel, double (*matrixTemp)[3], int y, int x) {
    int center = KERNEL_SIZE / 2;
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    /* Our 3x3 kernel */
    for (int j = -center; j <= center; j++) {
        for (int i = -center; i <= center; i++) {
            Pixel pix = pixel[y + i][x + i];
            double localChange = matrixTemp[center + i][center + j];
            r += pix.r * localChange;
            g += pix.g * localChange;
            b += pix.b * localChange;
        }
    }

    // Make sure within RBG range of pixel
    double min = 0;
    double max = 255;
    tempPixel[y][x].r = (int) clamp(min, max, r);
    tempPixel[y][x].g = (int) clamp(min, max, g);
    tempPixel[y][x].b = (int) clamp(min, max, b);
}

/*! Allocate memory for copy pixmap and apply kernel to the actual pixmap for all pixels */
void convolveImage(Pixel **pixmapTemp, double (*matrixTemp)[3]) {
    int center = KERNEL_SIZE / 2;

    // contiguous method of allocation
    auto **copyPixmap = new Pixel *[imageHeight];
    copyPixmap[0] = new Pixel[imageWidth * imageHeight];
    for (int i = 1; i < imageHeight; i++) {
        copyPixmap[i] = copyPixmap[i - 1] + imageWidth;
    }

    // Apply kernel to each pixel and omit outer edge
    for (int y = center; y < imageHeight - center; y++) {
        for (int x = center; x < imageWidth - center; x++) {
            applyKernel(pixmapTemp, copyPixmap, matrixTemp, y, x);
        }
    }
}

/*! Basically calculate sobel for every pixel and add it to the sobel pixmap */
void combineImg() {
    for (int row = 0; row < imageHeight; row++) {
        for (int col = 0; col < imageWidth; col++) {
            sobelPixmap[row][col].r = (unsigned char) calculateSobel(pixmapSH[row][col].r, pixmapSV[row][col].r);
            sobelPixmap[row][col].g = (unsigned char) calculateSobel(pixmapSH[row][col].g, pixmapSV[row][col].g);
            sobelPixmap[row][col].b = (unsigned char) calculateSobel(pixmapSH[row][col].b, pixmapSV[row][col].b);
        }
    }
}

/*! Returns sobel when given colorH and colorV */
double calculateSobel(double colorH, double colorV) {
    double x = std::pow(colorH, 2);
    double y = std::pow(colorV, 2);
    return sqrt(y + x);
}

/*! Combine bilateral filter + Sobel and ensure pixels are within range */
void combineBilateralSobel() {
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            pixmap[i][j].r = (unsigned char) clamp(0, 255, pixmap[i][j].r + sobelPixmap[i][j].r);
            pixmap[i][j].g = (unsigned char) clamp(0, 255, pixmap[i][j].g + sobelPixmap[i][j].g);
            pixmap[i][j].b = (unsigned char) clamp(0, 255, pixmap[i][j].b + sobelPixmap[i][j].b);
        }
    }
}

/*! Free all memory allocations if memory is not null) */
void destroy() {
    if (pixmap) {
        delete pixmap[0];
        delete pixmap;
    }
}

/*! load image in with OpenImageIO and allocate memory for image */
int readImage(const std::string &inFileName) {
    auto infile = ImageInput::open(inFileName);
    if (!infile) {
        std::cerr << "Could not input image file " << inFileName << ", error = " << geterror() << std::endl;
        return 0;
    }
    ImageSpec spec = infile->spec();

    // Save data into global variables
    imageWidth = spec.width;
    imageHeight = spec.height;
    imChannels = spec.nchannels;

    // allocate temporary structure to read the image
    auto *temporaryStruct = new unsigned char[imageWidth * imageHeight * imChannels];

    // read the image into the tmp_pixels from the input file, flipping it upside down using negative y-stride,
    // since OpenGL pixmaps have the bottom scanline first, and
    // oiio expects the top scanline first in the image file.
    int allocationSize = imageWidth * imChannels * sizeof(unsigned char);
    if (infile->read_image(TypeDesc::UINT8, &temporaryStruct[0] + (imageHeight - 1) * allocationSize, AutoStride,
                           -allocationSize)) {

        // get rid of the old OpenGL pixmap and make a new one of the new size
        destroy();

        // allocate space for the Pixmap using contiguous approach
        pixmap = new Pixel *[imageHeight];
        if (pixmap == nullptr) {}
        else {
            pixmap[0] = new Pixel[imageWidth * imageHeight];
        }
        for (int i = 1; i < imageHeight; i++) {
            pixmap[i] = pixmap[i - 1] + imageWidth;
        }

        // Build pixmap structure with temporarily read in pixels
        int index = 0;
        for (int row = 0; row < imageHeight; ++row) {
            for (int col = 0; col < imageWidth; ++col) {
                index = (row * imageWidth + col) * imChannels;
                if (imChannels != 1) {
                    pixmap[row][col].r = temporaryStruct[index];
                    pixmap[row][col].g = temporaryStruct[index + 1];
                    pixmap[row][col].b = temporaryStruct[index + 2];
                    // no alpha value is present so set it to 255
                    if (imChannels < 4) {
                        pixmap[row][col].a = 255;
                    } else {
                        pixmap[row][col].a = temporaryStruct[index + 3];
                    }
                } else {
                    pixmap[row][col].r = temporaryStruct[index];
                    pixmap[row][col].g = temporaryStruct[index];
                    pixmap[row][col].b = temporaryStruct[index];
                    pixmap[row][col].a = 255;
                }
            }
        }

        infile->close();

        // Set format to OpenGL 4 channel mode
        imChannels = 4;
        pixelFormat = GL_RGBA;


        // allocate space for the PixmapSH (contiguous approach)
        pixmapSH = new Pixel *[imageHeight];
        if (pixmapSH == nullptr) {}
        else {
            pixmapSH[0] = new Pixel[imageWidth * imageHeight];
        }
        for (int i = 1; i < imageHeight; i++) {
            pixmapSH[i] = pixmapSH[i - 1] + imageWidth;
        }


        // allocate space for the PixmapSV using contiguous
        pixmapSV = new Pixel *[imageHeight];
        if (pixmapSV == nullptr) {}
        else {
            pixmapSV[0] = new Pixel[imageWidth * imageHeight];
        }
        for (int i = 1; i < imageHeight; i++) {
            pixmapSV[i] = pixmapSV[i - 1] + imageWidth;
        }


        // allocate space for the sobelPixmap using contiguous approach
        sobelPixmap = new Pixel *[imageHeight];
        if (sobelPixmap == nullptr) {}
        else {
            sobelPixmap[0] = new Pixel[imageWidth * imageHeight];
        }
        for (int i = 1; i < imageHeight; i++) {
            sobelPixmap[i] = sobelPixmap[i - 1] + imageWidth;
        }

        pixmapSH = pixmap;
        pixmapSV = pixmap;
        return imageWidth * imageHeight;
    } else {
        std::cerr << "Could not read image from " << inFileName << ", error = " << geterror() << std::endl;
        infile->close();
        return 0;
    }
}

/*! Writes the current image displayed by openGL to a specified file */
void writeImage(const std::string &out) {
    // make a pixmap that is the size of the window
    unsigned char local_pixmap[WinWidth * WinHeight * imChannels];
    glReadPixels(0, 0, WinWidth, WinHeight, pixelFormat, GL_UNSIGNED_BYTE, local_pixmap);

    auto outfile = ImageOutput::create(out);
    if (!outfile) {
        std::cerr << "Error creating creating output image " << out << ", error = " << geterror() << std::endl;
        return;
    }

    // Open a file for writing the image
    ImageSpec spec(WinWidth, WinHeight, imChannels, TypeDesc::UINT8);
    if (!outfile->open(out, spec)) {
        std::cerr << "Error opening " << out << ", error = " << geterror() << std::endl;
        outfile->close();
        return;
    }

    //flip the image upside down by using negative y stride, since OpenGL pix maps have
    // the bottom scanline first, and OpenImageIO writes the top scanline first in the image file.
    int allocationSize = WinWidth * imChannels * sizeof(unsigned char);
    if (!outfile->write_image(TypeDesc::UINT8, local_pixmap + (WinHeight - 1) * allocationSize, AutoStride,
                              -allocationSize)) {
        std::cerr << "Error writing image to " << out << ", error = " << geterror() << std::endl;
        outfile->close();
        return;
    }

    outfile->close();
}

void runMainLoop(int argc, char *argv[]) {
    WinWidth = DEFAULT_WIDTH;
    WinHeight = DEFAULT_HEIGHT;
    imageWidth = 0;
    imageHeight = 0;

    std::cout << "Enter file name " << std::endl;
    std::cin >> fileInput;
    std::cout << "Enter output file name" << std::endl;
    std::cin >> fileOutput;
    std::cout << "Enter divisor amount for kernel (9 for bright images, 7-8 for dark images " << std::endl;
    std::cin >> divisorForKernel;

    if (argc == 3) {
        if (!readImage(fileInput)) {
            std::cerr << "Allocation or read issue with file " << std::endl;
        }
    }
    setKernel(SOBEL_DATA_V);
    setKernel(SOBEL_DATA_H);
    intensityImage();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(WinWidth, WinHeight);
    glutCreateWindow("Cartoon");

    glutDisplayFunc(handleDisplay);
    glutKeyboardFunc(handleKey);
    glutReshapeFunc(handleReshape);

    glutMainLoop();
}


