#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	
	float corx, cory;
float x, y;
	for (float ang = 0.0f; ang < 360 ; ang+=7.2)
	{
		x= (ang*M_PI)/180;
		y=(ang*M_PI)/180;
		corx=0.5*(cos(x));
		cory=0.5*(sin(y));
		
		glVertex3f(corx,cory,0.0);
		
		
	}
	
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
	glutCreateWindow("CIRCULO CON PUNTOS");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
	}
