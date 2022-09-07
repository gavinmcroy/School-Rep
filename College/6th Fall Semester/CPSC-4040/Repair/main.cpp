#include <iostream>
#include <vector>
#include <OpenImageIO/imageio.h>
#include <cmath>

#ifdef __APPLE__

#  include <GLUT/glut.h>

#else
#  include <GL/glut.h>
#endif

using namespace std;
OIIO_NAMESPACE_USING



// Struct Declaration
struct pixel {
    float r, g, b, a;
};


// Global Variable Declarations
int IMAGE_HEIGHT;
int IMAGE_WIDTH;
char *OUTPUT_FILENAME = nullptr;
pixel **ORIGINAL_PIXMAP = nullptr;
pixel **OUTPUT_PIXMAP = nullptr;
pixel **FIXED_PIXMAP = nullptr; // "fixed" is vague, but this is my artifact free pixmap
pixel **UNFIXED_PIXMAP = nullptr; // warped pixmap with artifacts
double PI = 3.1415926535897;
int SWITCH_IMAGE = 0;


/* Handles errors
 * input	- message is printed to stdout, if kill is true end program
 * output	- None
 * side effect - prints error message and kills program if kill flag is set
 */
void handleError(const string &message, bool kill) {
    cout << "ERROR: " << message << "\n";
    if (kill) {
        exit(0);
    }
}


/*
    Initializes a pixmap and sets it up for double array syntax for accessing elements
    input   - pixmap starting address, image width, image height
    output  - None
 */
void initializePixmap(pixel **&pixmap, int image_width, int image_height) {
    pixmap = new pixel *[image_height];
    pixmap[0] = new pixel[image_width * image_height];

    for (int i = 1; i < image_height; i++)
        pixmap[i] = pixmap[i - 1] + image_width;
}


/* Converts pixels from vector to pixel pointers
 * input		- vector of pixels, number of channels
 * output		- None
 * side effect	- saves pixel data from vector to PIXMAP
 */
pixel **convertVectorToImage(vector<float> vector_pixels, int channels) {
    pixel **image;
    initializePixmap(image, IMAGE_WIDTH, IMAGE_HEIGHT);

    int i = 0;
    if (channels == 3) {
        for (int row = IMAGE_HEIGHT - 1; row >= 0; row--)
            for (int col = 0; col < IMAGE_WIDTH; col++) {
                image[row][col].r = vector_pixels[i++];
                image[row][col].g = vector_pixels[i++];
                image[row][col].b = vector_pixels[i++];
                image[row][col].a = 1.0;
            }
    } else if (channels == 4) {
        for (int row = IMAGE_HEIGHT - 1; row >= 0; row--)
            for (int col = 0; col < IMAGE_HEIGHT; col++) {
                image[row][col].r = vector_pixels[i++];
                image[row][col].g = vector_pixels[i++];
                image[row][col].b = vector_pixels[i++];
                image[row][col].a = vector_pixels[i++];
            }
    } else
        handleError("Could not convert image.. sorry", 1);

    return image;
}


/* Reads image specified in argv[1]
 * input		- the input file name
 * output		- None
 */
pixel **readImage(const string &filename) {
    auto in = ImageInput::open(filename);
    if (!in)
        handleError("Could not open input file", true);
    const ImageSpec &spec = in->spec();
    IMAGE_WIDTH = spec.width;
    IMAGE_HEIGHT = spec.height;
    int channels = spec.nchannels;
    if (channels < 3 || channels > 4)
        handleError("Application supports 3 or 4 channel images only", 1);
    vector<float> pixels(IMAGE_WIDTH * IMAGE_HEIGHT * channels);
    in->read_image(TypeDesc::FLOAT, &pixels[0]);
    in->close();

    return convertVectorToImage(pixels, channels);
}


/*
    Flips image verticaly
    input       - pixel map, height of output image, width of output image
    output      - none
    side effect - flips a pixmap vertically
 */
void flipImageVertical(pixel **&pixmap_vertical_flip) {
    pixel **temp_pixmap;
    initializePixmap(temp_pixmap, IMAGE_WIDTH, IMAGE_HEIGHT);

    for (int row = 0; row < IMAGE_HEIGHT; row++)
        for (int col = 0; col < IMAGE_WIDTH; col++)
            temp_pixmap[row][col] = pixmap_vertical_flip[row][col];

    for (int row = IMAGE_HEIGHT - 1; row >= 0; row--)
        for (int col = 0; col < IMAGE_WIDTH; col++)
            pixmap_vertical_flip[(IMAGE_HEIGHT - 1) - row][col] = temp_pixmap[row][col];

    delete temp_pixmap;
}


/* Write image to specified file
 * input		- pixel array, width of display window, height of display window
 * output		- None
 * side effect	- writes image to a file
 */
void writeImage(pixel **&pixmap, char *output_file_name, int window_width, int window_height) {
    const char *filename = output_file_name;
    const int xres = window_width, yres = window_height;
    const int channels = 4; // RGBA`

    flipImageVertical(pixmap);
    auto out = ImageOutput::create(filename);
    if (!out) {
        handleError("Could not create output file", false);
        return;
    }
    ImageSpec spec(xres, yres, channels, TypeDesc::FLOAT);
    out->open(filename, spec);
    out->write_image(TypeDesc::FLOAT, pixmap[0]);
    out->close();
    cout << "SUCCESS: Image successfully written to " << output_file_name << "\n";
}


/* Draw Image to opengl display
 * input		- None
 * output		- None
 * side effect	- draws image to opengl display window
 */
void drawImage() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glRasterPos2i(0, 0);
    glDrawPixels(IMAGE_WIDTH, IMAGE_HEIGHT, GL_RGBA, GL_FLOAT, OUTPUT_PIXMAP[0]);
    glFlush();
}


/*
    Populates the output image based on the inverse warp function
 */
void performSimpleWarp(pixel **&input_pixmap, pixel **&output_pixmap) {
    int u, v; // u and v coordinates of the input image

    for (int row = 0; row < IMAGE_HEIGHT; row++)
        for (int col = 0; col < IMAGE_WIDTH; col++) {
            u = (int) ((double) IMAGE_WIDTH * (1.0 - sqrt(1.0 - ((double) col / (double) IMAGE_WIDTH))) *
                       (1.6 + 0.5 * cos((2 * PI * (double) row) / (double) IMAGE_HEIGHT)));
            v = (int) ((double) IMAGE_HEIGHT * (1.0 - sqrt(1.0 - ((double) row / (double) IMAGE_HEIGHT))) *
                       (1.6 + 0.5 * cos((2 * PI * (double) col) / (double) IMAGE_WIDTH)));
            // basic interpolation
            if (v > (IMAGE_HEIGHT - 1) or u > (IMAGE_WIDTH - 1) or v < 0 or u < 0) {
                output_pixmap[row][col].r = 0.0;
                output_pixmap[row][col].g = 0.0;
                output_pixmap[row][col].b = 0.0;
                output_pixmap[row][col].a = 0.0;
            } else
                output_pixmap[row][col] = input_pixmap[v][u];
        }
}


/*
    gets the weights for the bilinear warp
 */
void getBilinearInterpolationWeights(int x0, int y0, int x1, int y1, double u, double v, double *&weights) {
    *weights = (u - (double) x0) * (v - (double) y0);
    *(weights + 1) = ((double) x1 - u) * (v - (double) y0);
    *(weights + 2) = (u - (double) x0) * ((double) y1 - v);
    *(weights + 3) = ((double) x1 - u) * ((double) y1 - v);
}


/*
    fixes the reconstruction artifacts in the warped image
 */
void fixReconstructionArtifacts(pixel **&input_pixmap, pixel **&output_pixmap) {
    double u, v;
    int x0, y0, x1, y1;

    double *weights;

    weights = (double *) malloc(sizeof(double) * 4);


    for (int row = 0; row < IMAGE_HEIGHT; row++)
        for (int col = 0; col < IMAGE_WIDTH; col++) {
            u = ((double) IMAGE_WIDTH * (1.0 - sqrt(1.0 - ((double) col / (double) IMAGE_WIDTH))) *
                 (1.6 + 0.5 * cos((2 * PI * (double) row) / (double) IMAGE_HEIGHT)));
            v = ((double) IMAGE_HEIGHT * (1.0 - sqrt(1.0 - ((double) row / (double) IMAGE_HEIGHT))) *
                 (1.6 + 0.5 * cos((2 * PI * (double) col) / (double) IMAGE_WIDTH)));

            x0 = (int) floor(u);
            y0 = (int) floor(v);
            x1 = x0 + 1;
            y1 = y0 + 1;

            getBilinearInterpolationWeights(x0, y0, x1, y1, u, v, weights);

            if (v > (IMAGE_HEIGHT - 1) or u > (IMAGE_WIDTH - 1) or v < 0 or u < 0) {
                output_pixmap[row][col].r = 0.0;
                output_pixmap[row][col].g = 0.0;
                output_pixmap[row][col].b = 0.0;
                output_pixmap[row][col].a = 0.0;
            } else {
                output_pixmap[row][col].r = (float) ((*(weights + 3)) * ((double) input_pixmap[y0][x0].r) +
                                                     (*(weights + 1)) * ((double) input_pixmap[y1][x0].r) +
                                                     (*(weights + 2)) * ((double) input_pixmap[y0][x1].r) +
                                                     (*(weights)) * ((double) input_pixmap[y1][x1].r));
                output_pixmap[row][col].g = (float) ((*(weights + 3)) * ((double) input_pixmap[y0][x0].g) +
                                                     (*(weights + 1)) * ((double) input_pixmap[y1][x0].g) +
                                                     (*(weights + 2)) * ((double) input_pixmap[y0][x1].g) +
                                                     (*(weights)) * ((double) input_pixmap[y1][x1].g));
                output_pixmap[row][col].b = (float) ((*(weights + 3)) * ((double) input_pixmap[y0][x0].b) +
                                                     (*(weights + 1)) * ((double) input_pixmap[y1][x0].b) +
                                                     (*(weights + 2)) * ((double) input_pixmap[y0][x1].b) +
                                                     (*(weights)) * ((double) input_pixmap[y1][x1].b));
                output_pixmap[row][col].a = (float) ((*(weights + 3)) * ((double) input_pixmap[y0][x0].a) +
                                                     (*(weights + 1)) * ((double) input_pixmap[y1][x0].a) +
                                                     (*(weights + 2)) * ((double) input_pixmap[y0][x1].a) +
                                                     (*(weights)) * ((double) input_pixmap[y1][x1].a));
            }
        }
}


/* Key press handler
 * input	- Handled by opengl, because this is a callback function.
 * output	- None
 */
void handleKey(unsigned char key, int x, int y) {
    if (key == 'q' or key == 'Q') {
        cout << "\nProgram Terminated." << endl;
        exit(0);
    } else if ((key == 'w' or key == 'W') and OUTPUT_FILENAME != NULL)
        writeImage(OUTPUT_PIXMAP, OUTPUT_FILENAME, IMAGE_WIDTH, IMAGE_HEIGHT);
    else if ((key == 'w' or key == 'W') and OUTPUT_FILENAME == NULL)
        handleError("Output image unspecified.\nTo write to output image use:\n $> ./warp input.img output.img", 0);
    else if ((key == 'r' or key == 'R')) {
        if (SWITCH_IMAGE == 0)
            SWITCH_IMAGE = 1;
        fixReconstructionArtifacts(ORIGINAL_PIXMAP, FIXED_PIXMAP);
        OUTPUT_PIXMAP = FIXED_PIXMAP;
        glutPostRedisplay();
    } else if ((key == 'u' or key == 'U')) {
        if (SWITCH_IMAGE == 1)
            SWITCH_IMAGE = 0;
        OUTPUT_PIXMAP = UNFIXED_PIXMAP;
        glutPostRedisplay();
    }
}


/* Initialize opengl
* input	- command line arguments
* output	- none
*/
void openGlInit(int argc, char *argv[]) {
    // start up the glut utilities
    glutInit(&argc, argv);

    // create the graphics window, giving width, height, and title text
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(IMAGE_WIDTH, IMAGE_HEIGHT);
    glutCreateWindow("Warp Result");

    // set up the callback routines to be called when glutMainLoop() detects
    // an event
    glutDisplayFunc(drawImage);                // display callback
    glutKeyboardFunc(handleKey);            // keyboard callback

    // define the drawing coordinate system on the viewport
    // lower left is (0, 0), upper right is (WIDTH, HEIGHT)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, IMAGE_WIDTH, 0, IMAGE_HEIGHT);

    // specify window clear (background) color to be opaque white
    glClearColor(1, 1, 1, 0);

    // Routine that loops forever looking for events. It calls the registered
    // callback routine to handle each event that is detected
    glutMainLoop();
}


int main(int argc, char *argv[]) {

    // check for valid argument values
    if (argc != 2 and argc != 3)
        handleError("Proper use:\n$> warp input.img [output.img]", 1);

    if (argc == 3)
        OUTPUT_FILENAME = argv[2];

    // read the image data and store it in pixmap
    ORIGINAL_PIXMAP = readImage(argv[1]);

    // initialize the pixmaps
    initializePixmap(OUTPUT_PIXMAP, IMAGE_WIDTH, IMAGE_HEIGHT);
    initializePixmap(UNFIXED_PIXMAP, IMAGE_WIDTH, IMAGE_HEIGHT);
    initializePixmap(FIXED_PIXMAP, IMAGE_WIDTH, IMAGE_HEIGHT);

    // apply the warping function without artifact removal to unfixed  pixmap
    performSimpleWarp(ORIGINAL_PIXMAP, UNFIXED_PIXMAP);

    // copy the unfixed pixmap to the output pixmap
    for (int row = 0; row < IMAGE_HEIGHT; row++)
        for (int col = 0; col < IMAGE_WIDTH; col++)
            OUTPUT_PIXMAP[row][col] = UNFIXED_PIXMAP[row][col];

    // start opengl
    openGlInit(argc, argv);

    return 0;
}
