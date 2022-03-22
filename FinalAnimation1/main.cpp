#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>

GLfloat speed = 0.1f;

GLfloat position = 0.0f;
GLfloat pr = 0.0f;

GLfloat enemyPosition = 0.0f;
GLfloat roketPosition = 0.0f;
void update(int value) {

    if(position > 1.0)
    {
        position = -1.2f;
        pr = roketPosition;
    }

    position += speed;

    if(enemyPosition < -1.0)
        enemyPosition = 1.2f;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed -= 0.1f;
    break;
case 'd':
    speed += 0.1f;
    break;


glutPostRedisplay();


	}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
//enemy
   glPushMatrix();
 glTranslatef(0.0f ,enemyPosition , 0.0f);
    glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.9f,0.9f);
   glVertex2f(-0.5f, 0.9f);
   glVertex2f(-0.7f, 0.6f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.5f,0.6f);
   glVertex2f(-0.1f, 0.6f);
   glVertex2f(-0.3f, 0.3f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(0.1f,0.9f);
   glVertex2f(0.5f, 0.9f);
   glVertex2f(0.3f, 0.6f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(0.5f,0.6f);
   glVertex2f(0.9f, 0.6f);
   glVertex2f(0.7f, 0.3f);
   glEnd();
   glPopMatrix();

   //bullet
    glPushMatrix();
    glTranslatef(pr ,position, 0.0f);
    glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(-0.05f, -1.0f);
   glVertex2f(0.05f, -1.0f);
   glVertex2f(0.0f, -0.8f);
   glEnd();
    glPopMatrix();

//rocket
    glPushMatrix();
    glTranslatef(roketPosition,0.0f, 0.0f);
        glBegin(GL_QUADS);
      glColor3f(1.0f, 0.1f, 0.1f);
      glVertex2f(-0.1f, -1.0f);
      glVertex2f( 0.1f, -1.0f);
      glVertex2f( 0.1f,  -0.8f);
      glVertex2f(-0.1f,  -0.8f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.1f, 0.1f);
   glVertex2f(-0.2f, -0.9f);
   glVertex2f(0.2f, -0.9f);
   glVertex2f(0.0f, -0.8f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.1f, 0.1f);
   glVertex2f(-0.1f, -.8f);
   glVertex2f(0.1f, -.8f);
   glVertex2f(0.0f, -0.6f);
   glEnd();

glPopMatrix();

   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(420, 420);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Animation 1");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 10);
   glutMainLoop();
   return 0;
}
