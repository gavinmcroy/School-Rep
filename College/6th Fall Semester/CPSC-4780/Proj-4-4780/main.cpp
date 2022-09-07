#define GL_SILENCE_DEPRECATION


#ifdef __APPLE__
#include <OpenImageIO/imageio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#elif
#include <OpenImageIO/imageio.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif

OIIO_NAMESPACE_USING
GLuint texture;
GLUquadric *sphere = nullptr;
GLfloat rotate = 0;

void textureGeneration() {
    auto file = ImageInput::open("scuff.ppm");
    if (!file) {
        std::cerr << "Error with file. " << geterror();
        exit(-1);
    }
    ImageSpec spec = file->spec();
    auto *image = new unsigned char[spec.width * spec.height * spec.nchannels];
    file->read_image(TypeDesc::UINT8, image);
    file->close();

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, spec.width, spec.height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                 (const GLvoid *) image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void draw() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotate, 0, 1, 0);

    glColor3f(0.0, 0.0, 1);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, 5, 20, 20);
    glutSwapBuffers();
}

void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0,width / height, 0.1, 100.0);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    textureGeneration();
    sphere = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light[] = {0, 0, 1, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light);
    GLfloat mat[]{0, 0, 1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
}

void update(int x);

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Sphere");
    glutDisplayFunc(draw);
    glutTimerFunc(250, update, 0);
    glutReshapeFunc(resize);

    init();

    glutMainLoop();
}

void update(int x) {
    rotate += 2.0f;
    if (rotate > 360.f) {
        rotate -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
