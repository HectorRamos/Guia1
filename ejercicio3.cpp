#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
	
	//dibujando el triangulo de enfrente
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.9,0.0,0.0);
	glVertex3f(0.5,0.3,0.0);
	glVertex3f(0.5,-0.3,0.0);
	
	glEnd();
	
	glColor3f (0.0, 0.0, 1.0);
	//Dibujando el cuadrado
	glBegin(GL_QUADS);
	glVertex3f (-0.5, 0.25, 0.0);
	glVertex3f (0.5, 0.25, 0.0);
	glVertex3f (0.5, -0.25, 0.0);
	glVertex3f (-0.5, -0.25, 0.0);
	
	glEnd();
	
	//dibujando el triangulo de abajo utilizando TRIANGLE_STRIP
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0,-0.5,0.0);
	glVertex3f(0.25,-0.25,0.0);
	glVertex3f(-0.25,-0.25,0.0);
	glVertex3f(-0.45,-0.8,0.0);
	
	glEnd();
	
	//dibujando el triangulo de arriba utilizando TRIANGLE_STRIP
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0,0.5,0.0);
	glVertex3f(-0.25,0.25,0.0);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(-0.45,0.8,0.0);
	
	glEnd();
	
	//creando cuadros de atras
	glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
	glVertex3f (-0.6, 0.2, 0.0);
	glVertex3f (-0.5, 0.2, 0.0);
	glVertex3f (-0.5, 0.05, 0.0);
	glVertex3f (-0.6, 0.05, 0.0);
	glEnd();
	//creando cuadros de atras
	glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
	glVertex3f (-0.6, -0.2, 0.0);
	glVertex3f (-0.5, -0.2, 0.0);
	glVertex3f (-0.5, -0.05, 0.0);
	glVertex3f (-0.6, -0.05, 0.0);
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
	glutInitWindowSize(500,500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("ejercicio3");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
	}
