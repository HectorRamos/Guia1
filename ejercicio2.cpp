#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
	
	//dibujando el triangulo de arriba
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f,0.5f,0.0);
	glVertex3f(-0.25f,0.25f,0.0f);
	glVertex3f(0.25f,0.25f,0.0f);
	
	glEnd();
	
	//glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 1.0);
	//Dibujando el cuadrado
	glBegin(GL_QUADS);
	glVertex3f (-0.25f, 0.25f, 0.0f);
	glVertex3f (0.25f, 0.25f, 0.0f);
	glVertex3f (0.25f, -0.25f, 0.0f);
	glVertex3f (-0.25f, -0.25f, 0.0f);
	
	glEnd();
	
	//dibujando el triangulo de abajo
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0,-0.5,0.0);
	glVertex3f(0.25,-0.25,0.0);
	glVertex3f(-0.25,-0.25,0.0);
	
	glEnd();
	
	//dibujando el triangulo de la derecha
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(0.25,-0.25,0.0);
	glEnd();
	
	//dibujando el triangulo de la izquierda
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,0.0,0.0);
	glVertex3f(-0.25,-0.25,0.0);
	glVertex3f(-0.25,0.25,0.0);
	
	glEnd();
	glFlush ();
	
	}
	
void init (void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0,-1.0, 1.0);
	
	}
int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("ejercicio2");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
	}
