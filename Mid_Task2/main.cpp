#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{

glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (0, 0, 255);
glPointSize(5.0);

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




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(295, 90);
glVertex2i(314, 90);
glVertex2i(320, 110);
glVertex2i(325, 90);
glVertex2i(345, 90);

glVertex2i(330, 80);
glVertex2i(335, 60);
glVertex2i(320, 70);
glVertex2i(305, 60);
glVertex2i(310, 80);

glEnd();
glFlush ();



glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(375, 110);
glVertex2i(390, 110);
glVertex2i(398, 127);
glVertex2i(404, 110);
glVertex2i(422, 110);

glVertex2i(408, 100);
glVertex2i(413, 82);
glVertex2i(398, 92);
glVertex2i(383, 83);
glVertex2i(387, 99);

glEnd();
glFlush ();



glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(432, 167);
glVertex2i(450, 167);
glVertex2i(455, 185);
glVertex2i(460, 168);
glVertex2i(478, 167);

glVertex2i(465, 157);
glVertex2i(471, 139);
glVertex2i(455, 150);
glVertex2i(441, 139);
glVertex2i(445, 156);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(452, 246);
glVertex2i(470, 247);
glVertex2i(476, 265);
glVertex2i(482, 247);
glVertex2i(500, 247);

glVertex2i(486, 235);
glVertex2i(490, 218);
glVertex2i(476, 229);
glVertex2i(462, 219);
glVertex2i(466, 234);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(431, 325);
glVertex2i(450, 326);
glVertex2i(455, 342);
glVertex2i(461, 325);
glVertex2i(480, 325);

glVertex2i(465, 314);
glVertex2i(471, 297);
glVertex2i(456, 307);
glVertex2i(441, 297);
glVertex2i(445, 313);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(373, 382);
glVertex2i(390, 383);
glVertex2i(398, 399);
glVertex2i(405, 383);
glVertex2i(422, 383);

glVertex2i(408, 372);
glVertex2i(412, 355);
glVertex2i(398, 365);
glVertex2i(383, 354);
glVertex2i(388, 371);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(295, 405);
glVertex2i(313, 404);
glVertex2i(319, 421);
glVertex2i(325, 404);
glVertex2i(344, 404);

glVertex2i(329, 393);
glVertex2i(334, 376);
glVertex2i(319, 386);
glVertex2i(305, 376);
glVertex2i(309, 392);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(218, 382);
glVertex2i(234, 383);
glVertex2i(241, 400);
glVertex2i(246, 383);
glVertex2i(264, 383);

glVertex2i(250, 371);
glVertex2i(256, 354);
glVertex2i(241, 364);
glVertex2i(226, 354);
glVertex2i(231, 370);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(160, 325);
glVertex2i(176, 325);
glVertex2i(183, 342);
glVertex2i(189, 325);
glVertex2i(208, 325);

glVertex2i(192, 314);
glVertex2i(198, 297);
glVertex2i(183, 307);
glVertex2i(169, 297);
glVertex2i(173, 314);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(160, 167);
glVertex2i(176, 168);
glVertex2i(183, 185);
glVertex2i(189, 168);
glVertex2i(206, 168);

glVertex2i(192, 156);
glVertex2i(198, 139);
glVertex2i(183, 150);
glVertex2i(169, 139);
glVertex2i(173, 157);

glEnd();
glFlush ();




glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(137, 247);
glVertex2i(156, 247);
glVertex2i(162, 264);
glVertex2i(167, 247);
glVertex2i(186, 247);

glVertex2i(171, 236);
glVertex2i(178, 218);
glVertex2i(162, 228);
glVertex2i(147, 218);
glVertex2i(152, 235);

glEnd();
glFlush ();





glBegin(GL_LINE_LOOP);
glColor3f (255, 230, 0);
glVertex2i(216, 110);
glVertex2i(234, 110);
glVertex2i(241, 127);
glVertex2i(246, 110);
glVertex2i(265, 110);

glVertex2i(251, 99);
glVertex2i(256, 82);
glVertex2i(241, 92);
glVertex2i(227, 82);
glVertex2i(231, 98);

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
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Mid Task 2");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
