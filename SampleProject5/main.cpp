#include <windows.h>
#include <GL/glut.h>
#include <math.h>

GLfloat skyColor1 = 150.0f;
GLfloat skyColor2 = 214.0f;
GLfloat skyColor3 = 246.0f;

GLfloat sunColor1 = 255.0f;
GLfloat sunColor2 = 204.0f;
GLfloat sunColor3 = 51.0f;

GLfloat lampColor1 = 220.0f;
GLfloat lampColor2 = 220.0f;
GLfloat lampColor3 = 220.0f;

void Sky(){                                            //sk-01

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(skyColor1,skyColor2,skyColor3);
    glVertex2f(50.0f,50.0f);
    glVertex2f(-50.0f,50.0f);
	glVertex2f(-50.0f,15.0f);
	glVertex2f(50.0f,15.0f);
	glEnd();

    glPopMatrix();

}

void Sun(){                                             //su-02

    glPushMatrix();
    glTranslatef(30.0f, 42.0, 0.0f);

    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(sunColor1, sunColor2, sunColor3);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
    glPopMatrix();
}

void River(){                                                  //ri-06

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(46,155,209);
    glVertex2f(50.0f,15.0f);
    glVertex2f(-50.0f,15.0f);
	glVertex2f(-50.0f,-50.0f);
	glVertex2f(50.0f,-50.0f);
	glEnd();

    glPopMatrix();

}

void RoadBridge(){                                                 //rob-09

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(50.0f,-20.0f);
    glVertex2f(-50.0f,-20.0f);
	glVertex2f(-50.0f,-35.0f);
	glVertex2f(50.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-50.0f,-26.0f);
    glVertex2f(-42.0f,-26.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-34.0f,-26.0f);
    glVertex2f(-26.0f,-26.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-18.0f,-26.0f);
    glVertex2f(-10.0f,-26.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-2.0f,-26.0f);
    glVertex2f(6.0f,-26.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(14.0f,-26.0f);
    glVertex2f(22.0f,-26.0f);
	glEnd();

    glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(30.0f,-26.0f);
    glVertex2f(38.0f,-26.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(46.0f,-26.0f);
    glVertex2f(54.0f,-26.0f);
	glEnd();

//pillar 1
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();

//pillar 2
	glPushMatrix();
    glTranslatef(30.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();

//pillar 3
	glPushMatrix();
    glTranslatef(60.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();



    glPopMatrix();

}

void Lamppost1(){                                              //lp1-15

    glPushMatrix();
    glTranslatef(-24.0f, -20.0f, 0.0f);

    glLineWidth(10.0f);
    glBegin(GL_LINES); //1st part of lamppost
    glColor3ub(47,79,79);
    glVertex2i(12,23);
    glVertex2i(12,0);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of lamppost
    glColor3ub(47,79,79);
    glVertex2f(12.4,20);
    glVertex2f(16.4,26);
    glVertex2f(12.4,23);
    glEnd();

    glBegin(GL_QUADS); //light 1
    glColor3ub(lampColor1,lampColor2,lampColor3);
    glVertex2i(15,26);
    glVertex2i(17,25);
    glVertex2i(20,28);
    glVertex2i(19,30);
    glEnd();

	glPopMatrix();
}

void Lamppost2(){                                                 //lp2-16

    glPushMatrix();
    glTranslatef(0.0f, -20.0f, 0.0f);

    glLineWidth(10.0f);
    glBegin(GL_LINES); //1st part of lamppost
    glColor3ub(47,79,79);
    glVertex2i(12,23);
    glVertex2i(12,0);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of lamppost
    glColor3ub(47,79,79);
    glVertex2f(12.4,20);
    glVertex2f(16.4,26);
    glVertex2f(12.4,23);
    glEnd();

    glBegin(GL_QUADS); //light 1
    glColor3ub(lampColor1,lampColor2,lampColor3);
    glVertex2i(15,26);
    glVertex2i(17,25);
    glVertex2i(20,28);
    glVertex2i(19,30);
    glEnd();

	glPopMatrix();
}

void Lamppost3(){                                                   //lp3-17

    glPushMatrix();
    glTranslatef(-48.0f, -20.0f, 0.0f);

    glLineWidth(10.0f);
    glBegin(GL_LINES); //1st part of lamppost
    glColor3ub(47,79,79);
    glVertex2i(12,23);
    glVertex2i(12,0);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of lamppost
    glColor3ub(47,79,79);
    glVertex2f(12.4,20);
    glVertex2f(16.4,26);
    glVertex2f(12.4,23);
    glEnd();

    glBegin(GL_QUADS); //light 1
    glColor3ub(lampColor1,lampColor2,lampColor3);
    glVertex2i(15,26);
    glVertex2i(17,25);
    glVertex2i(20,28);
    glVertex2i(19,30);
    glEnd();

	glPopMatrix();
}

void Lamppost4(){                                                        //lp4-18

    glPushMatrix();
    glTranslatef(24.0f, -20.0f, 0.0f);

    glLineWidth(10.0f);
    glBegin(GL_LINES); //1st part of lamppost
    glColor3ub(47,79,79);
    glVertex2i(12,23);
    glVertex2i(12,0);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of lamppost
    glColor3ub(47,79,79);
    glVertex2f(12.4,20);
    glVertex2f(16.4,26);
    glVertex2f(12.4,23);
    glEnd();

    glBegin(GL_QUADS); //light 1
    glColor3ub(lampColor1,lampColor2,lampColor3);
    glVertex2i(15,26);
    glVertex2i(17,25);
    glVertex2i(20,28);
    glVertex2i(19,30);
    glEnd();

	glPopMatrix();
}

void RailingFront(){                                          //rrf-21

	glLineWidth(18);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(50.0f,-29.0f);
    glVertex2f(-50.0f,-29.0f);
	glEnd();

	//1
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-48.0f,-29.0f);
    glVertex2f(-48.0f,-35.0f);
	glEnd();

	//2
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-42.0f,-29.0f);
    glVertex2f(-42.0f,-35.0f);
	glEnd();

	//3
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-36.0f,-29.0f);
    glVertex2f(-36.0f,-35.0f);
	glEnd();

	//4
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-30.0f,-29.0f);
    glVertex2f(-30.0f,-35.0f);
	glEnd();

	//5
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-24.0f,-29.0f);
    glVertex2f(-24.0f,-35.0f);
	glEnd();

    //6
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-18.0f,-29.0f);
    glVertex2f(-18.0f,-35.0f);
	glEnd();

	//7
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-12.0f,-29.0f);
    glVertex2f(-12.0f,-35.0f);
	glEnd();

    //8
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-6.0f,-29.0f);
    glVertex2f(-6.0f,-35.0f);
	glEnd();

	//9
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.0f,-29.0f);
    glVertex2f(0.0f,-35.0f);
	glEnd();

	//10
	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(6.0f,-29.0f);
    glVertex2f(6.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(12.0f,-29.0f);
    glVertex2f(12.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(12.0f,-29.0f);
    glVertex2f(12.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(18.0f,-29.0f);
    glVertex2f(18.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(24.0f,-29.0f);
    glVertex2f(24.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(30.0f,-29.0f);
    glVertex2f(30.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(36.0f,-29.0f);
    glVertex2f(36.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(42.0f,-29.0f);
    glVertex2f(42.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(48.0f,-29.0f);
    glVertex2f(48.0f,-35.0f);
	glEnd();


}

void RailingBack(){                                               //rrb-14
    glPushMatrix();
    glTranslatef(0.0f, 15.0f, 0.0f);

	glLineWidth(18);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(50.0f,-29.0f);
    glVertex2f(-50.0f,-29.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-48.0f,-29.0f);
    glVertex2f(-48.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-42.0f,-29.0f);
    glVertex2f(-42.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-36.0f,-29.0f);
    glVertex2f(-36.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-30.0f,-29.0f);
    glVertex2f(-30.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-24.0f,-29.0f);
    glVertex2f(-24.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-18.0f,-29.0f);
    glVertex2f(-18.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-12.0f,-29.0f);
    glVertex2f(-12.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-6.0f,-29.0f);
    glVertex2f(-6.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.0f,-29.0f);
    glVertex2f(0.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(6.0f,-29.0f);
    glVertex2f(6.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(12.0f,-29.0f);
    glVertex2f(12.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(12.0f,-29.0f);
    glVertex2f(12.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(18.0f,-29.0f);
    glVertex2f(18.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(24.0f,-29.0f);
    glVertex2f(24.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(30.0f,-29.0f);
    glVertex2f(30.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(36.0f,-29.0f);
    glVertex2f(36.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(42.0f,-29.0f);
    glVertex2f(42.0f,-35.0f);
	glEnd();

	glLineWidth(15);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(48.0f,-29.0f);
    glVertex2f(48.0f,-35.0f);
	glEnd();

    glPopMatrix();
}

void RailBridge(){                                           //rab-10

    glPushMatrix();
    glTranslatef(0.0f, 30.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(50.0f,-23.0f);
    glVertex2f(-50.0f,-23.0f);
	glVertex2f(-50.0f,-29.0f);
	glVertex2f(50.0f,-29.0f);
	glEnd();

//pillar 1
    glPushMatrix();
    glTranslatef(0.0f, 6.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();

//pillar 2
	glPushMatrix();
    glTranslatef(30.0f, 6.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();

//pillar 3
	glPushMatrix();
    glTranslatef(60.0f, 6.0f, 0.0f);

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-23.0f,-35.0f);
    glVertex2f(-30.0f,-35.0f);
    glVertex2f(-30.0f,-45.0f);
    glVertex2f(-23.0f,-45.0f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-18.0f,-45.0f);
    glVertex2f(-35.0f,-45.0f);
    glVertex2f(-35.0f,-50.0f);
    glVertex2f(-18.0f,-50.0f);
	glEnd();

	glPopMatrix();



    glPopMatrix();

}

void RailPath(){                                                //rap-11
    glPushMatrix();
    glTranslatef(0.0f, 38.0f, 0.0f);

	glLineWidth(8);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(50.0f,-32.0f);
    glVertex2f(-50.0f,-32.0f);
	glEnd();

	glLineWidth(8);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(50.0f,-35.0f);
    glVertex2f(-50.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-48.0f,-32.0f);
    glVertex2f(-50.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-42.0f,-32.0f);
    glVertex2f(-44.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-36.0f,-32.0f);
    glVertex2f(-38.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-30.0f,-32.0f);
    glVertex2f(-32.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-24.0f,-32.0f);
    glVertex2f(-26.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-18.0f,-32.0f);
    glVertex2f(-20.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-12.0f,-32.0f);
    glVertex2f(-14.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(-6.0f,-32.0f);
    glVertex2f(-8.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(0.0f,-32.0f);
    glVertex2f(-2.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(6.0f,-32.0f);
    glVertex2f(4.0f,-35.0f);
	glEnd();


	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(12.0f,-32.0f);
    glVertex2f(10.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(18.0f,-32.0f);
    glVertex2f(16.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(24.0f,-32.0f);
    glVertex2f(22.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(30.0f,-32.0f);
    glVertex2f(28.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(36.0f,-32.0f);
    glVertex2f(34.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(42.0f,-32.0f);
    glVertex2f(40.0f,-35.0f);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(48.0f,-32.0f);
    glVertex2f(46.0f,-35.0f);
	glEnd();

    glPopMatrix();
}

GLfloat car1Position = -6.5f;
GLfloat car1Speed = 0.1f;

void Car1(){                                                      //cr1u-19

    glPushMatrix();
    glScalef(10.0f,10.0f,0.0f);
    glTranslatef(car1Position,-2.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.38f, -0.15f);
    glVertex2f( 1.45f, -0.15f);
    glVertex2f( 1.45f, 0.2f);
    glVertex2f(-0.38f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.4f, -0.15f);
    glVertex2f( 1.55f, -0.15f);
    glVertex2f( 1.55f, 0.07f);
    glVertex2f(1.4f, 0.07f);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( 1.4f, 0.14f);
    glVertex2f( 1.55f, 0.04f);
    glEnd();

    glLineWidth(17.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( 1.0f, 0.2f);
    glVertex2f( 1.49f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119,136,153);
    glVertex2f( -0.08f, 0.55f);
    glVertex2f( -0.28f, 0.2f);
    glVertex2f( 1.15f, 0.2f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f( -0.1f, 0.68f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( -0.13f, 0.55f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( 1.15f, 0.15f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( 0.35f, 0.2f);
    glVertex2f( 0.35f, 0.55f);
    glEnd();
//wheel front
	glTranslatef(1.15, -0.15f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glTranslatef(-0.01, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

//wheel back
	glTranslatef(-1.25, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glTranslatef(-0.01, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();


    glPopMatrix();
}

GLfloat car2Position = -6.5f;
GLfloat car2Speed = 0.1f;

void Car2(){                                                      //cr2-20

    glPushMatrix();
    glRotatef(180.0f, 0.0f, 1.0f,0.0f);
    glScalef(10.5f,10.5f,0.0f);
    glTranslatef(car2Position,-2.8f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(0,0,205);
    glVertex2f(-0.38f, -0.15f);
    glVertex2f( 1.45f, -0.15f);
    glVertex2f( 1.45f, 0.2f);
    glVertex2f(-0.38f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,205);
    glVertex2f(1.4f, -0.15f);
    glVertex2f( 1.55f, -0.15f);
    glVertex2f( 1.55f, 0.07f);
    glVertex2f(1.4f, 0.07f);
    glEnd();

    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f( 1.4f, 0.14f);
    glVertex2f( 1.55f, 0.04f);
    glEnd();

    glLineWidth(17.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f( 1.0f, 0.2f);
    glVertex2f( 1.49f, 0.07f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(119,136,153);
    glVertex2f( -0.08f, 0.55f);
    glVertex2f( -0.28f, 0.2f);
    glVertex2f( 1.15f, 0.2f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f( -0.1f, 0.68f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f( -0.13f, 0.55f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f( 1.15f, 0.15f);
    glVertex2f( 0.75f, 0.55f);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glColor3ub(0,0,205);
    glVertex2f( 0.35f, 0.2f);
    glVertex2f( 0.35f, 0.55f);
    glEnd();
//wheel front
	glTranslatef(1.15, -0.15f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glTranslatef(-0.01, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

//wheel back
	glTranslatef(-1.25, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glTranslatef(-0.01, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();


    glPopMatrix();
}


void Car1Update(int value) {                                      //cr1u-22
    if(car1Position >7.0)
        car1Position = -7.0f;
    car1Position += car1Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Car1Update, 0);
}

void Car2Update(int value) {                                       //cr2u-23
    if(car2Position >7.0)
        car2Position = -7.0f;
    car2Position += car2Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Car2Update, 0);
}

GLfloat shipPosition = -75.0f;
GLfloat shipSpeed = 0.8f;

void ShipUpdate(int value) {                                        //shu-26
    if(shipPosition >75.0)
        shipPosition = -75.0f;
    shipPosition += shipSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, ShipUpdate, 0);
}


void Ship(){                                                         //sh-13

    glPushMatrix();
    glTranslatef(shipPosition, 0.0, 0.0);
    //black part
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2f(-25, -10.0);
    glVertex2f(-18, -20);
    glVertex2f(18, -20);
    glVertex2f(25, -10.0);
    glEnd();

    //yellow part
    glColor3ub (200, 140, 5);
	glBegin(GL_QUADS);
    glVertex2f(-18, -10);
    glVertex2f(18, -10);
    glVertex2f(18, -2.0);
    glVertex2f(-18, -2.0);
    glEnd();

    //red part
    glColor3ub (175, 3, 60);
	glBegin(GL_QUADS);
    glVertex2f(-18, -2.0);
    glVertex2f(18, -2.0);
    glVertex2f(15, 3.0);
    glVertex2f(-15, 3.0);
    glEnd();

    //window 1
    glColor3ub (2, 80, 135);
	glBegin(GL_QUADS);
    glVertex2f(-14, -8.5);
    glVertex2f(-10, -8.5);
    glVertex2f(-10, -4.5);
    glVertex2f(-14, -4.5);
    glEnd();

    //window 2
    glColor3ub (2, 80, 135);
	glBegin(GL_QUADS);
    glVertex2f(-6, -8.5);
    glVertex2f(-2, -8.5);
    glVertex2f(-2, -4.5);
    glVertex2f(-6, -4.5);
    glEnd();

    //window 3
    glColor3ub (2, 80, 135);
	glBegin(GL_QUADS);
    glVertex2f(2.0, -8.5);
    glVertex2f(6.0, -8.5);
    glVertex2f(6.0, -4.5);
    glVertex2f(2.0, -4.5);
    glEnd();

    //window 4
    glColor3ub (2, 80, 135);
	glBegin(GL_QUADS);
    glVertex2f(10.0, -8.5);
    glVertex2f(14.0, -8.5);
    glVertex2f(14.0, -4.5);
    glVertex2f(10.0, -4.5);
    glEnd();

    //smoke pipe 1
    glColor3ub (180, 150, 3);
	glBegin(GL_QUADS);
    glVertex2f(-13.0, 3.0);
    glVertex2f(-10.0, 3.0);
    glVertex2f(-10.0, 8.0);
    glVertex2f(-13.0, 8.0);
    glEnd();

    glLineWidth(8.0f);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
    glVertex2f(-13.0, 8.0);
    glVertex2f(-10.0, 8.0);
    glEnd();

    //smoke pipe 2
    glColor3ub (180, 150, 3);
	glBegin(GL_QUADS);
    glVertex2f(-7.0, 3.0);
    glVertex2f(-4.0, 3.0);
    glVertex2f(-4.0, 8.0);
    glVertex2f(-7.0, 8.0);
    glEnd();

    glLineWidth(8.0f);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
    glVertex2f(-4.0, 8.0);
    glVertex2f(-7.0, 8.0);
    glEnd();


    //smoke pipe 3
    glColor3ub (180, 150, 3);
	glBegin(GL_QUADS);
    glVertex2f(-1.5, 3.0);
    glVertex2f(2.0, 3.0);
    glVertex2f(2.0, 8.0);
    glVertex2f(-1.5, 8.0);
    glEnd();

    glLineWidth(8.0f);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
    glVertex2f(-1.5, 8.0);
    glVertex2f(2.0, 8.0);
    glEnd();


    //smoke pipe 4
    glColor3ub (180, 150, 3);
	glBegin(GL_QUADS);
    glVertex2f(4.0, 3.0);
    glVertex2f(7.0, 3.0);
    glVertex2f(7.0, 8.0);
    glVertex2f(4.0, 8.0);
    glEnd();

    glLineWidth(8.0f);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
    glVertex2f(4.0, 8.0);
    glVertex2f(7.0, 8.0);
    glEnd();


    //smoke pipe 5
    glColor3ub (180, 150, 3);
	glBegin(GL_QUADS);
    glVertex2f(10.0, 3.0);
    glVertex2f(13.0, 3.0);
    glVertex2f(13.0, 8.0);
    glVertex2f(10.0, 8.0);
    glEnd();

    glLineWidth(8.0f);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
    glVertex2f(13.0, 8.0);
    glVertex2f(10.0, 8.0);
    glEnd();

    glPopMatrix();
}

GLfloat trainPosition=-90.0f;
GLfloat trainSpeed=3.0f;

void TrainUpdate(int value) {                                    //tru-25
    if(trainPosition >95.0)
        trainPosition = -90.0f;
    trainPosition += trainSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, TrainUpdate, 0);
}



void Train(){                                                     //tr-12

    glPushMatrix();
    glTranslatef(trainPosition, 0.0, 0.0);

    glBegin(GL_QUADS); //1st part of train
    glColor3ub(0, 51, 102);
    glVertex2i(-50,5);
    glVertex2i(-30,5);
    glVertex2i(-30,20);
    glVertex2i(-50,20);
    glEnd();

    glBegin(GL_QUADS); //1st part of train
    glColor3ub(0, 51, 102);
    glVertex2i(-50,20);
    glVertex2i(-30,20);
    glVertex2i(-32,23);
    glVertex2i(-48,23);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(-48,12);
    glVertex2i(-42,12);
    glVertex2i(-42,18);
    glVertex2i(-48,18);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(-40,12);
    glVertex2i(-32,12);
    glVertex2i(-32,18);
    glVertex2i(-40,18);
    glEnd();

    glBegin(GL_QUADS);//blocks
    glColor3ub(0,0,0);
    glVertex2i(-30,5);
    glVertex2i(-25,5);
    glVertex2i(-25,9);
    glVertex2i(-30,9);
    glEnd();



    glBegin(GL_QUADS); //2nd part of train
    glColor3ub(0, 51, 102);
    glVertex2i(-25,5);
    glVertex2i(0,5);
    glVertex2i(0,20);
    glVertex2i(-25,20);
    glEnd();

    glBegin(GL_QUADS); //2nd part of train
    glColor3ub(0, 51, 102);
    glVertex2i(-25,20);
    glVertex2i(0,20);
    glVertex2i(-2,23);
    glVertex2i(-23,23);
    glEnd();


    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(-23,12);
    glVertex2i(-17,12);
    glVertex2i(-17,18);
    glVertex2i(-23,18);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(-15,12);
    glVertex2i(-9,12);
    glVertex2i(-9,18);
    glVertex2i(-15,18);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(-8,12);
    glVertex2i(-1,12);
    glVertex2i(-1,18);
    glVertex2i(-8,18);
    glEnd();

    glBegin(GL_QUADS);//blocks
    glColor3ub(0,0,0);
    glVertex2i(0,5);
    glVertex2i(5,5);
    glVertex2i(5,9);
    glVertex2i(0,9);
    glEnd();

    glBegin(GL_QUADS); //3rd part of train
    glColor3ub(0, 51, 102);
    glVertex2i(5,5);
    glVertex2i(15,5);
    glVertex2i(15,20);
    glVertex2i(5,20);
    glEnd();

    glBegin(GL_QUADS); //3rd half part of train
    glColor3ub(0, 51, 102);
    glVertex2i(15,5);
    glVertex2i(30,5);
    glVertex2i(30,13);
    glVertex2i(15,13);
    glEnd();

    glBegin(GL_QUADS);//Window
    glColor3ub(255, 178, 102);
    glVertex2i(9,12);
    glVertex2i(15,12);
    glVertex2i(15,18);
    glVertex2i(9,18);
    glEnd();

    glBegin(GL_QUADS);//blocks
    glColor3ub(0,0,0);
    glVertex2i(16,13);
    glVertex2i(20,13);
    glVertex2i(20,16);
    glVertex2i(16,16);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(16,16);
    glVertex2i(20,16);
    glVertex2i(18,19);
    glEnd();

    glBegin(GL_QUADS);//blocks
    glColor3ub(0,0,0);
    glVertex2i(21,13);
    glVertex2i(25,13);
    glVertex2i(25,16);
    glVertex2i(21,16);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(21,16);
    glVertex2i(25,16);
    glVertex2i(23,19);
    glEnd();

    glBegin(GL_QUADS);//blocks
    glColor3ub(0,0,0);
    glVertex2i(27,13);
    glVertex2i(29,13);
    glVertex2i(30,16);
    glVertex2i(26,16);
    glEnd();

    glBegin(GL_QUADS); //3rd part of train
    glColor3ub(0, 51, 102);
    glVertex2i(5,20);
    glVertex2i(15,20);
    glVertex2i(12,23);
    glVertex2i(7,23);
    glEnd();

    //wheel 1
    glPushMatrix();
    glTranslatef(25.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();


    //wheel 2
    glPushMatrix();
    glTranslatef(20.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 3
    glPushMatrix();
    glTranslatef(15.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 4
    glPushMatrix();
    glTranslatef(10.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();


    //wheel 5
    glPushMatrix();
    glTranslatef(-4.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 6
    glPushMatrix();
    glTranslatef(-12.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 7
    glPushMatrix();
    glTranslatef(-20.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 8
    glPushMatrix();
    glTranslatef(-36.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    //wheel 9
    glPushMatrix();
    glTranslatef(-45.0, 5.0, 0.0);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

     glEnd();
     glPopMatrix();

    glPopMatrix();

}

void circle() {                                                //cc-33

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
}

GLfloat cloud1Position=40.0f;
GLfloat cloud1Speed=0.5f;

void Cloud1Update(int value) {                                   //cl1u-29

    if(cloud1Position <-80.0)
        cloud1Position = 60.0f;
    cloud1Position -= cloud1Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Cloud1Update, 0);
}

GLfloat cloud2Position=30.0f;
GLfloat cloud2Speed=0.5f;

void Cloud2Update(int value) {                                    //cl2u-30

    if(cloud2Position <-80.0)
        cloud2Position = 60.0f;
    cloud2Position -= cloud2Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Cloud2Update, 0);
}

void Cloud1()                                                       //cl1-03
{
    glPushMatrix();
	glTranslatef(cloud1Position, 0.0f, 0.0f);

    glColor3ub(255,250,250);
	glTranslatef(0.0f, 40.0f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(7.0f, 0.66f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(-2.0f, 5.0f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(-5.0f, 0.0f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(10.0f, 0.0f, 0.0f);
    circle();

    glPopMatrix();
}


void Cloud2(){                                                             //cl2-04

    glPushMatrix();
	glTranslatef(cloud2Position, 7.0f, 0.0f);

    glColor3ub(255,250,250);
	glTranslatef(-5.0f, 35.0f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(-5.0f, 0.66f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(2.0f, 5.0f, 0.0f);
    circle();

    glColor3ub(255,250,250);
	glTranslatef(6.0f, -3.0f, 0.0f);
    circle();

    glPopMatrix();
}

GLfloat planePosition=40.0f;
GLfloat planeSpeed=1.5f;

void PlaneUpdate(int value) {                                          //plu-31

    if(planePosition <-80.0)
        planePosition = 40.0f;
    planePosition -= planeSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, PlaneUpdate, 0);
}

void Plane(){                                                          //pl-05

    glPushMatrix();
	glTranslatef(planePosition, 5.0, 0.0f);

    glBegin(GL_QUADS); //1st part of plane
    glColor3ub(85,107,47);
    glVertex2i(20,30);
    glVertex2i(32,30);
    glVertex2i(33,35);
    glVertex2i(20,35);
    glEnd();

    glBegin(GL_QUADS); //2nd part of plane
    glColor3ub(128,128,0);
    glVertex2i(32,29);
    glVertex2i(34,29);
    glVertex2i(32,33);
    glVertex2i(30,33);
    glEnd();

    glBegin(GL_QUADS); //3rd part of plane
    glColor3ub(128,128,0);
    glVertex2i(28,35);
    glVertex2i(33,35);
    glVertex2i(33,40);
    glVertex2i(32,40);
    glEnd();

    glBegin(GL_QUADS); //1st wing
    glColor3ub(128,128,0);
    glVertex2i(27,25);
    glVertex2i(29,25);
    glVertex2i(28,31);
    glVertex2i(25,31);
    glEnd();

    glBegin(GL_QUADS); //2nd wing
    glColor3ub(128,128,0);
    glVertex2i(25,35);
    glVertex2i(27,35);
    glVertex2i(29,40);
    glVertex2i(28,40);
    glEnd();

    glBegin(GL_QUADS); //2nd part of plane
    glColor3ub(128,128,0);
    glVertex2i(25,35);
    glVertex2i(27,35);
    glVertex2i(29,40);
    glVertex2i(28,40);
    glEnd();

    glBegin(GL_QUADS); //window
    glColor3ub(102,205,170);
    glVertex2i(21,32);
    glVertex2i(23,32);
    glVertex2i(23,34);
    glVertex2i(21,34);
    glEnd();

    glBegin(GL_QUADS); //window
    glColor3ub(102,205,170);
    glVertex2i(24,32);
    glVertex2i(26,32);
    glVertex2i(26,34);
    glVertex2i(24,34);
    glEnd();

    glBegin(GL_QUADS); //window
    glColor3ub(102,205,170);
    glVertex2i(27,32);
    glVertex2i(29,32);
    glVertex2i(29,34);
    glVertex2i(27,34);
    glEnd();

    glBegin(GL_POLYGON); //1st part of plane
    glColor3ub(85,107,47);
    glVertex2i(20,30);
    glVertex2i(20,35);
    glVertex2i(18,33);
    glEnd();

    glPopMatrix();
}

GLfloat boat1Position=-50.0f;
GLfloat boat1Speed=0.3f;



void Boat1(){                                                                      //bt1-07

    glPushMatrix();
    glTranslatef(boat1Position,6.0f, 0.0f);

    glBegin(GL_QUADS); //1st part of boat
    glColor3ub(139,69,19);
    glVertex2f(-6.0f,5.0f);
    glVertex2f(-1.0f,5.0f);
    glVertex2f(2.0f,8.5f);
    glVertex2f(-9.0f,8.5f);
    glEnd();

    glBegin(GL_LINES); //2nd part of boat
    glColor3ub(0,0,0);
    glVertex2f(-4.0f,8.5f);
    glVertex2f(-4.0f,14.0f);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of boat
    glColor3ub(184,134,11);
    glVertex2f(-8.0f,11.0f);
    glVertex2f(-4.2f,9.0f);
    glVertex2f(-4.2f,14.0f);
    glEnd();



    glPopMatrix();
}
void Boat1Update(int value) {                                             //bt1u-27

    if(boat1Position >60.0)
        boat1Position = -52.0f;
    boat1Position += boat1Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Boat1Update, 0);
}

GLfloat boat2Position=-30.0f;
GLfloat boat2Speed=0.3f;

void Boat2Update(int value) {                                             //bt2u-28

    if(boat2Position >60.0)
        boat2Position = -50.0f;
    boat2Position += boat2Speed;
	glutPostRedisplay();
	glutTimerFunc(100, Boat2Update, 0);
}

void Boat2(){                                                              //bt2-08

    glPushMatrix();
    glTranslatef(boat2Position,8.0f, 0.0f);

    glBegin(GL_QUADS); //1st part of boat
    glColor3ub(139,69,19);
    glVertex2f(-6.0f,5.0f);
    glVertex2f(-1.0f,5.0f);
    glVertex2f(2.0f,8.5f);
    glVertex2f(-9.0f,8.5f);
    glEnd();

    glBegin(GL_LINES); //2nd part of boat
    glColor3ub(0,0,0);
    glVertex2f(-4.0f,8.5f);
    glVertex2f(-4.0f,14.0f);
    glEnd();

    glBegin(GL_TRIANGLES); //2nd part of boat
    glColor3ub(184,134,11);
    glVertex2f(-8.0f,11.0f);
    glVertex2f(-4.2f,9.0f);
    glVertex2f(-4.2f,14.0f);
    glEnd();


    glPopMatrix();
}

GLfloat busPosition=-2.6f;
GLfloat busSpeed=0.03f;

void BusUpdate(int value) {                                          //buu-24

    if(busPosition >2.8)
        busPosition = -2.6f;
    busPosition += busSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, BusUpdate, 0);
}

void Bus(){                                                           //bu-22

	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScalef(25.0f,28.0f,0.0f);
	glTranslatef(busPosition, -0.4f, 0.0f);

    glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(0.0f,0.04f);
	glVertex2f(-0.8f,0.04f);
	glVertex2f(-0.8f,-0.4f);
	glVertex2f(0.0f,-0.4f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(70,130,180);
	glVertex2f(0.0f,0.0f);
	glVertex2f(-0.76f,0.0f);
	glVertex2f(-0.76f,-0.17f);
	glVertex2f(-0.0f,-0.17f);
	glEnd();

    glLineWidth(0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.76f,0.0f);
	glVertex2f(-0.76f,-0.17f);
	glEnd();

    glLineWidth(0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.6f,0.0f);
	glVertex2f(-0.6f,-0.17f);
	glEnd();

    glLineWidth(0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.44f,0.0f);
	glVertex2f(-0.44f,-0.17f);
	glEnd();

    glLineWidth(0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.28f,0.0f);
	glVertex2f(-0.28f,-0.17f);
	glEnd();

    glLineWidth(0.0f);
    glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex2f(-0.14f,0.0f);
	glVertex2f(-0.14f,-0.17f);
	glEnd();

	glTranslatef(-0.17, -0.4f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();


	glTranslatef(-0.46, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();


	glTranslatef(0.0, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glTranslatef(0.46, 0.0f, 0.0f);
	glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(128,128,128);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();


    glPopMatrix();
}

void handleKeypress(unsigned char key, int x, int y) {                      //hk-32
	switch (key) {

	    case 'D':
            sunColor1 = 255.0f;
            sunColor2 = 204.0f;
            sunColor3 = 51.0f;

            skyColor1 = 150.0f;
            skyColor2 = 214.0f;
            skyColor3 = 246.0f;

            lampColor1 = 220.0f;
            lampColor2 = 220.0f;
            lampColor3 = 220.0f;

glutPostRedisplay();
            break;

        case 'd':
            sunColor1 = 255.0f;
            sunColor2 = 204.0f;
            sunColor3 = 51.0f;

            skyColor1 = 150.0f;
            skyColor2 = 214.0f;
            skyColor3 = 246.0f;

            lampColor1 = 220.0f;
            lampColor2 = 220.0f;
            lampColor3 = 220.0f;

glutPostRedisplay();
            break;

        case 'N':
            sunColor1 = 255.0f;
            sunColor2 = 255.0f;
            sunColor3 = 255.0f;

            skyColor1 = 0.0f;
            skyColor2 = 0.0f;
            skyColor3 = 0.0f;

            lampColor1 = 255.0f;
            lampColor2 = 255.0f;
            lampColor3 = 0.0f;

glutPostRedisplay();
            break;

        case 'n':
            sunColor1 = 255.0f;
            sunColor2 = 255.0f;
            sunColor3 = 255.0f;

            skyColor1 = 0.0f;
            skyColor2 = 0.0f;
            skyColor3 = 0.0f;

            lampColor1 = 255.0f;
            lampColor2 = 255.0f;
            lampColor3 = 0.0f;

glutPostRedisplay();
            break;
	}
}

void Display() {                                                     //dp-34
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

   Sky();            //sk-01
   Sun();            //su-02
   Cloud1();         //cl1-03
   Cloud2();         //cl2-04
   Plane();          //pl-05
   River();          //ri-06
   Boat1();          //bt1-07
   Boat2();          //bt2-08
   RoadBridge();     //rob-09
   RailBridge();     //rab-10
   RailPath();       //rap-11
   Train();          //tr-12
   Ship();           //sh-13
   RailingBack();    //rrb-14
   Lamppost1();      //lp1-15
   Lamppost2();      //lp2-16
   Lamppost3();      //lp3-17
   Lamppost4();      //lp4-18
   Car1();           //cr1-19
   Bus();            //bu-22
   Car2();           //cr2-20
   RailingFront();   //rrf-21

   glFlush();
}

int main(int argc, char** argv) {                                          //mn-35
   glutInit(&argc, argv);
   glutInitWindowSize(1300, 780);
   glutInitWindowPosition(50,50);
   glutCreateWindow("Final Project");
   glutDisplayFunc(Display);
   gluOrtho2D(-50,50,-50,50);
   glutKeyboardFunc(handleKeypress);

   glutTimerFunc(100, Car1Update, 0);
   glutTimerFunc(100, Car2Update, 0);
   glutTimerFunc(100, ShipUpdate, 0);
   glutTimerFunc(100, TrainUpdate, 0);
   glutTimerFunc(100, PlaneUpdate, 0);
   glutTimerFunc(100, Boat1Update, 0);
   glutTimerFunc(100, Boat2Update, 0);
   glutTimerFunc(100, BusUpdate, 0);
   glutTimerFunc(100, Cloud1Update, 0);
   glutTimerFunc(100, Cloud2Update, 0);

   glutMainLoop();
   return 0;
}
