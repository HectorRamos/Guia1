#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display()
{

    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Resetear transformaciones
    glLoadIdentity();

    // Rotar en "rotate_x" y "rotate_y"
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Translates the screen left or right,

    // Otras transformaciones
    glScalef(scale, scale, scale);

    
    //cara trasera del cubo
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
	glVertex3f (0.0, 0.5, 0.5);
	glVertex3f (0.5, 0.5, 0.5);
	glVertex3f (0.5, 0.0, 0.5);
	glVertex3f (0.0, 0.0, 0.5);
    glEnd();
    
    glColor3f(1.0,0.0,0.0);//rojo
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.5,0.0,0.5);
	glVertex3f(0.0,0.0,0.5);
	
	glEnd();
	
	glColor3f(1.0,1.0,0.0); //amarillo
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.5,0.5);
	glVertex3f(0.0,0.5,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(0.0,0.0,0.5);
	
	glEnd();
	
	glColor3f(0.0,1.0,0.0); //verde
	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.5,0.0,0.5);
	
	glEnd();
	
//varios colores frente
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(0.0,0.5,0.0);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0.5,0.5,0.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(0.5,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0.0,0.0,0.0);
	
	glEnd();
	
	glColor3f(0.0,0.0,1.0);//azul
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.5,0.0);
	glVertex3f(0.5,0.5,0.0);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.0,0.5,0.5);
	
	glEnd();
    glFlush();
    glutSwapBuffers();

}


void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;

    //  Flecha izquierda: disminuir rotación 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;

    else if (key == GLUT_KEY_UP)
        rotate_x += 7;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;

    else if (key == GLUT_KEY_F2)
        rotate_z += 7;

    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;

    // actualización de visualización
    glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    
    {
	case 't':
			rotate_z +=7; //OBSERVACION: agrege estas letras para la rotacion en Z ya que las teclas especiales como f2 no me funcionan bien
			break;
	case 'T':
			rotate_z -=7;
			break;
    case 's':
        scale=0.5;
        break;
    case 'S':
        scale=1.5;
        break;
    case 'e':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;	
    case 27:
        exit(0);			// exit
    }

    glutPostRedisplay();		  // actualización de visualización
}



int main(int argc, char* argv[])
{

    glutInit(&argc,argv);

    //  Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (0,0);
    // Crear ventana
    glutCreateWindow("Ejercicio4 cubo");

    //  Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); //invoca funcion de teclado
    glutSpecialFunc(specialKeys);//invoca teclas de función especial
    glutMainLoop();
    return 0;

}
