#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <vector>
#include <cfloat>
#include <cstdlib>
#include <OpenImageIO/imageio.h>

#ifdef __APPLE__

#include <GLUT/glut.h>

#else
#include <GL/glut.h>
#endif

OIIO_NAMESPACE_USING

typedef struct Pixel {
    float red;
    float green;
    float blue;
    float alpha;
} Pixel;

float gammaValue;
/* Display Luminance Map */
float **LDMap = nullptr;
/* World Luminance Map */
float **LWMap = nullptr;
/* World Luminance with Applied Filter */
float **LWMapLowPass = nullptr;
/* Subtract LW low pass from log(LW) */
float **LWMapHighPass = nullptr;

Pixel **PIXMAP = nullptr;
Pixel **copyPixmap = nullptr;
char *outputFile = nullptr;
float **filter = nullptr;

const int FILTER_SIZE = 15;
const int RGB = 3;
const int RGBA = 4;
std::string flagOptions[2] = {"-g", "-c"};
int imageHeight;
int imageWidth;

/* Begin Class */
class Image {
public:
    int width;
    int height;
    Pixel **pixmap;

    Image(int x, int y);
};

/* Constructor with pixmap size */
Image::Image(int x, int y) {
    width = x;
    height = y;
    pixmap = new Pixel *[height];
    pixmap[0] = new Pixel[width * height];

    for (int i = 1; i < height; i++) {
        pixmap[i] = pixmap[i - 1] + width;
    }
}
/* End Class */

/* Handles errors and kills program is flag is set true */
void handleError(const std::string &message, bool kill) {
    std::cout << "ERROR: " << message << "\n";
    if (kill) {
        exit(0);
    }
}

/* Initializes a filter map and sets it up for double array syntax for accessing elements */
void initializeFilterMap(float **&filterMap) {
    filterMap = new float *[FILTER_SIZE];
    filterMap[0] = new float[FILTER_SIZE * FILTER_SIZE];

    for (int i = 1; i < FILTER_SIZE; i++) {
        filterMap[i] = filterMap[i - 1] + FILTER_SIZE;
    }
}

/* Finds the maximum of two floating point numbers. If the numbers are equal maximum returns the first parameter */
float maximum(float a, float b) {
    return (a < b) ? b : a;
}


/* Initializes a pixmap and sets it up for double array syntax for accessing elements */
void initializePixmap(Pixel **&pixmap) {
    pixmap = new Pixel *[imageHeight];
    pixmap[0] = new Pixel[imageWidth * imageHeight];

    for (int i = 1; i < imageHeight; i++) {
        pixmap[i] = pixmap[i - 1] + imageWidth;
    }
}

/* Initializes a luminance map and sets it up for double array syntax for accessing elements */
void initializeLuminanceMap(float **&luminanceMap) {
    luminanceMap = new float *[imageHeight];
    luminanceMap[0] = new float[imageWidth * imageHeight];

    for (int i = 1; i < imageHeight; i++) {
        luminanceMap[i] = luminanceMap[i - 1] + imageWidth;
    }
}

/* Converts pixels from vector to Pixel pointers */
Image convertVectorToImage(std::vector<float> vector_pixels, int channels) {
    Image image(imageWidth, imageHeight);
    int i = 0;
    if (channels == RGB) {
        for (int row = image.height - 1; row >= 0; row--) {
            for (int col = 0; col < image.width; col++) {
                image.pixmap[row][col].red = vector_pixels[i++];
                image.pixmap[row][col].green = vector_pixels[i++];
                image.pixmap[row][col].blue = vector_pixels[i++];
                image.pixmap[row][col].alpha = 1.0;
            }
        }
    } else if (channels == RGBA) {
        for (int row = image.height - 1; row >= 0; row--) {
            for (int col = 0; col < image.width; col++) {
                image.pixmap[row][col].red = vector_pixels[i++];
                image.pixmap[row][col].green = vector_pixels[i++];
                image.pixmap[row][col].blue = vector_pixels[i++];
                image.pixmap[row][col].alpha = vector_pixels[i++];
            }
        }
    } else {
        handleError("Could not convert image", true);
    }
    return image;
}

/* Flips image vertically */
void flipImageVertical(float *&pixmapVerticalFlip, int height, int width) {
    Pixel **tempPixmap;
    initializePixmap(tempPixmap);

    int incrementer = 0;
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            tempPixmap[i][j].red = pixmapVerticalFlip[incrementer++];
            tempPixmap[i][j].green = pixmapVerticalFlip[incrementer++];
            tempPixmap[i][j].blue = pixmapVerticalFlip[incrementer++];
            tempPixmap[i][j].alpha = pixmapVerticalFlip[incrementer++];
        }
    }

    incrementer = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixmapVerticalFlip[incrementer++] = tempPixmap[i][j].red;
            pixmapVerticalFlip[incrementer++] = tempPixmap[i][j].green;
            pixmapVerticalFlip[incrementer++] = tempPixmap[i][j].blue;
            pixmapVerticalFlip[incrementer++] = tempPixmap[i][j].alpha;
        }
    }

    delete tempPixmap;
}

/* Reads image specified in argv[1] */
Image readImage(const std::string &filename) {
    auto in = ImageInput::open(filename);
    if (!in) {
        handleError("Could not open input file", true);
    }

    const ImageSpec &spec = in->spec();
    imageWidth = spec.width;
    imageHeight = spec.height;
    int channels = spec.nchannels;

    if (channels < RGB || channels > RGBA) {
        handleError("Application supports 3 or 4 channel images only", true);
    }

    std::vector<float> pixels(imageWidth * imageHeight * channels);

    in->read_image(TypeDesc::FLOAT, &pixels[0]);
    in->close();
    return convertVectorToImage(pixels, channels);
}

/* Write image to specified fill with given Pixel array, width of display window, height of display window */
void writeImage(float *glutDisplayMap, int windowWidth, int windowHeight) {
    const char *filename = outputFile;
    const int xRes = windowWidth;
    const int yRes = windowHeight;
    const int channels = 4;

    auto out = ImageOutput::create(filename);
    if (!out) {
        handleError("Could not create output file", false);
        return;
    }
    ImageSpec spec(xRes, yRes, channels, TypeDesc::FLOAT);
    out->open(filename, spec);
    out->write_image(TypeDesc::FLOAT, glutDisplayMap);
    out->close();

    std::cout << "SUCCESS: Image successfully written to " << outputFile << "\n";
}

/* Calculates the kernel values on a specified channel */
void calculateFilterMap(float **&filterMap, int filterRange, float **lwMap, int lwMapRow, int lwMapCol) {
    int offsetLwMapRow;
    int offsetLwMapCol;

    for (int i = 0; i < FILTER_SIZE; i++) {
        offsetLwMapRow = lwMapRow + i - filterRange;
        for (int j = 0; j < FILTER_SIZE; j++) {
            offsetLwMapCol = lwMapCol + j - filterRange;

            if (offsetLwMapRow < 0 || offsetLwMapRow >= imageHeight || offsetLwMapCol < 0 ||
                offsetLwMapCol >= imageWidth) {
                filterMap[i][j] = 0.0;
            } else {
                filterMap[i][j] =
                        lwMap[offsetLwMapRow][offsetLwMapCol] * filter[i][j];
            }
        }
    }
}

/* Adds together the values of a inputFilter Used for calculating the Pixel value of the center of a kernel */
float sumFilterMapValues(float **&inputFilter) {
    float sumOfFilterValues = 0.0;

    for (int row = 0; row < FILTER_SIZE; row++) {
        for (int col = 0; col < FILTER_SIZE; col++) {
            sumOfFilterValues += inputFilter[row][col];
        }
    }

    return sumOfFilterValues;
}

/* Restores the image to it's original */
void swapOriginalImageAndToneMappedImage() {
    Pixel **tempPixmap;

    initializePixmap(tempPixmap);

    /* Copy the current pixmap */
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            tempPixmap[i][j] = PIXMAP[i][j];
        }
    }

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            PIXMAP[i][j] = copyPixmap[i][j];
        }
    }

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            copyPixmap[i][j] = tempPixmap[i][j];
        }
    }

    delete tempPixmap;
}

/* Convolve the world luminance map with the specified filter */
void convolveWorldLuminance() {
    int filterRange;
    float **filterMap = nullptr;

    filterRange = FILTER_SIZE / 2;

    initializeFilterMap(filterMap);

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            calculateFilterMap(filterMap, filterRange, LWMapLowPass, i, j);
            LWMapLowPass[i][j] = sumFilterMapValues(filterMap);
        }
    }
}

/* Flips a kernel both horizontally and vertically */
void flipFilterXAndY() {
    float **tempFilter = nullptr;

    initializeFilterMap(tempFilter);

    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            tempFilter[i][j] = filter[(FILTER_SIZE - 1) - i][(FILTER_SIZE - 1) - j];
        }
    }

    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            filter[i][j] = tempFilter[i][j];
        }
    }

    delete tempFilter;
}

/* Calculates a scale factor. Divides the filter by the calculated scale factor. */
void normalizeFilter() {
    float scaleFactor;
    float filterValue;
    float sumOfNegativeValues = 0;
    float sumOfPositiveValues = 0;

    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            filterValue = filter[i][j];
            if (filterValue < 0) {
                sumOfNegativeValues += abs(filterValue);
            } else if (filterValue > 0) {
                sumOfPositiveValues += filterValue;
            }
        }
    }
    scaleFactor = maximum(sumOfPositiveValues, sumOfNegativeValues);
    scaleFactor = scaleFactor != 0 ? 1.0 / scaleFactor : 1.0;

    for (int row = 0; row < FILTER_SIZE; row++) {
        for (int col = 0; col < FILTER_SIZE; col++) {
            filter[row][col] = scaleFactor * filter[row][col];
        }
    }
}


/* Gets the world luminance */
void getWorldLuminance(Pixel **&pixmap) {
    Pixel pixel;

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            pixel = pixmap[i][j];
            LWMap[i][j] = (1.0 / 61.0) * (20.0 * pixel.red + 40.0 * pixel.green + pixel.blue);
        }
    }
}


/* Calculates the log with correction for log of zero which is undefined */
float logWithCorrectionForLogOfZero(float value) {
    if (value <= 0) {
        value = FLT_MIN;
    }
    return log(value);
}

/* Gets the display luminance with tone mapping with convolution algorithm */
void getDisplayLuminanceWithConvolutionOnLW() {
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            LWMapLowPass[i][j] = logWithCorrectionForLogOfZero(LWMap[i][j]);
        }
    }
    convolveWorldLuminance();

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            LWMapHighPass[i][j] = logWithCorrectionForLogOfZero(LWMap[i][j]) - LWMapLowPass[i][j];
        }
    }

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            LDMap[i][j] = exp(gammaValue * LWMapLowPass[i][j] + LWMapHighPass[i][j]);
        }
    }
}

/* Gets the display luminance with simple tone mapping algorithm */
void getDisplayLuminance() {
    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            LDMap[i][j] = exp(gammaValue * logWithCorrectionForLogOfZero(LWMap[i][j]));
        }
    }
}

/* Calculates display luminance over world luminance and makes sure you don't divide by zero */
float LDOverLW(float LD, float LW) {
    if (LW <= 0) {
        LW = FLT_MIN;
    }
    return LD / LW;
}

/* Calculates the gamma corrected image with simple tone map algorithm */
void calculateGammaCorrectedImage(Pixel **&imagePixmap) {
    getWorldLuminance(imagePixmap);
    getDisplayLuminance();

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            imagePixmap[i][j].red = LDOverLW(LDMap[i][j], LWMap[i][j]) * imagePixmap[i][j].red;
            imagePixmap[i][j].green = LDOverLW(LDMap[i][j], LWMap[i][j]) * imagePixmap[i][j].green;
            imagePixmap[i][j].blue = LDOverLW(LDMap[i][j], LWMap[i][j]) * imagePixmap[i][j].blue;
        }
    }
}

/* Calculates the gamma corrected image with tone mapping with convolution algorithm */
void calculateGammaCorrectedImageWithConvolution(Pixel **&image_pixmap) {
    getWorldLuminance(image_pixmap);
    getDisplayLuminanceWithConvolutionOnLW();

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            image_pixmap[i][j].red = LDOverLW(LDMap[i][j], LWMap[i][j]) * image_pixmap[i][j].red;
            image_pixmap[i][j].green = LDOverLW(LDMap[i][j], LWMap[i][j]) * image_pixmap[i][j].green;
            image_pixmap[i][j].blue = LDOverLW(LDMap[i][j], LWMap[i][j]) * image_pixmap[i][j].blue;
        }
    }
}

/* Draw Image to opengl display */
void drawImage() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glRasterPos2i(0, 0);
    glDrawPixels(imageWidth, imageHeight, GL_RGBA, GL_FLOAT, PIXMAP[0]);
    glFlush();
}


/* OpenGL Key press handler */
void handleKey(unsigned char key, int x, int y) {
    if (key == 'w') {
        if (outputFile != nullptr) {
            int window_width = glutGet(GLUT_WINDOW_WIDTH);
            int window_height = glutGet(GLUT_WINDOW_HEIGHT);
            auto *glut_display_map = (float *) malloc(window_width * window_height * 4 * sizeof(float));
            glReadPixels(0, 0, window_width, window_height, GL_RGBA, GL_FLOAT, glut_display_map);
            flipImageVertical(glut_display_map, window_height, window_width);
            writeImage(glut_display_map, window_width, window_height);
        } else {
            handleError("Cannot write to file. Specify filename in third argument to write to file.", false);
        }
    } else if (key == 'q' || key == 'Q') {
        std::cout << "\nProgram Terminated." << std::endl;
        exit(0);
    } else if (key == 's' || key == 'S') {
        swapOriginalImageAndToneMappedImage();
        drawImage();
    }
}

void openGlInit(int argc, char *argv[]) {
    glutInit(&argc, argv);

    /* create the graphics window, giving width, height, and title text */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(imageWidth, imageHeight);
    glutCreateWindow("Tone map Result");

    glutDisplayFunc(drawImage);
    glutKeyboardFunc(handleKey);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, imageWidth, 0, imageHeight);

    glClearColor(1, 1, 1, 0);

    glutMainLoop();
}

/* ./programName ['-c' or '-g' need to use one] gamaValue input.img <optionalOutName.img> */
int main(int argc, char *argv[]) {
    bool withConvolution;
    const int MIN_ARGS = 4;
    const int MAX_ARGS = 5;

    if (argc != MIN_ARGS && argc != MAX_ARGS) {
        handleError("Proper use:\n$> tone map ['-c' or '-g' need to use one] gamma_value input.img\n"
                    "$> tone map ['-c' or '-g' need to use one] gamma_value input.img output.img\n"
                    "supported input image formats: .exr .png\n"
                    "supported output image formats: .exr .hdr .png. jpg .tiff\n", true);
    }
    /* Means there is a file output name */
    if (argc == MAX_ARGS) {
        outputFile = argv[4];
    }

    initializeFilterMap(filter);

    for (int i = 0; i < FILTER_SIZE; i++) {
        for (int j = 0; j < FILTER_SIZE; j++) {
            filter[i][j] = 1;
        }
    }

    normalizeFilter();
    flipFilterXAndY();


    if (flagOptions[0] == argv[1]) {
        withConvolution = true;
    } else if (flagOptions[1] == argv[1]) {
        withConvolution = false;
    } else {
        handleError("\nInvalid flag options\nValid flag options are: [-g] for simple tone map and [-c]"
                    "which convolves the log-space luminance into a blurred channel and sharpened channel S,"
                    " and recomposes them as gamma * B + S\n", true);
    }

    gammaValue = atof(argv[2]);

    Image image = readImage(argv[3]);

    initializePixmap(copyPixmap);
    for (int row = 0; row < imageHeight; row++) {
        for (int col = 0; col < imageWidth; col++) {
            copyPixmap[row][col] = image.pixmap[row][col];
        }
    }

    if (withConvolution) {
        initializeLuminanceMap(LWMap);
        initializeLuminanceMap(LDMap);
        initializeLuminanceMap(LWMapLowPass);
        initializeLuminanceMap(LWMapHighPass);
        calculateGammaCorrectedImageWithConvolution(image.pixmap);
        delete LWMap;
        delete LWMapLowPass;
        delete LWMapHighPass;
        delete LDMap;

    } else {
        initializeLuminanceMap(LWMap);
        initializeLuminanceMap(LDMap);
        calculateGammaCorrectedImage(image.pixmap);
        delete LWMap;
        delete LDMap;
    }

    PIXMAP = image.pixmap;
    openGlInit(argc, argv);
}