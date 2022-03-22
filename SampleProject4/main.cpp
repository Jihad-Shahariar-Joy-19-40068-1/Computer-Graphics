#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h>

float _move_car_1 = 0.00f;
float _speed_car_1 = 0.0025f;

float _move_car_2 = 0.00f;
float _speed_car_2 = 0.0025f;

float _move_car_3 = 0.00f;
float _speed_car_3 = 0.0025f;

float _move_train = 0.00f;
float _speed_train = 0.0025f;

float _move_ship = 0.00f;
float _speed_ship = 0.0025f;

float _move_sun = 1.00f;
float _move_cloud_1 = 0.00f;
float _move_cloud_2 = 0.00f;
float _move_boat = 0.00f;

void update_car_1(int value) {
    if(_speed_car_1>1.00f || _speed_car_1<0.00f)
    {
        _speed_car_1 = 0.0f;
    }
    _move_car_1 += _speed_car_1;
    if(_move_car_1-1.3 > 1.0)
    {
        _move_car_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_2(int value) {
    if(_speed_car_2>1 || _speed_car_2<0)
    {
        _speed_car_2 = 0.0f;
    }
    _move_car_2 -= _speed_car_2;
    if(_move_car_2+1.3 < -1.0)
    {
        _move_car_2 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_3(int value) {
    if(_speed_car_3>1 || _speed_car_3<0)
    {
        _speed_car_3 = 0.0f;
    }
    _move_car_3 -= _speed_car_3;
    if(_move_car_3+1.3 < -1.0)
    {
        _move_car_3 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_3, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_train(int value) {
    if(_speed_train>1 || _speed_train<0)
    {
        _speed_train = 0.0f;
    }
    _move_train -= _speed_train;
    if(_move_train+1.3 < -1.0)
    {
        _move_train = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_train, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_ship(int value) {
    if(_speed_ship>1 || _speed_ship<0)
    {
        _speed_ship = 0.0f;
    }
    _move_ship -= _speed_ship;
    if(_move_ship +1.3 < -1.0)
    {
        _move_ship = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_ship, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_sun(int value){
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < -1.0)
    {
        _move_sun = 1.3;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_sun, 0);
}

void update_cloud_1(int value) {
    _move_cloud_1 += 0.0025f;
    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_cloud_2(int value){
    _move_cloud_2 -= 0.0025f;
    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_2, 0);
}

void update_boat(int value) {
    _move_boat += 0.0025f;
    if(_move_boat-1.3 > 1.0)
    {
        _move_boat = -1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_boat, 0); //Notify GLUT to call update again in 25 milliseconds
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          update_car_1(0);
          update_car_2(0);
          update_car_3(0);
          update_train(0);
          update_ship(0);
          break;
      case GLUT_KEY_DOWN:
          exit(0);
          break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
      case 81:
          _speed_car_1+=0.0025f;
          update_car_1(0);
          break;
      case 87:
          _speed_car_1-=0.0025f;
          update_car_1(0);
          break;
      case 65:
          _speed_car_2+=0.0025f;
          update_car_2(0);
          break;
      case 83:
          _speed_car_2-=0.0025f;
          update_car_2(0);
          break;
      case 69:
          _speed_train+=0.0025f;
          update_train(0);
          break;
      case 82:
          _speed_train-=0.0025f;
          update_train(0);
          break;
      case 90:
          _speed_car_3+=0.0025f;
          update_car_3(0);
          break;
      case 88:
          _speed_car_3-=0.0025f;
          update_car_3(0);
          break;
      case 68:
          _speed_ship+=0.0025f;
          update_ship(0);
          break;
      case 70:
          _speed_ship-=0.0025f;
          update_ship(0);
          break;
    }
}

void sky(){
    //Sky
    if(_move_sun<=1.00f && _move_sun>=0.90f){
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.90f && _move_sun>=0.55f){
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.55f && _move_sun>=0.35f){
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.961, 0.933);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }

    else if(_move_sun<0.35f && _move_sun>=0.25f){
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.855, 0.725);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }

    else if(_move_sun<0.25f && _move_sun>=0.10f){
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.10f && _move_sun>=-0.10f){
        glBegin(GL_QUADS);
        glColor3f(1.000, 0.388, 0.278);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3f(0.412, 0.412, 0.412);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();

        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glTranslatef(0.80,1.05,0);
        glScalef(0.6,1,1);
        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.95,0.95,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.75,0.85,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.65,0.65,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(0.65,0.75,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.65,0.93,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.10,0.67,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(0.15,0.67,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.35,0.85,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(0.25,0.73,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(-0.72,0.63,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
        glTranslatef(0.65,0.73,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
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
    }
}

void field_1(){
    //field 1
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.05);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.05);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, 0.135);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, 0.135);

    glEnd();
}

void rail_track(){
    //Rail track
    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, 0.015);
    glVertex2f(-1.0, 0.030);
    glVertex2f(1.0, 0.030);
    glVertex2f(1.0, 0.015);

    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, 0.080);
    glVertex2f(-1.0, 0.095);
    glVertex2f(1.0, 0.095);
    glVertex2f(1.0, 0.080);

    glColor3f(0.184, 0.310, 0.310);
    for(float i = -0.99; i<=1; i =i+0.03){
        glVertex2f(i,0.030);
        glVertex2f(i,0.080);
        glVertex2f(i+0.01, 0.080);
        glVertex2f(i+0.01, 0.030);
    }
    glEnd();
}

void train(){
    glColor3d(0.282, 0.239, 0.545);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.05, 0.065);
        glVertex2f(0.30, 0.065);
        glVertex2f(0.30, 0.26);
        glVertex2f(0.05, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.07, 0.110);
        glVertex2f(0.28, 0.110);
        glVertex2f(0.28, 0.215);
        glVertex2f(0.07, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.17, 0.110);
        glVertex2f(0.18, 0.110);
        glVertex2f(0.18, 0.215);
        glVertex2f(0.17, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.07, 0.235);
        glVertex2f(0.28, 0.235);
        glVertex2f(0.28, 0.26);
        glVertex2f(0.07, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.10,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.25,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.30, 0.075);
        glVertex2f(0.35, 0.075);
        glVertex2f(0.35, 0.095);
        glVertex2f(0.30, 0.095);
	glEnd();
    glPopMatrix();

	/////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.35, 0.065);
        glVertex2f(0.60, 0.065);
        glVertex2f(0.60, 0.26);
        glVertex2f(0.35, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 0.110);
        glVertex2f(0.58, 0.110);
        glVertex2f(0.58, 0.215);
        glVertex2f(0.37, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glVertex2f(0.47, 0.110);
        glVertex2f(0.48, 0.110);
        glVertex2f(0.48, 0.215);
        glVertex2f(0.47, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 0.235);
        glVertex2f(0.58, 0.235);
        glVertex2f(0.58, 0.26);
        glVertex2f(0.37, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.40,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.55,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.60, 0.075);
        glVertex2f(0.65, 0.075);
        glVertex2f(0.65, 0.095);
        glVertex2f(0.60, 0.095);
	glEnd();
    glPopMatrix();

    /////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.65, 0.065);
        glVertex2f(0.90, 0.065);
        glVertex2f(0.90, 0.26);
        glVertex2f(0.65, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.67, 0.110);
        glVertex2f(0.88, 0.110);
        glVertex2f(0.88, 0.215);
        glVertex2f(0.67, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.77, 0.110);
        glVertex2f(0.78, 0.110);
        glVertex2f(0.78, 0.215);
        glVertex2f(0.77, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.67, 0.235);
        glVertex2f(0.88, 0.235);
        glVertex2f(0.88, 0.26);
        glVertex2f(0.67, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.70,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.85,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        if(_move_sun<-0.10){
            glColor3f(1.000, 0.973, 0.863);
            glPushMatrix();
            glTranslatef(_move_train, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                glVertex2f(0.05, 0.245);
                glVertex2f(0.05, 0.255);
                glVertex2f(-0.00, 0.26);
                glVertex2f(-0.00, 0.24);
            glEnd();
            glPopMatrix();
        }
        glutSwapBuffers();
}

void sun(){
    //Sun
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    if(_move_sun<=1.00 && _move_sun>=0.95f){
       glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.647, 0.000);
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

    else if(_move_sun<0.95f && _move_sun>=0.85f){
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

    else if(_move_sun<0.85 && _move_sun>=0.65){
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

    else if(_move_sun<0.65 && _move_sun>=0.45){
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

    else if(_move_sun<0.45 && _move_sun>=0.25){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.647, 0.000);
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

    else if(_move_sun<0.25 && _move_sun>=0.10){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
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

    else{
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.271, 0.000);
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

void cloud_left(){
    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
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
}

void red_building(){
    //Red Building
    glBegin(GL_QUADS);
    glColor3f(0.698, 0.133, 0.133);
    glVertex2f(-0.95, -0.05);
    glVertex2f(-0.75, -0.05);
    glVertex2f(-0.75, 0.45);
    glVertex2f(-0.95, 0.45);

    //Door of Red Building
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.90, -0.05);
    glVertex2f(-0.80, -0.05);
    glVertex2f(-0.80, 0.15);
    glVertex2f(-0.90, 0.15);

    //2 Window of Red Building
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);;
    glVertex2f(-0.93, 0.26);
    glVertex2f(-0.88, 0.26);
    glVertex2f(-0.88, 0.36);
    glVertex2f(-0.93, 0.36);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.82, 0.26);
    glVertex2f(-0.77, 0.26);
    glVertex2f(-0.77, 0.36);
    glVertex2f(-0.82, 0.36);

    //Roof top of red building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.93, 0.45);
    glVertex2f(-0.87, 0.45);
    glVertex2f(-0.87, 0.52);
    glVertex2f(-0.93, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.94, 0.52);
    glVertex2f(-0.86, 0.52);
    glVertex2f(-0.86, 0.54);
    glVertex2f(-0.94, 0.54);

    glEnd();
}

void blue_building(){
    //Blue Building
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex2f(-0.65, -0.05);
    glVertex2f(-0.45, -0.05);
    glVertex2f(-0.45, 0.45);
    glVertex2f(-0.65, 0.45);

    //Door of blue building
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.63, -0.05);
    glVertex2f(-0.57, -0.05);
    glVertex2f(-0.57, 0.15);
    glVertex2f(-0.63, 0.15);

    //Little window of blue building
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.53, 0.03);
    glVertex2f(-0.48, 0.03);
    glVertex2f(-0.48, 0.13);
    glVertex2f(-0.53, 0.13);

    //Big window of blue building
    glBegin(GL_QUADS);
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-0.63, 0.25);
    glVertex2f(-0.47, 0.25);
    glVertex2f(-0.47, 0.36);
    glVertex2f(-0.63, 0.36);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.63, 0.31);
    glVertex2f(-0.63, 0.30);
    glVertex2f(-0.47, 0.30);
    glVertex2f(-0.47, 0.31);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.555, 0.36);
    glVertex2f(-0.555, 0.25);
    glVertex2f(-0.545, 0.25);
    glVertex2f(-0.545, 0.36);

    //Roof top of blue building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.46, 0.45);
    glVertex2f(-0.52, 0.45);
    glVertex2f(-0.52, 0.52);
    glVertex2f(-0.46, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.45, 0.52);
    glVertex2f(-0.53, 0.52);
    glVertex2f(-0.53, 0.54);
    glVertex2f(-0.45, 0.54);

    glEnd();
}

void phone_box(){
    //Phone Box
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(-0.41, -0.05);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.41, 0.15);

    //Window of Phone Box
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.40, 0.02);
    glVertex2f(-0.35, 0.02);
    glVertex2f(-0.35, 0.13);
    glVertex2f(-0.40, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(-0.38, 0.02);
    glVertex2f(-0.38, 0.13);

    glVertex2f(-0.37, 0.02);
    glVertex2f(-0.37, 0.13);

    glVertex2f(-0.40, 0.07);
    glVertex2f(-0.35, 0.07);

    glVertex2f(-0.40, 0.08);
    glVertex2f(-0.35, 0.08);
    glEnd();

    //Top of Phone Box
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(-0.41, 0.15);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.36, 0.17);
    glVertex2f(-0.39, 0.17);
    glEnd();

}

void twin_tower(){
    //Tower 1 of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.30, -0.05);
    glVertex2f(-0.08, -0.05);
    glVertex2f(-0.08, 0.60);
    glVertex2f(-0.30, 0.60);

    //Roof top of tower 1
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.31, 0.60);
    glVertex2f(-0.07, 0.60);
    glVertex2f(-0.07, 0.62);
    glVertex2f(-0.31, 0.62);

    //1st floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, -0.03);
    glVertex2f(-0.20, -0.03);
    glVertex2f(-0.20, 0.05);
    glVertex2f(-0.28, 0.05);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, -0.03);
    glVertex2f(-0.10, -0.03);
    glVertex2f(-0.10, 0.05);
    glVertex2f(-0.18, 0.05);

    //2nd floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, 0.07);
    glVertex2f(-0.20, 0.07);
    glVertex2f(-0.20, 0.15);
    glVertex2f(-0.28, 0.15);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, 0.07);
    glVertex2f(-0.10, 0.07);
    glVertex2f(-0.10, 0.15);
    glVertex2f(-0.18, 0.15);

    //3rd floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, 0.17);
    glVertex2f(-0.20, 0.17);
    glVertex2f(-0.20, 0.25);
    glVertex2f(-0.28, 0.25);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, 0.17);
    glVertex2f(-0.10, 0.17);
    glVertex2f(-0.10, 0.25);
    glVertex2f(-0.18, 0.25);

    //4th floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, 0.27);
    glVertex2f(-0.20, 0.27);
    glVertex2f(-0.20, 0.35);
    glVertex2f(-0.28, 0.35);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, 0.27);
    glVertex2f(-0.10, 0.27);
    glVertex2f(-0.10, 0.35);
    glVertex2f(-0.18, 0.35);

    //5th floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, 0.37);
    glVertex2f(-0.20, 0.37);
    glVertex2f(-0.20, 0.45);
    glVertex2f(-0.28, 0.45);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, 0.37);
    glVertex2f(-0.10, 0.37);
    glVertex2f(-0.10, 0.45);
    glVertex2f(-0.18, 0.45);

    //6th floor window of tower 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.28, 0.47);
    glVertex2f(-0.20, 0.47);
    glVertex2f(-0.20, 0.55);
    glVertex2f(-0.28, 0.55);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.18, 0.47);
    glVertex2f(-0.10, 0.47);
    glVertex2f(-0.10, 0.55);
    glVertex2f(-0.18, 0.55);

    //Tower 2 of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.08, -0.05);
    glVertex2f(0.30, -0.05);
    glVertex2f(0.30, 0.60);
    glVertex2f(0.08, 0.60);

    //Roof top of tower 2
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(0.31, 0.60);
    glVertex2f(0.07, 0.60);
    glVertex2f(0.07, 0.62);
    glVertex2f(0.31, 0.62);

    //1st floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.1, -0.03);
    glVertex2f(0.18, -0.03);
    glVertex2f(0.18, 0.05);
    glVertex2f(0.1, 0.05);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.20, -0.03);
    glVertex2f(0.28, -0.03);
    glVertex2f(0.28, 0.05);
    glVertex2f(0.20, 0.05);

    //2nd floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.18, 0.07);
    glVertex2f(0.10, 0.07);
    glVertex2f(0.10, 0.15);
    glVertex2f(0.18, 0.15);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.28, 0.07);
    glVertex2f(0.20, 0.07);
    glVertex2f(0.20, 0.15);
    glVertex2f(0.28, 0.15);

    //3rd floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.18, 0.17);
    glVertex2f(0.10, 0.17);
    glVertex2f(0.10, 0.25);
    glVertex2f(0.18, 0.25);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.28, 0.17);
    glVertex2f(0.20, 0.17);
    glVertex2f(0.20, 0.25);
    glVertex2f(0.28, 0.25);

    //4th floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.18, 0.27);
    glVertex2f(0.10, 0.27);
    glVertex2f(0.10, 0.35);
    glVertex2f(0.18, 0.35);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.28, 0.27);
    glVertex2f(0.20, 0.27);
    glVertex2f(0.20, 0.35);
    glVertex2f(0.28, 0.35);

    //5th floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.18, 0.37);
    glVertex2f(0.10, 0.37);
    glVertex2f(0.10, 0.45);
    glVertex2f(0.18, 0.45);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.28, 0.37);
    glVertex2f(0.20, 0.37);
    glVertex2f(0.20, 0.45);
    glVertex2f(0.28, 0.45);

    //6th floor window of tower 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.18, 0.47);
    glVertex2f(0.10, 0.47);
    glVertex2f(0.10, 0.55);
    glVertex2f(0.18, 0.55);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.28, 0.47);
    glVertex2f(0.20, 0.47);
    glVertex2f(0.20, 0.55);
    glVertex2f(0.28, 0.55);

    //Joining of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.08, 0.15);
    glVertex2f(0.08, 0.15);
    glVertex2f(0.08, 0.27);
    glVertex2f(-0.08, 0.27);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.08, 0.17);
    glVertex2f(0.08, 0.17);
    glVertex2f(0.08, 0.25);
    glVertex2f(-0.08, 0.25);

    glEnd();
}

void building_side_road(){
    //Building side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.05);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.05);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.10);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.10);
    glEnd();
}

void road(){
    //Main road lane 1
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-1.0, -0.32);
    glVertex2f(1.0, -0.32);
    glVertex2f(1.0, -0.12);

    //Main Road Strips 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.30);
    glVertex2f(-0.95, -0.32);
    glVertex2f(-0.65, -0.32);
    glVertex2f(-0.65, -0.30);

    //Main Road Strips 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.55, -0.30);
    glVertex2f(-0.55, -0.32);
    glVertex2f(-0.25, -0.32);
    glVertex2f(-0.25, -0.30);

    //Main Road Strips 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.15, -0.30);
    glVertex2f(-0.15, -0.32);
    glVertex2f(0.15, -0.32);
    glVertex2f(0.15, -0.30);

    //Main Road Strips 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.25, -0.30);
    glVertex2f(0.25, -0.32);
    glVertex2f(0.55, -0.32);
    glVertex2f(0.55, -0.30);

    //Main Road Strips 5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.65, -0.30);
    glVertex2f(0.65, -0.32);
    glVertex2f(.95, -0.32);
    glVertex2f(.95, -0.30);
    glEnd();

    //Main road lane 2
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.32);
    glVertex2f(-1.0, -0.50);
    glVertex2f(1.0, -0.50);
    glVertex2f(1.0, -0.32);

    glEnd();
}

void car_1(){
    glColor3d(0.000, 0.545, 0.545);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.85, -0.20);
        glVertex2f(-0.55, -0.20);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.60, -0.13);
        glVertex2f(-0.65, -0.03);
        glVertex2f(-0.75, -0.03);
        glVertex2f(-0.80, -0.03);
        glVertex2f(-0.85, -0.13);
        glVertex2f(-0.85, -0.20);
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.61, -0.13);
        glVertex2f(-0.66, -0.04);
        glVertex2f(-0.79, -0.04);
        glVertex2f(-0.84, -0.13);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.73, -0.13);
        glVertex2f(-0.72, -0.13);
        glVertex2f(-0.72, -0.04);
        glVertex2f(-0.73, -0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
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
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
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
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
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
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
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

    if(_move_sun<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_move_car_1, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.165);
            glVertex2f(-0.55, -0.175);
            glVertex2f(-0.505, -0.195);
            glVertex2f(-0.505, -0.145);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_2(){
    glColor3d(0.545, 0.000, 0.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.54, -0.42);
        glVertex2f(-0.21, -0.42);
        glVertex2f(-0.20, -0.40);
        glVertex2f(-0.20, -0.13);
        glVertex2f(-0.21, -0.11);
        glVertex2f(-0.54, -0.11);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.55, -0.40);
        glVertex2f(-0.54, -0.42);
	glEnd();
    glPopMatrix();

    glColor3d(0.902, 0.902, 0.980);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.52, -0.28);
        glVertex2f(-0.44, -0.28);
        glVertex2f(-0.44, -0.15);
        glVertex2f(-0.52, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.41, -0.28);
        glVertex2f(-0.33, -0.28);
        glVertex2f(-0.33, -0.15);
        glVertex2f(-0.41, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.30, -0.28);
        glVertex2f(-0.22, -0.28);
        glVertex2f(-0.22, -0.15);
        glVertex2f(-0.30, -0.15);
	glEnd();
    glPopMatrix();

    glColor3f(1.000, 0.647, 0.000);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53, -0.40);
        glVertex2f(-0.22, -0.40);
        glVertex2f(-0.225, -0.38);
        glVertex2f(-0.525, -0.38);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
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
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
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

    if(_move_sun<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_move_car_2, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.405);
            glVertex2f(-0.55, -0.395);
            glVertex2f(-0.605, -0.385);
            glVertex2f(-0.605, -0.415);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_3(){
    glColor3d(0.118, 0.565, 1.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.55, -0.25);
        glVertex2f(0.50, -0.25);
        glVertex2f(0.50, -0.40);
        glVertex2f(0.85, -0.40);
        glVertex2f(0.85, -0.10);
        glVertex2f(0.65, -0.10);
        glVertex2f(0.55, -0.25);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.00);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.57, -0.25);
        glVertex2f(0.84, -0.25);
        glVertex2f(0.84, -0.12);
        glVertex2f(0.65, -0.12);
	glEnd();
    glPopMatrix();

    glColor3d(0.118, 0.565, 1.000);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.71, -0.25);
        glVertex2f(0.72, -0.25);
        glVertex2f(0.72, -0.12);
        glVertex2f(0.71, -0.12);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
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
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
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

    if(_move_sun<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_move_car_3, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(0.50, -0.385);
            glVertex2f(0.50, -0.375);
            glVertex2f(0.45, -0.365);
            glVertex2f(0.45, -0.395);
        glEnd();
        glPopMatrix();
    }
    glutSwapBuffers();
}

void park_side_road(){
    //River side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.50);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.50);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.55);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.55);
    glEnd();
}

void house_1(){
    //House 1
    glBegin(GL_QUADS);
    glColor3f(0.400, 0.804, 0.667);
    glVertex2f(0.45, -0.03);
    glVertex2f(0.72, -0.03);
    glVertex2f(0.72, 0.17);
    glVertex2f(0.45, 0.17);

    //Door of House 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(0.56, -0.03);
    glVertex2f(0.60, -0.03);
    glVertex2f(0.60, 0.12);
    glVertex2f(0.56, 0.12);

    //Window of House 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.48, 0.03);
    glVertex2f(0.52, 0.03);
    glVertex2f(0.52, 0.10);
    glVertex2f(0.48, 0.10);

    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.64, 0.03);
    glVertex2f(0.68, 0.03);
    glVertex2f(0.68, 0.10);
    glVertex2f(0.64, 0.10);

    //Basement of house 1
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.44, -0.05);
    glVertex2f(0.73, -0.05);
    glVertex2f(0.73, -0.03);
    glVertex2f(0.44, -0.03);

    //Roof of house 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex2f(0.44, 0.17);
    glVertex2f(0.73, 0.17);
    glVertex2f(0.73, 0.19);
    glVertex2f(0.44, 0.19);
    glEnd();

    //Roof of house 1
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.937, 0.835);
    glVertex2f(0.44, 0.19);
    glVertex2f(0.73, 0.19);
    glVertex2f(0.59, 0.27);
    glEnd();
}

void house_2(){
    //House 2
    glBegin(GL_QUADS);
    glColor3f(0.804, 0.361, 0.361);
    glVertex2f(0.78, -0.03);
    glVertex2f(0.95, -0.03);
    glVertex2f(0.95, 0.17);
    glVertex2f(0.78, 0.17);

    //Door of House 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.87, -0.03);
    glVertex2f(0.92, -0.03);
    glVertex2f(0.92, 0.12);
    glVertex2f(0.87, 0.12);

    //Window of House 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.80, 0.03);
    glVertex2f(0.84, 0.03);
    glVertex2f(0.84, 0.10);
    glVertex2f(0.80, 0.10);

    //Basement of house 2
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.77, -0.05);
    glVertex2f(0.96, -0.05);
    glVertex2f(0.96, -0.03);
    glVertex2f(0.77, -0.03);

    //Roof of house 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex2f(0.77, 0.17);
    glVertex2f(0.96, 0.17);
    glVertex2f(0.96, 0.19);
    glVertex2f(0.77, 0.19);
    glEnd();

    //Roof of house 2
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.937, 0.835);
    glVertex2f(0.77, 0.19);
    glVertex2f(0.96, 0.19);
    glVertex2f(0.86, 0.25);
    glEnd();
}

void road_lamp_one_side(){
    //Lam Stand 1
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.735, -0.10);
    glVertex2f(-0.720, -0.10);
    glVertex2f(-0.725, 0.15);
    glVertex2f(-0.730, 0.15);
    glEnd();

    //Lamp Stand 1 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.730, 0.15);
    glVertex2f(-0.705, 0.15);
    glVertex2f(-0.710, 0.18);
    glVertex2f(-0.728, 0.18);
    glEnd();

    //Lam Stand 2
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.435, -0.10);
    glVertex2f(-0.420, -0.10);
    glVertex2f(-0.425, 0.15);
    glVertex2f(-0.430, 0.15);
    glEnd();

    //Lamp Stand 2 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.430, 0.15);
    glVertex2f(-0.405, 0.15);
    glVertex2f(-0.410, 0.18);
    glVertex2f(-0.428, 0.18);
    glEnd();

    //Lam Stand 3
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.135, -0.10);
    glVertex2f(-0.120, -0.10);
    glVertex2f(-0.125, 0.15);
    glVertex2f(-0.130, 0.15);
    glEnd();

    //Lamp Stand 3 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.130, 0.15);
    glVertex2f(-0.105, 0.15);
    glVertex2f(-0.110, 0.18);
    glVertex2f(-0.128, 0.18);
    glEnd();

    //Lam Stand 4
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.235, -0.10);
    glVertex2f(0.220, -0.10);
    glVertex2f(0.225, 0.15);
    glVertex2f(0.230, 0.15);
    glEnd();

    //Lamp Stand 4 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.230, 0.15);
    glVertex2f(0.205, 0.15);
    glVertex2f(0.210, 0.18);
    glVertex2f(0.228, 0.18);
    glEnd();

    //Lam Stand 5
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.535, -0.10);
    glVertex2f(0.520, -0.10);
    glVertex2f(0.525, 0.15);
    glVertex2f(0.530, 0.15);
    glEnd();

    //Lamp Stand 5 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.530, 0.15);
    glVertex2f(0.505, 0.15);
    glVertex2f(0.510, 0.18);
    glVertex2f(0.528, 0.18);
    glEnd();

    //Lam Stand 5
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.835, -0.10);
    glVertex2f(0.820, -0.10);
    glVertex2f(0.825, 0.15);
    glVertex2f(0.830, 0.15);
    glEnd();

    //Lamp Stand 5 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.830, 0.15);
    glVertex2f(0.805, 0.15);
    glVertex2f(0.810, 0.18);
    glVertex2f(0.828, 0.18);
    glEnd();
}

void road_lamp_another_side(){
    //Lam Stand - 1
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.735, -0.50);
    glVertex2f(-0.720, -0.50);
    glVertex2f(-0.725, -0.25);
    glVertex2f(-0.730, -0.25);
    glEnd();

    //Lamp Stand - 1 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.730, -0.25);
    glVertex2f(-0.705, -0.25);
    glVertex2f(-0.710, -0.22);
    glVertex2f(-0.728, -0.22);
    glEnd();

    //Lam Stand - 2
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.435, -0.50);
    glVertex2f(-0.420, -0.50);
    glVertex2f(-0.425, -0.25);
    glVertex2f(-0.430, -0.25);
    glEnd();

    //Lamp Stand - 2 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.430, -0.25);
    glVertex2f(-0.405, -0.25);
    glVertex2f(-0.410, -0.22);
    glVertex2f(-0.428, -0.22);
    glEnd();

    //Lam Stand - 3
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(-0.135, -0.50);
    glVertex2f(-0.120, -0.50);
    glVertex2f(-0.125, -0.25);
    glVertex2f(-0.130, -0.25);
    glEnd();

    //Lamp Stand - 3 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(-0.130, -0.25);
    glVertex2f(-0.105, -0.25);
    glVertex2f(-0.110, -0.22);
    glVertex2f(-0.128, -0.22);
    glEnd();

    //Lam Stand - 4
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.235, -0.50);
    glVertex2f(0.220, -0.50);
    glVertex2f(0.225, -0.25);
    glVertex2f(0.230, -0.25);
    glEnd();

    //Lamp Stand - 4 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.230, -0.25);
    glVertex2f(0.205, -0.25);
    glVertex2f(0.210, -0.22);
    glVertex2f(0.228, -0.22);
    glEnd();

    //Lam Stand - 5
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.535, -0.50);
    glVertex2f(0.520, -0.50);
    glVertex2f(0.525, -0.25);
    glVertex2f(0.530, -0.25);
    glEnd();

    //Lamp Stand - 5 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.530, -0.25);
    glVertex2f(0.505, -0.25);
    glVertex2f(0.510, -0.22);
    glVertex2f(0.528, -0.22);
    glEnd();

    //Lam Stand - 6
    glBegin(GL_POLYGON);
    glColor3f(0.275, 0.510, 0.706);
    glVertex2f(0.835, -0.50);
    glVertex2f(0.820, -0.50);
    glVertex2f(0.825, -0.25);
    glVertex2f(0.830, -0.25);
    glEnd();

    //Lamp Stand - 6 bulb
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.647, 0.000);
    glVertex2f(0.830, -0.25);
    glVertex2f(0.805, -0.25);
    glVertex2f(0.810, -0.22);
    glVertex2f(0.828, -0.22);
    glEnd();
}

void field_2(){
    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, -0.523);
    glVertex2f(-0.060, -0.523);
    glVertex2f(-0.060, -0.528);
    glVertex2f(-1.0, -0.528);

    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(0.060, -0.523);
    glVertex2f(1.0, -0.523);
    glVertex2f(1.0, -0.528);
    glVertex2f(0.060, -0.528);

    glColor3f(0.184, 0.310, 0.310);
    for(float i = -1.0; i<=-0.060; i =i+0.02){
        glVertex2f(i, -0.57);
        glVertex2f(i, -0.520);
        glVertex2f(i+0.005, -0.520);
        glVertex2f(i+0.005, -0.57);
    }

    for(float i = 0.060; i<=1; i =i+0.02){
        glVertex2f(i, -0.57);
        glVertex2f(i, -0.520);
        glVertex2f(i+0.005, -0.520);
        glVertex2f(i+0.005, -0.57);
    }
    glEnd();
    //field 2
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.57);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.57);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, -0.73);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, -0.73);
    glEnd();
}

void road_side_park(){
    //River Side Bench 1
    glBegin(GL_QUADS);
    glColor3f(0.961, 1.000, 0.980);
    glVertex2f(-0.855, -0.70);
    glVertex2f(-0.87, -0.70);
    glVertex2f(-0.87, -0.62);
    glVertex2f(-0.855, -0.62);

    glVertex2f(-0.755, -0.70);
    glVertex2f(-0.77, -0.70);
    glVertex2f(-0.77, -0.62);
    glVertex2f(-0.755, -0.62);

    glColor3f(0.941, 1.000, 0.941);
    glVertex2f(-0.885, -0.62);
    glVertex2f(-0.740, -0.62);
    glVertex2f(-0.740, -0.60);
    glVertex2f(-0.885, -0.60);

    //River Side Bench 2
    glColor3f(0.961, 1.000, 0.980);
    glVertex2f(0.855, -0.70);
    glVertex2f(0.87, -0.70);
    glVertex2f(0.87, -0.62);
    glVertex2f(0.855, -0.62);

    glVertex2f(0.755, -0.70);
    glVertex2f(0.77, -0.70);
    glVertex2f(0.77, -0.62);
    glVertex2f(0.755, -0.62);

    glColor3f(0.941, 1.000, 0.941);
    glVertex2f(0.885, -0.62);
    glVertex2f(0.740, -0.62);
    glVertex2f(0.740, -0.60);
    glVertex2f(0.885, -0.60);

    //Road On park
    glColor3f(0.941, 0.902, 0.549);
    glVertex2f(-0.05, -0.68);
    glVertex2f(0.05, -0.68);
    glVertex2f(0.05, -0.57);
    glVertex2f(-0.05, -0.57);

    glColor3f(0.741, 0.718, 0.420);
    glVertex2f(-0.060, -0.68);
    glVertex2f(-0.050, -0.68);
    glVertex2f(-0.050, -0.57);
    glVertex2f(-0.060, -0.57);

    glVertex2f(0.060, -0.68);
    glVertex2f(0.050, -0.68);
    glVertex2f(0.050, -0.57);
    glVertex2f(0.060, -0.57);

    //River Side Temple
    glColor3f(0.627, 0.322, 0.176);
    glVertex2f(-0.15, -0.70);
    glVertex2f(0.15, -0.70);
    glVertex2f(0.15, -0.68);
    glVertex2f(-0.15, -0.68);

    glColor3f(0.804, 0.522, 0.247);
    glVertex2f(-0.12, -0.68);
    glVertex2f(0.12, -0.68);
    glVertex2f(0.12, -0.66);
    glVertex2f(-0.12, -0.66);

    glColor3f(0.957, 0.643, 0.376);
    glVertex2f(-0.10, -0.66);
    glVertex2f(-0.08, -0.66);
    glVertex2f(-0.08, -0.48);
    glVertex2f(-0.10, -0.48);

    glVertex2f(0.10, -0.66);
    glVertex2f(0.08, -0.66);
    glVertex2f(0.08, -0.48);
    glVertex2f(0.10, -0.48);

    glColor3f(0.804, 0.522, 0.247);
    glVertex2f(-0.12, -0.48);
    glVertex2f(0.12, -0.48);
    glVertex2f(0.12, -0.46);
    glVertex2f(-0.12, -0.46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.961, 0.871, 0.702);
    glVertex2f(-0.12, -0.46);
    glVertex2f(0.12, -0.46);
    glVertex2f(0.00, -0.34);
    glVertex2f(-0.12, -0.46);
    glEnd();

    //River Side
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.871, 0.678);
    glVertex2f(-1.0, -0.73);
    glColor3f(1.000, 0.894, 0.769);
    glVertex2f(1.0, -0.73);
    glColor3f(1.000, 0.922, 0.804);
    glVertex2f(1.0, -0.77);
    glColor3f(0.871, 0.722, 0.529);
    glVertex2f(-1.0, -0.77);
    glEnd();
}

void river(){
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 1.000);
    glVertex2f(1.0, -0.77);

    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-1.0, -0.77);

    glColor3f(0.498, 1.000, 0.831);
    glVertex2f(-1.0, -1.0);

    glColor3f(0.282, 0.820, 0.800);
    glVertex2f(1.0, -1.0);

    glEnd();
}

void park_tree(){
    //Park Tree 1
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

    //Park Tree 2
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

    //Park Tree 3
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
}

void boat(){
    glPushMatrix();//start_pushpop
    glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.0, -1.05, 0.0);
        glScalef(0.55, 0.55, 0);
        glPushMatrix();
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_QUADS);
        glVertex2f(0.35, 0.35);
        glVertex2f(0.75, 0.35);
        glVertex2f(0.95, 0.45);
        glVertex2f(0.15, 0.45);

        glEnd();
        glPopMatrix();
    glPushMatrix();
    glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.12, -1.03, 0.0);
        glScalef(0.50, 0.50, 0);
        glColor3f(0.948,0.934,0.734);
        glBegin(GL_QUADS);
        glVertex2f(0.55, 0.45);
        glVertex2f(0.15, 0.45);
        glVertex2f(0.15, 0.65);
        glVertex2f(0.55, 0.65);

        glEnd();
        glPopMatrix();
}

void ship(){
    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_POLYGON);
        glVertex2f(-0.75, -0.98);
        glVertex2f(-0.45, -0.98);
        glVertex2f(-0.40, -0.83);
        glVertex2f(-0.80, -0.83);
        glEnd();
        glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(1.000, 1.000, 0.941);
        glBegin(GL_POLYGON);
        glVertex2f(-0.70, -0.83);
        glVertex2f(-0.45, -0.83);
        glVertex2f(-0.45, -0.75);
        glVertex2f(-0.70, -0.75);
        glEnd();
        glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(1.000, 0.980, 0.941);
        glBegin(GL_POLYGON);
        glVertex2f(-0.60, -0.75);
        glVertex2f(-0.50, -0.75);
        glVertex2f(-0.50, -0.65);
        glVertex2f(-0.60, -0.65);
        glEnd();
        glPopMatrix();
}

void myDisplay(void){
    glLoadIdentity();
    sky();
    sun();
    field_1();
    rail_track();
    train();
    cloud_left();
    cloud_right();
    red_building();
    blue_building();
    phone_box();
    twin_tower();
    house_1();
    house_2();
    building_side_road();
    road_lamp_one_side();
    road();
    car_1();
    car_3();
    car_2();
    road_lamp_another_side();
    park_side_road();
    field_2();
    park_tree();
    road_side_park();
    river();
    boat();
    ship();
    glFlush();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Slipstream City");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);
    glutTimerFunc(20, update_boat, 0);
    myInit ();
    glutMainLoop();
}
