#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h>

float _move_sun = 1.00f;
float _move= 0.0f;
float _move1= 0.0f;
float _move2=0.0f;
float _move_car=0.02f;
float _move_car2=0.00f;
float _move_cloud_1 = 0.00f;
float _move_cloud_2 = 0.00f;
float _move_boat=0.00f;
float _move_ship = 0.00f;


void update_sun(int value){
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < 0.0)
    {
        _move_sun = 1.3;
    }
glutPostRedisplay(); //Notify GLUT that the display has changed

glutTimerFunc(30, update_sun, 0);
}

void sky(){
     glPushMatrix();

     //Sky
    if(_move_sun<=1.00f && _move_sun>=0.80f){
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, 0.5);
        glVertex2f(-1.0, 0.5);
        glEnd();
    }

    else if(_move_sun<0.80f && _move_sun>=0.60f){
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.961, 0.933);
        glVertex2f(1.0, 0.5);
        glVertex2f(-1.0, 0.5);
        glEnd();
    }

    else if(_move_sun<0.60f && _move_sun>=0.35f){
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.937, 0.588, 0.301);
        glVertex2f(1.0, 0.5);
        glVertex2f(-1.0, 0.5);
        glEnd();
    }

     glPopMatrix();
 }

  void river(){
     glPushMatrix();

     glBegin(GL_POLYGON);
     glColor3f(0.050f, 0.247f, 0.949f);
     glVertex2f(-1.0f, 0.10f);
     glVertex2f(1.0f, 0.10f);
     glVertex2f(1.0f, 0.40f);
     glVertex2f(-1.0f, 0.40f);
     glEnd();
     glPopMatrix();
 }

 void sun(){
    //Sun
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    if(_move_sun<=1.00 && _move_sun>=0.80f){
       glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }

    else if(_move_sun<0.80f && _move_sun>=0.60f){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.843, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }

    else if(_move_sun<0.60 && _move_sun>=0.35){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(0.901, 0.411, 0.058);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }


}

 void bridge(){
     glPushMatrix();

     glBegin(GL_POLYGON);
     glColor3f(0.329, 0.231, 0.011);
     glVertex2f(0.85f, 0.09f);
     glVertex2f(0.84f, 0.09f);
     glVertex2f(0.84f, 0.41f);
     glVertex2f(0.85f, 0.41f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.329, 0.231, 0.011);
     glVertex2f(0.95f, 0.09f);
     glVertex2f(0.96f, 0.09f);
     glVertex2f(0.96f, 0.41f);
     glVertex2f(0.95f, 0.41f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.450, 0.439, 0.407);
     glVertex2f(0.85f, 0.09f);
     glVertex2f(0.95f, 0.09f);
     glVertex2f(0.95f, 0.41f);
     glVertex2f(0.85f, 0.41f);
     glEnd();

     glPopMatrix();
 }

 void ground(){
    glPushMatrix();

     glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.5f, 0.0);
     glVertex2f(-1.0f, 0.10f);
     glVertex2f(1.0f, 0.10f);
     glVertex2f(1.0f, -1.0f);
     glVertex2f(-1.0f, -1.0f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.5f, 0.0);
     glVertex2f(-1.0f, 0.40f);
     glVertex2f(1.0f, 0.40f);
     glVertex2f(1.0f, 0.5f);
     glVertex2f(-1.0f, 0.5f);
     glEnd();

     glPopMatrix();
}

void hills(){
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.843, 0.337);
    glVertex2f(-1.0f, 0.52f);
    glVertex2f(-0.85f, 0.60f);
    glVertex2f(-0.5f, 0.46f);
    glVertex2f(-1.0f, 0.46f);
    glVertex2f(-1.0f, 0.52f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.843, 0.337);
    glVertex2f(-0.55f, 0.46f);
    glVertex2f(-0.35f, 0.55f);
    glVertex2f(-0.18f, 0.46f);//
    glVertex2f(-0.55f, 0.46f);
    glVertex2f(-0.55f, 0.47f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, 0.46f);
    glVertex2f(-0.02f, 0.55f);
    glVertex2f(0.15f, 0.46f);//
    glVertex2f(-0.2f, 0.46f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.843, 0.337);
    glVertex2f(0.14f, 0.46f);
    glVertex2f(0.34f, 0.55f);
    glVertex2f(0.54f, 0.46f);//
    glVertex2f(0.14f, 0.46f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.843, 0.337);
    glVertex2f(0.52f, 0.46f);
    glVertex2f(0.64f, 0.59f);
    glVertex2f(0.78f, 0.46f);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.843, 0.337);
    glVertex2f(0.78f, 0.46f);
    glVertex2f(0.91f, 0.63f);
    glVertex2f(1.00f, 0.56f);
    glVertex2f(1.00f, 0.46f);
    glEnd();

    glPopMatrix();
}

void house(){
    glPushMatrix();

    //House
    glBegin(GL_TRIANGLES);
    glColor3f(0.466f, 0.035f, 0.623f);
    glVertex2f(0.1f, 0.15f);
    glVertex2f(0.5f, 0.15f);
    glVertex2f(0.3f, 0.28f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.949f, 0.850f, 0.094f);
    glVertex2f(0.12f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.48f, -0.1f);
    glVertex2f(0.12f, -0.1f);
    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3f(0.949f, 0.447f, 0.094f);
    glVertex2f(0.26f, -0.1f);
    glVertex2f(0.34f, -0.1f);
    glVertex2f(0.34f, 0.1f);
    glVertex2f(0.26f, 0.1f);
    glEnd();
    //Windrow
    glBegin(GL_POLYGON);
    glColor3f(0.949f, 0.447f, 0.094f);
    glVertex2f(0.40f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.45f, 0.0f);
    glVertex2f(0.40f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.949f, 0.447f, 0.094f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.20f, 0.1f);
    glVertex2f(0.20f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.137, 0.121, 0.105);
    glVertex2f(0.49f, -0.1f);
    glVertex2f(0.11f, -0.1f);
    glVertex2f(0.11f, -0.15f);
    glVertex2f(0.49f, -0.15f);
    glEnd();
    glPopMatrix();
}

void tree(){
    glPushMatrix();
    //House side tree
    glBegin(GL_POLYGON);
    glColor3f(0.768f, 0.478f, 0.031f);
    glVertex2f(0.61f, 0.15f);
    glVertex2f(0.66f, 0.15f);
    glVertex2f(0.67f, -0.05f);
    glVertex2f(0.60f, -0.05f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.521f, 0.772f, 0.027f);
    glVertex2f(0.55f, 0.35f);
    glVertex2f(0.72f, 0.35f);
    glVertex2f(0.635f, 0.51f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.521f, 0.772f, 0.027f);
    glVertex2f(0.57f, 0.35f);
    glVertex2f(0.70f, 0.35f);
    glVertex2f(0.77f, 0.25f);
    glVertex2f(0.50f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.521f, 0.772f, 0.027f);
    glVertex2f(0.52f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.82f, 0.15f);
    glVertex2f(0.45f, 0.15f);
    glEnd();


//***********Road side Trees*************

    //Road Tree1
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.84, -0.65);
    glVertex2f(-0.81, -0.65);
    glVertex2f(-0.82, -0.45);
    glVertex2f(-0.83, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(-0.88, -0.50);
    glVertex2f(-0.77, -0.50);
    glVertex2f(-0.825, -0.30);
    glVertex2f(-0.88, -0.50);
    glEnd();

    //Road Tree 2
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.59, -0.65);
    glVertex2f(-0.56, -0.65);
    glVertex2f(-0.57, -0.45);
    glVertex2f(-0.58, -0.45);
    glEnd();

    glPushMatrix();
        glTranslatef(-0.595,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.555,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.575,-0.385,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    //Road Tree 4
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.34, -0.65);
    glVertex2f(-0.31, -0.65);
    glVertex2f(-0.32, -0.45);
    glVertex2f(-0.33, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(-0.38, -0.50);
    glVertex2f(-0.27, -0.50);
    glVertex2f(-0.325, -0.30);
    glVertex2f(-0.38, -0.50);
    glEnd();

    //Flower Three 1
    glPushMatrix();
        glTranslatef(-0.20, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.22, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.24, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.18, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.210, -0.570,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0435;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    //Flower 1
    glPushMatrix();
    glTranslatef(-0.24,-0.59,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(-0.21,-0.58,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(-0.18,-0.60,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

     //Road Tree 5
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.014, -0.65);
    glVertex2f(0.014, -0.65);
    glVertex2f(0.009, -0.45);
    glVertex2f(-0.009, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(-0.06, -0.50);
    glVertex2f(0.06, -0.50);
    glVertex2f(0.0, -0.30);
    glVertex2f(-0.06, -0.50);
    glEnd();

    //Flower Three 2
    glPushMatrix();
        glTranslatef(0.20, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.22, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.24, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.18, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.210, -0.570,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0435;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    //Flower 2
    glPushMatrix();
    glTranslatef(0.24,-0.59,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(0.21,-0.58,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(0.18,-0.60,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();


     //Park Tree 4
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(0.34, -0.65);
    glVertex2f(0.31, -0.65);
    glVertex2f(0.32, -0.45);
    glVertex2f(0.33, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(0.38, -0.50);
    glVertex2f(0.27, -0.50);
    glVertex2f(0.325, -0.30);
    glVertex2f(0.38, -0.50);
    glEnd();

    //Park Tree 5
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(0.59, -0.65);
    glVertex2f(0.56, -0.65);
    glVertex2f(0.57, -0.45);
    glVertex2f(0.58, -0.45);
    glEnd();

    glPushMatrix();
        glTranslatef(0.595,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.555,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.575,-0.385,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    //Park Tree 5
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(0.84, -0.65);
    glVertex2f(0.81, -0.65);
    glVertex2f(0.82, -0.45);
    glVertex2f(0.83, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(0.88, -0.50);
    glVertex2f(0.77, -0.50);
    glVertex2f(0.825, -0.30);
    glVertex2f(0.88, -0.50);
    glEnd();

    glPopMatrix();
}

void Tree2(){
    ///////############## Road side trees ####################

    glPushMatrix();
        glTranslatef(0.0, -0.19,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.02, -0.19,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.04, -0.14,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.02, -0.14,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.010, -0.145,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0435;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    //Flower
    glPushMatrix();
    glTranslatef(0.01,-0.15,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(0.05,-0.14,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
    glTranslatef(-0.02,-0.14,0);
        glScalef(0.6,1,1);
        glColor3f(0.964, 0.074, 0.247);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(-0.375f, -0.22f);
    glVertex2f(-0.360f, -0.20f);
    glVertex2f(-0.350f, -0.19f);
    glVertex2f(-0.370f, -0.20f);
    glVertex2f(-0.360f, -0.17f);
    glVertex2f(-0.380f, -0.19f);
    glVertex2f(-0.385f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(-0.390f, -0.19f);
    glVertex2f(-0.410f, -0.17f);
    glVertex2f(-0.40f, -0.2f);
    glVertex2f(-0.42f, -0.19f);
    glVertex2f(-0.41f, -0.20f);
    glVertex2f(-0.395f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(-0.275f, -0.22f);
    glVertex2f(-0.260f, -0.20f);
    glVertex2f(-0.250f, -0.19f);
    glVertex2f(-0.270f, -0.20f);
    glVertex2f(-0.260f, -0.17f);
    glVertex2f(-0.280f, -0.19f);
    glVertex2f(-0.285f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(-0.290f, -0.19f);
    glVertex2f(-0.310f, -0.17f);
    glVertex2f(-0.30f, -0.2f);
    glVertex2f(-0.32f, -0.19f);
    glVertex2f(-0.31f, -0.20f);
    glVertex2f(-0.295f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(-0.175f, -0.22f);
    glVertex2f(-0.160f, -0.20f);
    glVertex2f(-0.150f, -0.19f);
    glVertex2f(-0.170f, -0.20f);
    glVertex2f(-0.160f, -0.17f);
    glVertex2f(-0.180f, -0.19f);
    glVertex2f(-0.185f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(-0.190f, -0.19f);
    glVertex2f(-0.210f, -0.17f);
    glVertex2f(-0.20f, -0.2f);
    glVertex2f(-0.22f, -0.19f);
    glVertex2f(-0.21f, -0.20f);
    glVertex2f(-0.195f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(-0.075f, -0.22f);
    glVertex2f(-0.060f, -0.20f);
    glVertex2f(-0.050f, -0.19f);
    glVertex2f(-0.070f, -0.20f);
    glVertex2f(-0.060f, -0.17f);
    glVertex2f(-0.080f, -0.19f);
    glVertex2f(-0.085f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(-0.090f, -0.19f);
    glVertex2f(-0.110f, -0.17f);
    glVertex2f(-0.10f, -0.2f);
    glVertex2f(-0.12f, -0.19f);
    glVertex2f(-0.11f, -0.20f);
    glVertex2f(-0.095f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.075f, -0.22f);
    glVertex2f(0.060f, -0.20f);
    glVertex2f(0.050f, -0.19f);
    glVertex2f(0.070f, -0.20f);
    glVertex2f(0.060f, -0.17f);
    glVertex2f(0.080f, -0.19f);
    glVertex2f(0.085f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.090f, -0.19f);
    glVertex2f(0.110f, -0.17f);
    glVertex2f(0.10f, -0.2f);
    glVertex2f(0.12f, -0.19f);
    glVertex2f(0.11f, -0.20f);
    glVertex2f(0.095f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.175f, -0.22f);
    glVertex2f(0.160f, -0.20f);
    glVertex2f(0.150f, -0.19f);
    glVertex2f(0.170f, -0.20f);
    glVertex2f(0.160f, -0.17f);
    glVertex2f(0.180f, -0.19f);
    glVertex2f(0.185f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.190f, -0.19f);
    glVertex2f(0.210f, -0.17f);
    glVertex2f(0.20f, -0.2f);
    glVertex2f(0.22f, -0.19f);
    glVertex2f(0.21f, -0.20f);
    glVertex2f(0.195f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.275f, -0.22f);
    glVertex2f(0.260f, -0.20f);
    glVertex2f(0.250f, -0.19f);
    glVertex2f(0.270f, -0.20f);
    glVertex2f(0.260f, -0.17f);
    glVertex2f(0.280f, -0.19f);
    glVertex2f(0.285f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.290f, -0.19f);
    glVertex2f(0.310f, -0.17f);
    glVertex2f(0.30f, -0.2f);
    glVertex2f(0.32f, -0.19f);
    glVertex2f(0.31f, -0.20f);
    glVertex2f(0.295f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.375f, -0.22f);
    glVertex2f(0.360f, -0.20f);
    glVertex2f(0.350f, -0.19f);
    glVertex2f(0.370f, -0.20f);
    glVertex2f(0.360f, -0.17f);
    glVertex2f(0.380f, -0.19f);
    glVertex2f(0.385f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.390f, -0.19f);
    glVertex2f(0.410f, -0.17f);
    glVertex2f(0.40f, -0.2f);
    glVertex2f(0.42f, -0.19f);
    glVertex2f(0.41f, -0.20f);
    glVertex2f(0.395f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.475f, -0.22f);
    glVertex2f(0.460f, -0.20f);
    glVertex2f(0.450f, -0.19f);
    glVertex2f(0.470f, -0.20f);
    glVertex2f(0.460f, -0.17f);
    glVertex2f(0.480f, -0.19f);
    glVertex2f(0.485f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.490f, -0.19f);
    glVertex2f(0.510f, -0.17f);
    glVertex2f(0.50f, -0.2f);
    glVertex2f(0.52f, -0.19f);
    glVertex2f(0.51f, -0.20f);
    glVertex2f(0.495f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.575f, -0.22f);
    glVertex2f(0.560f, -0.20f);
    glVertex2f(0.550f, -0.19f);
    glVertex2f(0.570f, -0.20f);
    glVertex2f(0.560f, -0.17f);
    glVertex2f(0.580f, -0.19f);
    glVertex2f(0.585f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.590f, -0.19f);
    glVertex2f(0.610f, -0.17f);
    glVertex2f(0.60f, -0.2f);
    glVertex2f(0.62f, -0.19f);
    glVertex2f(0.61f, -0.20f);
    glVertex2f(0.595f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.675f, -0.22f);
    glVertex2f(0.660f, -0.20f);
    glVertex2f(0.650f, -0.19f);
    glVertex2f(0.670f, -0.20f);
    glVertex2f(0.660f, -0.17f);
    glVertex2f(0.680f, -0.19f);
    glVertex2f(0.685f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.690f, -0.19f);
    glVertex2f(0.710f, -0.17f);
    glVertex2f(0.70f, -0.2f);
    glVertex2f(0.72f, -0.19f);
    glVertex2f(0.71f, -0.20f);
    glVertex2f(0.695f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.775f, -0.22f);
    glVertex2f(0.760f, -0.20f);
    glVertex2f(0.750f, -0.19f);
    glVertex2f(0.770f, -0.20f);
    glVertex2f(0.760f, -0.17f);
    glVertex2f(0.780f, -0.19f);
    glVertex2f(0.785f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.790f, -0.19f);
    glVertex2f(0.810f, -0.17f);
    glVertex2f(0.80f, -0.2f);
    glVertex2f(0.82f, -0.19f);
    glVertex2f(0.81f, -0.20f);
    glVertex2f(0.795f, -0.22f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.6,0.1);
    glVertex2f(0.875f, -0.22f);
    glVertex2f(0.860f, -0.20f);
    glVertex2f(0.850f, -0.19f);
    glVertex2f(0.870f, -0.20f);
    glVertex2f(0.860f, -0.17f);
    glVertex2f(0.880f, -0.19f);
    glVertex2f(0.885f, -0.15f);
    glColor3f(.6,1.0,0.184);
    glVertex2f(0.890f, -0.19f);
    glVertex2f(0.910f, -0.17f);
    glVertex2f(0.90f, -0.2f);
    glVertex2f(0.92f, -0.19f);
    glVertex2f(0.91f, -0.20f);
    glVertex2f(0.895f, -0.22f);
    glEnd();
    glPopMatrix();


}

void update_cloud_1(int value) {
    _move_cloud_1 += 0.0015f;
    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = 1.9;
    }
 glutPostRedisplay(); //Notify GLUT that the display has changed
 glutTimerFunc(20, update_cloud_1, 0);
}
void cloud_left(){

    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.78,0.82,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.74,0.87,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.70,0.91,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.65,0.88,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.61,0.80,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.68,0.77,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
        glTranslatef(-0.75,0.78,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
        glutSwapBuffers();
}
void update_cloud_2(int value){
    _move_cloud_2 -= 0.0015f;
    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = -1.9;
    }
 glutPostRedisplay(); //Notify GLUT that the display has changed
 glutTimerFunc(20, update_cloud_2, 0);
}
void cloud_right(){
    //Cloud on the right
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.78,0.70,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.74,0.75,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.70,0.79,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.65,0.76,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.61,0.76,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.68,0.65,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.63,0.66,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
        glTranslatef(0.75,0.66,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
        glutSwapBuffers();
        glutSwapBuffers();
}


void Car(){
    glColor3d(0.000, 0.545, 0.545);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
    //
    glBegin(GL_POLYGON);
 glBegin(GL_POLYGON);
 glColor3f(1.0f, 1.0f, 0.0f); // Yellow
  glVertex2f(-0.80, -0.35);
  glVertex2f(-0.75, -0.30);
  glVertex2f(-0.70, -0.20);
  glVertex2f(-0.60, -0.20);
  glVertex2f(-0.50, -0.35);
  glVertex2f(-0.80, -0.30);
  glVertex2f(-0.50, -0.30);
  glVertex2f(-0.50, -0.35);

   glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
 glColor3f(.0f, .250f, 0.0f); // Yellow
        glVertex2f(-0.75, -0.30);
        glVertex2f(-0.70, -0.22);
        glVertex2f(-0.66, -0.22);
        glVertex2f(-0.66, -0.30);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
 glColor3f(.0f, .250f, 0.0f); // Yellow
        glVertex2f(-0.64, -0.30);
        glVertex2f(-0.64, -0.22);
        glVertex2f(-0.60, -0.22);
        glVertex2f(-0.55, -0.30);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(_move_car, 0.0f, 0.0f);
        glTranslatef(-0.75,-0.35,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
        glTranslatef(-0.75,-0.35,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
        glTranslatef(-0.55,-0.35,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car, 0.0f, 0.0f);
        glTranslatef(-0.55,-0.35,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void Car2(){
    glColor3d(0.000, 0.545, 0.545);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
    //
    glBegin(GL_POLYGON);
 glBegin(GL_POLYGON);
 glColor3f(0.854, 0.149, 0.062);
  glVertex2f(0.80, -0.45);
  glVertex2f(0.75, -0.40);
  glVertex2f(0.70, -0.30);
  glVertex2f(0.60, -0.30);
  glVertex2f(0.50, -0.45);
  glVertex2f(0.80, -0.40);
  glVertex2f(0.50, -0.40);
  glVertex2f(0.50, -0.45);

   glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.062, 0.086, 0.854);
        glVertex2f(0.75, -0.40);
        glVertex2f(0.70, -0.32);
        glVertex2f(0.66, -0.32);
        glVertex2f(0.66, -0.40);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
 glColor3f(0.062, 0.086, 0.854); // Yellow
        glVertex2f(0.64, -0.40);
        glVertex2f(0.64, -0.32);
        glVertex2f(0.60, -0.32);
        glVertex2f(0.55, -0.40);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(_move_car2, 0.0f, 0.0f);
        glTranslatef(0.75,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
        glTranslatef(0.75,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
        glTranslatef(0.55,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_car2, 0.0f, 0.0f);
        glTranslatef(0.55,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
glEnd();

    glPopMatrix();

    glutSwapBuffers();
    glutSwapBuffers();
}

void road(){
    glPushMatrix();
    //Main road
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.25);
    glVertex2f(-1.0, -0.55);
    glVertex2f(1.0, -0.55);
    glVertex2f(1.0, -0.25);

    //Main Road Strips 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.39);
    glVertex2f(-0.95, -0.41);
    glVertex2f(-0.65, -0.41);
    glVertex2f(-0.65, -0.39);

    //Main Road Strips 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.55, -0.39);
    glVertex2f(-0.55, -0.41);
    glVertex2f(-0.25, -0.41);
    glVertex2f(-0.25, -0.39);

    //Main Road Strips 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.15, -0.39);
    glVertex2f(-0.15, -0.41);
    glVertex2f(0.15, -0.41);
    glVertex2f(0.15, -0.39);

    //Main Road Strips 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.25, -0.39);
    glVertex2f(0.25, -0.41);
    glVertex2f(0.55, -0.41);
    glVertex2f(0.55, -0.39);

    //Main Road Strips 5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.65, -0.39);
    glVertex2f(0.65, -0.41);
    glVertex2f(.95, -0.41);
    glVertex2f(.95, -0.39);
    glEnd();

    //Road side Strip
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.25);
    glVertex2f(1.0, -0.25);
    glVertex2f(1.0, -0.22);
    glVertex2f(-1.0, -0.22);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.55);
    glVertex2f(1.0, -0.55);
    glVertex2f(1.0, -0.58);
    glVertex2f(-1.0, -0.58);
    glEnd();
    glPopMatrix();

}

void playground(){
     glPushMatrix();
    //boundary
     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-1.0f, 0.13f);
     glVertex2f(-0.47f, 0.13f);
     glVertex2f(-0.47f, 0.14f);
     glVertex2f(-1.0f, 0.14f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-1.0f, 0.149f);
     glVertex2f(-1.0f, 0.09f);
     glVertex2f(-0.99f, 0.09f);
     glVertex2f(-0.99f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.98f, 0.149f);
     glVertex2f(-0.98f, 0.09f);
     glVertex2f(-0.97f, 0.09f);
     glVertex2f(-0.97f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.96f, 0.149f);
     glVertex2f(-0.96f, 0.09f);
     glVertex2f(-0.95f, 0.09f);
     glVertex2f(-0.95f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.94f, 0.149f);
     glVertex2f(-0.94f, 0.09f);
     glVertex2f(-0.93f, 0.09f);
     glVertex2f(-0.93f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.92f, 0.149f);
     glVertex2f(-0.92f, 0.09f);
     glVertex2f(-0.91f, 0.09f);
     glVertex2f(-0.91f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.90f, 0.149f);
     glVertex2f(-0.90f, 0.09f);
     glVertex2f(-0.89f, 0.09f);
     glVertex2f(-0.89f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.88f, 0.149f);
     glVertex2f(-0.88f, 0.09f);
     glVertex2f(-0.87f, 0.09f);
     glVertex2f(-0.87f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.86f, 0.149f);
     glVertex2f(-0.86f, 0.09f);
     glVertex2f(-0.85f, 0.09f);
     glVertex2f(-0.85f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.84f, 0.149f);
     glVertex2f(-0.84f, 0.09f);
     glVertex2f(-0.83f, 0.09f);
     glVertex2f(-0.83f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.82f, 0.149f);
     glVertex2f(-0.82f, 0.09f);
     glVertex2f(-0.81f, 0.09f);
     glVertex2f(-0.81f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.80f, 0.149f);
     glVertex2f(-0.80f, 0.09f);
     glVertex2f(-0.79f, 0.09f);
     glVertex2f(-0.79f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.78f, 0.149f);
     glVertex2f(-0.78f, 0.09f);
     glVertex2f(-0.77f, 0.09f);
     glVertex2f(-0.77f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.76f, 0.149f);
     glVertex2f(-0.76f, 0.09f);
     glVertex2f(-0.75f, 0.09f);
     glVertex2f(-0.75f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.74f, 0.149f);
     glVertex2f(-0.74f, 0.09f);
     glVertex2f(-0.73f, 0.09f);
     glVertex2f(-0.73f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.72f, 0.149f);
     glVertex2f(-0.72f, 0.09f);
     glVertex2f(-0.71f, 0.09f);
     glVertex2f(-0.71f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.70f, 0.149f);
     glVertex2f(-0.70f, 0.09f);
     glVertex2f(-0.69f, 0.09f);
     glVertex2f(-0.69f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.68f, 0.149f);
     glVertex2f(-0.68f, 0.09f);
     glVertex2f(-0.67f, 0.09f);
     glVertex2f(-0.67f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.66f, 0.149f);
     glVertex2f(-0.66f, 0.09f);
     glVertex2f(-0.65f, 0.09f);
     glVertex2f(-0.65f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.64f, 0.149f);
     glVertex2f(-0.64f, 0.09f);
     glVertex2f(-0.63f, 0.09f);
     glVertex2f(-0.63f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.62f, 0.149f);
     glVertex2f(-0.62f, 0.09f);
     glVertex2f(-0.61f, 0.09f);
     glVertex2f(-0.61f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.60f, 0.149f);
     glVertex2f(-0.60f, 0.09f);
     glVertex2f(-0.59f, 0.09f);
     glVertex2f(-0.59f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.58f, 0.149f);
     glVertex2f(-0.58f, 0.09f);
     glVertex2f(-0.57f, 0.09f);
     glVertex2f(-0.57f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.56f, 0.149f);
     glVertex2f(-0.56f, 0.09f);
     glVertex2f(-0.55f, 0.09f);
     glVertex2f(-0.55f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.54f, 0.149f);
     glVertex2f(-0.54f, 0.09f);
     glVertex2f(-0.53f, 0.09f);
     glVertex2f(-0.53f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.52f, 0.149f);
     glVertex2f(-0.52f, 0.09f);
     glVertex2f(-0.51f, 0.09f);
     glVertex2f(-0.51f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.50f, 0.149f);
     glVertex2f(-0.50f, 0.09f);
     glVertex2f(-0.49f, 0.09f);
     glVertex2f(-0.49f, 0.149f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.48f, 0.149f);
     glVertex2f(-0.48f, 0.09f);
     glVertex2f(-0.47f, 0.09f);
     glVertex2f(-0.47f, 0.149f);
     glEnd();

     //road side boundary
     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-1.0f, -0.175f);
     glVertex2f(-0.47f, -0.175f);
     glVertex2f(-0.47f, -0.185f);
     glVertex2f(-1.0f, -0.185f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-1.0f, -0.16f);
     glVertex2f(-0.99f, -0.16f);
     glVertex2f(-0.99f, -0.21f);
     glVertex2f(-1.00f, -0.21f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.98f, -0.16f);
     glVertex2f(-0.98f, -0.21f);
     glVertex2f(-0.97f, -0.21f);
     glVertex2f(-0.97f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.96f, -0.16f);
     glVertex2f(-0.96f, -0.21f);
     glVertex2f(-0.95f, -0.21f);
     glVertex2f(-0.95f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.94f, -0.16f);
     glVertex2f(-0.94f, -0.21f);
     glVertex2f(-0.93f, -0.21f);
     glVertex2f(-0.93f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.92f, -0.16f);
     glVertex2f(-0.92f, -0.21f);
     glVertex2f(-0.91f, -0.21f);
     glVertex2f(-0.91f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.90f, -0.16f);
     glVertex2f(-0.90f, -0.21f);
     glVertex2f(-0.89f, -0.21f);
     glVertex2f(-0.89f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.88f, -0.16f);
     glVertex2f(-0.88f, -0.21f);
     glVertex2f(-0.87f, -0.21f);
     glVertex2f(-0.87f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.86f, -0.16f);
     glVertex2f(-0.86f, -0.21f);
     glVertex2f(-0.85f, -0.21f);
     glVertex2f(-0.85f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.84f, -0.16f);
     glVertex2f(-0.84f, -0.21f);
     glVertex2f(-0.83f, -0.21f);
     glVertex2f(-0.83f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.82f, -0.16f);
     glVertex2f(-0.82f, -0.21f);
     glVertex2f(-0.81f, -0.21f);
     glVertex2f(-0.81f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.80f, -0.16f);
     glVertex2f(-0.80f, -0.21f);
     glVertex2f(-0.79f, -0.21f);
     glVertex2f(-0.79f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.78f, -0.16f);
     glVertex2f(-0.78f, -0.21f);
     glVertex2f(-0.77f, -0.21f);
     glVertex2f(-0.77f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.76f, -0.16f);
     glVertex2f(-0.76f, -0.21f);
     glVertex2f(-0.75f, -0.21f);
     glVertex2f(-0.75f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.74f, -0.16f);
     glVertex2f(-0.74f, -0.21f);
     glVertex2f(-0.73f, -0.21f);
     glVertex2f(-0.73f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.72f, -0.16f);
     glVertex2f(-0.72f, -0.21f);
     glVertex2f(-0.71f, -0.21f);
     glVertex2f(-0.71f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.70f, -0.16f);
     glVertex2f(-0.70f, -0.21f);
     glVertex2f(-0.69f, -0.21f);
     glVertex2f(-0.69f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.68f, -0.16f);
     glVertex2f(-0.68f, -0.21f);
     glVertex2f(-0.67f, -0.21f);
     glVertex2f(-0.67f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.66f, -0.16f);
     glVertex2f(-0.66f, -0.21f);
     glVertex2f(-0.65f, -0.21f);
     glVertex2f(-0.65f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.64f, -0.16f);
     glVertex2f(-0.64f, -0.21f);
     glVertex2f(-0.63f, -0.21f);
     glVertex2f(-0.63f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.62f, -0.16f);
     glVertex2f(-0.62f, -0.21f);
     glVertex2f(-0.61f, -0.21f);
     glVertex2f(-0.61f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.60f, -0.16f);
     glVertex2f(-0.60f, -0.21f);
     glVertex2f(-0.59f, -0.21f);
     glVertex2f(-0.59f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.58f, -0.16f);
     glVertex2f(-0.58f, -0.21f);
     glVertex2f(-0.57f, -0.21f);
     glVertex2f(-0.57f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.56f, -0.16f);
     glVertex2f(-0.56f, -0.21f);
     glVertex2f(-0.55f, -0.21f);
     glVertex2f(-0.55f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.54f, -0.16f);
     glVertex2f(-0.54f, -0.21f);
     glVertex2f(-0.53f, -0.21f);
     glVertex2f(-0.53f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.52f, -0.16f);
     glVertex2f(-0.52f, -0.21f);
     glVertex2f(-0.51f, -0.21f);
     glVertex2f(-0.51f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.50f, -0.16f);
     glVertex2f(-0.50f, -0.21f);
     glVertex2f(-0.49f, -0.21f);
     glVertex2f(-0.49f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.48f, -0.16f);
     glVertex2f(-0.48f, -0.21f);
     glVertex2f(-0.47f, -0.21f);
     glVertex2f(-0.47f, -0.16f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.654, 0.682, 0.682);
     glVertex2f(-0.48f, 0.12f);
     glVertex2f(-0.48f, -0.08f);
     glVertex2f(-0.47f, -0.08f);
     glVertex2f(-0.47f, 0.12f);
     glEnd();

     //Branch 1
     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.99f, 0.13f);
     glVertex2f(-0.90f, 0.13f);
     glVertex2f(-0.90f, 0.11f);
     glVertex2f(-0.99f, 0.11f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.98f, 0.11f);
     glVertex2f(-0.97f, 0.11f);
     glVertex2f(-0.97f, 0.06f);
     glVertex2f(-0.98f, 0.06f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.91f, 0.11f);
     glVertex2f(-0.92f, 0.11f);
     glVertex2f(-0.92f, 0.06f);
     glVertex2f(-0.91f, 0.06f);
     glEnd();

    //Branch 2
     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.50f, 0.13f);
     glVertex2f(-0.59f, 0.13f);
     glVertex2f(-0.59f, 0.11f);
     glVertex2f(-0.50f, 0.11f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.51f, 0.11f);
     glVertex2f(-0.52f, 0.11f);
     glVertex2f(-0.52f, 0.06f);
     glVertex2f(-0.51f, 0.06f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.941, 0.921, 0.921);
     glVertex2f(-0.58f, 0.11f);
     glVertex2f(-0.57f, 0.11f);
     glVertex2f(-0.57f, 0.06f);
     glVertex2f(-0.58f, 0.06f);
     glEnd();

     glPopMatrix();
}

void Railline(){
    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.95f, -0.7f);
    glVertex2f(-0.95f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.90f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.9f);
    glVertex2f(-0.90f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-0.75f, -0.7f);
    glVertex2f(-0.75f, -0.9f);
    glVertex2f(-0.80f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.70f, -0.7f);
    glVertex2f(-0.65f, -0.7f);
    glVertex2f(-0.65f, -0.9f);
    glVertex2f(-0.70f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.60f, -0.7f);
    glVertex2f(-0.55f, -0.7f);
    glVertex2f(-0.55f, -0.9f);
    glVertex2f(-0.60f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.50f, -0.7f);
    glVertex2f(-0.45f, -0.7f);
    glVertex2f(-0.45f, -0.9f);
    glVertex2f(-0.50f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.35f, -0.9f);
    glVertex2f(-0.40f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.30f, -0.7f);
    glVertex2f(-0.25f, -0.7f);
    glVertex2f(-0.25f, -0.9f);
    glVertex2f(-0.30f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.20f, -0.7f);
    glVertex2f(-0.15f, -0.7f);
    glVertex2f(-0.15f, -0.9f);
    glVertex2f(-0.20f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.10f, -0.7f);
    glVertex2f(-0.05f, -0.7f);
    glVertex2f(-0.05f, -0.9f);
    glVertex2f(-0.10f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(0.05f, -0.7f);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(0.0f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.10f, -0.7f);
    glVertex2f(0.15f, -0.7f);
    glVertex2f(0.15f, -0.9f);
    glVertex2f(0.10f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.20f, -0.7f);
    glVertex2f(0.25f, -0.7f);
    glVertex2f(0.25f, -0.9f);
    glVertex2f(0.20f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.30f, -0.7f);
    glVertex2f(0.35f, -0.7f);
    glVertex2f(0.35f, -0.9f);
    glVertex2f(0.30f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.45f, -0.7f);
    glVertex2f(0.45f, -0.9f);
    glVertex2f(0.40f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.50f, -0.7f);
    glVertex2f(0.55f, -0.7f);
    glVertex2f(0.55f, -0.9f);
    glVertex2f(0.50f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.60f, -0.7f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.9f);
    glVertex2f(0.60f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.70f, -0.7f);
    glVertex2f(0.75f, -0.7f);
    glVertex2f(0.75f, -0.9f);
    glVertex2f(0.70f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.85f, -0.7f);
    glVertex2f(0.85f, -0.9f);
    glVertex2f(0.80f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.90f, -0.7f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.95f, -0.9f);
    glVertex2f(0.90f, -0.9f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.05f, -0.7f);
    glVertex2f(1.05f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
//line//
    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.71f);
    glVertex2f(1.0f, -0.71f);
    glVertex2f(1.0f, -0.72f);
    glVertex2f(-1.0f, -0.72f);
    glEnd();

    glColor3f(0.502f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.88f);
    glVertex2f(1.0f, -0.88f);
    glVertex2f(1.0f, -0.89f);
    glVertex2f(-1.0f, -0.89f);
    glEnd();

 }

 void wheel1(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.92, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }

 void wheel2(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.83, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }

 void wheel3(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.725, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }
 void wheel4(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.63, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }

 void wheel5(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.50, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }
 void wheel6(){
     glPushMatrix();
     glRotatef(_move1, 0.0, 0.0, 1.0);
     glTranslatef(-0.39, -0.845, 0.0);
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_POLYGON);
     for(int i=0; i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.035;
        float x=r * cos(A);
        float y=r * sin(A);
        glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
 }

 void train(){
     glLoadIdentity();
     glMatrixMode(GL_MODELVIEW);
     glColor3d(1,0,0);
     glPushMatrix();
     glTranslatef(_move,0.0f,0.0f);

     glBegin(GL_POLYGON);     //Last Body
     glColor3f(0.623, 0.015, 0.490);
     glVertex2f(-0.95f,-0.82f);
     glVertex2f(-0.80f,-0.82f);
     glVertex2f(-0.80f,-0.55f);
     glVertex2f(-0.95f,-0.55f);
     glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.066, 0.050, 0.066);
    glVertex2f(-0.95f, -0.55f);
    glVertex2f(-0.80f, -0.55f);
    glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.858, 0.858, 0.721);
     glVertex2f(-0.92f,-0.70f);
     glVertex2f(-0.83f,-0.70f);
     glVertex2f(-0.83f,-0.60f);
     glVertex2f(-0.92f,-0.60f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.196, 0.184, 0.184);
     glVertex2f(-0.80f,-0.82f);
     glVertex2f(-0.80f,-0.77f);
     glVertex2f(-0.75f,-0.77f);
     glVertex2f(-0.75f,-0.82f);
     glEnd();

     glBegin(GL_POLYGON);     //Middle Body
     glColor3f(0.043, 0.015, 0.623);
     glVertex2f(-0.75f,-0.82f);
     glVertex2f(-0.60f,-0.82f);
     glVertex2f(-0.60f,-0.55f);
     glVertex2f(-0.75f,-0.55f);
     glEnd();

     glLineWidth(7);
     glBegin(GL_LINES);
     glColor3f(0.066, 0.050, 0.066);
     glVertex2f(-0.75f, -0.55f);
     glVertex2f(-0.60f, -0.55f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.858, 0.858, 0.721);
     glVertex2f(-0.72f,-0.70f);
     glVertex2f(-0.63f,-0.70f);
     glVertex2f(-0.63f,-0.60f);
     glVertex2f(-0.72f,-0.60f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.196, 0.184, 0.184);
     glVertex2f(-0.60f,-0.82f);
     glVertex2f(-0.60f,-0.77f);
     glVertex2f(-0.55f,-0.77f);
     glVertex2f(-0.55f,-0.82f);
     glEnd();

     glBegin(GL_POLYGON);     //1st Body 2
     glColor3f(0.968, 0.223, 0.168);
     glVertex2f(-0.55f,-0.82f);
     glVertex2f(-0.45f,-0.82f);
     glVertex2f(-0.45f,-0.55f);
     glVertex2f(-0.55f,-0.55f);
     glEnd();

     glLineWidth(7);
     glBegin(GL_LINES);
     glColor3f(0.066, 0.050, 0.066);
     glVertex2f(-0.55f, -0.55f);
     glVertex2f(-0.45f, -0.55f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.858, 0.858, 0.721);
     glVertex2f(-0.53f,-0.70f);
     glVertex2f(-0.47f,-0.70f);
     glVertex2f(-0.47f,-0.60f);
     glVertex2f(-0.53f,-0.60f);
     glEnd();

     glBegin(GL_POLYGON);     //1st Body 1
     glColor3f(0.960, 0.968, 0.168);
     glVertex2f(-0.45f,-0.82f);
     glVertex2f(-0.35f,-0.82f);
     glVertex2f(-0.35f,-0.68f);
     glVertex2f(-0.45f,-0.68f);
     glEnd();

     glLineWidth(7);
     glBegin(GL_LINES);
     glColor3f(0.066, 0.050, 0.066);
     glVertex2f(-0.45f, -0.68f);
     glVertex2f(-0.35f, -0.68f);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.784, 0.176, 0.803);
     glVertex2f(-0.365f,-0.68f);
     glVertex2f(-0.365f,-0.58f);
     glVertex2f(-0.41f,-0.58f);
     glVertex2f(-0.41f,-0.68f);
     glEnd();

     glLineWidth(7);
     glBegin(GL_LINES);
     glColor3f(0.066, 0.050, 0.066);
     glVertex2f(-0.365f, -0.58f);
     glVertex2f(-0.41f, -0.58f);
     glEnd();

     wheel1();
     wheel2();
     wheel3();
     wheel4();
     wheel5();
     wheel6();

     glPopMatrix();
     glutSwapBuffers();
     glutSwapBuffers();
     }


 void clock(){

    glBegin(GL_LINES);
//draw the hour line
//
glBegin(GL_QUADS);
    glColor3ub(152, 134, 134);
    glVertex2f(-0.80,0.35);
    glVertex2f(-0.80,0.15);
    glVertex2f(-0.70,0.15);
    glVertex2f(-0.70,0.35);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 102);
    glVertex2f(-0.80,0.35);
    glVertex2f(-0.80,0.15);
    glVertex2f(-0.70,0.15);
    glVertex2f(-0.70,0.35);
    glVertex2f(-0.80,0.15);
    glVertex2f(-0.70,0.15);
    glVertex2f(-0.80,0.35);
    glVertex2f(-0.70,0.35);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.1f, 0.0f);
    //12
    glVertex2f(-0.75f, 0.35f);
    glVertex2f(-0.75f, 0.31f);


    //6
    glVertex2f(-0.75f, 0.15f);
    glVertex2f(-0.75f, 0.19f);

    //3
    glVertex2f(-0.70f, 0.25f);
    glVertex2f(-0.72f, 0.25f);

    //9
    glVertex2f(-0.80f, 0.25f);
    glVertex2f(-0.785f, 0.25f);

    //1
    glVertex2f(-0.73f, 0.35f);
    glVertex2f(-0.73f, 0.31f);
    //11
    glVertex2f(-0.77f, 0.35f);
    glVertex2f(-0.77f, 0.31f);

    //2
    glVertex2f(-0.70f, 0.30f);
    glVertex2f(-0.72f, 0.30f);

    //4
    glVertex2f(-0.70f, 0.20f);
    glVertex2f(-0.72f, 0.20f);

    //8
    glVertex2f(-0.80f, 0.20f);
    glVertex2f(-0.785f,0.20f);

    //10
    glVertex2f(-0.80f, 0.30f);
    glVertex2f(-0.785f, 0.30f);

    //5
    glVertex2f(-0.73f,0.15f);
    glVertex2f(-0.73f, 0.19f);

    //7
    glVertex2f(-0.77f, 0.15f);
    glVertex2f(-0.77f, 0.19f);

    glEnd();

    glPushMatrix();
glLineWidth(1.5);//second
glBegin(GL_LINES);   //1
glColor3ub(0, 0, 102);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.745,0.34);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.5);//min
    glBegin(GL_LINES);  //2
    glColor3ub(0,0,0);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.72,0.25);
    glEnd();
    glPopMatrix();
    //hour
    glPushMatrix();
    glLineWidth(3.5);
    glBegin(GL_LINES);  //2
    glColor3ub(224, 11, 11);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.73,0.22);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.086, 0.074, 0.074);
    glVertex2f(-0.765,0.15);
    glVertex2f(-0.735,0.15);
    glVertex2f(-0.735,0.06);
    glVertex2f(-0.765,0.06);
    glEnd();
    glPopMatrix();
    glFlush();
}

void boat(){
     //glLoadIdentity();
     //glMatrixMode(GL_MODELVIEW);
     glPushMatrix();//start_pushpop
     glTranslatef(_move_boat, 0.0f, 0.0f);

        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_QUADS);
        glVertex2f(-0.80, 0.35);
        glVertex2f(-0.60, 0.35);
        glVertex2f(-0.65, 0.29);
        glVertex2f(-0.75, 0.29);
        glVertex2f(-0.80, 0.35);
        glEnd();

        glColor3f(0.662, 0.717, 0.203);
        glBegin(GL_QUADS);
        glVertex2f(-0.76, 0.35);
        glVertex2f(-0.77, 0.42);
        glVertex2f(-0.63, 0.42);
        glVertex2f(-0.64, 0.35);
        glVertex2f(-0.76, 0.35);

        glEnd();
        glPopMatrix();
        glutSwapBuffers();
}

void ship(){
    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_POLYGON);
        glVertex2f(0.75, 0.12);
        glVertex2f(0.45, 0.12);
        glVertex2f(0.40, 0.2);
        glVertex2f(0.80, 0.2);
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(0.854, 0.509, 0.062);
        glBegin(GL_POLYGON);
        glVertex2f(0.75, 0.20);
        glVertex2f(0.45, 0.20);
        glVertex2f(0.45, 0.25);
        glVertex2f(0.75, 0.25);
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(0.631, 0.368, 0.031);
        glBegin(GL_POLYGON);
        glVertex2f(0.65, 0.25);
        glVertex2f(0.50, 0.25);
        glVertex2f(0.50, 0.30);
        glVertex2f(0.65, 0.30);
        glEnd();
        glPopMatrix();
}


void myDisplay(void){
    glLoadIdentity();
    sky();
    sun();
    river();
    boat();
    ship();
    ground();
    cloud_left();
    cloud_right();
    bridge();
    hills();
    Railline();
    Tree2();
    road();
    Car();
    Car2();
    tree();
    house();
    playground();
    train();
    clock();
    glFlush();
    glutSwapBuffers();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}
void update(int value) {

    _move += .006;
    if(_move-1.3 > 1.0)
    {
        _move = -1.0;
    }
glutPostRedisplay(); //Notify GLUT that the display has changed

glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void updateCar(int value) {
    _move_car += .005;
    if(_move_car-1.3 > 1.0)
    {
        _move_car = -1.0;
    }
 glutPostRedisplay(); //Notify GLUT that the display has changed
 glutTimerFunc(25, updateCar, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car2(int value){
    _move_car2 -= 0.008f;
    if(_move_car2+1.3 < -1.0)
    {
        _move_car2 = +1.0;
    }
 glutPostRedisplay(); //Notify GLUT that the display has changed
 glutTimerFunc(20, update_car2, 0);
}


void update_boat(int value) {
    _move_boat += .0006;
    if(_move_boat-1.3 > 1.0)
    {
        _move_boat = -1.0;
    }
 glutPostRedisplay();
 glutTimerFunc(25,update_boat, 0);
}

void update_ship(int value){
    _move_ship -= 0.0009f;
    if(_move_ship+1.3 < -1.0)
    {
        _move_ship = -1.9;
    }
 glutPostRedisplay(); //Notify GLUT that the display has changed
 glutTimerFunc(20, update_ship, 0);
}



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1400, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Slipstream City");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);
    glutTimerFunc(25, updateCar, 0);
    glutTimerFunc(20, update_car2, 0);
    glutTimerFunc(30, update_sun, 0);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(25,update_boat, 0);
    glutTimerFunc(20, update_ship, 0);
    myInit ();
    glutMainLoop();
}
