#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


//19-40068-1: Jihad Shahariar Joy


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 0, 0);
glPointSize(5.0);

//Division lines
glBegin(GL_LINES);
glVertex2i(340, 2);
glVertex2i(340, 478);
glVertex2i(2, 250);
glVertex2i(638, 250);
glVertex2i(2, 478);
glVertex2i(638, 478);
glVertex2i(2, 2);
glVertex2i(2, 478);
glVertex2i(638, 2);
glVertex2i(638, 478);
glVertex2i(2, 2);
glVertex2i(638, 2);
glEnd();
glFlush ();

//Triangles
glBegin(GL_TRIANGLES);
glVertex2i(180, 390);
glVertex2i(150, 450);
glVertex2i(210, 450);
glEnd();
glFlush ();
glBegin(GL_TRIANGLES);
glVertex2i(180, 390);
glVertex2i(150, 330);
glVertex2i(210, 330);
glEnd();
glFlush ();

//Polygon
glBegin(GL_POLYGON);
glVertex2i(500, 420);
glVertex2i(445, 340);
glVertex2i(500, 380);
glVertex2i(555, 340);
glEnd();
glFlush ();

//Lines for 'M' structure
glBegin(GL_LINES);
glVertex2i(430, 80);
glVertex2i(430, 160);

glVertex2i(430, 160);
glVertex2i(480, 120);

glVertex2i(480, 120);
glVertex2i(530, 160);

glVertex2i(530, 160);
glVertex2i(530, 80);
glEnd();
glFlush ();

//Quads
glBegin(GL_QUADS);
glVertex2i(105, 105);
glVertex2i(105, 185);
glVertex2i(185, 185);
glVertex2i(185, 105);

glVertex2i(145, 65);
glVertex2i(145, 145);
glVertex2i(225, 145);
glVertex2i(225, 65);
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
glutInitWindowSize (1000, 780);
glutInitWindowPosition (300, 60);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
