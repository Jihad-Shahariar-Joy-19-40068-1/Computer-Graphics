#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void myDisplay(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(4.0);


    glBegin(GL_TRIANGLES);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(70,280);
    glVertex2i(120,230);
    glVertex2i(120,280);

    glVertex2i(220,270);
    glVertex2i(200,280);
    glVertex2i(200,270);

    glVertex2i(580,270);
    glVertex2i(570,230);
    glVertex2i(570,270);

    glVertex2i(125,225);
    glVertex2i(165,185);
    glVertex2i(165,225);

    glVertex2i(155,180);
    glVertex2i(165,180);
    glVertex2i(165,185);

    glVertex2i(570,225);
    glVertex2i(560,180);
    glVertex2i(560,225);


    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(120,230);
    glVertex2i(200,230);
    glVertex2i(200,280);
    glVertex2i(120,280);

    glVertex2i(200,230);
    glVertex2i(220,230);
    glVertex2i(220,270);
    glVertex2i(200,270);

    glVertex2i(220,230);
    glVertex2i(570,230);
    glVertex2i(570,270);
    glVertex2i(220,270);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(165,180);
    glVertex2i(560,180);
    glVertex2i(560,225);
    glVertex2i(165,225);

    glEnd();
    glFlush ();




    glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(90, 280);
glVertex2i(300, 280);

glVertex2i(300, 280);
glVertex2i(300, 350);

glVertex2i(300, 350);
glVertex2i(90, 350);

glVertex2i(90, 350);
glVertex2i(90, 280);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(90, 333);
glVertex2i(300, 333);

glVertex2i(300, 333);
glVertex2i(300, 335);

glVertex2i(300, 335);
glVertex2i(90, 335);

glVertex2i(90, 335);
glVertex2i(90, 333);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(90, 316);
glVertex2i(300, 316);

glVertex2i(300, 316);
glVertex2i(300, 318);

glVertex2i(300, 318);
glVertex2i(90, 318);

glVertex2i(90, 318);
glVertex2i(90, 316);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(90, 299);
glVertex2i(300, 299);

glVertex2i(300, 299);
glVertex2i(300, 301);

glVertex2i(300, 301);
glVertex2i(90, 301);

glVertex2i(90, 301);
glVertex2i(90, 299);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(130, 280);
glVertex2i(132, 280);

glVertex2i(132, 280);
glVertex2i(132, 350);

glVertex2i(132, 350);
glVertex2i(130, 350);

glVertex2i(130, 350);
glVertex2i(130, 280);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(170, 280);
glVertex2i(172, 280);

glVertex2i(172, 280);
glVertex2i(172, 350);

glVertex2i(172, 350);
glVertex2i(170, 350);

glVertex2i(170, 350);
glVertex2i(170, 280);

glEnd();
glFlush ();



glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(210, 280);
glVertex2i(212, 280);

glVertex2i(212, 280);
glVertex2i(212, 350);

glVertex2i(212, 350);
glVertex2i(210, 350);

glVertex2i(210, 350);
glVertex2i(210, 280);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(250, 280);
glVertex2i(252, 280);

glVertex2i(252, 280);
glVertex2i(252, 350);

glVertex2i(252, 350);
glVertex2i(250, 350);

glVertex2i(250, 350);
glVertex2i(250, 280);

glEnd();
glFlush ();


glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_POLYGON);
glVertex2i(305, 280);
glVertex2i(360, 280);

glVertex2i(360, 280);
glVertex2i(360, 340);

glVertex2i(360, 340);
glVertex2i(345, 360);

glVertex2i(345, 360);
glVertex2i(305, 360);

glVertex2i(305, 360);
glVertex2i(305, 280);

glEnd();
glFlush ();



glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(365, 280);
glVertex2i(495, 280);

glVertex2i(495, 280);
glVertex2i(495, 350);

glVertex2i(495, 350);
glVertex2i(365, 350);

glVertex2i(365, 350);
glVertex2i(365, 280);

glEnd();
glFlush ();




glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(365, 333);
glVertex2i(495, 333);

glVertex2i(495, 333);
glVertex2i(495, 335);

glVertex2i(495, 335);
glVertex2i(365, 335);

glVertex2i(365, 335);
glVertex2i(365, 333);

glEnd();
glFlush ();



glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(365, 316);
glVertex2i(495, 316);

glVertex2i(495, 316);
glVertex2i(495, 318);

glVertex2i(495, 318);
glVertex2i(365, 318);

glVertex2i(365, 318);
glVertex2i(365, 316);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(365, 299);
glVertex2i(495, 299);

glVertex2i(495, 299);
glVertex2i(495, 301);

glVertex2i(495, 301);
glVertex2i(365, 301);

glVertex2i(365, 301);
glVertex2i(365, 299);

glEnd();
glFlush ();



glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(405, 280);
glVertex2i(407, 280);

glVertex2i(407, 280);
glVertex2i(407, 350);

glVertex2i(407, 350);
glVertex2i(405, 350);

glVertex2i(405, 350);
glVertex2i(405, 280);

glEnd();
glFlush ();

glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(447, 280);
glVertex2i(449, 280);

glVertex2i(449, 280);
glVertex2i(449, 350);

glVertex2i(449, 350);
glVertex2i(447, 350);

glVertex2i(447, 350);
glVertex2i(447, 280);

glEnd();
glFlush ();


glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_POLYGON);
glVertex2i(500, 280);
glVertex2i(530, 280);

glVertex2i(530, 280);
glVertex2i(530, 365);

glVertex2i(530, 365);
glVertex2i(510, 365);

glVertex2i(510, 365);
glVertex2i(500, 340);

glVertex2i(500, 340);
glVertex2i(500, 280);

glEnd();
glFlush ();


glColor3ub (10, 10, 10);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(535, 280);
glVertex2i(577, 280);

glVertex2i(577, 280);
glVertex2i(577, 350);

glVertex2i(577, 350);
glVertex2i(535, 350);

glVertex2i(535, 350);
glVertex2i(535, 280);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(535, 333);
glVertex2i(577, 333);

glVertex2i(577, 333);
glVertex2i(577, 335);

glVertex2i(577, 335);
glVertex2i(535, 335);

glVertex2i(535, 335);
glVertex2i(535, 333);

glEnd();
glFlush ();

glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(535, 316);
glVertex2i(577, 316);

glVertex2i(577, 316);
glVertex2i(577, 318);

glVertex2i(577, 318);
glVertex2i(535, 318);

glVertex2i(535, 318);
glVertex2i(535, 316);

glEnd();
glFlush ();


glColor3ub (255, 255, 255);
glPointSize(5.0);

glBegin(GL_QUADS);
glVertex2i(535, 299);
glVertex2i(577, 299);

glVertex2i(577, 299);
glVertex2i(577, 301);

glVertex2i(577, 301);
glVertex2i(535, 301);

glVertex2i(535, 301);
glVertex2i(535, 299);

glEnd();
glFlush ();



}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (940, 680);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Mid Task !");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
