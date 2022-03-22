#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

//19-40068-1: Jihad Shahariar Joy

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(20.0);

glBegin(GL_LINE_LOOP);

glVertex2i(375,210);
glVertex2i(280,210);
glVertex2i(250,310);
glVertex2i(220,210);
glVertex2i(125,210);
glVertex2i(200,158);
glVertex2i(170,60);
glVertex2i(250,130);
glVertex2i(330,60);
glVertex2i(300,158);

glEnd();
glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 480);
glutInitWindowPosition (200, 60);
glutCreateWindow ("Task 2");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
