#include<iostream>
#include<cmath>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;
int r;


void myDisplay(void)
{
float x = 25;

//Red Circle
r = 160;
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (255, 0, 0);
glPointSize(x);

glBegin(GL_POINTS);

int x_old = 0;
int y_old = r;
int x_new, y_new;

int pk = 1-r;

cout<<endl;

cout<<"\n\t----------------";
cout<<"\n\tOther Simulation";
cout<<"\n\t----------------";
cout<<"\n";
cout<<"\n";

for(int i = x_old; x_old<y_old; i=i+1)
{
        if(pk>=0)
        {
            x_new = x_old+1;
            y_new = y_old-1;

            cout<<"\tk = "<<i;//<<endl;
            cout<<"\t O1 = ["<<x_old<<", "<<y_old<<"]";
            cout<<"\t O2 = ["<<y_old<<", "<<x_old<<"]";
            cout<<"\t O3 = ["<<y_old<<", "<<x_old*(-1)<<"]";
            cout<<"\t O4 = ["<<x_old<<", "<<y_old*(-1)<<"]";
            cout<<"\t O5 = ["<<x_old*(-1)<<", "<<y_old*(-1)<<"]";
            cout<<"\t O6 = ["<<y_old*(-1)<<", "<<x_old*(-1)<<"]";
            cout<<"\t O7 = ["<<y_old*(-1)<<", "<<x_old<<"]";
            cout<<"\t O8 = ["<<x_old*(-1)<<", "<<y_old<<"]";

            glVertex2i(x_old + 320, y_old + 240);
            glVertex2i(y_old + 320, x_old + 240);
            glVertex2i(y_old + 320, x_old*(-1) + 240);
            glVertex2i(x_old + 320, y_old*(-1) + 240);
            glVertex2i(x_old*(-1) + 320, y_old*(-1) + 240);
            glVertex2i(y_old*(-1) + 320, x_old*(-1) + 240);
            glVertex2i(y_old*(-1) + 320, x_old + 240);
            glVertex2i(x_old*(-1) + 320, y_old + 240);


            cout<<endl;



            pk = pk + 2*(x_old+1) + (y_new*y_new - y_old*y_old) - (y_new - y_old) + 1;

            x_old = x_new;
            y_old = y_new;


        }
        else if(pk<0)
        {
            x_new = x_old+1;
            y_new = y_old;

            cout<<"\tk = "<<i;//<<endl;
            cout<<"\t O1 = ["<<x_old<<", "<<y_old<<"]";
            cout<<"\t O2 = ["<<y_old<<", "<<x_old<<"]";
            cout<<"\t O3 = ["<<y_old<<", "<<x_old*(-1)<<"]";
            cout<<"\t O4 = ["<<x_old<<", "<<y_old*(-1)<<"]";
            cout<<"\t O5 = ["<<x_old*(-1)<<", "<<y_old*(-1)<<"]";
            cout<<"\t O6 = ["<<y_old*(-1)<<", "<<x_old*(-1)<<"]";
            cout<<"\t O7 = ["<<y_old*(-1)<<", "<<x_old<<"]";
            cout<<"\t O8 = ["<<x_old*(-1)<<", "<<y_old<<"]";


            glVertex2i(x_old + 320, y_old + 240);
            glVertex2i(y_old + 320, x_old + 240);
            glVertex2i(y_old + 320, x_old*(-1) + 240);
            glVertex2i(x_old + 320, y_old*(-1) + 240);
            glVertex2i(x_old*(-1) + 320, y_old*(-1) + 240);
            glVertex2i(y_old*(-1) + 320, x_old*(-1) + 240);
            glVertex2i(y_old*(-1) + 320, x_old + 240);
            glVertex2i(x_old*(-1) + 320, y_old + 240);


            cout<<endl;

            pk = pk + 2*(x_old+1) + (y_new*y_new - y_old*y_old) - (y_new - y_old) + 1;

            x_old = x_new;
            y_old = y_new;

        }
}
cout<<endl<<endl;
glEnd();
glFlush ();


//A

    glColor3ub (128, 0, 0);
    glPointSize(5.0);


    glBegin(GL_QUADS);
    glColor3f ( 255, 255, 255);
    glVertex2i(350,400);
    glVertex2i(390,400);
    glVertex2i(390,200);
    glVertex2i(350,230);

    glVertex2i(350,150);
    glVertex2i(390,180);
    glVertex2i(390,150);
    glVertex2i(350,150);

    glEnd();
    glFlush ();


    glBegin(GL_QUADS);
    glColor3f ( 255, 255, 255);
    glVertex2i(220,80);
    glVertex2i(260,80);
    glVertex2i(390,400);
    glVertex2i(350,400);

    glEnd();
    glFlush ();

    glBegin(GL_QUADS);
    glColor3f ( 255, 255, 255);
    glVertex2i(295,210);
    glVertex2i(350,210);
    glVertex2i(350,170);
    glVertex2i(295,170);

    glEnd();
    glFlush ();

    glBegin(GL_TRIANGLES);
    glColor3f ( 255, 255, 255);
    glVertex2i(350, 225);
    glVertex2i(350, 155);
    glVertex2i(395, 190);
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
glutInitWindowSize (940, 750);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Bonus Task");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();

}
