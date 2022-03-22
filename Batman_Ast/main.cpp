#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void myDisplay(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(4.0);

    // Batman"s dress color is Black but we are doing it in Blue !!!???
    //Batman"s head
    //Left horn

    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(180,330);
    glVertex2i(200,330);
    glVertex2i(200,390);
    glVertex2i(180,390);
    glEnd();
    glFlush ();

    //Right horn
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(220,330);
    glVertex2i(240,330);
    glVertex2i(240,390);
    glVertex2i(220,390);

    glEnd();
    glFlush ();

    //face masked
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(200,330);
    glVertex2i(220,330);
    glVertex2i(220,360);
    glVertex2i(200,360);

    glEnd();
    glFlush ();

    //face open shadow
    glBegin(GL_QUADS);
    glColor3f ( 0.67,0.40,0.07 );
    glVertex2i(180,330);
    glVertex2i(200,330);
    glVertex2i(200,310);
    glVertex2i(180,310);
    glEnd();
    glFlush ();

    //face open light
    glBegin(GL_QUADS);
    glColor3f ( 0.97,0.61,0.20 );
    glVertex2i(200,330);
    glVertex2i(240,330);
    glVertex2i(240,310);
    glVertex2i(200,310);

    glEnd();
    glFlush ();


    //Body
    //Chest
    glBegin(GL_QUADS);
    glColor3f ( 0.47,0.47,0.47 );
    glVertex2i(150,310);
    glVertex2i(270,310);
    glVertex2i(270,280);
    glVertex2i(150,280);

    glEnd();
    glFlush ();

    //Chest and Shoulders
    glBegin(GL_QUADS);
    glColor3f ( 0.47,0.47,0.47 );
    glVertex2i(130,280);
    glVertex2i(290,280);
    glVertex2i(290,255);
    glVertex2i(130,255);

    glEnd();
    glFlush();


    //hand
    glBegin(GL_QUADS);
    glColor3f ( 0.97,0.61,0.20 );
    glVertex2i(130,255);
    glVertex2i(290,255);
    glVertex2i(290,230);
    glVertex2i(130,230);

    glEnd();
    glFlush ();

    //hand
    glBegin(GL_QUADS);
    glColor3f ( 0.47,0.47,0.47 );
    glVertex2i(150,255);
    glVertex2i(270,255);
    glVertex2i(270,230);
    glVertex2i(150,230);

    glEnd();
    glFlush ();


    //gloves blue color
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(130,230);
    glVertex2i(290,230);
    glVertex2i(290,205);
    glVertex2i(130,205);

    glEnd();
    glFlush ();


    //Belt
    glBegin(GL_QUADS);
    glColor3f ( 0.99,0.93,0.13 );
    glVertex2i(150,230);
    glVertex2i(270,230);
    glVertex2i(270,205);
    glVertex2i(150,205);

    glEnd();
    glFlush ();


    //Wings
    glBegin(GL_QUADS);
    glColor3f ( 0.0 ,0.0 ,0.0 );
    glVertex2i(130,205);
    glVertex2i(290,205);
    glVertex2i(290,140);
    glVertex2i(130,140);

    glEnd();
    glFlush ();


    //Pant???
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(150,205);
    glVertex2i(270,205);
    glVertex2i(270,180);
    glVertex2i(150,180);

    glEnd();
    glFlush ();


    //BATMAN UNDERWARE DARK AREA
    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.04,0.12 );
    glVertex2i(150,205);
    glVertex2i(175,205);
    glVertex2i(175,180);
    glVertex2i(150,180);

    glEnd();
    glFlush ();


    //Legs
    //Left leg
    glBegin(GL_QUADS);
    glColor3f ( 0.4,0.4,0.4 );
    glVertex2i(150,180);
    glVertex2i(200,180);
    glVertex2i(200,100);
    glVertex2i(150,100);

    glEnd();
    glFlush ();

    //Right leg
    glBegin(GL_QUADS);
    glColor3f ( 0.4,0.4,0.4 );
    glVertex2i(270,180);
    glVertex2i(220,180);
    glVertex2i(220,100);
    glVertex2i(270,100);

    glEnd();
    glFlush ();

    //pant bottom area
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(175,180);
    glVertex2i(245,180);
    glVertex2i(245,160);
    glVertex2i(175,160);

    glEnd();
    glFlush ();


    //Left leg shadow
    glBegin(GL_QUADS);
    glColor3f ( 0.2,0.2,0.2 );
    glVertex2i(150,180);
    glVertex2i(175,180);
    glVertex2i(175,100);
    glVertex2i(150,100);

    glEnd();
    glFlush ();

    //Right leg shadow
    glBegin(GL_QUADS);
    glColor3f ( 0.2,0.2,0.2 );
    glVertex2i(245,160);
    glVertex2i(220,160);
    glVertex2i(220,100);
    glVertex2i(245,100);

    glEnd();
    glFlush ();

    //Shoe
    //Right leg shoe(Batman POV)
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(150,100);
    glVertex2i(200,100);
    glVertex2i(200,80);
    glVertex2i(150,80);

    glEnd();
    glFlush ();

    //Right leg shoe shadow(Batman POV)
    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(150,100);
    glVertex2i(175,100);
    glVertex2i(175,80);
    glVertex2i(150,80);

    glEnd();
    glFlush ();


    //Left leg shoe(Batman POV)
    glBegin(GL_QUADS);
    glColor3f ( 0.04,0.11,0.30 );
    glVertex2i(220,100);
    glVertex2i(270,100);
    glVertex2i(270,80);
    glVertex2i(220,80);

    glEnd();
    glFlush ();


    //Left leg show shadow(Batman POV)
    glBegin(GL_QUADS);
    glColor3f ( 0.02,0.05,0.12 );
    glVertex2i(220,100);
    glVertex2i(245,100);
    glVertex2i(245,80);
    glVertex2i(220,80);

    glEnd();
    glFlush ();


    //batman left shadow leg show
    glBegin(GL_QUADS);
    glColor3f ( 0.2,0.2,0.2 );
    glVertex2i(175,280);
    glVertex2i(245,280);
    glVertex2i(245,255);
    glVertex2i(175,255);

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
glutCreateWindow ("Batman");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
