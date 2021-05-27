#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
	/* şterge toţi pixelii */
	glClear(GL_COLOR_BUFFER_BIT);
	/* desenează un dreptunghi cu colţurile în punctele
	* (0.25, 0.25, 0.0) şi (0.75, 0.75, 0.0)
	*/
	glColor3f(0.3, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	/* forţează procesarea rutinelor de desenare*/
	glFlush();
}
void init(void)
{
	/* selectează culoarea de ştergere a ecranului */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* iniţializează puntul de vizualizare al scenei */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declara dimensiunea iniţială a ferestrei şi modul de afişare
* (single buffer si RGBA). Deschide fereastra cu “hello” in bara
* de titlu. Apelează rutinele de iniţializare. Înregistrează funcţiile
* callback de afişarea. Intra în bucla principală si procesează
* eventualele evenimente.
*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
