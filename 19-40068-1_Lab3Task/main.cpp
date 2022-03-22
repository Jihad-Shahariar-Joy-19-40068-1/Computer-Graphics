#include<stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int X1,Y1,X2,Y2;

void DDA(void);
void Bressenham(void);
void myInit(void);
void plot(double a,double b);

int main(int argc, char** argv)
{
    cout << "Enter your choice:"<<endl;
    cout<<""<<endl;
    cout << "1.DDA"<<endl;
    cout<<"2.Bressenham"<<endl;
    cout<<"3.Exit"<<endl;

    int choice;
    cout<< ""<<endl;
    cout<<"Input:"<<endl;
    cin>> choice;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 50);
    glutCreateWindow ("Task 3");
    switch(choice)
    {
    case 1:
        cout << "Enter Initial points:"<<endl;
        cin >> X1 >> Y1;

        cout <<"Enter End points:"<<endl;
        cin >> X2 >> Y2;
        glutDisplayFunc(DDA);
        break;

    case 2:
        cout << "Enter Initial points:"<<endl;
        cin >> X1 >> Y1;

        cout <<"Enter End points:"<<endl;
        cin >> X2 >> Y2;
        glutDisplayFunc(Bressenham);
        break;

    case 3:
        return 0;
        break;
    }

    myInit ();
    glutMainLoop();
    return 0;
}

void DDA(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    int length = abs(X2 - X1);

    if(abs(Y2-Y1) > length)
    {
        length = abs(Y2 - Y1);
    }

    double xincrement = (X2 - X1) / length;
    double yincrement = (Y2 - Y1) / length;

    double x = X1 + 0.5;
    double y = Y1 + 0.5;

    for(int i = 1 ; i <= length ; i++)
    {
        plot(x,y);
        x += xincrement;
        y += yincrement;
    }


    glFlush ();

}

void Bressenham()
{
    glClear (GL_COLOR_BUFFER_BIT);
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int D = 2*dy - dx;
    int y = Y1;
    int x = X1;

    for (x=X1; x <= X2; x++)
    {
        plot(x,y);
        if(D > 0)
        {
            y = y + 1;
            D = D - 2*dx;
        }
        else
        {
            D = D + 2*dy;
        }
    }
    glFlush ();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void plot(double a,double b)
{
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2d(round(a),round(b));
    glEnd();
}
