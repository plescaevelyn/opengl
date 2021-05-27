#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    /*şterge toţi pixelii*/
    glClear(GL_COLOR_BUFFER_BIT);
    /* desenează un triunghi echilateral*/
    glColor3f(1.0, 0.45, 0.45);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.50, 0.68301270189, 0.0);
    glEnd();
    /* forţează procesarea rutinelor de desenare*/
    glFlush();
}
void init(void)
{
    /* selectează culoarea de ştergere a ecranului */
    glClearColor(0.45, 0.45, 1.0, 0.0);
    /* iniţializează puntul de vizualizare al scenei */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1.0, 0.0, 1.0, 0.0, -5.0, 0.0);
}

/*
* Declara dimensiunea iniţială a ferestrei şi modul de afişare
* (single buffer si RGBA). Deschide fereastra cu “hello” in bara
* de titlu. Apelează rutinele de iniţializare. Înregistrează funcţiile
* callback de afişarea. Intra în bucla principală si procesează
* eventualele evenimente.
*/

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(125, 100);
    glutCreateWindow("Triunghi echilateral");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}