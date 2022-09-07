#include <iostream>

#define GL_SILENCE_DEPRECATION

#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

OIIO_NAMESPACE_USING

void loadImage(std::string &input);

void init();

void display();

void reshape(int w, int h);

void keyboard(unsigned char key, int x, int y);

void update(int value);

static GLint height;
double rotate = 0.0;
GLuint tex;
int sphereID = 0;

unsigned char *image = nullptr;
ImageSpec spec;


int main(int argc, char *argv[]) {
    std::string wow = argv[1];
    loadImage(wow);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutTimerFunc(1000, update, 0);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//    glGenTextures(1, &tex);
//    glBindTexture(GL_TEXTURE_2D, tex);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 8, 8, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, image);
//    glBindTexture(GL_TEXTURE_2D, 0);

    GLUquadricObj *sphere=nullptr;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricTexture(sphere, true);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    sphereID = glGenLists(1);
    glNewList(sphereID, GL_COMPILE);
    gluSphere(sphere, 1.0, 20, 20);
    glEndList();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(0, 0);
    //        glDrawPixels(specs[state].width, specs[state].height, getImagePixelTypeForGL(), GL_UNSIGNED_BYTE,
    //                     images[state]);
      //glDrawPixels(spec.width,spec.height,GL_RGB,GL_UNSIGNED_BYTE,image);
    glCallList(sphereID);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, GLsizei(w), GLsizei(h));
    height = (GLint) h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble) w, 0, (GLdouble) h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {

}

void update(int value) {
    rotate += 2.0f;
    if (rotate > 360.f) {
        rotate -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
    std::cout << "hit" << std::endl;
}

void loadImage(std::string &input) {
    auto file = ImageInput::open(input);
    if (!file) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }
    spec = file->spec();
    image = new unsigned char[spec.width * spec.height * spec.nchannels];
    file->read_image(TypeDesc::UINT8, image);
    file->close();
}
