#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (79, 148, 205);
glPointSize(5.0);


//Background
glBegin(GL_QUADS);
glVertex2i(0, 0);
glVertex2i(0, 640);

glVertex2i(0, 640);
glVertex2i(640, 480);

glVertex2i(640, 480);
glVertex2i(640, 0);

glVertex2i(640, 0);
glVertex2i(0, 0);

glEnd();
glFlush ();

//Hair
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(260, 430);
glVertex2i(310, 430);

glVertex2i(310, 430);
glVertex2i(310, 470);

glVertex2i(310, 470);
glVertex2i(260, 470);

glVertex2i(260, 470);
glVertex2i(260, 430);

glEnd();
glFlush ();

glColor3ub (10, 10, 10);
glPointSize(5.0);
//Hair
glBegin(GL_QUADS);
glVertex2i(310, 430);
glVertex2i(370, 430);

glVertex2i(370, 430);
glVertex2i(370, 455);

glVertex2i(370, 455);
glVertex2i(310, 455);

glVertex2i(310, 455);
glVertex2i(310, 430);

glEnd();
glFlush ();

//FACE
glColor3ub (236, 188, 140);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(280, 375);
glVertex2i(365, 375);

glVertex2i(365, 375);
glVertex2i(365, 430);

glVertex2i(365, 430);
glVertex2i(280, 430);

glVertex2i(280, 430);
glVertex2i(280, 375);

glEnd();
glFlush ();

//Glass right
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(260, 422);
glVertex2i(280, 422);

glVertex2i(280, 422);
glVertex2i(280, 405);

glVertex2i(280, 405);
glVertex2i(260, 405);

glVertex2i(260, 405);
glVertex2i(260, 422);

glEnd();
glFlush ();

//Glass middle
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(280, 422);
glVertex2i(295, 422);

glVertex2i(295, 422);
glVertex2i(295, 416);

glVertex2i(295, 416);
glVertex2i(280, 416);

glVertex2i(280, 416);
glVertex2i(280, 422);

glEnd();
glFlush ();

//Glass left
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(295, 405);
glVertex2i(320, 405);

glVertex2i(320, 405);
glVertex2i(320, 422);

glVertex2i(320, 422);
glVertex2i(295, 422);

glVertex2i(295, 422);
glVertex2i(295, 405);

glEnd();
glFlush ();

//hair side
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(331, 390);
glVertex2i(342, 390);

glVertex2i(342, 390);
glVertex2i(342, 430);

glVertex2i(342, 430);
glVertex2i(331, 430);

glVertex2i(331, 430);
glVertex2i(331, 390);

glEnd();
glFlush ();

//Hair side/back
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(342, 417);
glVertex2i(355, 417);

glVertex2i(355, 417);
glVertex2i(355, 430);

glVertex2i(355, 430);
glVertex2i(342, 430);

glVertex2i(342, 430);
glVertex2i(342, 417);

glEnd();
glFlush ();

//Neck
glColor3ub (236, 188, 140);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(310, 355);
glVertex2i(365, 355);

glVertex2i(365, 375);
glVertex2i(310, 375);

glEnd();
glFlush ();

//Coat collar
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(365, 355);
glVertex2i(385, 355);

glVertex2i(385, 380);
glVertex2i(365, 380);

glVertex2i(365, 380);
glVertex2i(375, 380);

glVertex2i(375, 390);
glVertex2i(365, 390);

glVertex2i(290, 355);
glVertex2i(310, 355);

glVertex2i(310, 375);
glVertex2i(290, 375);

//Coat full body
glVertex2i(270, 355);
glVertex2i(405, 355);

glVertex2i(405, 230);
glVertex2i(270, 230);

glEnd();
glFlush ();


//T shirt(White) inside Coat
glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(310, 335);
glVertex2i(365, 335);

glVertex2i(365, 355);
glVertex2i(310, 355);

glVertex2i(320, 320);
glVertex2i(355, 320);

glVertex2i(355, 335);
glVertex2i(320, 335);

glVertex2i(330, 300);
glVertex2i(345, 300);

glVertex2i(345, 320);
glVertex2i(330, 320);

glEnd();
glFlush ();

//Gray Coat line
glColor3ub (128, 128, 128);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(330, 250);
glVertex2i(345, 250);

glVertex2i(345, 300);
glVertex2i(330, 300);

//Gray Belt
glVertex2i(290, 240);
glVertex2i(385, 240);

glVertex2i(385, 250);
glVertex2i(290, 250);

glEnd();
glFlush ();

//Navy blue Pant
glColor3ub (0, 0, 128);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(290, 240);
glVertex2i(385, 240);

glVertex2i(385, 215);
glVertex2i(290, 215);

glVertex2i(290, 215);
glVertex2i(320, 215);

glVertex2i(320, 120);
glVertex2i(290, 120);

glVertex2i(355, 215);
glVertex2i(385, 215);

glVertex2i(385, 120);
glVertex2i(355, 120);

glEnd();
glFlush ();

//Shocks both
glColor3ub (128, 128, 128);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(290, 120);
glVertex2i(320, 120);

glVertex2i(320, 105);
glVertex2i(290, 105);

glVertex2i(355, 120);
glVertex2i(385, 120);

glVertex2i(385, 105);
glVertex2i(355, 105);

glEnd();
glFlush ();

//Shoe both
glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(290, 105);
glVertex2i(320, 105);

glVertex2i(320, 75);
glVertex2i(290, 75);

glVertex2i(355, 105);
glVertex2i(385, 105);

glVertex2i(385, 75);
glVertex2i(355, 75);

glVertex2i(260, 90);
glVertex2i(290, 90);

glVertex2i(290, 75);
glVertex2i(260, 75);

glVertex2i(385, 90);
glVertex2i(415, 90);

glVertex2i(415, 75);
glVertex2i(385, 75);

glEnd();
glFlush ();

//Hands both
glColor3ub (236, 188, 140);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(270, 230);
glVertex2i(300, 230);

glVertex2i(300, 220);
glVertex2i(270, 220);

glVertex2i(270, 220);
glVertex2i(290, 220);

glVertex2i(290, 205);
glVertex2i(270, 205);

glVertex2i(375, 230);
glVertex2i(405, 230);

glVertex2i(405, 220);
glVertex2i(375, 220);

glVertex2i(405, 220);
glVertex2i(385, 220);

glVertex2i(385, 205);
glVertex2i(405, 205);

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
glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize (840, 680);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Human");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
