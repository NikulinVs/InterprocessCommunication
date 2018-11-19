#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

int width = 800;
int height = 600;
int interval = 1;

void enable2D ( int width, int height )
{
	glViewport ( 0 , 0 , width, height );
	glMatrixMode ( GL_PROJECTION );
	glLoadIdentity ( );
	glOrtho ( 0.0f , width, 0.0f , height, 0.0f , 1.0f );
	glMatrixMode ( GL_MODELVIEW );
	glLoadIdentity ( );
}

void drawRect ( float x, float y, float width, float height )
{
	glBegin ( GL_QUADS );
	glVertex2f ( x, y );
	glVertex2f ( x + width, y );
	glVertex2f ( x + width, y + height );
	glVertex2f ( x, y + height );
	glEnd ( );
}

void draw ( )
{
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity ( );

	drawRect ( 100 , 200, 100, 100 );

	glutSwapBuffers ( );
}

void update ( int value )
{
	glutTimerFunc ( interval, update, 0 );

	glutPostRedisplay ( );
}

void render_init(int argc, char ** argv, int w, int h)
{
	width = w;
	height = h;

	glutInit ( & argc, argv );
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize ( width, height );
	glutCreateWindow ( "Pong" );

	glutDisplayFunc ( draw );
	glutTimerFunc ( interval, update, 0 );

	enable2D ( width, height );
	glColor3f ( 1.0f , 0.0f , 1.0f );
	glutMainLoop();
}

int main(int argc, char** argv)
{
    render_init(argc, argv, width, height);

    return 0;
}
