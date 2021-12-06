#define GL_SILENCE_DEPRECATION

#include "Cartoon.h"

/*! window dimensions if no image */
const int DEFAULT_WIDTH = 512;
const int DEFAULT_HEIGHT = 512;

/*! window width and height */
int WinWidth;
int WinHeight;

/*! image width and height */
int ImWidth;
int ImHeight;

/*! number of channels per image pixel */
int ImChannels;

/*! viewport width and height */
int VpWidth;
int VpHeight;

/*! viewport offset from lower left corner of window */
int xOffset;
int yOffset;

/*! the pixel format used to correctly  draw the image */
int pixelFormat;

/*! the image pixmap used for OpenGL */
Pixel **pixmap;

Pixel **pixmapSH;
Pixel **pixmapSV;
Pixel **sobelPixmap;

std::string outName;
const int kernelSize = 3;
double kernel[kernelSize][kernelSize];
double range[kernelSize][kernelSize];
double domain[kernelSize][kernelSize];
float **intenseMatrix;
float **tempMatrix;


double SOBEL_V[3][3] = {{-1, 0, 1},
                        {-2, 0, 2},
                        {-1, 0, 1}};

double SOBEL_H[3][3] = {{1,  2,  1},
                        {0,  0,  0},
                        {-1, -2, -1}};

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

/*! Determines the intensity values for each pixel of the image */
void intensityImg() {
    // Allocation process for intensity matrix
    intenseMatrix = new float *[ImHeight];
    if (intenseMatrix != nullptr) {
        intenseMatrix[0] = new float[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        intenseMatrix[i] = intenseMatrix[i - 1] + ImWidth;
    }

    //allocation process for temp matrix
    tempMatrix = new float *[ImHeight];
    if (tempMatrix != nullptr) {
        tempMatrix[0] = new float[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        tempMatrix[i] = tempMatrix[i - 1] + ImWidth;
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
    for (int row = 0; row < ImHeight; row++) {
        for (int col = 0; col < ImWidth; col++) {
            intenseMatrix[row][col] = (float) ((pixmap[row][col].r * 0.4) + (pixmap[row][col].g * 0.7) +
                                               (pixmap[row][col].b * 0.01));
        }
    }
}

/*! Ensures that the range given is within the range we want) */
void getRange(int i, int j) {
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            double rangeValue = 0.0;
            /* Ensures that the range is within desired range */
            if (i + x >= 0 && i + x < ImHeight && j + y >= 0 && j + y < ImWidth) {
                double top = intenseMatrix[i + x][j + y] - intenseMatrix[i][j];
                top = pow(top, 2);
                // 98 = 2(7)^2 (7 is the standard deviation)
                top /= 98;
                rangeValue = exp(-top);
            }
            range[x + 1][y + 1] = rangeValue;
        }
    }
}

/*! Applies domain * range to kernel */
void domainRange() {
    for (int row = 0; row < kernelSize; row++) {
        for (int col = 0; col < kernelSize; col++) {
            kernel[row][col] = domain[row][col] * range[row][col];
        }
    }
}

/*! Apply final kernel to the intensity img to create a new intensity image */
void applyIntensityKernel(int y, int x) {
    int center = kernelSize / 2;
    double s = 0.0;

    // The kernel is centered at k_center loop takes values -1, 0, 1
    for (int j = -center; j <= center; j++) {
        for (int i = -center; i <= center; i++) {
            double modifier = kernel[center + i][center + j];
            if (i + x < 0 || i + x >= ImWidth || j + y < 0 || j + y >= ImHeight) {
                continue;
            }
            s = intenseMatrix[y + j][x + i] * modifier;
        }
    }
    tempMatrix[y][x] = (float) s;
}

void applyBilateralFilter() {
    for (int i = 0; i < ImHeight; i++) {
        for (int j = 0; j < ImWidth; j++) {
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
    for (int i = 0; i < ImHeight; i++) {
        for (int j = 0; j < ImWidth; j++) {
            double averageR = 0.0;
            double averageG = 0.0;
            double averageB = 0.0;
            if (i - 1 >= 0 && i + 1 < ImHeight && j - 1 >= 0 && j + 1 < ImWidth) {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        averageR += pixmap[x][y].r;
                        averageG += pixmap[x][y].g;
                        averageB += pixmap[x][y].b;
                    }
                }
                pixmap[i][j].r = (unsigned char) (averageR / 9);
                pixmap[i][j].g = (unsigned char) (averageG / 9);
                pixmap[i][j].b = (unsigned char) (averageB / 9);
            }
        }
    }
}

//void print() {
//    std::cout << "SOBEL H" << std::endl;
//    for (int row = 0; row < kernelSize; row++) {
//        for (int col = 0; col < kernelSize; col++) {
//            std::cout << SOBEL_H[row][col] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl << "SOBEL V" << std::endl;
//    for (int row = 0; row < kernelSize; row++) {
//        for (int col = 0; col < kernelSize; col++) {
//
//            std::cout << SOBEL_V[row][col] << " ";
//        }
//        std::cout << std::endl;
//    }
//}

void flipKernel(double kernelTemp[][3]) {
    double temp;
    // Preform horizontal flip
    for (int y = 0; y < kernelSize; y++) {
        for (int x = 0; x < kernelSize / 2; x++) {
            temp = kernelTemp[kernelSize - x - 1][y];
            kernelTemp[kernelSize - x - 1][y] = kernelTemp[x][y];
            kernelTemp[x][y] = temp;
        }
    }

    // Preform vertical flip
    for (int x = 0; x < kernelSize; x++) {
        for (int y = 0; y < kernelSize / 2; y++) {
            temp = kernelTemp[x][kernelSize - y - 1];
            kernelTemp[x][kernelSize - y - 1] = kernelTemp[x][y];
            kernelTemp[x][y] = temp;
        }
    }
}

/*! Apply the scale factor to the kernel */
void setKernel(double (*matrixTemp)[3]) {
    double sum = 0.0;
    int weight;

    for (int row = 0; row < kernelSize; row++) {
        for (int col = 0; col < kernelSize; col++) {
            weight = (int) matrixTemp[row][col];
            if (weight > 0) {
                sum += weight;
            }
        }
    }

    flipKernel(matrixTemp);

    for (int row = 0; row < kernelSize; row++) {
        for (int col = 0; col < kernelSize; col++) {
            matrixTemp[row][col] = .25 * (matrixTemp[row][col] / sum);
        }
    }
}

/*! The kernel is centered at k_center loop takes values -1, 0, 1. Applies kernel to one pixel */
void applyKernel(Pixel **pix, Pixel **temp_pixel, double (*matrixTemp)[3], int y, int x) {
    int center = kernelSize / 2;
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    /* Our 3x3 kernel */
    for (int j = -center; j <= center; j++) {
        for (int i = -center; i <= center; i++) {
            Pixel p = pix[y + i][x + i];
            double modifier = matrixTemp[center + i][center + j];
            r += p.r * modifier;
            g += p.g * modifier;
            b += p.b * modifier;
        }
    }

    // Make sure within RBG range of pixel
    temp_pixel[y][x].r = (int) clamp(0.0, 255.0, r);
    temp_pixel[y][x].g = (int) clamp(0.0, 255.0, g);
    temp_pixel[y][x].b = (int) clamp(0.0, 255.0, b);
}

/*! Allocate memory for copy pixmap and apply kernel to the actual pixmap for all pixels */
void convolveImage(Pixel **pixmapTemp, double (*matrixTemp)[3]) {
    int center = kernelSize / 2;

    // contiguous method of allocation
    auto **copyPixmap = new Pixel *[ImHeight];
    copyPixmap[0] = new Pixel[ImWidth * ImHeight];
    for (int i = 1; i < ImHeight; i++) {
        copyPixmap[i] = copyPixmap[i - 1] + ImWidth;
    }

    // Apply kernel to each pixel and omit outer edge
    for (int y = center; y < ImHeight - center; y++) {
        for (int x = center; x < ImWidth - center; x++) {
            applyKernel(pixmapTemp, copyPixmap, matrixTemp, y, x);
        }
    }
}

/*! Returns sobel when given colorH and colorV */
double calculateSobel(double colorH, double colorV) {
    double x = pow(colorH, 2);
    double y = pow(colorV, 2);
    return sqrt(y + x);
}

/*! Basically calculate sobel for every pixel and add it to the sobel pixmap */
void combineImg() {
    for (int row = 0; row < ImHeight; row++) {
        for (int col = 0; col < ImWidth; col++) {
            sobelPixmap[row][col].r = (unsigned char) calculateSobel(pixmapSH[row][col].r, pixmapSV[row][col].r);
            sobelPixmap[row][col].g = (unsigned char) calculateSobel(pixmapSH[row][col].g, pixmapSV[row][col].g);
            sobelPixmap[row][col].b = (unsigned char) calculateSobel(pixmapSH[row][col].b, pixmapSV[row][col].b);
        }
    }
}

/*! Combine bilateral filter + Sobel and ensure pixels are within range */
void combineBilateralSobel() {
    for (int i = 0; i < ImHeight; i++) {
        for (int j = 0; j < ImWidth; j++) {
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
    ImWidth = spec.width;
    ImHeight = spec.height;
    ImChannels = spec.nchannels;

    // allocate temporary structure to read the image
    auto *temporaryStruct = new unsigned char[ImWidth * ImHeight * ImChannels];

    // read the image into the tmp_pixels from the input file, flipping it upside down using negative y-stride,
    // since OpenGL pixmaps have the bottom scanline first, and
    // oiio expects the top scanline first in the image file.
    int allocationSize = ImWidth * ImChannels * sizeof(unsigned char);
    if(!infile->read_image(TypeDesc::UINT8, &temporaryStruct[0] + (ImHeight - 1) * allocationSize, AutoStride, -allocationSize)){
        std::cerr << "Could not read image from " << inFileName << ", error = " << geterror() << std::endl;
        infile->close();
        return 0;
    }

    // get rid of the old OpenGL pixmap and make a new one of the new size
    destroy();

    // allocate space for the Pixmap using contiguous approach
    pixmap = new Pixel *[ImHeight];
    if (pixmap != nullptr) {
        pixmap[0] = new Pixel[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        pixmap[i] = pixmap[i - 1] + ImWidth;
    }

    // Build pixmap structure with temporarily read in pixels
    int index;
    for (int row = 0; row < ImHeight; ++row) {
        for (int col = 0; col < ImWidth; ++col) {
            index = (row * ImWidth + col) * ImChannels;
            if (ImChannels == 1) {
                pixmap[row][col].r = temporaryStruct[index];
                pixmap[row][col].g = temporaryStruct[index];
                pixmap[row][col].b = temporaryStruct[index];
                pixmap[row][col].a = 255;
            } else {
                pixmap[row][col].r = temporaryStruct[index];
                pixmap[row][col].g = temporaryStruct[index + 1];
                pixmap[row][col].b = temporaryStruct[index + 2];
                // no alpha value is present so set it to 255
                if (ImChannels < 4) {
                    pixmap[row][col].a = 255;
                } else {
                    pixmap[row][col].a = temporaryStruct[index + 3];
                }
            }
        }
    }

    infile->close();

    // Set format to OpenGL 4 channel mode
    pixelFormat = GL_RGBA;
    ImChannels = 4;

    // allocate space for the PixmapSH (contiguous approach)
    pixmapSH = new Pixel *[ImHeight];
    if (pixmapSH != nullptr) {
        pixmapSH[0] = new Pixel[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        pixmapSH[i] = pixmapSH[i - 1] + ImWidth;
    }


    // allocate space for the PixmapSV using contiguous
    pixmapSV = new Pixel *[ImHeight];
    if (pixmapSV != nullptr) {
        pixmapSV[0] = new Pixel[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        pixmapSV[i] = pixmapSV[i - 1] + ImWidth;
    }


    // allocate space for the sobelPixmap using contiguous approach
    sobelPixmap = new Pixel *[ImHeight];
    if (sobelPixmap != nullptr) {
        sobelPixmap[0] = new Pixel[ImWidth * ImHeight];
    }
    for (int i = 1; i < ImHeight; i++) {
        sobelPixmap[i] = sobelPixmap[i - 1] + ImWidth;
    }

    pixmapSH = pixmap;
    pixmapSV = pixmap;
    return ImWidth * ImHeight;
}

void writeImage(const std::string &out) {
    // make a pixmap that is the size of the window
    unsigned char local_pixmap[WinWidth * WinHeight * ImChannels];
    glReadPixels(0, 0, WinWidth, WinHeight, pixelFormat, GL_UNSIGNED_BYTE, local_pixmap);

    auto outfile = ImageOutput::create(out);
    if (!outfile) {
        std::cerr << "Could not create output image for " << out << ", error = " << geterror() << std::endl;
        return;
    }

    // Open a file for writing the image
    ImageSpec spec(WinWidth, WinHeight, ImChannels, TypeDesc::UINT8);
    if (!outfile->open(out, spec)) {
        std::cerr << "Could not open " << out << ", error = " << geterror() << std::endl;
        outfile->close();
        return;
    }

    //flip the image upside down by using negative y stride, since OpenGL pix maps have
    // the bottom scanline first, and OpenImageIO writes the top scanline first in the image file.
    unsigned int memorySize = WinWidth * ImChannels * sizeof(unsigned char);
    if (!outfile->write_image(TypeDesc::UINT8, local_pixmap + (WinHeight - 1) * memorySize, AutoStride,
                              -memorySize)) {
        std::cerr << "Could not write image to " << out << ", error = " << geterror() << std::endl;
        outfile->close();
        return;
    }

    outfile->close();
}

void handleDisplay() {
    // Background to all black
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // only draw the image if it is of a valid size
    if (ImWidth > 0 && ImHeight > 0){
        displayimage();
    }
    glFlush();
}

void handleKey(unsigned char key, int x, int y) {
    switch (key) {
        // 's' - apply the sobel operator to the image
        case 's':
            convolveImage(pixmapSH, SOBEL_H); //make pixmapSH
            convolveImage(pixmapSV, SOBEL_V); //make pixmapSV
            combineImg(); //combine the two pixmap
            combineBilateralSobel();
            glutReshapeWindow(WinWidth, WinHeight); // OpenGL window should match new image
            glutPostRedisplay();
            break;
        case 'b': // 'b' - apply the bilateral filter to the image
            applyBilateralFilter();
            glutReshapeWindow(WinWidth, WinHeight); // OpenGL window should match new image
            glutPostRedisplay();
            break;
        case 'w':        // 'w' - write the current image to a file
            writeImage(outName);
            break;

        case 'q':        // q or ESC - quit
        case 'Q':
        case 27:
            destroy();
            exit(0);

        default:        // not a valid key -- just ignore it
            return;
    }
}

void handleReshape(int w, int h) {
    float imageaspect = (float) ImWidth / (float) ImHeight;    // aspect ratio of image
    float newaspect = (float) w / (float) h; // new aspect ratio of window

    // record the new window size in global variables for easy access
    WinWidth = w;
    WinHeight = h;

    // if the image fits in the window, viewport is the same size as the image
    if (w >= ImWidth && h >= ImHeight) {
        xOffset = (w - ImWidth) / 2;
        yOffset = (h - ImHeight) / 2;
        VpWidth = ImWidth;
        VpHeight = ImHeight;
    }
        // if the window is wider than the image, use the full window height
        // and size the width to match the image aspect ratio
    else if (newaspect > imageaspect) {
        VpHeight = h;
        VpWidth = int(imageaspect * VpHeight);
        xOffset = int((w - VpWidth) / 2);
        yOffset = 0;
    }
        // if the window is narrower than the image, use the full window width
        // and size the height to match the image aspect ratio
    else {
        VpWidth = w;
        VpHeight = int(VpWidth / imageaspect);
        yOffset = int((h - VpHeight) / 2);
        xOffset = 0;
    }

    // center the viewport in the window
    glViewport(xOffset, yOffset, VpWidth, VpHeight);

    // viewport coordinates are simply pixel coordinates
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, VpWidth, 0, VpHeight);
    glMatrixMode(GL_MODELVIEW);
}

void displayimage() {
    // if the window is smaller than the image, scale it down, otherwise do not scale
    if (WinWidth < ImWidth || WinHeight < ImHeight)
        glPixelZoom(float(VpWidth) / ImWidth, float(VpHeight) / ImHeight);
    else
        glPixelZoom(1.0, 1.0);

    // display starting at the lower lefthand corner of the viewport
    glRasterPos2i(0, 0);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glDrawPixels(ImWidth, ImHeight, pixelFormat, GL_UNSIGNED_BYTE, pixmap[0]);
}

void runMainLoop(int argc, char *argv[]) {
    // scan command line and process
    // only one parameter allowed, an optional image filename and extension
    //Check to see the user entered four command arugments
//    if (argc < 3) {
//        std::cerr << "USAGE: ./cartoon <in.png> <out.png>" << std::endl;
//        exit(1);
//    }

    // set up the default window and empty pixmap if no image or image fails to load
    WinWidth = DEFAULT_WIDTH;
    WinHeight = DEFAULT_HEIGHT;
    ImWidth = 0;
    ImHeight = 0;

    std::string input;
    std::cin >> input;
//       img_name = argv[1];
//       out_name = argv[2];

    // load the image if present, and size the window to match
    if (argc == 3) {
        if (readImage(input)) {

        }
    }
    setKernel(SOBEL_V);
    setKernel(SOBEL_H);

    intensityImg();

    // start up GLUT
    glutInit(&argc, argv);

    // create the graphics window, giving width, height, and title text
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(WinWidth, WinHeight);
    glutCreateWindow("Cartoon");

    // set up the callback routines
    glutDisplayFunc(handleDisplay); // display update callback
    glutKeyboardFunc(handleKey);      // keyboard key press callback
    glutReshapeFunc(handleReshape); // window resize callback


    // Enter GLUT's event loop
    glutMainLoop();
}


