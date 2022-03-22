#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x,y,i;
float counter=0.0;
float counter1=0.01;
void init(void)
{
	gluOrtho2D(0,800,400,0);
	glOrtho(0,800,500,0,1,-1);
}
void clock(void)
{
	//glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	 glLoadIdentity();
	glRotatef(counter,0.0,0.0,-1.0);
	counter+=2;

	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(105,105,105);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.72*sin(i);
			y=0.72*cos(i);
			glVertex2f(x,y);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255,255,255);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.7*sin(i);
			y=0.7*cos(i);
			glVertex2f(x,y);
		}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3ub(105,105,105);
		glVertex2f(-0.03,0);
		glVertex2f(-0.1,0.65);
		glVertex2f(-0.05,0.65);
		glVertex2f(0.03,0.03);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(105,105,105);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.05*sin(i);
			y=0.05*cos(i);
			glVertex2f(x,y);
		}
	glEnd();


	 glLoadIdentity();
	glRotatef(counter1,0.0,0.0,-4.5);
	counter1+=0.16;

    glBegin(GL_POLYGON);
        glColor3ub(105,105,105);
		glVertex2f(-0.03,0.03);
		glVertex2f(0.03,0.03);
		glVertex2f(0.03,0.4);
		glVertex2f(-0.03,0.4);

	glEnd();

	glutSwapBuffers();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(-1,-1);
	glutInitWindowSize(660,500);
	glutCreateWindow("Clock");
	init();
	glutDisplayFunc(clock);
	glutIdleFunc(clock);
	glutMainLoop();
	return 0;
}
