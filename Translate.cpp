#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat trans = 0.0;
static GLfloat color = 0.0;

void init(void)
{
    glClearColor(1.0, 0.7, 0.7, 0.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(trans, 0.0, 1.0);
    glColor3f(1.0, 0.23, 0.3);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glColor3f(0.3, 0.3, color);
    glRectf(-15.0, -15.0, 15.0, 15.0);
    glPopMatrix();
    glutSwapBuffers();
}
void transLeft(void)
{
    trans -= 0.5;
    color -= 0.1;
    glutPostRedisplay();
}

void transRight(void)
{
    trans += 0.5;
    color += 0.1;
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-150.0, 150.0, -150.0, 150.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void mouse(int button, int state, int x, int y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(transLeft);
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(transRight);
        break;
    default:
        break;
    }
}

/*
* Initializarea modului de afisare dublu-buffer
* Inregistrarea functiilor callback pentru tratarea
* evenimentelor generate de mouse
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
