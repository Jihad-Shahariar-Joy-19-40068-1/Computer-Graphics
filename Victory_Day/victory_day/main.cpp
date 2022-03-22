#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <Windows.h>
#include <MMSystem.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool onOff_car=false;
bool onOff_bus=false;
bool onOff_boat=false;

float run = 0.0;//for boat
float boat_speed = 3.0;//for boat

float run1 = 0.0;//for cloud1
float run2 = 0.0;//for cloud2
float run3 = 0.0;//for cloud3
float run4 = 0.0;//for cloud4
float run5 = 0.0;//for cloud5


float tri = 0.0;//for jeep
float tri_bus = 0.0;//for bus

float rain = 0.0;
float _nt = 0.0;

//for human walking on footpath
float walk = 0.0;
float walk_back = 0.0;

float walk1 = 0.0;
float walk2 = 0.0;
float walk3 = 0.0;
float walk_heli = 0.0;
float walk_building_front = 0.0;
float walk5 = 0.0;

int field_x[25];
int field_y[25];
float field_speed[26];
int human_no = 25;
int human_count=0;
int head_left[25];

float walk_speed = 1.9f;//for human walking
float walk_speed_back = 2.8f;//for human walking

float walk_speed1 = 2.5f;
float walk_speed2 = 1.8f;
float walk_speed3 = 1.3f;
float walk_speed_heli = 2.3f;
float walk_speed_building_front = 2.0f;
float walk_speed5 = 5.0f;//1.0f;

bool head_left1 = false;
bool head_left2 = true;
bool head_left3 = false;
bool head_left_heli = true;
bool head_left_building_front = false;
bool head_left5 = false;


float sun_set_pos = 120.0;//initial position
float sun_rise_pos = -160.0;
float sun_speed = 0.5f;
float sun_sky;

float fly = 0;//helicopter
float fly_speed = 5.0f;
bool flyup = false;
bool flydown = false;
bool pilot_request = false;
bool pilot_onboard = false;

float plane_x = 0;//plane
float plane_speed = 3.5f;
bool onOff_plane = false;

float moonx = 120;//moon
float moony = -160.0;
float moonx_speed = 1.2f;
float moony_speed = 0.5f;

int star_count = 0;//star
int star_no=50;//no of stars --- can be changed
int p[50];//creating random star
int q[50];//creating random star

int flower_count = 0;
int flower_no = 200;//no of flowers --- can be changed
int flow_p[205];
int flow_q[205];
int color_r[205];
int color_g[205];
int color_b[205];


bool frd = false;
bool bck = false;

bool frd_bus = false;
bool bck_bus = false;

bool rainday = false;

bool sunup = true;
bool sundown = false;
bool night = false;


void fly_start(int value){
    if(flyup) {
        fly += fly_speed;
    if (fly > 770)
        flyup = false;

        glutPostRedisplay();
        glutTimerFunc(25, fly_start, 0);
    }
}
void fly_end (int value ) {
    if (flydown) {
        fly -= fly_speed;
    if (fly < 0)
        flydown = false;

        glutPostRedisplay();
        glutTimerFunc(25, fly_end, 0);
    }
}

void carbackward (int value){
    if(bck) {
        tri -= 2.2f;
        if (tri < -400) {
            tri += 1700;
        }
        glutPostRedisplay();
        glutTimerFunc(25, carbackward, 0);
    }
}
void carforward (int value ) {
    if (frd) {
        tri += 2.2f;
        if(tri > 1300)
        {
            tri -= 1700;
        }
        glutPostRedisplay();
        glutTimerFunc(25, carforward, 0);
    }
}

void busbackward (int value){
    if(bck_bus) {
        tri_bus -= 2.2f;
        if (tri_bus < -1300) {
            tri_bus += 1700;
        }
        glutPostRedisplay();
        glutTimerFunc(25, busbackward, 0);
    }
}

void busforward (int value ) {
    if (frd_bus) {
        tri_bus += 2.2f;
        if(tri_bus > 500)
        {
            tri_bus -= 1700;
        }
        glutPostRedisplay();
        glutTimerFunc(25, busforward, 0);
    }
}

void Rain(int value){
if(rainday){
    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1300; y%=750;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(x,y);
        glVertex2i(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();//Notify GLUT that the display has changed
	glutTimerFunc(5, Rain, 0);//Notify GLUT to call update again in 5 milliseconds
    glFlush();
}
}

void update (int value)
{
    if(sundown)
    {
    sun_set_pos -= sun_speed;
    sun_sky = sun_set_pos;

    if (sun_set_pos < -160)
    {
        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;

        night = true;
        sundown = false;
        sunup = false;
    }
    }

    if(sunup)
    {
    sun_rise_pos += sun_speed;
    sun_sky = sun_rise_pos;

    if (sun_rise_pos > 120)
    {
        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;

        sundown = true;
        night = false;
        sunup = false;
    }
    }



    if(night)
    {
    moonx += moonx_speed;
    moony += moony_speed;
    if (moony > 190)
    {
        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;

        sunup = true;
        sundown = false;
        night = false;
    }
    }


    if(onOff_boat){
    run += boat_speed;//boat
    if (run > 1300)
        run -= 1700;
    }

    if(onOff_plane){
    plane_x += plane_speed;//boat
    if (plane_x > 1500){
        plane_x = -350;
        onOff_plane = false;
    }
    }

    walk += walk_speed;//human
    if (walk > 1300)
    {
        walk -= 1700;
    }
    walk_back -= walk_speed_back;//human
    if (walk_back < -1300)
    {
        walk_back += 1700;
    }

    for(int a=0; a < human_count; a++){
    if (head_left[a]==1){
        field_x[a] -= field_speed[a];//human

        if (field_x[a] < 0)
            head_left[a]=0;
}

    if (head_left[a]==0){
        field_x[a] += field_speed[a];//human

        if (field_x[a] > 309)
            head_left[a]=1;
    }
    }

    if (head_left1){
        walk1 -= walk_speed1;//human
        if (walk1 < 338-410)
            head_left1=false;
    }

    if (!head_left1){
        walk1 += walk_speed1;//human
        if (walk1 > 517-410)
            head_left1=true;
    }
    if (head_left2){
        walk2 -= walk_speed2;//human
        if (walk2 < 332-389)
            head_left2=false;
    }

    if (!head_left2){
        walk2 += walk_speed2;//human
        if (walk2 > 516-389)
            head_left2=true;
    }

    if (head_left3){
        walk3 -= walk_speed3;//human
        if (walk3 < 855-880)
            head_left3=false;
    }

    if (!head_left3){
        walk3 += walk_speed3;//human
        if (walk3 > 1009-880)
            head_left3=true;
    }

    if(pilot_request){
        head_left_heli = false;
        walk_heli += walk_speed_heli;//human
        if (walk_heli > 1082-900){
                walk_speed_heli = 0;
                pilot_onboard=true;
                head_left_heli=true;
        }
    }
    else if (!pilot_onboard){
            walk_speed_heli = 2.2;
    if (head_left_heli){
        walk_heli -= walk_speed_heli;//human
        if (walk_heli < 859-900)
            head_left_heli=false;
    }

    if (!head_left_heli){
        walk_heli += walk_speed_heli;//human
        if (walk_heli > 1028-900)
            head_left_heli=true;
    }
    }
    if (head_left_building_front){
        walk_building_front-= walk_speed_building_front;//human
        if (walk_building_front< 350-900)
            head_left_building_front=false;
    }

    if (!head_left_building_front){
        walk_building_front+= walk_speed_building_front;//human
        if (walk_building_front> 1270-900)
            head_left_building_front=true;
    }


    run1 += 2.6;//cloud
    if (run1 > 750+50)
        run1 = -600;

    run2 += 2.9f;
    if (run2 > 1150+50)
        run2 = -200;

    run3 += 3.1f;
    if (run3 > 500+50)
        run3 = -1050;

    run4 += 2.4f;
    if (run4 > 1150+50)
        run4 = -300;

    run5 += 2.0f;
    if (run5 > 500+50)
        run5 = -1050;


    if (onOff_car){
        tri += 2.3*4;
        if (tri > 1300)
            tri -= 1700;
    }
    if (onOff_bus){
        tri_bus -= 2.2*5;
        if (tri_bus < -1300)
            tri_bus += 1700;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void myKeyboard (unsigned char key, int x, int y) {

    switch (key)
    {
    case 'q':
        pilot_request = true;
        if(fly<=0 && pilot_onboard){
            sndPlaySound("heli_start1.wav",SND_ASYNC);
        flyup = true;
        flydown = false;
        pilot_request = false;
        fly_start(fly);
        }
        break;

    case 'w':
        if(fly>=420){
            sndPlaySound("heli_land.wav",SND_ASYNC);
        flyup = false;
        flydown = true;
        fly_end(fly);
        }
        if(fly<=0 && pilot_onboard){
            pilot_onboard=false;
        }
        break;


    case 'a':
        frd = false;
        bck = true;
        onOff_car=false;
        carbackward (tri);
        break;


    case 'd':
        frd = true;
        bck = false;
        onOff_car=false;
        carforward (tri);
        break;

    case 's':
        frd = false;
        bck = false;
        onOff_car=false;
        break;

    case 'z':
        frd_bus = false;
        bck_bus = true;
        onOff_bus=false;
        busbackward (tri_bus);
        break;

    case 'c':
        frd_bus = true;
        bck_bus = false;
        onOff_bus=false;
        busforward (tri_bus);
        break;

    case 'x':
        frd_bus = false;
        bck_bus = false;
        onOff_bus=false;
        break;

    case 'r':
        rainday = true;
        Rain(rain);
        sndPlaySound("rain1.wav",SND_ASYNC|SND_LOOP);
        break;

    case 't':
        rainday = false;
        sndPlaySound(NULL,SND_ASYNC);
        if(onOff_boat)
            sndPlaySound("road.wav",SND_ASYNC|SND_LOOP);
        break;

    case 'p':
        sunup = true;
        sundown = false;
        night = false;
        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;
        break;

    case 'o':
        sunup = false;
        sundown = true;
        night = false;
        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;

        break;

    case 'i':
        sunup = false;
        sundown = false;
        night = true;

        sun_rise_pos = -160;
        sun_set_pos = 120;
        moonx = 120;
        moony = -160;

        break;
    case 'e':
        onOff_plane = true;
        if(plane_x<=0)
            sndPlaySound("plane.wav",SND_ASYNC);

        break;


        case 32:
        if(onOff_car || onOff_boat || onOff_bus){
            onOff_boat=false;
            onOff_bus=false;
            onOff_car=false;

            frd = false;
            bck = false;
            frd_bus = false;
            bck_bus = false;

            sndPlaySound(NULL,SND_ASYNC);

        }

        else{
            onOff_boat=true;
            onOff_bus=true;
            onOff_car=true;

            sndPlaySound("road.wav",SND_ASYNC|SND_LOOP);
            }
        break;

        case 27:
        exit(0);
        break;

    default:
    break;
    }
}

void Night(){
    if(night)
    {
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

    if (moony>155 && moony<=190)
        glColor3f(0.412, 0.412, 0.412);//morning
    else if(moony>120 && moony<=155)
        glColor3f(0.1, 0.1, 0.1);//dark-night
    else if (moony>-160 && moony<=120)
        glColor3f(0.412, 0.412, 0.412);//night
    glVertex2i(0,750);
    glVertex2i(1300,750);

    if (moony>155 && moony<=190)
        glColor3f(1.000, 0.388, 0.278);//morning
    else if(moony>120 && moony<=155)
        glColor3f(0.900, 0.900, 0.900);//dark-night
    else if (moony>-160 && moony<=120)
        glColor3f(0.9, 1.000, 1.000);//night
    glVertex2i(1300,550);
    glVertex2i(0,550);

    glEnd();





    }
    }

void star()
{
    if(night)
    {
        //star
    if (moony>-160 && moony<=155)
    {
        for(int pq=0;pq<star_no;pq++)
        {
            if (star_count==pq)
            {
            p[star_count]=rand()%1300;
            q[star_count]=(rand()%(750+1-550)) +550;
            star_count++;
            }
        }


        for(int a= 0; a < star_no; a++)
        {
            glBegin(GL_POLYGON);
            glColor3f(1.000, 1.000, 1.000);

            for(int i=0;i<=360;i++)
            {
                float angle= i*3.1416/180;
                glVertex2f(p[a]+cos(angle)*3, q[a]+sin(angle)*3);
            }
            glEnd();
        }
        }
    }
}

void moon()
{
    glPushMatrix();
    glTranslatef(moonx, moony, 0.0);

    if(moony>=-160 && moony<=-60)
        glColor3ub(150, 160, 170);
    else if(moony>-60 && moony<=120)
        glColor3f(0.902, 0.902, 0.980);


    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(150+cos(angle)*25, 670+sin(angle)*25);//150,670, 25= size
    }
    glEnd();
    glPopMatrix();
}

void sun_d()
{
    if(sundown)
    {
    glPushMatrix();
    glTranslatef(0.0, sun_set_pos, 0.0);

    glBegin(GL_POLYGON);

    if(sun_set_pos<=120 && sun_set_pos>=105)
        glColor3f(1.000, 1.000, 0.000);
    else if(sun_set_pos<105 && sun_set_pos>=0)
        glColor3f(1.000, 0.910, 0.000);
    else if(sun_set_pos<0 && sun_set_pos>=-40)
        glColor3f(1.000, 0.843, 0.000);
    else if(sun_set_pos<-40 && sun_set_pos>=-50)
        glColor3f(1.000, 0.843, 0.000);
    else if(sun_set_pos<-50 && sun_set_pos>=-100)
        glColor3f(1.000, 0.647, 0.000);
    else if(sun_set_pos<-100 && sun_set_pos>=-118)
        glColor3f(1.000, 0.549, 0.000);
    else
        glColor3f(1.000, 0.271, 0.000);


    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(740+cos(angle)*30, 670+sin(angle)*30);//740,670, 30= size
    }
    glEnd();
    glPopMatrix();
    }
}

void sun_u()
{
    if(sunup)
    {
    glPushMatrix();
    glTranslatef(0.0, sun_rise_pos, 0.0);

    glBegin(GL_POLYGON);

    if(sun_rise_pos<=120 && sun_rise_pos>=20)
        glColor3f(1.000, 1.000, 0.000);
    else if(sun_rise_pos<20 && sun_rise_pos>=-10)
        glColor3f(1.000, 0.910, 0.000);
    else if(sun_rise_pos<-10 && sun_rise_pos>=-40)
        glColor3f(1.000, 0.843, 0.000);
    else if(sun_rise_pos<-40 && sun_rise_pos>=-70)
        glColor3f(1.000, 0.843, 0.000);
    else if(sun_rise_pos<-70 && sun_rise_pos>=-100)
        glColor3f(1.000, 0.647, 0.000);
    else if(sun_rise_pos<-100 && sun_rise_pos>=-122)
        glColor3f(1.000, 0.549, 0.000);
    else
        glColor3f(1.000, 0.271, 0.000);


    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*30, 670+sin(angle)*30);//305,670, 30= size
    }
    glEnd();
    glPopMatrix();
    }
}

void sky()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

    if(sun_sky<=155 && sun_sky>=15)//noon
        glColor3f(0.529, 0.808, 0.922);
    else if(sun_sky<15 && sun_sky>=-20)//noon
        glColor3f(0.000, 0.749, 1.000);
    else if(sun_sky<-20 && sun_sky>=-55)//noon
        glColor3f(0.000, 0.749, 1.000);
    else if(sun_sky<-55 && sun_sky>=-90)//after noon
        glColor3f(0.529, 0.808, 0.980);
    else if(sun_sky<-90 && sun_sky>=-125)//sunset
        glColor3f(0.529, 0.808, 0.980);
    else if(sun_sky<-125 && sun_sky>=-160)//sunset
        glColor3f(1.000, 0.388, 0.278);
    else
        glColor3f(0.412, 0.412, 0.412);//night


    glVertex2i(0,750);
    glVertex2i(1300,750);


    if(sun_sky<=155 && sun_sky>=15)
        glColor3f(1.000, 1.000, 1.000);
    else if(sun_sky<15 && sun_sky>=-20)
        glColor3f(0.8, 1.000, 1.000);
    else if(sun_sky<-20 && sun_sky>=-55)
       glColor3f(1.000, 0.961, 0.933);
    else if(sun_sky<-55 && sun_sky>=-90)
        glColor3f(1.000, 0.855, 0.725);
    else if(sun_sky<-90 && sun_sky>=-125)
        glColor3f(0.957, 0.643, 0.376);
    else if(sun_sky<-125 && sun_sky>=-160)
        glColor3f(0.957, 0.643, 0.376);
    else
        glColor3f(0.8, 1.000, 1.000);//night

    glVertex2i(1300,550);
    glVertex2i(0,550);

    glEnd();


}

void plane()
{
    glPushMatrix();
    glTranslatef(-400+plane_x, 0.0, 0.0);

//Plane Part
glBegin(GL_QUADS);
glColor3ub(238, 203, 173);  //TAIL

glVertex2i(200,700);
glVertex2i(210,701);

glVertex2i(210,701);
glVertex2i(220,680);

glVertex2i(220,680);
glVertex2i(215,680);

glVertex2i(210,680);
glVertex2i(200,700);

glColor3ub(238, 223, 204);  //TAIL2

glVertex2i(195,700);
glVertex2i(205,700);

glVertex2i(205,700);
glVertex2i(205,690);

glVertex2i(205,690);
glVertex2i(195,690);

glVertex2i(195,690);
glVertex2i(195,700);


glColor3ub(255, 222, 173); //BODY

glVertex2i(210,680);
glVertex2i(270,680);

glVertex2i(270,680);
glVertex2i(270,655);

glVertex2i(270,655);
glVertex2i(220,655);

glVertex2i(220,655);
glVertex2i(210,680);


glColor3ub(205, 193, 197); //HEAD

glVertex2i(270,662);
glVertex2i(278,662);

glVertex2i(278,662);
glVertex2i(278,673);

glVertex2i(278,673);
glVertex2i(270,673);

glVertex2i(270,673);
glVertex2i(270,662);


glColor3ub(255, 250, 205); //FAN

glVertex2i(272,675);
glVertex2i(276,675);

glVertex2i(276,675);
glVertex2i(276,683);

glVertex2i(276,683);
glVertex2i(272,683);

glVertex2i(272,683);
glVertex2i(272,675);

glColor3ub(255, 250, 205); //FAN2

glVertex2i(272,653);
glVertex2i(276,653);

glVertex2i(276,653);
glVertex2i(276,660);

glVertex2i(276,660);
glVertex2i(272,660);

glVertex2i(272,660);
glVertex2i(272,653);


glColor3ub(96, 123, 139); //Window1

glVertex2i(258,660);
glVertex2i(265,660);

glVertex2i(265,660);
glVertex2i(265,675);

glVertex2i(265,675);
glVertex2i(258,675);

glVertex2i(258,675);
glVertex2i(258,660);


glColor3ub(96, 123, 139); //Window2

glVertex2i(248,660);
glVertex2i(255,660);

glVertex2i(255,660);
glVertex2i(255,675);

glVertex2i(255,675);
glVertex2i(248,675);

glVertex2i(248,675);
glVertex2i(248,660);


glColor3ub(96, 123, 139); //Window3

glVertex2i(230,660);
glVertex2i(245,660);

glVertex2i(245,660);
glVertex2i(245,675);

glVertex2i(245,675);
glVertex2i(230,675);

glVertex2i(230,675);
glVertex2i(230,660);


glColor3ub(139, 131, 120); //Stand

glVertex2i(262,644);
glVertex2i(264,644);

glVertex2i(264,644);
glVertex2i(264,655);

glVertex2i(264,655);
glVertex2i(262,655);

glVertex2i(262,655);
glVertex2i(262,644);

glColor3ub(139, 131, 120); //Stand2

glVertex2i(242,644);
glVertex2i(244,644);

glVertex2i(244,644);
glVertex2i(244,655);

glVertex2i(244,655);
glVertex2i(242,655);

glVertex2i(242,655);
glVertex2i(242,644);


glColor3ub(0,106,78); //flag

glVertex2i(237,633);
glVertex2i(268,633);  //flag middle point = (252, 642)

glVertex2i(268,633);
glVertex2i(268,650);

glVertex2i(268,650);
glVertex2i(237,650);

glVertex2i(237,650);
glVertex2i(237,633);

glEnd();

    glBegin(GL_POLYGON);            //flag-plane
    glColor3ub(244,42,65);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(252+cos(angle)*5.5,642+sin(angle)*5.5);
    }
    glEnd();

glPopMatrix();
}


void basepart()
{
glBegin(GL_QUADS);

if(night)
    glColor3ub(155,138,103);//Night
else if(!night && sun_sky< -90)
    glColor3ub(171,151,113);//Morning & Evening
else
    glColor3ub (186, 164, 123);//Day

glVertex2i(0, 250);
glVertex2i(1300, 250);          //basepart

if(night)
    glColor3ub(141, 151, 64);//Night
else if(!night && sun_sky< -90)
    glColor3ub(152,125,69);//Morning & Evening
else
    glColor3ub (156, 126, 72);//Day

glVertex2i(1300, 550);
glVertex2i(0, 550);
glEnd();
}

void grasspart()
{
//Grass Part
glBegin(GL_QUADS);
if(night)
    glColor3ub(0, 204, 102);//Night
else if(!night && sun_sky< -90)
    glColor3ub(255, 128, 0);//Morning & Evening
else
    glColor3ub(128, 255, 0);//Day

glVertex2i(1300,550);
glVertex2i(0,550);

//glColor3ub(0, 153, 51);
glColor3ub(0, 51, 0);
glVertex2i(0,500);
glVertex2i(1300,500);
glEnd();
}

void grass()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=25;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 45;
    int y_distance = 13;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(-16+grass_x, 5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void grass1()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=200;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 55;
    int y_distance = 13;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(340-355-16+grass_x,276-295+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void grass2_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=20;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 28;
    int y_distance = 13;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1059-355-16+grass_x, 276-327+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void grass3_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=20;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 40;
    int y_distance = 13;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1064-355-16+grass_x, 276-354+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}
void grass4_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=10;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 38;
    int y_distance = 13;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1225-355-16+grass_x, 276-391+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}
void grass5_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=8;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 28;
    int y_distance = 15;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1207-355-16+grass_x, 276-418+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void grass6_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=20;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 30;
    int y_distance = 16;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1069-355-16+grass_x, 276-442+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void grass7_heli()
{
    int grass_x=0;
    int grass_y=0;
    int grass_no=20;
    int grass_distance=(1300-0)/grass_no;

    int x_distance = 30;
    int y_distance = 16;

    bool grass_check_y = false;

    for (int i =0; i< grass_no;i++){
    glPushMatrix();
    glTranslatef(1082-355-16+grass_x, 276-480+5+grass_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(361,477);
    glVertex2i(365,470);
    glVertex2i(370,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(365,480);
    glVertex2i(372,470);
    glVertex2i(367,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(370,480);
    glVertex2i(369,470);
    glVertex2i(373,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(375,480);
    glVertex2i(371,470);
    glVertex2i(375,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(5, 152, 35);
    glVertex2i(380,480);
    glVertex2i(374,470);
    glVertex2i(377,470);

    glBegin(GL_TRIANGLES);
    glColor3ub(11, 102, 35);
    glVertex2i(383,479);
    glVertex2i(375,470);
    glVertex2i(379,470);

    glEnd();

    glPopMatrix();
    grass_x= grass_x + x_distance + i;
    if(!grass_check_y)
    {
        grass_y = 0;
        grass_check_y = true;
    }
    else{

        grass_y = -y_distance;
        grass_check_y = false;
    }
    }
}

void memorial()
{
//-------------Memorial draw----------//

glBegin(GL_TRIANGLES);
glColor3ub(105, 105, 105);

glVertex2i(510,430);
glVertex2i(870,430);
glVertex2i(690,530);

glColor3ub(128, 128, 128);

glVertex2i(540,430);
glVertex2i(840,430);
glVertex2i(690,565);

glColor3ub(169,169,169);

glVertex2i(565,430);
glVertex2i(815,430);
glVertex2i(690,590);

glColor3ub(192, 192, 192);
//glColor3ub(128, 128, 128);

glVertex2i(595,430);
glVertex2i(785,430);
glVertex2i(690,620);

glColor3ub(211, 211, 211);
//glColor3ub(169,169,169);

glVertex2i(620,430);
glVertex2i(760,430);
glVertex2i(690,640);

glColor3ub(220, 220, 220);
//glColor3ub(192, 192, 192);

glVertex2i(645,430);
glVertex2i(735,430);
glVertex2i(690,665);

//glColor3ub(210,220,225);
//glColor3ub(245,255,250);
glColor3ub(211, 211, 211);
glVertex2i(665,430);
glVertex2i(715,430);
glVertex2i(690,685);

glColor3ub(178,34,34);

glVertex2i(670,430);
glVertex2i(710,430);
glVertex2i(690,450);

glEnd();
}

void memorial_front_border()
{
    //-------------------Memorial Front border----------------------


glBegin(GL_QUADS);
//green grass area
//up part
if(night)
    glColor3ub(13, 124, 9);//Night
else if(!night && sun_sky< -90)
//    glColor3ub(228, 246, 62);//Morning & Evening
glColor3ub(31, 246, 31);//Morning & Evening

else
    glColor3ub(0, 204, 0);//Day

glVertex2i(330,430);
glVertex2i(1050,430);

//Down part
if(night)
    glColor3ub(46, 70, 0);//Night
else if(!night && sun_sky< -90)
    glColor3ub(46, 70, 0);//Morning & Evening
else
    glColor3ub(46, 70, 0);//Day

glVertex2i(1050,255);
glVertex2i(325,255);

//border
glColor3ub(255,69,0);
//glColor3ub(176,31,2);

glVertex2i(330,430);
glVertex2i(1050,430);
glVertex2i(1052,415);
glVertex2i(328,415);

glVertex2i(328,415);
glVertex2i(340,415);
glVertex2i(325,255);
glVertex2i(310,255);

glVertex2i(1040,415);
glVertex2i(1052,415);
glVertex2i(1058,255);
glVertex2i(1043,255);

glVertex2i(325,270);
glVertex2i(1050,270);
glVertex2i(1050,255);
glVertex2i(325,255);

glEnd();
}

void memorial_lake()
{
//--------------------Memorial Lake Border------------//
glBegin(GL_QUADS);
glColor3ub(255,69,0);
//glColor3ub(176,31,2);


glVertex2i(540,415);
glVertex2i(840,415);
glVertex2i(870,255);
glVertex2i(510,255);

glColor3ub(178,34,34);
glVertex2i(555,415);
glVertex2i(825,415);
glVertex2i(851,270);
glVertex2i(529,270);

//-----------Lake-----------//
glColor3ub(169,169,169);
glVertex2i(560,410);
glVertex2i(820,410);
glVertex2i(845,275);
glVertex2i(535,275);

//Lake color adjustment
if(night)
    glColor3ub(51,51,255);//Night
else if(!night && sun_sky< -90)
    glColor3ub(30,144,255);//Morning & Evening
else
    glColor3ub(102, 255, 255);//Day

glVertex2i(565,405);
glVertex2i(815,405);

if(night)
    glColor3ub(0, 42, 104);//Night
else if(!night && sun_sky< -90)
    glColor3ub(25,25,112);//Morning & Evening
else
    glColor3ub(0,0,205);//Day

glVertex2i(837,280);
glVertex2i(543,280);

glEnd();
}

void memorial_flag()
{
//--------------------FLAG-2------------//
glBegin(GL_QUADS);
glColor3ub(0, 0, 0);
     glVertex2i(740,530);      //flag-2
     glVertex2i(743,530);
     glVertex2i(743,415);
     glVertex2i(740,415);

     glEnd();
     if (!night)
     {
     glBegin(GL_QUADS);
     glColor3ub(0,106,78);
     glVertex2i(743,530);      //flag-2-green
     glVertex2i(790,530);
     glVertex2i(790,500);
     glVertex2i(743,500);

    glEnd();

    glBegin(GL_POLYGON);            //flag-2-cir
    glColor3ub(244,42,65);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(765+cos(angle)*9,515+sin(angle)*9);
    }
    glEnd();
    }

}

//------------------------Human Shapes--------------------//
void human_field()//created (Maximum) 25 humans on the field
{

//-------------------------Based on Human 1-----------------//
    for(int pq=0;pq<human_no;pq++)
        {
            field_speed[0]=2;
            if (human_count==pq)
            {
            field_x[human_count]=(rand()%(309+1-0))+0;
            field_y[human_count]=(rand()%(213+1-0))+0;
            field_speed[human_count+1]=((rand()%(40+1-10))+10)/10;
            head_left[human_count] = (rand()%(1+1-0)+0);

            human_count++;
            }
        }
        sort(field_y, field_y + human_count);// To create one human after another gradually

    for(int a= 0; a < human_count; a++)
        {
    glPushMatrix();
    glTranslatef(8-411+field_x[a], 392-272-field_y[a], 0.0);

    if(head_left[a]==1){
    glBegin(GL_POLYGON);    //Face Left
    glColor3ub(255, 233, 209);
    glVertex2i(400,390);
    glVertex2i(405,395);
    glVertex2i(413,395);
    glVertex2i(413,383);
    glVertex2i(410,383);
    glVertex2i(410,385);
    glVertex2i(405,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(405+cos(angle)*1,392+sin(angle)*1);
    }
    glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(405,400);
    glVertex2i(413,400);
    glVertex2i(413,395);
    glVertex2i(402,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(408,357);
    glVertex2i(401,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(416,357);
    glVertex2i(410.5,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(401,378);
    glVertex2i(406,378);
    glVertex2i(399,370);
    glVertex2i(396,370);}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand at night
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();

    //Flag on left hand
    if(!night){
    glBegin(GL_QUADS);      //left-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(397,412);
    glVertex2i(398,412);
    glVertex2i(398,370);
    glVertex2i(397,370);
    glEnd();

    glBegin(GL_QUADS);      //left-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(398,412);
    glVertex2i(414,412);
    glVertex2i(414,402);
    glVertex2i(398,402);
    glEnd();

    glBegin(GL_POLYGON);   //left-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(406+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }

    if(head_left[a]==0){
    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(423,390);
    glVertex2i(418,395);
    glVertex2i(409,395);
    glVertex2i(409,383);
    glVertex2i(413,383);
    glVertex2i(413,385);
    glVertex2i(418,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye right side
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(417+cos(angle)*1,392+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair right side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(409,400);
    glVertex2i(417,400);
    glVertex2i(420,395);
    glVertex2i(409,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(410,357);
    glVertex2i(404,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(418,357);
    glVertex2i(412,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side
    glVertex2i(415,378);
    glVertex2i(420,378);
    glVertex2i(425,370);
    glVertex2i(422,370);
    glEnd();}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side at night
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand right side
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);
    glEnd();

    //Flag on right hand
    if(!night){
    glBegin(GL_QUADS);      //right-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(423,412);
    glVertex2i(424,412);
    glVertex2i(424,370);
    glVertex2i(423,370);
    glEnd();

    glBegin(GL_QUADS);      //right-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(407,412);
    glVertex2i(423,412);
    glVertex2i(423,402);
    glVertex2i(407,402);
    glEnd();

    glBegin(GL_POLYGON);   //right-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(415+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }


    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[a],color_g[a],color_b[a]);
    glVertex2i(405,383);
    glVertex2i(416,383);
    glVertex2i(422,378);
    glVertex2i(416,375);
    glVertex2i(416,360);
    glVertex2i(413,360);
    glVertex2i(410,367);
    glVertex2i(408,360);
    glVertex2i(405,360);
    glVertex2i(405,375);
    glVertex2i(400,378);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(405,371);
    glVertex2i(416,371);
    glVertex2i(416,369);
    glVertex2i(405,369);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(407,383);
    glVertex2i(408,383);
    glVertex2i(408,370);
    glVertex2i(407,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(413,383);
    glVertex2i(414,383);
    glVertex2i(414,370);
    glVertex2i(413,370);
    glEnd();


    glPopMatrix();
        }

}

void human1()
{
//-------------------------Human 1-----------------//
    glPushMatrix();
    //glTranslatef(walk1, 15.0, 0.0);
    glTranslatef(walk1, 0.0, 0.0);

    if(head_left1){
    glBegin(GL_POLYGON);    //Face Left
    glColor3ub(255, 233, 209);
    glVertex2i(400,390);
    glVertex2i(405,395);
    glVertex2i(413,395);
    glVertex2i(413,383);
    glVertex2i(410,383);
    glVertex2i(410,385);
    glVertex2i(405,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(405+cos(angle)*1,392+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(405,400);
    glVertex2i(413,400);
    glVertex2i(413,395);
    glVertex2i(402,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(408,357);
    glVertex2i(401,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(416,357);
    glVertex2i(410.5,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(401,378);
    glVertex2i(406,378);
    glVertex2i(399,370);
    glVertex2i(396,370);}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand at night
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();

    //Flag on left hand
    if(!night){
    glBegin(GL_QUADS);      //left-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(397,412);
    glVertex2i(398,412);
    glVertex2i(398,370);
    glVertex2i(397,370);
    glEnd();

    glBegin(GL_QUADS);      //left-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(398,412);
    glVertex2i(414,412);
    glVertex2i(414,402);
    glVertex2i(398,402);
    glEnd();

    glBegin(GL_POLYGON);   //left-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(406+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }

    if(!head_left1){
    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(423,390);
    glVertex2i(418,395);
    glVertex2i(409,395);
    glVertex2i(409,383);
    glVertex2i(413,383);
    glVertex2i(413,385);
    glVertex2i(418,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye right side
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(417+cos(angle)*1,392+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair right side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(409,400);
    glVertex2i(417,400);
    glVertex2i(420,395);
    glVertex2i(409,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(410,357);
    glVertex2i(404,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(418,357);
    glVertex2i(412,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side
    glVertex2i(415,378);
    glVertex2i(420,378);
    glVertex2i(425,370);
    glVertex2i(422,370);
    glEnd();}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side at night
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand right side
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);
    glEnd();

    //Flag on right hand
    if(!night){
    glBegin(GL_QUADS);      //right-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(423,412);
    glVertex2i(424,412);
    glVertex2i(424,370);
    glVertex2i(423,370);
    glEnd();

    glBegin(GL_QUADS);      //right-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(407,412);
    glVertex2i(423,412);
    glVertex2i(423,402);
    glVertex2i(407,402);
    glEnd();

    glBegin(GL_POLYGON);   //right-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(415+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }


    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[1],color_g[1],color_b[1]);
    glVertex2i(405,383);
    glVertex2i(416,383);
    glVertex2i(422,378);
    glVertex2i(416,375);
    glVertex2i(416,360);
    glVertex2i(413,360);
    glVertex2i(410,367);
    glVertex2i(408,360);
    glVertex2i(405,360);
    glVertex2i(405,375);
    glVertex2i(400,378);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(405,371);
    glVertex2i(416,371);
    glVertex2i(416,369);
    glVertex2i(405,369);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(407,383);
    glVertex2i(408,383);
    glVertex2i(408,370);
    glVertex2i(407,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(413,383);
    glVertex2i(414,383);
    glVertex2i(414,370);
    glVertex2i(413,370);
    glEnd();


    glPopMatrix();

}

void human2()
{
//--------------------------Human 2---------//

    glPushMatrix();
    glTranslatef(walk2, -20.0, 0.0);

    if(head_left2){

    glBegin(GL_POLYGON);    //Face-left
    glColor3ub(255, 233, 209);
    glVertex2i(380,350);
    glVertex2i(385,355);
    glVertex2i(394,355);
    glVertex2i(394,343);
    glVertex2i(390,343);
    glVertex2i(390,345);
    glVertex2i(385,345);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(385+cos(angle)*1,352+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(382,360);
    glVertex2i(394,360);
    glVertex2i(394,355);
    glVertex2i(384,355);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(384,320);
    glVertex2i(388,320);
    glVertex2i(388,317);
    glVertex2i(382.5,317);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(392,320);
    glVertex2i(396,320);
    glVertex2i(396,317);
    glVertex2i(390.5,317);
    glEnd();
    }

if(!head_left2){
    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(404,350);
    glVertex2i(399,355);
    glVertex2i(390,355);
    glVertex2i(390,343);
    glVertex2i(394,343);
    glVertex2i(394,345);
    glVertex2i(399,345);
    glEnd();

    glBegin(GL_POLYGON);  //Eye other side
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(398+cos(angle)*1,352+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair other side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(390,360);
    glVertex2i(401,360);
    glVertex2i(399,355);
    glVertex2i(390,355);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(384,320);
    glVertex2i(388,320);
    glVertex2i(390,317);
    glVertex2i(384,317);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(392,320);
    glVertex2i(396,320);
    glVertex2i(398,317);
    glVertex2i(392.5,317);
    glEnd();
}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(381,338);
    glVertex2i(384,338);
    glVertex2i(384,329);
    glVertex2i(381,329);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(397,338);
    glVertex2i(400,338);
    glVertex2i(400,329);
    glVertex2i(397,329);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[2],color_g[2],color_b[2]);

    glVertex2i(385,343);
    glVertex2i(396,343);
    glVertex2i(402,338);
    glVertex2i(396,335);
    glVertex2i(396,320);
    glVertex2i(393,320);
    glVertex2i(390,327);
    glVertex2i(388,320);
    glVertex2i(385,320);
    glVertex2i(385,335);
    glVertex2i(380,338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(385,330);
    glVertex2i(396,330);
    glVertex2i(396,328);
    glVertex2i(385,328);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(395,343);
    glVertex2i(397,343);
    glVertex2i(387,329);
    glVertex2i(385,329);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(384,343);
    glVertex2i(386,343);
    glVertex2i(396,329);
    glVertex2i(394,329);
    glEnd();


    glPopMatrix();
}

void human_heli()
{
//--------------------------Human heli---------//
    glPushMatrix();
    glTranslatef(walk_heli, 0.0, 0.0);

    if(pilot_onboard){
    glPushMatrix();
    glTranslatef(0.0, fly, 0.0);

    //Human face in the pilot seat of the helicopter

    glBegin(GL_POLYGON);    //Face-left pilot
    glColor3ub(255, 233, 209);
    glVertex2i(855,415);
    glVertex2i(860,420);
    glVertex2i(869,420);
    //glVertex2i(869,408);
    //glVertex2i(865,408);
    glVertex2i(869,412);
    glVertex2i(867,410);
    glVertex2i(860,410);
    glEnd();

    glBegin(GL_POLYGON);  //Eye with sun-glass
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(859+cos(angle)*2.5,417+sin(angle)*2);
    }
    glEnd();

glBegin(GL_POLYGON);  //headphone
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(866+cos(angle)*2.5,419+sin(angle)*4.5);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(860,420);
    glVertex2i(869,420);
    glVertex2i(869,425);
    glVertex2i(857,425);
    glEnd();

    glPopMatrix();
    }

    else if(!pilot_onboard){
    if(!head_left_heli){

    glBegin(GL_POLYGON);    //Face-right
    glColor3ub(255, 233, 209);
    glVertex2i(912,360);
    glVertex2i(908,365);
    glVertex2i(899,365);
    glVertex2i(899,353);
    glVertex2i(902,353);
    glVertex2i(902,355);
    glVertex2i(908,355);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(906+cos(angle)*1,362+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(899,370);
    glVertex2i(910,370);
    glVertex2i(908,365);
    glVertex2i(899,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(895,330);
    glVertex2i(899,330);
    glVertex2i(902,327);
    glVertex2i(895,327);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(903,330);
    glVertex2i(906,330);
    glVertex2i(909,327);
    glVertex2i(903,327);
    glEnd();
    }

    if(head_left_heli){
    glBegin(GL_POLYGON);    //Face other side
    glColor3ub(255, 233, 209);
    glVertex2i(889,360);
    glVertex2i(894,365);
    glVertex2i(902,365);
    glVertex2i(902,353);
    glVertex2i(899,353);
    glVertex2i(899,355);
    glVertex2i(894,355);
    glEnd();

    glBegin(GL_POLYGON);  //Eye other side
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(895+cos(angle)*1,362+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair other side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(892,370);
    glVertex2i(902,370);
    glVertex2i(902,365);
    glVertex2i(894,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(895,330);
    glVertex2i(899,330);
    glVertex2i(899,327);
    glVertex2i(892,327);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(903,330);
    glVertex2i(906,330);
    glVertex2i(906,327);
    glVertex2i(900,327);
    glEnd();

    }

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(891,348);
    glVertex2i(894,348);
    glVertex2i(894,339);
    glVertex2i(891,339);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(907,348);
    glVertex2i(910,348);
    glVertex2i(910,339);
    glVertex2i(907,339);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[50],color_g[50],color_b[50]);
    glVertex2i(895,353);
    glVertex2i(906,353);
    glVertex2i(912,348);
    glVertex2i(906,345);
    glVertex2i(906,330);
    glVertex2i(903,330);
    glVertex2i(900,337);
    glVertex2i(898,330);
    glVertex2i(895,330);
    glVertex2i(895,345);
    glVertex2i(890,348);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(895,340);
    glVertex2i(906,340);
    glVertex2i(906,338);
    glVertex2i(895,338);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(905,353);
    glVertex2i(906,353);
    glVertex2i(896,339);
    glVertex2i(895,339);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(895,353);
    glVertex2i(896,353);
    glVertex2i(906,339);
    glVertex2i(905,339);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(896,353);
    glVertex2i(897,353);
    glVertex2i(897,339);
    glVertex2i(896,339);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(904,353);
    glVertex2i(905,353);
    glVertex2i(905,339);
    glVertex2i(904,339);
    glEnd();


    }
    glPopMatrix();
}

void human3()
{
//--------------------------Human 3---------//
    glPushMatrix();
    glTranslatef(walk3, 0.0, 0.0);

    if(head_left3){

    glBegin(GL_POLYGON);    //Face left
    glColor3ub(255, 233, 209);
    glVertex2i(870,400);
    glVertex2i(875,405);
    glVertex2i(883,405);
    glVertex2i(883,393);
    glVertex2i(880,393);
    glVertex2i(880,395);
    glVertex2i(875,395);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(875+cos(angle)*1,402+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(875,410);
    glVertex2i(883,410);
    glVertex2i(883,405);
    glVertex2i(872,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(874,370);
    glVertex2i(878,370);
    glVertex2i(878,367);
    glVertex2i(872.5,367);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(882,370);
    glVertex2i(886,370);
    glVertex2i(886,367);
    glVertex2i(880.5,367);
    glEnd();
    }

    if(!head_left3){

    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(893,400);
    glVertex2i(888,405);
    glVertex2i(880,405);
    glVertex2i(880,393);
    glVertex2i(883,393);
    glVertex2i(883,395);
    glVertex2i(888,395);
    glEnd();

    glBegin(GL_POLYGON);  //Eye other side
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(887+cos(angle)*1,402+sin(angle)*1);
    }
    glEnd();

    glBegin(GL_QUADS);   //Hair other side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(880,410);
    glVertex2i(886,410);
    glVertex2i(889,405);
    glVertex2i(880,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(874,370);
    glVertex2i(878,370);
    glVertex2i(880,367);
    glVertex2i(874,367);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(882,370);
    glVertex2i(886,370);
    glVertex2i(888,367);
    glVertex2i(882,367);
    glEnd();
    }


    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(871,388);
    glVertex2i(874,388);
    glVertex2i(874,379);
    glVertex2i(871,379);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(887,388);
    glVertex2i(890,388);
    glVertex2i(890,379);
    glVertex2i(887,379);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[3],color_g[3],color_b[3]);

    glVertex2i(875,393);
    glVertex2i(886,393);
    glVertex2i(892,388);
    glVertex2i(886,385);
    glVertex2i(886,370);
    glVertex2i(883,370);
    glVertex2i(880,377);
    glVertex2i(878,370);
    glVertex2i(875,370);
    glVertex2i(875,385);
    glVertex2i(870,388);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(875,381);
    glVertex2i(886,381);
    glVertex2i(886,379);
    glVertex2i(875,379);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(877,393);
    glVertex2i(878,393);
    glVertex2i(878,380);
    glVertex2i(877,380);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(883,393);
    glVertex2i(884,393);
    glVertex2i(884,380);
    glVertex2i(883,380);
    glEnd();


    glPopMatrix();
}

void human_walking()
{
//--------------------------Human walking on road---------//
    glPushMatrix();
    glTranslatef(walk, 0.0, 0.0);

    glBegin(GL_POLYGON);    //Face
    glColor3ub(255, 233, 209);
    glVertex2i(62,275);
    glVertex2i(58,280);
    glVertex2i(48,280);
    glVertex2i(48,268);
    glVertex2i(52,268);
    glVertex2i(52,270);
    glVertex2i(58,270);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(56+cos(angle)*1,277+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(48,285);
    glVertex2i(60,285);
    glVertex2i(58,280);
    glVertex2i(48,280);
    glEnd();


//    glBegin(GL_POLYGON);    //Face other side
//    glColor3ub(255, 233, 209);
//    glVertex2i(38,275);
//    glVertex2i(43,280);
//    glVertex2i(52,280);
//    glVertex2i(52,268);
//    glVertex2i(48,268);
//    glVertex2i(48,270);
//    glVertex2i(43,270);
//    glEnd();
//
//    glBegin(GL_POLYGON);  //Eye other side
//    glColor3ub(10, 10, 10);
//  for(int i=0;i<=360;i++)
//    {
//    float angle= i*3.1416/180;
//    glVertex2f(43+cos(angle)*1,277+sin(angle)*1);
//    }
//glEnd();
//
//    glBegin(GL_QUADS);   //Hair other side
//    //glColor3ub(75, 83, 32);
//    glColor3ub(40, 40, 40);
//    glVertex2i(41,285);
//    glVertex2i(52,285);
//    glVertex2i(52,280);
//    glVertex2i(43,280);
//    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(41,263);
    glVertex2i(44,263);
    glVertex2i(44,254);
    glVertex2i(41,254);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(57,263);
    glVertex2i(60,263);
    glVertex2i(60,254);
    glVertex2i(57,254);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[0],color_g[0],color_b[0]);

    glVertex2i(45,268);
    glVertex2i(56,268);
    glVertex2i(62,263);
    glVertex2i(56,260);
    glVertex2i(56,245);
    glVertex2i(53,245);
    glVertex2i(50,252);
    glVertex2i(48,245);
    glVertex2i(45,245);
    glVertex2i(45,260);
    glVertex2i(40,263);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(45,256);
    glVertex2i(56,256);
    glVertex2i(56,253);
    glVertex2i(45,253);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(54,268);
    glVertex2i(56,268);
    glVertex2i(47,254);
    glVertex2i(45,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(45,268);
    glVertex2i(47,268);
    glVertex2i(56,254);
    glVertex2i(54,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(46,268);
    glVertex2i(47,268);
    glVertex2i(47,254);
    glVertex2i(46,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(54,268);
    glVertex2i(55,268);
    glVertex2i(55,254);
    glVertex2i(54,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(45,245);
    glVertex2i(49,245);
    glVertex2i(52,242);
    glVertex2i(45,242);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(53,245);
    glVertex2i(57,245);
    glVertex2i(59,242);
    glVertex2i(53,242);
    glEnd();

    glPopMatrix();

}

void human_walking_back()
{
//--------------------------Human walking on road---------//
    glPushMatrix();
    glTranslatef(walk_back+1210, -8.0, 0.0);

//    glBegin(GL_POLYGON);    //Face
//    glColor3ub(255, 233, 209);
//    glVertex2i(62,275);
//    glVertex2i(58,280);
//    glVertex2i(48,280);
//    glVertex2i(48,268);
//    glVertex2i(52,268);
//    glVertex2i(52,270);
//    glVertex2i(58,270);
//    glEnd();
//
//    glBegin(GL_POLYGON);  //Eye
//    glColor3ub(10, 10, 10);
//  for(int i=0;i<=360;i++)
//    {
//    float angle= i*3.1416/180;
//    glVertex2f(56+cos(angle)*1,277+sin(angle)*1);
//    }
//glEnd();
//
//    glBegin(GL_QUADS);   //Hair
//    //glColor3ub(75, 83, 32);
//    glColor3ub(40, 40, 40);
//    glVertex2i(48,285);
//    glVertex2i(60,285);
//    glVertex2i(58,280);
//    glVertex2i(48,280);
//    glEnd();


    glBegin(GL_POLYGON);    //Face other side
    glColor3ub(255, 233, 209);
    glVertex2i(38,275);
    glVertex2i(43,280);
    glVertex2i(52,280);
    glVertex2i(52,268);
    glVertex2i(48,268);
    glVertex2i(48,270);
    glVertex2i(43,270);
    glEnd();

    glBegin(GL_POLYGON);  //Eye other side
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(43+cos(angle)*1,277+sin(angle)*1);
    }
    glEnd();

    glBegin(GL_QUADS);   //Hair other side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(41,285);
    glVertex2i(52,285);
    glVertex2i(52,280);
    glVertex2i(43,280);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(41,263);
    glVertex2i(44,263);
    glVertex2i(44,254);
    glVertex2i(41,254);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(57,263);
    glVertex2i(60,263);
    glVertex2i(60,254);
    glVertex2i(57,254);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[10],color_g[10],color_b[10]);

    glVertex2i(45,268);
    glVertex2i(56,268);
    glVertex2i(62,263);
    glVertex2i(56,260);
    glVertex2i(56,245);
    glVertex2i(53,245);
    glVertex2i(50,252);
    glVertex2i(48,245);
    glVertex2i(45,245);
    glVertex2i(45,260);
    glVertex2i(40,263);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(45,256);
    glVertex2i(56,256);
    glVertex2i(56,253);
    glVertex2i(45,253);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(54,268);
    glVertex2i(56,268);
    glVertex2i(47,254);
    glVertex2i(45,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(45,268);
    glVertex2i(47,268);
    glVertex2i(56,254);
    glVertex2i(54,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(46,268);
    glVertex2i(47,268);
    glVertex2i(47,254);
    glVertex2i(46,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(54,268);
    glVertex2i(55,268);
    glVertex2i(55,254);
    glVertex2i(54,254);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(44,245);
    glVertex2i(48,245);
    glVertex2i(48,242);
    glVertex2i(42,242);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(52,245);
    glVertex2i(56,245);
    glVertex2i(56,242);
    glVertex2i(50,242);
    glEnd();

    glPopMatrix();

}

void human_boat()
{
//-------------------------Human boat-----------------//
    glPushMatrix();
    glTranslatef(304-410, 386-699, 0.0);

//
//    glBegin(GL_POLYGON);    //Face Left
//    glColor3ub(255, 233, 209);
//    glVertex2i(400,390);
//    glVertex2i(405,395);
//    glVertex2i(413,395);
//    glVertex2i(413,383);
//    glVertex2i(410,383);
//    glVertex2i(410,385);
//    glVertex2i(405,385);
//    glEnd();
//
//    glBegin(GL_POLYGON);  //Eye
//    glColor3ub(10, 10, 10);
//    for(int i=0;i<=360;i++)
//    {
//    float angle= i*3.1416/180;
//    glVertex2f(405+cos(angle)*1,392+sin(angle)*1);
//    }
//    glEnd();
//
//    glBegin(GL_QUADS);   //Hair
//    //glColor3ub(75, 83, 32);
//    glColor3ub(40, 40, 40);
//    glVertex2i(405,400);
//    glVertex2i(413,400);
//    glVertex2i(413,395);
//    glVertex2i(402,395);
//    glEnd();


    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(423,390);
    glVertex2i(418,395);
    glVertex2i(410,395);
    glVertex2i(410,383);
    glVertex2i(413,383);
    glVertex2i(413,385);
    glVertex2i(418,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye right side
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(417+cos(angle)*1,392+sin(angle)*1);
    }
    glEnd();

    glBegin(GL_QUADS);   //Hair right side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(410,400);
    glVertex2i(417,400);
    glVertex2i(420,395);
    glVertex2i(410,395);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(color_r[11],color_g[10],color_b[9]);
    glVertex2i(405,383);
    glVertex2i(416,383);
    glVertex2i(422,378);
    glVertex2i(416,375);
    glVertex2i(416,360);
    glVertex2i(413,360);
    glVertex2i(410,367);
    glVertex2i(408,360);
    glVertex2i(405,360);
    glVertex2i(405,375);
    glVertex2i(400,378);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(405,371);
    glVertex2i(416,371);
    glVertex2i(416,369);
    glVertex2i(405,369);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(407,383);
    glVertex2i(408,383);
    glVertex2i(408,370);
    glVertex2i(407,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(413,383);
    glVertex2i(414,383);
    glVertex2i(414,370);
    glVertex2i(413,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(408,357);
    glVertex2i(402.5,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(416,357);
    glVertex2i(410.5,357);
    glEnd();

    glPopMatrix();

}

void human_jeep()
{
//-------------------------Human jeep-----------------//
    glPushMatrix();
    glTranslatef(237-411, 373-570, 0.0);

//
//    glBegin(GL_POLYGON);    //Face Left
//    glColor3ub(255, 233, 209);
//    glVertex2i(400,390);
//    glVertex2i(405,395);
//    glVertex2i(413,395);
//    glVertex2i(413,383);
//    glVertex2i(410,383);
//    glVertex2i(410,385);
//    glVertex2i(405,385);
//    glEnd();
//
//    glBegin(GL_POLYGON);  //Eye
//    glColor3ub(10, 10, 10);
//    for(int i=0;i<=360;i++)
//    {
//    float angle= i*3.1416/180;
//    glVertex2f(405+cos(angle)*1,392+sin(angle)*1);
//    }
//    glEnd();
//
//    glBegin(GL_QUADS);   //Hair
//    //glColor3ub(75, 83, 32);
//    glColor3ub(40, 40, 40);
//    glVertex2i(405,400);
//    glVertex2i(413,400);
//    glVertex2i(413,395);
//    glVertex2i(402,395);
//    glEnd();


    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(423,390);
    glVertex2i(418,395);
    glVertex2i(410,395);
    glVertex2i(410,383);
    glVertex2i(413,383);
    glVertex2i(413,385);
    glVertex2i(418,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye right side
    glColor3ub(10, 10, 10);
    for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(417+cos(angle)*1,392+sin(angle)*1);
    }
    glEnd();

    glBegin(GL_QUADS);   //Hair right side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(410,400);
    glVertex2i(417,400);
    glVertex2i(420,395);
    glVertex2i(410,395);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();

    glBegin(GL_POLYGON);   //Body
    glColor3ub(255,0,0);
    glVertex2i(405,383);
    glVertex2i(416,383);
    glVertex2i(422,378);
    glVertex2i(416,375);
    glVertex2i(416,360);
    glVertex2i(413,360);
    glVertex2i(410,367);
    glVertex2i(408,360);
    glVertex2i(405,360);
    glVertex2i(405,375);
    glVertex2i(400,378);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(405,371);
    glVertex2i(416,371);
    glVertex2i(416,369);
    glVertex2i(405,369);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(407,383);
    glVertex2i(408,383);
    glVertex2i(408,370);
    glVertex2i(407,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(413,383);
    glVertex2i(414,383);
    glVertex2i(414,370);
    glVertex2i(413,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(408,357);
    glVertex2i(402.5,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(416,357);
    glVertex2i(410.5,357);
    glEnd();

    glPopMatrix();

}

void human_building_front()
{
//-------------------------Human watchtower-----------------//
    glPushMatrix();
    glTranslatef(walk_building_front+901-410, 350-250, 0.0);

    if(head_left_building_front){
    glBegin(GL_POLYGON);    //Face Left
    glColor3ub(255, 233, 209);
    glVertex2i(400,390);
    glVertex2i(405,395);
    glVertex2i(413,395);
    glVertex2i(413,383);
    glVertex2i(410,383);
    glVertex2i(410,385);
    glVertex2i(405,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(405+cos(angle)*1,392+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(405,400);
    glVertex2i(413,400);
    glVertex2i(413,395);
    glVertex2i(402,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(408,357);
    glVertex2i(401,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(416,357);
    glVertex2i(410,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand
    glVertex2i(401,378);
    glVertex2i(406,378);
    glVertex2i(399,370);
    glVertex2i(396,370);}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand at night
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();

    //Flag on left hand
    if(!night){
    glBegin(GL_QUADS);      //left-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(397,412);
    glVertex2i(398,412);
    glVertex2i(398,370);
    glVertex2i(397,370);
    glEnd();

    glBegin(GL_QUADS);      //left-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(398,412);
    glVertex2i(414,412);
    glVertex2i(414,402);
    glVertex2i(398,402);
    glEnd();

    glBegin(GL_POLYGON);   //left-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(406+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }

    if(!head_left_building_front){
    glBegin(GL_POLYGON);    //Face right
    glColor3ub(255, 233, 209);
    glVertex2i(423,390);
    glVertex2i(418,395);
    glVertex2i(409,395);
    glVertex2i(409,383);
    glVertex2i(413,383);
    glVertex2i(413,385);
    glVertex2i(418,385);
    glEnd();

    glBegin(GL_POLYGON);  //Eye right side
    glColor3ub(10, 10, 10);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(417+cos(angle)*1,392+sin(angle)*1);
    }
glEnd();

    glBegin(GL_QUADS);   //Hair right side
    //glColor3ub(75, 83, 32);
    glColor3ub(40, 40, 40);
    glVertex2i(409,400);
    glVertex2i(417,400);
    glVertex2i(420,395);
    glVertex2i(409,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Left shoe
    glVertex2i(404,360);
    glVertex2i(408,360);
    glVertex2i(410,357);
    glVertex2i(404,357);

    glColor3ub(10, 10, 10);   //Right shoe
    glVertex2i(412,360);
    glVertex2i(416,360);
    glVertex2i(418,357);
    glVertex2i(412,357);
    glEnd();

    if(!night){
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side
    glVertex2i(415,378);
    glVertex2i(420,378);
    glVertex2i(425,370);
    glVertex2i(422,370);
    glEnd();}

    else{
    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Right hand right side at night
    glVertex2i(417,378);
    glVertex2i(420,378);
    glVertex2i(420,369);
    glVertex2i(417,369);
    glEnd();}

    glBegin(GL_QUADS);
    glColor3ub(255, 233, 209);   //Left hand right side
    glVertex2i(401,378);
    glVertex2i(404,378);
    glVertex2i(404,369);
    glVertex2i(401,369);
    glEnd();

    //Flag on right hand
    if(!night){
    glBegin(GL_QUADS);      //right-hand-flag
    glColor3ub(10, 10, 10);
    glVertex2i(423,412);
    glVertex2i(424,412);
    glVertex2i(424,370);
    glVertex2i(423,370);
    glEnd();

    glBegin(GL_QUADS);      //right-hand-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(407,412);
    glVertex2i(423,412);
    glVertex2i(423,402);
    glVertex2i(407,402);
    glEnd();

    glBegin(GL_POLYGON);   //right-hand-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(415+cos(angle)*3,407+sin(angle)*3);
    }
    glEnd();
    }
    }

    glBegin(GL_POLYGON);   //Body
    glColor3ub(255,102,255);
    glVertex2i(405,383);
    glVertex2i(416,383);
    glVertex2i(422,378);
    glVertex2i(416,375);
    glVertex2i(416,360);
    glVertex2i(413,360);
    glVertex2i(410,367);
    glVertex2i(408,360);
    glVertex2i(405,360);
    glVertex2i(405,375);
    glVertex2i(400,378);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //Belt
    glVertex2i(405,371);
    glVertex2i(416,371);
    glVertex2i(416,369);
    glVertex2i(405,369);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(407,383);
    glVertex2i(408,383);
    glVertex2i(408,370);
    glVertex2i(407,370);

    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);   //stripes
    glVertex2i(413,383);
    glVertex2i(414,383);
    glVertex2i(414,370);
    glVertex2i(413,370);
    glEnd();

    glPopMatrix();

}

//------------------------Human Shapes end--------------------//

void heli()
{
    glPushMatrix();
    glTranslatef(0.0, fly, 0.0);


    glBegin(GL_QUADS);      //glass
    glColor3ub(100, 255, 255);
    glVertex2i(1025,410);
    glVertex2i(1060,410);
    glVertex2i(1067,437);
    glVertex2i(1039,426);
    glEnd();

    glBegin(GL_POLYGON);   //body
    //glColor3ub(75, 73, 32);
    glColor3ub(200, 50, 50);
    glVertex2i(1055,380);
    glVertex2i(1045,380);
    glVertex2i(1025,390);
    glVertex2i(1020,400);
    glVertex2i(1025,410);
    glVertex2i(1050,410);
    glVertex2i(1060,422);
    glVertex2i(1065,435);
    glVertex2i(1150,435);
    glVertex2i(1175,420);
    glVertex2i(1250,420);
    glVertex2i(1250,410);
    glVertex2i(1210,405);
    glVertex2i(1180,397);
    glVertex2i(1155,380);
    glEnd();

    glBegin(GL_QUADS);   //tail upper part
    //glColor3ub(75, 73, 32);
    glColor3ub(240, 30, 30);
    glVertex2i(1235,420);
    glVertex2i(1253,440);
    glVertex2i(1260,440);
    glVertex2i(1250,420);

    glBegin(GL_QUADS);   //tail lower part
    //glColor3ub(75, 73, 32);
    glColor3ub(240, 30, 30);
    glVertex2i(1235,410);
    glVertex2i(1250,410);
    glVertex2i(1258,398);
    glVertex2i(1250,398);

    glBegin(GL_QUADS);   //tail end part
    //glColor3ub(75, 73, 32);
    glColor3ub(200, 50, 50);
    glVertex2i(1250,420);
    glVertex2i(1260,417);
    glVertex2i(1260,413);
    glVertex2i(1250,410);

    //Flag on heli
    if(!night){
    glBegin(GL_QUADS);      //heli-flag-green
    glColor3ub(0, 106, 78);
    glVertex2i(1180,417);
    glVertex2i(1200,417);
    glVertex2i(1200,405);
    glVertex2i(1180,405);
    glEnd();

    glBegin(GL_POLYGON);   //heli-flag-cir
    glColor3ub(244, 42, 65);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(1190+cos(angle)*4,411+sin(angle)*4);
    }
    glEnd();
    }

    //body design start
    glBegin(GL_QUADS);
    glColor3ub(50, 255, 255);
    glVertex2i(1030,405);
    glVertex2i(1165,405);
    glVertex2i(1165,395);
    glVertex2i(1030,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 106, 78);
    glVertex2i(1030,403);
    glVertex2i(1165,403);
    glVertex2i(1165,401);
    glVertex2i(1030,401);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(244, 42, 65);
    glVertex2i(1030,399);
    glVertex2i(1165,399);
    glVertex2i(1165,397);
    glVertex2i(1030,397);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 130, 56);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(1030+cos(angle)*6,400+sin(angle)*6);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(112, 130, 56);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(1165+cos(angle)*6,400+sin(angle)*6);
    }
    glEnd();
    //body design end

    glBegin(GL_QUADS);      //door
    //glColor3ub(112, 130, 56);
    glColor3ub(240, 30, 30);
    glVertex2i(1065,425);
    glVertex2i(1095,425);
    glVertex2i(1095,380);
    glVertex2i(1065,380);
    glEnd();

    glBegin(GL_QUADS);      //door window
    glColor3ub(100, 255, 255);
    glVertex2i(1070,420);
    glVertex2i(1090,420);
    glVertex2i(1090,405);
    glVertex2i(1070,405);
    glEnd();

    glBegin(GL_QUADS);      //door handle
    //glColor3ub(75, 73, 32);
    glColor3ub(200, 50, 50);
    glVertex2i(1087,403);
    glVertex2i(1097,403);
    glVertex2i(1097,398);
    glVertex2i(1087,398);
    glEnd();

    glBegin(GL_QUADS);      //window 1
    glColor3ub(100, 255, 255);
    glVertex2i(1100,425);
    glVertex2i(1120,425);
    glVertex2i(1120,410);
    glVertex2i(1100,410);
    glEnd();

    glBegin(GL_QUADS);      //window 2
    glColor3ub(100, 255, 255);
    glVertex2i(1130,425);
    glVertex2i(1150,425);
    glVertex2i(1150,410);
    glVertex2i(1130,410);
    glEnd();

    glBegin(GL_QUADS);      //top
    glColor3ub(112, 130, 56);
    //glColor3ub(240, 30, 30);
    glVertex2i(1070,440);
    glVertex2i(1135,440);
    glVertex2i(1150,435);
    glVertex2i(1060,435);

    glEnd();

    glBegin(GL_QUADS);      //top blade base
    glColor3ub(129,116,96);
    glVertex2i(1095,445);
    glVertex2i(1115,445);
    glVertex2i(1115,440);
    glVertex2i(1095,440);

    glVertex2i(1100,455);
    glVertex2i(1110,455);
    glVertex2i(1110,440);
    glVertex2i(1100,440);
    glEnd();

    if(fly>0){

    glBegin(GL_QUADS);      //top blade base
    glColor3ub(129,116,96);
    glVertex2i(1095,445);
    glVertex2i(1115,445);
    glVertex2i(1115,440);
    glVertex2i(1095,440);

    glVertex2i(1100,455);
    glVertex2i(1110,455);
    glVertex2i(1110,440);
    glVertex2i(1100,440);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(90,100,100);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1105+cos(angle)*95,453+sin(angle)*15);
    }

    glEnd();
}

    if(fly<=0){
    glBegin(GL_QUADS);      //Top Blades
    glColor3ub(99,96,96);     //Top

    glVertex2i(1013,455);
    glVertex2i(1105,455);
    glVertex2i(1105,450);
    glVertex2i(1018,450);

    glVertex2i(1105,455);
    glVertex2i(1198,455);
    glVertex2i(1203,450);
    glVertex2i(1105,450);

    glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1105+cos(angle)*6,453+sin(angle)*3);
    }

    glEnd();


    glBegin(GL_QUADS);      //Landing Stand

    glColor3ub(99,96,96);

    glVertex2i(1065,365);       //1
    glVertex2i(1070,365);
    glVertex2i(1070,380);
    glVertex2i(1065,380);


    glVertex2i(1125,365);
    glVertex2i(1130,365);
    glVertex2i(1130,380);
    glVertex2i(1125,380);


    glVertex2i(1055,360);
    glVertex2i(1140,360);
    glVertex2i(1140,365);
    glVertex2i(1055,365);


    glVertex2i(1075,355);        //2
    glVertex2i(1080,355);
    glVertex2i(1080,380);
    glVertex2i(1075,380);


    glVertex2i(1135,355);
    glVertex2i(1140,355);
    glVertex2i(1140,380);
    glVertex2i(1135,380);


    glVertex2i(1065,350);
    glVertex2i(1150,350);
    glVertex2i(1150,355);
    glVertex2i(1065,355);

    glEnd();
    glPopMatrix();


}

void flower()
{
    if(!night)
    {
        for(int pq=0;pq<flower_no;pq++)
        {
            if (flower_count==pq)
            {
            flow_p[flower_count]=(rand()%(872+1-510))+510;
            flow_q[flower_count]=(rand()%(437+1-417))+417;

            color_r[flower_count]=(rand()%(255+1-0))+0;
            color_g[flower_count]=(rand()%(255+1-0))+0;
            color_b[flower_count]=(rand()%(255+1-0))+0;

            flower_count++;
            }
        }


        for(int a= 0; a < flower_no/2; a++)
        {
            glBegin(GL_POLYGON);
            //glColor3f(1.000, 1.000, 1.000);
            glColor3ub(color_r[a],color_g[a],color_b[a]);

            for(int i=0;i<=360;i++)
            {
                float angle= i*3.1416/180;
                glVertex2f(flow_p[a]+cos(angle)*6.5, flow_q[a]+sin(angle)*6.5);
            }
            glEnd();
        }
        for(int a= flower_no/2; a < flower_no; a++)
        {
            glBegin(GL_POLYGON);
            //glColor3f(1.000, 1.000, 1.000);
            glColor3ub(color_r[a],color_g[a],color_b[a]);

            for(int i=0;i<=360;i++)
            {
                float angle= i*3.1416/180;
                glVertex2f(flow_p[a]+cos(angle)*4.5, flow_q[a]+sin(angle)*4.5);
            }
            glEnd();
        }
        }
    }

void bus()
{

glPushMatrix(); //bus start pushing
glTranslatef(tri_bus, 15, 0.0);

glBegin(GL_QUADS);          //Bus

glColor3ub(245, 222, 179);

glVertex2i(950,190);
glVertex2i(1200,190);

glVertex2i(1200,190);
glVertex2i(1200,290);

glVertex2i(1200,290);
glVertex2i(965,290);

glVertex2i(950,240);
glVertex2i(950,190);


glColor3ub(222, 184, 135);

glVertex2i(970,190);
glVertex2i(1000,190);
                                   //Bus door
glVertex2i(1000,260);
glVertex2i(1000,260);

glVertex2i(1000,260);
glVertex2i(970,260);

glVertex2i(970,260);
glVertex2i(970,190);


glColor3ub(205, 133, 63);

glVertex2i(1010,225);
glVertex2i(1190,225);
                                   //Bus paint
glVertex2i(1190,225);
glVertex2i(1190,230);

glVertex2i(1190,230);
glVertex2i(1010,230);

glVertex2i(1010,230);
glVertex2i(1010,225);


glColor3ub(70, 130, 180);

glVertex2i(1010,235);
glVertex2i(1035,235);
                                   //Window1
glVertex2i(1035,235);
glVertex2i(1035,270);

glVertex2i(1035,270);
glVertex2i(1010,270);

glVertex2i(1010,270);
glVertex2i(1010,235);


glColor3ub(70, 130, 180);

glVertex2i(1043,235);
glVertex2i(1068,235);
                                   //Window2
glVertex2i(1068,235);
glVertex2i(1068,270);

glVertex2i(1068,270);
glVertex2i(1043,270);

glVertex2i(1043,270);
glVertex2i(1043,235);


glColor3ub(70, 130, 180);

glVertex2i(1076,235);
glVertex2i(1101,235);
                                   //Window3
glVertex2i(1101,235);
glVertex2i(1101,270);

glVertex2i(1101,270);
glVertex2i(1076,270);

glVertex2i(1076,270);
glVertex2i(1076,235);


glColor3ub(70, 130, 180);

glVertex2i(1109,235);
glVertex2i(1134,235);
                                   //Window4
glVertex2i(1134,235);
glVertex2i(1134,270);

glVertex2i(1134,270);
glVertex2i(1109,270);

glVertex2i(1109,270);
glVertex2i(1109,235);


glColor3ub(70, 130, 180);

glVertex2i(1142,235);
glVertex2i(1167,235);
                                   //Window5
glVertex2i(1167,235);
glVertex2i(1167,270);

glVertex2i(1167,270);
glVertex2i(1142,270);

glVertex2i(1142,270);
glVertex2i(1142,235);


glColor3ub(70, 130, 180);

glVertex2i(1175,235);
glVertex2i(1190,235);
                                   //Window6_half
glVertex2i(1190,235);
glVertex2i(1190,270);

glVertex2i(1190,270);
glVertex2i(1175,270);

glVertex2i(1175,270);
glVertex2i(1175,235);


glColor3ub(70, 130, 180);

glVertex2i(973,193);
glVertex2i(997,193);
                                   //Bus door glass
glVertex2i(997,257);
glVertex2i(997,260);

glVertex2i(997,257);
glVertex2i(973,257);

glVertex2i(973,257);
glVertex2i(973,193);



glColor3ub(85, 107, 47);

glVertex2i(990,220);
glVertex2i(1005,220);
                                   //Bus door Handle
glVertex2i(1005,220);
glVertex2i(1005,225);

glVertex2i(1005,225);
glVertex2i(990,225);

glVertex2i(990,225);
glVertex2i(990,220);


glColor3ub(85, 107, 47);

glVertex2i(1175,205);
glVertex2i(1185,205);
                                   //fuel_line
glVertex2i(1185,205);
glVertex2i(1185,215);

glVertex2i(1185,215);
glVertex2i(1175,215);

glVertex2i(1175,215);
glVertex2i(1175,205);


glColor3ub(230, 20, 20);

glVertex2i(1190,210);
glVertex2i(1200,210);
glVertex2i(1200,200);
glVertex2i(1190,200);

glEnd();

//Flag
if(!night){
    glBegin(GL_QUADS);

     glColor3ub(0,106,78);
     glVertex2i(1010,750-528);      //flag-3-green
     glVertex2i(1090,750-528);
     glVertex2i(1090,750-489);
     glVertex2i(1010,750-489);

    glEnd();

    glBegin(GL_POLYGON);            //flag-3-cir
    glColor3ub(245, 42, 65);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(1050+cos(angle)*15, 242+sin(angle)*15);
    }
    glEnd();
}



//Bus tire
//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1040+cos(angle)*30,190+sin(angle)*25);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1040+cos(angle)*19,190+sin(angle)*17);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1040+cos(angle)*9,190+sin(angle)*9);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1140+cos(angle)*30,190+sin(angle)*25);
    }
    glEnd();
//    glPopMatrix();



//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1140+cos(angle)*19,190+sin(angle)*17);
    }

    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1140+cos(angle)*9, 190+sin(angle)*9);
    }
    glEnd();
//    glPopMatrix();

    glPopMatrix();//Bus end pushing
}

void tree_middle_right()
{
    glBegin(GL_TRIANGLES);          //Tree 7 Part

glColor3ub(13, 163, 63);

glVertex2i(890,440);
glVertex2i(920,440);
glVertex2i(905,470);
glEnd();

glBegin(GL_QUADS);          //Tree 7 Part

glColor3ub(0,67,0);

glVertex2i(895,440);
glVertex2i(880,415);
glVertex2i(930,415);
glVertex2i(915,440);

glColor3ub(0,0,85);

glVertex2i(885,415);
glVertex2i(870,390);
glVertex2i(940,390);
glVertex2i(925,415);

glColor3ub(0,56,0);

glVertex2i(903,378);
glVertex2i(909,378);
glVertex2i(909,390);
glVertex2i(903,390);
glEnd();
}

void tree_middle_left()
{
    glBegin(GL_TRIANGLES);          //Tree 6 Part

glColor3ub(13, 163, 63);

glVertex2i(460,440);
glVertex2i(490,440);
glVertex2i(475,470);
glEnd();

glBegin(GL_QUADS);          //Tree 6 Part

glColor3ub(0,67,0);

glVertex2i(465,440);
glVertex2i(450,415);
glVertex2i(500,415);
glVertex2i(485,440);

glColor3ub(0,0,85);

glVertex2i(455,415);
glVertex2i(440,390);
glVertex2i(510,390);
glVertex2i(495,415);

glColor3ub(0,56,0);

glVertex2i(473,378);
glVertex2i(479,378);
glVertex2i(479,390);
glVertex2i(473,390);
glEnd();
}

void tree_uppermost_right()
{
    glBegin(GL_TRIANGLES);          //Tree 6 Part

glColor3ub(13, 163, 63);

glVertex2i(1240,570);
glVertex2i(1270,570);
glVertex2i(1255,600);
glEnd();

glBegin(GL_QUADS);          //Tree 6 Part

glColor3ub(0,67,0);

glVertex2i(1245,570);
glVertex2i(1230,545);
glVertex2i(1280,545);
glVertex2i(1265,570);

glColor3ub(0,0,85);

glVertex2i(1235,545);
glVertex2i(1220,520);
glVertex2i(1290,520);
glVertex2i(1275,545);

glColor3ub(0,56,0);

glVertex2i(1253,508);
glVertex2i(1258,508);
glVertex2i(1258,520);
glVertex2i(1253,520);
glEnd();
}

void tree_lower_vertical()
{
    glBegin(GL_TRIANGLES);          //Tree 5 Part

glColor3ub(13, 163, 63);

glVertex2i(270,390);
glVertex2i(300,390);
glVertex2i(285,420);
glEnd();

glBegin(GL_QUADS);          //Tree 5 Part

glColor3ub(0,67,0);

glVertex2i(275,390);
glVertex2i(260,365);
glVertex2i(310,365);
glVertex2i(295,390);

glColor3ub(0,0,85);

glVertex2i(265,365);
glVertex2i(250,340);
glVertex2i(320,340);
glVertex2i(305,365);

glColor3ub(0,56,0);

glVertex2i(283,328);
glVertex2i(289,328);
glVertex2i(289,340);
glVertex2i(283,340);
glEnd();
}

void tree_upper_vertical()
{
    glBegin(GL_TRIANGLES);          //Tree 4 Part

glColor3ub(13, 163, 63);

glVertex2i(280,480);
glVertex2i(310,480);
glVertex2i(295,510);
glEnd();

glBegin(GL_QUADS);          //Tree 4 Part

glColor3ub(0,67,0);

glVertex2i(285,480);
glVertex2i(270,455);
glVertex2i(320,455);
glVertex2i(305,480);

glColor3ub(0,0,85);

glVertex2i(275,455);
glVertex2i(260,430);
glVertex2i(330,430);
glVertex2i(315,455);

glColor3ub(0,56,0);

glVertex2i(293,418);
glVertex2i(299,418);
glVertex2i(299,430);
glVertex2i(293,430);
glEnd();
}

void tree_upper_left()
{
//Tree 1 Part
glBegin(GL_TRIANGLES);
glColor3ub(13, 163, 63);

glVertex2i(50,570);
glVertex2i(80,570);
glVertex2i(65,600);
glEnd();

glBegin(GL_QUADS);             //Tree 1 Part

glColor3ub(0,67,0);

glVertex2i(55,570);
glVertex2i(40,545);
glVertex2i(90,545);
glVertex2i(75,570);

glColor3ub(0,0,85);

glVertex2i(45,545);
glVertex2i(30,520);
glVertex2i(100,520);
glVertex2i(85,545);

glColor3ub(0,56,0);

glVertex2i(62,508);
glVertex2i(68,508);
glVertex2i(68,520);
glVertex2i(62,520);
glEnd();

}

void tree_upper_middle()
{
    glBegin(GL_TRIANGLES);          //Tree 2 Part

glColor3ub(13, 163, 63);

glVertex2i(145,570);
glVertex2i(175,570);
glVertex2i(160,600);
glEnd();

glBegin(GL_QUADS);            //Tree 2 Part

glColor3ub(0,67,0);

glVertex2i(150,570);
glVertex2i(135,545);
glVertex2i(185,545);
glVertex2i(170,570);

glColor3ub(0,0,85);

glVertex2i(140,545);
glVertex2i(125,520);
glVertex2i(195,520);
glVertex2i(180,545);

glColor3ub(0,56,0);

glVertex2i(158,508);
glVertex2i(163,508);
glVertex2i(163,520);
glVertex2i(158,520);
glEnd();
}

void tree_upper_right()
{
    glBegin(GL_TRIANGLES);          //Tree 3 Part

glColor3ub(13, 163, 63);

glVertex2i(240,570);
glVertex2i(270,570);
glVertex2i(255,600);
glEnd();

glBegin(GL_QUADS);          //Tree 3 Part

glColor3ub(0,67,0);

glVertex2i(245,570);
glVertex2i(230,545);
glVertex2i(280,545);
glVertex2i(265,570);

glColor3ub(0,0,85);

glVertex2i(235,545);
glVertex2i(220,520);
glVertex2i(290,520);
glVertex2i(275,545);

glColor3ub(0,56,0);

glVertex2i(253,508);
glVertex2i(258,508);
glVertex2i(258,520);
glVertex2i(253,520);
glEnd();
}

void mini_tree1()//No need to use
{
//    glPushMatrix();
//    glTranslatef(80-180, 500-750, 0.0);

    glBegin(GL_POLYGON);  //tree leaf
    glColor3ub(21, 122, 35);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(98+cos(angle)*25,452+sin(angle)*25);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 2
    glColor3ub(45,240,40);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(68+cos(angle)*20,442+sin(angle)*20);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 3
    glColor3ub(21, 122, 35);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(62+cos(angle)*5.5,433+sin(angle)*5.5);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 4
    glColor3ub(21, 122, 35);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(70+cos(angle)*7.5,448+sin(angle)*7.5);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 5
    glColor3ub(45,240,40);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(90+cos(angle)*9,463+sin(angle)*9);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 6
    glColor3ub(45,240,40);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(98+cos(angle)*5,448+sin(angle)*5);
    }
    glEnd();

    glBegin(GL_POLYGON);  //tree leaf 7
    glColor3ub(45,240,40);
  for(int i=0;i<=360;i++)
    {
    float angle= i*3.1416/180;
    glVertex2f(110+cos(angle)*7,440+sin(angle)*7);
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(85,405);
    glVertex2i(70,390);
    glVertex2i(100,390);

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(85,397);
    glVertex2i(60,390);
    glVertex2i(110,390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2i(80,440);
    glVertex2i(90,440);
    glVertex2i(93,390);
    glVertex2i(77,390);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(61,434);
    glVertex2i(80,420);
    glVertex2i(80,428);

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(68,450);
    glVertex2i(80,430);
    glVertex2i(83,440);

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(90,465);
    glVertex2i(83,440);
    glVertex2i(90,440);

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(99,448);
    glVertex2i(90,442);
    glVertex2i(90,430);

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(112,440);
    glVertex2i(90,433);
    glVertex2i(90,425);

    glEnd();
//    glPopMatrix();
}

void mini_tree2()//initial point (84,428)
{
    glPushMatrix();
    glTranslatef(10-84, 428-210-10, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(85,390);
    glVertex2i(68,365);
    glVertex2i(102,365);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,380);
    glVertex2i(65,355);
    glVertex2i(105,355);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,370);
    glVertex2i(62,345);
    glVertex2i(108,345);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,370);
    glVertex2i(60,335);
    glVertex2i(110,335);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(85,335);
    glVertex2i(92,320);
    glVertex2i(78,320);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,325);
    glVertex2i(98,320);
    glVertex2i(72,320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2i(84.5,370);
    glVertex2i(85.5,370);
    glVertex2i(89,320);
    glVertex2i(81,320);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(80,368);
    glVertex2i(85,360);
    glVertex2i(85,350);

    glBegin(GL_TRIANGLES);
    glVertex2i(92,363);
    glVertex2i(85,355);
    glVertex2i(85,345);

    glBegin(GL_TRIANGLES);
    glVertex2i(75,355);
    glVertex2i(85,345);
    glVertex2i(85,335);

    glBegin(GL_TRIANGLES);
    glVertex2i(95,347);
    glVertex2i(85,337);
    glVertex2i(85,327);
    glEnd();

        glBegin(GL_POLYGON);   //red fruit
    glColor3ub(204, 0, 0);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(76+cos(angle)*2.5,360+sin(angle)*2.5);
    }
    glEnd();


    glBegin(GL_POLYGON);   //blue fruit
    glColor3ub(0, 0, 204);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(94+cos(angle)*2.5,352+sin(angle)*2.5);
    }
    glEnd();


    glBegin(GL_POLYGON);   //yellow fruit
    glColor3ub(255, 255, 150);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(75+cos(angle)*2.5,344+sin(angle)*2.5);
    }
    glEnd();


    glPopMatrix();
}

void mini_tree3()//initial point (84,428)
{
    int tree_x, tree_y;
    tree_x = 30;
    tree_y =20;
    int tree_yy = 20;
    int tree_distance = 60;
    int tree_no = 30;
    bool tree_check_y = false;

    for (int i=0; i < tree_no; i++)
    {
    glPushMatrix();
    glTranslatef(10-84+tree_x, 428-210-10-tree_y, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3ub(21, 122, 35);
    glVertex2i(85,390);
    glVertex2i(68,365);
    glVertex2i(102,365);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,380);
    glVertex2i(65,355);
    glVertex2i(105,355);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,370);
    glVertex2i(62,345);
    glVertex2i(108,345);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,370);
    glVertex2i(60,335);
    glVertex2i(110,335);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 51, 0);
    glVertex2i(85,335);
    glVertex2i(92,320);
    glVertex2i(78,320);

    glBegin(GL_TRIANGLES);
    glVertex2i(85,325);
    glVertex2i(98,320);
    glVertex2i(72,320);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2i(84.5,370);
    glVertex2i(85.5,370);
    glVertex2i(89,320);
    glVertex2i(81,320);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(80,368);
    glVertex2i(85,360);
    glVertex2i(85,350);

    glBegin(GL_TRIANGLES);
    glVertex2i(92,363);
    glVertex2i(85,355);
    glVertex2i(85,345);

    glBegin(GL_TRIANGLES);
    glVertex2i(75,355);
    glVertex2i(85,345);
    glVertex2i(85,335);

    glBegin(GL_TRIANGLES);
    glVertex2i(95,347);
    glVertex2i(85,337);
    glVertex2i(85,327);
    glEnd();

    glBegin(GL_POLYGON);   //red fruit
    glColor3ub(255, 0, 0);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(76+cos(angle)*2.5,360+sin(angle)*2.5);
    }
    glEnd();


    glBegin(GL_POLYGON);   //blue fruit
    glColor3ub(204, 0, 204);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(94+cos(angle)*2.5,352+sin(angle)*2.5);
    }
    glEnd();


    glBegin(GL_POLYGON);   //yellow fruit
    glColor3ub(128, 255, 0);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(75+cos(angle)*2.5,344+sin(angle)*2.5);
    }
    glEnd();


    glPopMatrix();
    tree_x=tree_x+tree_distance;
    if(!tree_check_y)
    {
        tree_y = 0;
        tree_check_y=true;
    }
    else{
        tree_y = tree_yy;
        tree_check_y= false;
    }
    }

}


void watch_tower1()
{
    glBegin(GL_QUADS);
glColor3ub(133,120,101);        //WatchTower 1

glVertex2i(340,570);
glVertex2i(340,565);      //base
glVertex2i(420,565);
glVertex2i(420,570);

glColor3ub(58,65,4);

glVertex2i(365,585);
glVertex2i(365,570);        //big quad
glVertex2i(395,570);
glVertex2i(395,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(395,585);
glVertex2i(395,584);
glVertex2i(420,584);
glVertex2i(420,585);

glVertex2i(419,584);
glVertex2i(419,565);
glVertex2i(420,565);
glVertex2i(420,584);

glVertex2i(395,576);
glVertex2i(395,577);
glVertex2i(420,577);
glVertex2i(420,576);

glVertex2i(414,585);
glVertex2i(414,570);
glVertex2i(415,570);
glVertex2i(414,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);

glColor3ub(58,65,4);

glVertex2i(403,595);     //Big border
glVertex2i(403,570);
glVertex2i(406,570);
glVertex2i(406,595);

glVertex2i(392,595);
glVertex2i(392,585);
glVertex2i(395,585);
glVertex2i(395,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(340,585);
glVertex2i(340,584);
glVertex2i(365,584);
glVertex2i(365,585);

glVertex2i(339,584);
glVertex2i(339,565);
glVertex2i(340,565);
glVertex2i(340,584);

glVertex2i(340,576);
glVertex2i(340,577);
glVertex2i(365,577);
glVertex2i(365,576);

glVertex2i(345,585);
glVertex2i(345,570);
glVertex2i(346,570);
glVertex2i(346,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(354,595);
glVertex2i(354,570);   //big border
glVertex2i(357,570);
glVertex2i(357,595);

glVertex2i(365,595);
glVertex2i(365,585);
glVertex2i(369,585);
glVertex2i(369,595);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(344,595);       //Triangle
glVertex2i(416,595);
glVertex2i(380,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(354,565);
glVertex2i(354,500);
glVertex2i(359,500);    //pillar
glVertex2i(359,565);

glVertex2i(401,565);
glVertex2i(401,500);
glVertex2i(406,500);
glVertex2i(406,565);
glEnd();

glBegin(GL_QUADS);      //Ladder

glColor3ub(0,0,0);

glVertex2i(375,565);
glVertex2i(375,500);
glVertex2i(377,500);
glVertex2i(377,565);

glVertex2i(385,565);
glVertex2i(385,500);
glVertex2i(387,500);
glVertex2i(387,565);

glVertex2i(377,562);
glVertex2i(377,561);
glVertex2i(385,561);
glVertex2i(385,562);

glVertex2i(377,557);
glVertex2i(377,556);
glVertex2i(385,556);
glVertex2i(385,557);

glVertex2i(377,552);
glVertex2i(377,551);
glVertex2i(385,551);
glVertex2i(385,552);

glVertex2i(377,547);
glVertex2i(377,546);
glVertex2i(385,546);
glVertex2i(385,547);

glVertex2i(377,542);
glVertex2i(377,541);
glVertex2i(385,541);
glVertex2i(385,542);

glVertex2i(377,537);
glVertex2i(377,536);
glVertex2i(385,536);
glVertex2i(385,537);

glVertex2i(377,532);
glVertex2i(377,531);
glVertex2i(385,532);
glVertex2i(385,531);

glVertex2i(377,527);
glVertex2i(377,526);
glVertex2i(385,526);
glVertex2i(385,527);

glVertex2i(377,522);
glVertex2i(377,521);
glVertex2i(385,521);
glVertex2i(385,522);

glVertex2i(377,517);
glVertex2i(377,516);
glVertex2i(385,516);
glVertex2i(385,517);

glVertex2i(377,512);
glVertex2i(377,511);
glVertex2i(385,511);
glVertex2i(385,512);

glVertex2i(377,507);
glVertex2i(377,506);
glVertex2i(385,506);
glVertex2i(385,507);

glVertex2i(377,502);
glVertex2i(377,501);
glVertex2i(385,501);
glVertex2i(385,502);
glEnd();
}

void watch_tower2()
{

glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 2

glVertex2i(1140,570);
glVertex2i(1140,565);      //base
glVertex2i(1220,565);
glVertex2i(1220,570);

glColor3ub(58,65,4);

glVertex2i(1165,585);
glVertex2i(1165,570);        //big quad
glVertex2i(1195,570);
glVertex2i(1195,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(1195,585);
glVertex2i(1195,584);
glVertex2i(1220,584);
glVertex2i(1220,585);

glVertex2i(1219,584);
glVertex2i(1219,565);
glVertex2i(1220,565);
glVertex2i(1220,584);

glVertex2i(1195,576);
glVertex2i(1195,577);
glVertex2i(1220,577);
glVertex2i(1220,576);

glVertex2i(1214,585);
glVertex2i(1214,570);
glVertex2i(1215,570);
glVertex2i(1214,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);

glColor3ub(58,65,4);

glVertex2i(1203,595);     //Big border
glVertex2i(1203,570);
glVertex2i(1206,570);
glVertex2i(1206,595);

glVertex2i(1192,595);
glVertex2i(1192,585);
glVertex2i(1195,585);
glVertex2i(1195,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(1140,585);
glVertex2i(1140,584);
glVertex2i(1165,584);
glVertex2i(1165,585);

glVertex2i(1139,584);
glVertex2i(1139,565);
glVertex2i(1140,565);
glVertex2i(1140,584);

glVertex2i(1140,576);
glVertex2i(1140,577);
glVertex2i(1165,577);
glVertex2i(1165,576);

glVertex2i(1145,585);
glVertex2i(1145,570);
glVertex2i(1146,570);
glVertex2i(1146,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(1154,595);
glVertex2i(1154,570);   //big border
glVertex2i(1157,570);
glVertex2i(1157,595);

glVertex2i(1165,595);
glVertex2i(1165,585);
glVertex2i(1169,585);
glVertex2i(1169,595);

//Ladder
glColor3ub(0,0,0);

glVertex2i(1175,565);
glVertex2i(1175,500);
glVertex2i(1177,500);
glVertex2i(1177,565);

glVertex2i(1185,565);
glVertex2i(1185,500);
glVertex2i(1187,500);
glVertex2i(1187,565);

glVertex2i(1177,562);
glVertex2i(1177,561);
glVertex2i(1185,561);
glVertex2i(1185,562);

glVertex2i(1177,557);
glVertex2i(1177,556);
glVertex2i(1185,556);
glVertex2i(1185,557);

glVertex2i(1177,552);
glVertex2i(1177,551);
glVertex2i(1185,551);
glVertex2i(1185,552);

glVertex2i(1177,547);
glVertex2i(1177,546);
glVertex2i(1185,546);
glVertex2i(1185,547);

glVertex2i(1177,542);
glVertex2i(1177,541);
glVertex2i(1185,541);
glVertex2i(1185,542);

glVertex2i(1177,537);
glVertex2i(1177,536);
glVertex2i(1185,536);
glVertex2i(1185,537);

glVertex2i(1177,532);
glVertex2i(1177,531);
glVertex2i(1185,532);
glVertex2i(1185,531);

glVertex2i(1177,527);
glVertex2i(1177,526);
glVertex2i(1185,526);
glVertex2i(1185,527);

glVertex2i(1177,522);
glVertex2i(1177,521);
glVertex2i(1185,521);
glVertex2i(1185,522);

glVertex2i(1177,517);
glVertex2i(1177,516);
glVertex2i(1185,516);
glVertex2i(1185,517);

glVertex2i(1177,512);
glVertex2i(1177,511);
glVertex2i(1185,511);
glVertex2i(1185,512);

glVertex2i(1177,507);
glVertex2i(1177,506);
glVertex2i(1185,506);
glVertex2i(1185,507);

glVertex2i(1177,502);
glVertex2i(1177,501);
glVertex2i(1185,501);
glVertex2i(1185,502);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(1144,595);       //Triangle
glVertex2i(1216,595);
glVertex2i(1180,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(1154,565);
glVertex2i(1154,500);
glVertex2i(1159,500);    //pillar
glVertex2i(1159,565);

glVertex2i(1201,565);
glVertex2i(1201,500);
glVertex2i(1206,500);
glVertex2i(1206,565);

glEnd();


}

void hut1()
{
    glBegin(GL_QUADS);      //Hut 1

glColor3ub(255, 218, 185);
glVertex2i(700,490);
glVertex2i(700,540);
glVertex2i(620,540);
glVertex2i(620,490);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 218, 245);
glVertex2i(710,540);
glVertex2i(660,565);
glVertex2i(610,540);
glEnd();



glBegin(GL_QUADS);      //Hut 1 Door
glColor3ub(131, 139, 139);
glVertex2i(635,490);
glVertex2i(635,530);
glVertex2i(645,530);
glVertex2i(645,490);
glEnd();

}

void hut2()
{
glBegin(GL_QUADS);          //Hut 2

glColor3ub(238, 203, 173);
glVertex2i(820,490);
glVertex2i(820,540);
glVertex2i(740,540);
glVertex2i(740,490);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(238, 203, 233);
glVertex2i(830,540);
glVertex2i(780,565);
glVertex2i(730,540);
glEnd();


glBegin(GL_QUADS);          //Hut 2 Door
glColor3ub(0,0,0);
glVertex2i(795,490);
glVertex2i(795,525);
glVertex2i(765,525);
glVertex2i(765,490);
glEnd();

}

void hut3()
{
    glBegin(GL_QUADS);      //Hut 3
glColor3ub(205, 183, 181);
glVertex2i(940,490);
glVertex2i(940,540);
glVertex2i(860,540);
glVertex2i(860,490);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(205, 183, 241);
glVertex2i(950,540);
glVertex2i(900,565);
glVertex2i(850,540);
glEnd();


glBegin(GL_QUADS);      //Hut 3 Door
glColor3ub(0,0,0);
glVertex2i(915,490);
glVertex2i(915,525);
glVertex2i(885,525);
glVertex2i(885,490);
glEnd();

}

void building()
{
    glBegin(GL_QUADS);
    glColor3ub(200,185,150);
    glVertex2i(1000,485);  //building
    glVertex2i(1120,485);
    glVertex2i(1120,585);
    glVertex2i(1000,585);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(150, 160, 170);
    glVertex2i(990,585);                 //buildingborder
    glVertex2i(1130,585);
    glVertex2i(1130,600);
    glVertex2i(990,600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69, 66, 66);
    glVertex2i(1045,530);
    glVertex2i(1045,485);
    glVertex2i(1075,485);
    glVertex2i(1075,530);

    glColor3ub(69, 66, 66);
    glVertex2i(1010,545);
    glVertex2i(1010,525);
    glVertex2i(1030,525);
    glVertex2i(1030,545);

    glColor3ub(69, 66, 66);
    glVertex2i(1110,525);
    glVertex2i(1110,545);
    glVertex2i(1090,545);
    glVertex2i(1090,525);
    glEnd();

}

void river()
{
glBegin(GL_QUADS);
if(night)
    glColor3ub(0, 42, 104);//Night
else if(!night && sun_sky< -90)
    glColor3ub(25,25,112);//Morning & Evening
else
    glColor3ub(0,0,205);//Day
glVertex2i(0, 200);
glVertex2i(0, 0);          //river Part

if(night)
    glColor3ub(51,51,255);//Night
else if(!night && sun_sky< -90)
    glColor3ub(30,144,255);//Morning & Evening
else
    glColor3ub(102, 255, 255);//Day
glVertex2i(1300, 0);
glVertex2i(1300, 200);

glEnd();
}

void footpath()
{
glBegin(GL_QUADS);
//glColor3ub (158, 191, 247);
//glColor3ub (238,232,170);
glColor3ub (205,92,92);

glVertex2i(0, 230);
glVertex2i(1300, 230);
glVertex2i(1300, 250);
glVertex2i(0, 250);

glEnd();

}

void building_complex_flag()
{
    glBegin(GL_QUADS);

     glColor3ub(0, 0, 0);
     glVertex2i(494,560);      //flag-l
     glVertex2i(496,560);
     glVertex2i(496,600);
     glVertex2i(494,600);

     glEnd();

     if(!night){
     glBegin(GL_QUADS);
     glColor3ub(0, 106, 78);
     glVertex2i(496,580);      //flag-green
     glVertex2i(530,580);
     glVertex2i(530,600);
     glVertex2i(496,600);

    glEnd();

  glBegin(GL_POLYGON);            //flag-cir
    glColor3ub(244, 42, 65);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(513+cos(angle)*7,590+sin(angle)*7);

    }
    glEnd();
     }
}

void building_complex()
{
    //building-start
    glPushMatrix();
    glTranslatef(15.0, 40.0, 0.0);
    building_complex_flag();

    glBegin(GL_QUADS);        //building-2
    glColor3ub(82,82,82);
    glVertex2i(440,450);
    glVertex2i(550,450);
    glVertex2i(550,510);
    glVertex2i(440,510);


    glColor3ub(219, 184, 102);        //buildingside-1
    glVertex2i(420,450);
    glVertex2i(440,450);
    glVertex2i(440,525);
    glVertex2i(420,525);
                                   //buildingside-2
    glVertex2i(550,450);
    glVertex2i(570,450);
    glVertex2i(570,525);
    glVertex2i(550,525);
                                //buildingup
    glVertex2i(440,510);
    glVertex2i(550,510);
    glVertex2i(550,525);
    glVertex2i(440,525);


     glColor3ub(155, 100, 60);
     glVertex2i(410,445);      //buildingbase
     glVertex2i(580,445);
     glVertex2i(580,450);
     glVertex2i(410,450);


     glColor3ub(70, 130, 180);
     glVertex2i(440,515);      //buildingw
     glVertex2i(550,515);
     glVertex2i(550,530);
     glVertex2i(440,530);



     glColor3ub(0, 0, 0);
     glVertex2i(450,515);      //border-1
     glVertex2i(453,515);
     glVertex2i(453,530);
     glVertex2i(450,530);


      glColor3ub(0, 0, 0);
     glVertex2i(463,515);      //border-2
     glVertex2i(466,515);
     glVertex2i(466,530);
     glVertex2i(463,530);

      glColor3ub(0, 0, 0);
     glVertex2i(476,515);      //border-3
     glVertex2i(479,515);
     glVertex2i(479,530);
     glVertex2i(476,530);


      glColor3ub(0, 0, 0);
     glVertex2i(489,515);      //border-4
     glVertex2i(492,515);
     glVertex2i(492,530);
     glVertex2i(489,530);



      glColor3ub(0, 0, 0);
     glVertex2i(502,515);      //border-5
     glVertex2i(505,515);
     glVertex2i(505,530);
     glVertex2i(502,530);



      glColor3ub(0, 0, 0);
     glVertex2i(515,515);      //border-6
     glVertex2i(518,515);
     glVertex2i(518,530);
     glVertex2i(515,530);


       glColor3ub(0, 0, 0);
     glVertex2i(528,515);      //border-7
     glVertex2i(531,515);
     glVertex2i(531,530);
     glVertex2i(528,530);


       glColor3ub(0, 0, 0);
     glVertex2i(541,515);      //border-8
     glVertex2i(544,515);
     glVertex2i(544,530);
     glVertex2i(541,530);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(168, 190, 213);
    glVertex2i(410,525);
    glVertex2i(495,560);
    glVertex2i(580,525);

    glEnd();             //building-end
    glPopMatrix();
}

void helipad()
{
    //helipad

    glBegin(GL_POLYGON);            //helipad outer circle
    glColor3ub(160, 160, 0);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1103+cos(angle)*113,355+sin(angle)*32);

    }
    glEnd();


    glBegin(GL_POLYGON);            //helipad
    glColor3ub(0, 102, 102);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1103+cos(angle)*110,355+sin(angle)*30);

    }
    glEnd();

    glBegin(GL_QUADS);              // Helipad
    glColor3ub(152, 154, 156);
    glVertex2i(1130,335);
    glVertex2i(1140,335);
    glVertex2i(1140,375);
    glVertex2i(1130,375);

    glVertex2i(1070,335);
    glVertex2i(1080,335);
    glVertex2i(1080,375);
    glVertex2i(1070,375);

    glVertex2i(1080,350);
    glVertex2i(1140,350);
    glVertex2i(1140,360);
    glVertex2i(1080,360);



    glEnd();
}

void road()
{
    glBegin(GL_QUADS);

glColor3ub(0,0,0);
                            //road
glVertex2i(0,230);
glVertex2i(1300,230);
glVertex2i(1300,100);
glVertex2i(0,100);

glColor3ub(152, 154, 156);

glVertex2i(60,165);          //roadline-1
glVertex2i(160,165);
glVertex2i(160,175);
glVertex2i(60,175);

glVertex2i(190,165);          //roadline-2
glVertex2i(290,165);
glVertex2i(290,175);
glVertex2i(190,175);

glVertex2i(320,165);          //roadline-3
glVertex2i(420,165);
glVertex2i(420,175);
glVertex2i(320,175);

glVertex2i(450,165);          //roadline-4
glVertex2i(550,165);
glVertex2i(550,175);
glVertex2i(450,175);

glVertex2i(580,165);          //roadline-5
glVertex2i(680,165);
glVertex2i(680,175);
glVertex2i(580,175);

glVertex2i(710,165);          //roadline-5
glVertex2i(810,165);
glVertex2i(810,175);
glVertex2i(710,175);

glVertex2i(840,165);          //roadline-6
glVertex2i(940,165);
glVertex2i(940,175);
glVertex2i(840,175);

glVertex2i(970,165);          //roadline-7
glVertex2i(1070,165);
glVertex2i(1070,175);
glVertex2i(970,175);

glVertex2i(1100,165);          //roadline-8
glVertex2i(1200,165);
glVertex2i(1200,175);
glVertex2i(1100,175);

glVertex2i(1230,165);          //roadline-9
glVertex2i(1270,165);
glVertex2i(1270,175);
glVertex2i(1230,175);



glEnd();


}

void jeep()
{

glPushMatrix(); //Jeep start pushing
glTranslatef(tri, 0.0, 0.0);
glColor3ub(135, 206, 235);    //Jeep

    glBegin(GL_TRIANGLES);      //Jeep
    glVertex2i(290,170);
    glVertex2i(270,220);
    glVertex2i(270,175);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(100,130);
    glVertex2i(130,130);
    glVertex2i(130,220);
    glVertex2i(100,220);

    glVertex2i(130,130);        //Tire Cut 1
    glVertex2i(150,150);
    glVertex2i(150,220);
    glVertex2i(130,220);

    glVertex2i(150,150);
    glVertex2i(180,150);
    glVertex2i(180,220);
    glVertex2i(150,220);

    glVertex2i(180,150);
    glVertex2i(200,130);       //Tire Cut 1
    glVertex2i(200,220);
    glVertex2i(180,220);

    glVertex2i(200,130);
    glVertex2i(270,130);
    glVertex2i(270,220);
    glVertex2i(200,220);

    glVertex2i(270,130);       //Tire Cut 2
    glVertex2i(290,150);
    glVertex2i(290,185);
    glVertex2i(270,190);

    glVertex2i(290,150);
    glVertex2i(320,150);
    glVertex2i(320,180);
    glVertex2i(290,185);

    glVertex2i(320,150);       //Tire Cut 2
    glVertex2i(340,130);
    glVertex2i(340,175);
    glVertex2i(320,180);


    glVertex2i(340,130);
    glVertex2i(360,130);
    glVertex2i(360,170);
    glVertex2i(340,175);


    glColor3ub(75, 195, 250);

    glVertex2i(210,135);           // Door
    glVertex2i(265,135);
    glVertex2i(265,215);
    glVertex2i(210,215);



    glColor3ub(8, 69, 112);
    glVertex2i(215,180);           // Door Window
    glVertex2i(260,180);
    glVertex2i(260,210);
    glVertex2i(215,210);

    glEnd();

    human_jeep();

    glBegin(GL_QUADS);
    glColor3ub(75, 195, 250);

    glVertex2i(215,180);           // Hide_Human_body_Door_color
    glVertex2i(210,135);
    glVertex2i(265,135);
    glVertex2i(260,180);

    glColor3ub(8, 69, 112);                   // 2nd Window
    glVertex2i(140,180);
    glVertex2i(190,180);
    glVertex2i(190,210);
    glVertex2i(140,210);

    glEnd();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*30,135+sin(angle)*25);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*19,135+sin(angle)*17);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*9,135+sin(angle)*9);
    }
    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*30,135+sin(angle)*25);
    }
    glEnd();
//    glPopMatrix();



//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*19,135+sin(angle)*17);
    }

    glEnd();
//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(0,0,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*9, 135+sin(angle)*9);
    }
    glEnd();
//    glPopMatrix();


    glBegin(GL_QUADS);
    glColor3ub(50, 150, 200);

    glVertex2i(205,170);
    glVertex2i(220,170);
    glVertex2i(220,175);
    glVertex2i(205,175);

    glVertex2i(100,175);
    glVertex2i(110,175);
    glVertex2i(110,220);
    glVertex2i(100,220);

    glVertex2i(122,155);
    glVertex2i(132,155);
    glVertex2i(132,165);
    glVertex2i(122,165);

    glColor3ub(230, 20, 20);
    glVertex2i(100,175);
    glVertex2i(110,175);
    glVertex2i(110,188);
    glVertex2i(100,188);

    glEnd();

    glPopMatrix();//Jeep end pushing

}

void playground()
{
glBegin(GL_QUADS);
glColor3ub(99,91,91);  //border from tower to fence
glVertex2i(330,500);
glVertex2i(300,250);
glVertex2i(310,250);
glVertex2i(340,500);
glEnd();


glBegin(GL_QUADS);
//glColor3ub(5,179,20);  //playground
glColor3ub(0,130,13);  //playground

glVertex2i(0,250);
glVertex2i(300,250);

if(!night && sun_sky< -90)
    glColor3ub(238, 204, 37);//Morning & Evening
else if(!night)
    glColor3ub(5,253,28);//Day time

glVertex2i(330,500);
glVertex2i(0,500);
glEnd();

glBegin(GL_QUADS);
glColor3ub(99,91,91);
glVertex2i(0,500);
glVertex2i(0,490);
glVertex2i(330,490);
glVertex2i(330,500);
glEnd();

glBegin(GL_LINES);

glColor3ub(99,91,91);

glVertex2i(165,490);
glVertex2i(130,250);


glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(181,181,181);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(148+cos(angle)*40,380+sin(angle)*20);
    }
    glEnd();
}

void fence()
{
glBegin(GL_QUADS);      //fence     fence
glColor3ub(0,0,0);
glVertex2i(0,250);
glVertex2i(1300,250);
glVertex2i(1300,257);
glVertex2i(0,257);

glVertex2i(0,290);
glVertex2i(1300,290);
glVertex2i(1300,295);
glVertex2i(0,295);

glVertex2i(25,310);
glVertex2i(25,250);
glVertex2i(30,250);
glVertex2i(30,310);

glVertex2i(40,310);
glVertex2i(40,250);
glVertex2i(45,250);
glVertex2i(45,310);

glVertex2i(55,310);
glVertex2i(55,250);
glVertex2i(60,250);
glVertex2i(60,310);

glVertex2i(70,310);
glVertex2i(70,250);
glVertex2i(75,250);
glVertex2i(75,310);

glVertex2i(85,310);
glVertex2i(85,250);
glVertex2i(90,250);
glVertex2i(90,310);

glVertex2i(100,310);
glVertex2i(100,250);
glVertex2i(105,250);
glVertex2i(105,310);

glVertex2i(115,310);
glVertex2i(115,250);
glVertex2i(120,250);
glVertex2i(120,310);

glVertex2i(130,310);
glVertex2i(130,250);
glVertex2i(135,250);
glVertex2i(135,310);

glVertex2i(145,310);
glVertex2i(145,250);
glVertex2i(150,250);
glVertex2i(150,310);

glVertex2i(160,310);
glVertex2i(160,250);
glVertex2i(165,250);
glVertex2i(165,310);

glVertex2i(175,310);
glVertex2i(175,250);
glVertex2i(180,250);
glVertex2i(180,310);

glVertex2i(190,310);
glVertex2i(190,250);
glVertex2i(195,250);
glVertex2i(195,310);

glVertex2i(205,310);
glVertex2i(205,250);
glVertex2i(210,250);
glVertex2i(210,310);

glVertex2i(220,310);
glVertex2i(220,250);
glVertex2i(225,250);
glVertex2i(225,310);

glVertex2i(235,310);
glVertex2i(235,250);
glVertex2i(240,250);
glVertex2i(240,310);

glVertex2i(250,310);
glVertex2i(250,250);
glVertex2i(255,250);
glVertex2i(255,310);

glVertex2i(265,310);
glVertex2i(265,250);
glVertex2i(270,250);
glVertex2i(270,310);

glVertex2i(280,310);
glVertex2i(280,250);
glVertex2i(285,250);
glVertex2i(285,310);

glVertex2i(295,310);
glVertex2i(295,250);
glVertex2i(300,250);
glVertex2i(300,310);

glVertex2i(310,310);
glVertex2i(310,250);
glVertex2i(315,250);
glVertex2i(315,310);

glVertex2i(325,310);
glVertex2i(325,250);
glVertex2i(330,250);
glVertex2i(330,310);

glVertex2i(340,310);
glVertex2i(340,250);
glVertex2i(345,250);
glVertex2i(345,310);

glVertex2i(355,310);
glVertex2i(355,250);
glVertex2i(360,250);
glVertex2i(360,310);

glVertex2i(370,310);
glVertex2i(370,250);
glVertex2i(375,250);
glVertex2i(375,310);

glVertex2i(385,310);
glVertex2i(385,250);
glVertex2i(390,250);
glVertex2i(390,310);

glVertex2i(400,310);
glVertex2i(400,250);
glVertex2i(405,250);
glVertex2i(405,310);

glVertex2i(415,310);
glVertex2i(415,250);
glVertex2i(420,250);
glVertex2i(420,310);

glVertex2i(430,310);
glVertex2i(430,250);
glVertex2i(435,250);
glVertex2i(435,310);

glVertex2i(445,310);
glVertex2i(445,250);
glVertex2i(450,250);
glVertex2i(450,310);

glVertex2i(460,310);
glVertex2i(460,250);
glVertex2i(465,250);
glVertex2i(465,310);

glVertex2i(475,310);
glVertex2i(475,250);
glVertex2i(480,250);
glVertex2i(480,310);

glVertex2i(490,310);
glVertex2i(490,250);
glVertex2i(495,250);
glVertex2i(495,310);

glVertex2i(505,310);
glVertex2i(505,250);
glVertex2i(510,250);
glVertex2i(510,310);

glVertex2i(520,310);
glVertex2i(520,250);
glVertex2i(525,250);
glVertex2i(525,310);

glVertex2i(535,310);
glVertex2i(535,250);
glVertex2i(540,250);
glVertex2i(540,310);

glVertex2i(550,310);
glVertex2i(550,250);
glVertex2i(555,250);
glVertex2i(555,310);

glVertex2i(565,310);
glVertex2i(565,250);
glVertex2i(570,250);
glVertex2i(570,310);

glVertex2i(580,310);
glVertex2i(580,250);
glVertex2i(585,250);
glVertex2i(585,310);

glVertex2i(595,310);
glVertex2i(595,250);
glVertex2i(600,250);
glVertex2i(600,310);

glVertex2i(610,310);
glVertex2i(610,250);
glVertex2i(615,250);
glVertex2i(615,310);

glVertex2i(625,310);
glVertex2i(625,250);
glVertex2i(630,250);
glVertex2i(630,310);

glVertex2i(640,310);
glVertex2i(640,250);
glVertex2i(645,250);
glVertex2i(645,310);

glVertex2i(655,310);
glVertex2i(655,250);
glVertex2i(660,250);
glVertex2i(660,310);

glVertex2i(670,310);
glVertex2i(670,250);
glVertex2i(675,250);
glVertex2i(675,310);

glVertex2i(685,310);
glVertex2i(685,250);
glVertex2i(690,250);
glVertex2i(690,310);

glVertex2i(700,310);
glVertex2i(700,250);
glVertex2i(705,250);
glVertex2i(705,310);

glVertex2i(715,310);
glVertex2i(715,250);
glVertex2i(720,250);
glVertex2i(720,310);

glVertex2i(730,310);
glVertex2i(730,250);
glVertex2i(735,250);
glVertex2i(735,310);

glVertex2i(745,310);
glVertex2i(745,250);
glVertex2i(750,250);
glVertex2i(750,310);

glVertex2i(760,310);
glVertex2i(760,250);
glVertex2i(765,250);
glVertex2i(765,310);

glVertex2i(775,310);
glVertex2i(775,250);
glVertex2i(780,250);
glVertex2i(780,310);

glVertex2i(790,310);
glVertex2i(790,250);
glVertex2i(795,250);
glVertex2i(795,310);

glVertex2i(805,310);
glVertex2i(805,250);
glVertex2i(810,250);
glVertex2i(810,310);

glVertex2i(820,310);
glVertex2i(820,250);
glVertex2i(825,250);
glVertex2i(825,310);

glVertex2i(835,310);
glVertex2i(835,250);
glVertex2i(840,250);
glVertex2i(840,310);

glVertex2i(850,310);
glVertex2i(850,250);
glVertex2i(855,250);
glVertex2i(855,310);

glVertex2i(865,310);
glVertex2i(865,250);
glVertex2i(870,250);
glVertex2i(870,310);

glVertex2i(880,310);
glVertex2i(880,250);
glVertex2i(885,250);
glVertex2i(885,310);

glVertex2i(895,310);
glVertex2i(895,250);
glVertex2i(900,250);
glVertex2i(900,310);

glVertex2i(910,310);
glVertex2i(910,250);
glVertex2i(915,250);
glVertex2i(915,310);

glVertex2i(925,310);
glVertex2i(925,250);
glVertex2i(930,250);
glVertex2i(930,310);

glVertex2i(940,310);
glVertex2i(940,250);
glVertex2i(945,250);
glVertex2i(945,310);

glVertex2i(955,310);
glVertex2i(955,250);
glVertex2i(960,250);
glVertex2i(960,310);

glVertex2i(970,310);
glVertex2i(970,250);
glVertex2i(975,250);
glVertex2i(975,310);

glVertex2i(985,310);
glVertex2i(985,250);
glVertex2i(990,250);
glVertex2i(990,310);

glVertex2i(1000,310);
glVertex2i(1000,250);
glVertex2i(1005,250);
glVertex2i(1005,310);

glVertex2i(1015,310);
glVertex2i(1015,250);
glVertex2i(1020,250);
glVertex2i(1020,310);

glVertex2i(1030,310);
glVertex2i(1030,250);
glVertex2i(1035,250);
glVertex2i(1035,310);

glVertex2i(1045,310);
glVertex2i(1045,250);
glVertex2i(1050,250);
glVertex2i(1050,310);

glVertex2i(1060,310);
glVertex2i(1060,250);
glVertex2i(1065,250);
glVertex2i(1065,310);

glVertex2i(1075,310);
glVertex2i(1075,250);
glVertex2i(1080,250);
glVertex2i(1080,310);

glVertex2i(1090,310);
glVertex2i(1090,250);
glVertex2i(1095,250);
glVertex2i(1095,310);

glVertex2i(1105,310);
glVertex2i(1105,250);
glVertex2i(1110,250);
glVertex2i(1110,310);

glVertex2i(1120,310);
glVertex2i(1120,250);
glVertex2i(1125,250);
glVertex2i(1125,310);

glVertex2i(1135,310);
glVertex2i(1135,250);
glVertex2i(1140,250);
glVertex2i(1140,310);

glVertex2i(1150,310);
glVertex2i(1150,250);
glVertex2i(1155,250);
glVertex2i(1155,310);

glVertex2i(1165,310);
glVertex2i(1165,250);
glVertex2i(1170,250);
glVertex2i(1170,310);

glVertex2i(1185,310);
glVertex2i(1185,250);
glVertex2i(1190,250);
glVertex2i(1190,310);

glVertex2i(1200,310);
glVertex2i(1200,250);
glVertex2i(1205,250);
glVertex2i(1205,310);

glVertex2i(1215,310);
glVertex2i(1215,250);
glVertex2i(1220,250);
glVertex2i(1220,310);

glVertex2i(1230,310);
glVertex2i(1230,250);
glVertex2i(1235,250);
glVertex2i(1235,310);

glVertex2i(1245,310);
glVertex2i(1245,250);
glVertex2i(1250,250);
glVertex2i(1250,310);

glVertex2i(1260,310);
glVertex2i(1260,250);
glVertex2i(1265,250);
glVertex2i(1265,310);

glVertex2i(1275,310);
glVertex2i(1275,250);
glVertex2i(1280,250);
glVertex2i(1280,310);

glVertex2i(1290,310);
glVertex2i(1290,250);
glVertex2i(1295,250);
glVertex2i(1295,310);

glEnd();
}

void road_signboard_car_behind()
{
glBegin(GL_QUADS);
glColor3ub(100,100,100);

glVertex2i(0,233);               //road-border/footpath-start
glVertex2i(1300,233);
glVertex2i(1300,229);
glVertex2i(0,229);

glColor3ub(99,96,96);
glVertex2i(10,310);
glVertex2i(15,310);              //signboard-stand-1-carbehind
glVertex2i(15,230);
glVertex2i(10,230);

glVertex2i(1285,310);
glVertex2i(1290,310);              //signboard-stand-2-carbehind
glVertex2i(1290,230);
glVertex2i(1285,230);


glVertex2i(680,400);
glVertex2i(680,230);              //signboard-3-mid1-carbehind
glVertex2i(690,230);
glVertex2i(690,400);

glVertex2i(700,400);
glVertex2i(700,230);              //signboard-4-mid2-carbehind
glVertex2i(710,230);
glVertex2i(710,400);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0, 102, 51);
glVertex2i(2,320);
glVertex2i(22,320);              //signboard-plate-1-carbehind
glVertex2i(22,270);
glVertex2i(2,270);

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2i(4,318);
glVertex2i(20,318);              //signboard-plate-1-carbehind
glVertex2i(20,272);
glVertex2i(4,272);

glBegin(GL_QUADS);
glColor3ub(0, 102, 51);
glVertex2i(6,316);
glVertex2i(18,316);              //signboard-plate-1-carbehind
glVertex2i(18,274);
glVertex2i(6,274);

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2i(11,308);
glVertex2i(17,308);              //signboard-plate-1-sign-carbehind
glVertex2i(17,302);
glVertex2i(11,302);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);  //signboard-plate-2-sign-carbehind
glVertex2i(11,310);
glVertex2i(6,305);
glVertex2i(11,300);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0, 102, 51);
glVertex2i(1278,320);
glVertex2i(1298,320);              //signboard-plate-2-carbehind
glVertex2i(1298,270);
glVertex2i(1278,270);

glBegin(GL_QUADS);
glColor3ub(255, 255, 255);
glVertex2i(1280,318);
glVertex2i(1296,318);              //signboard-plate-2-carbehind
glVertex2i(1296,272);
glVertex2i(1280,272);

glBegin(GL_QUADS);
glColor3ub(0, 102, 51);
glVertex2i(1282,316);
glVertex2i(1294,316);              //signboard-plate-2-carbehind
glVertex2i(1294,274);
glVertex2i(1282,274);

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2i(1287,308);
glVertex2i(1293,308);              //signboard-plate-2-sign-carbehind
glVertex2i(1293,302);
glVertex2i(1287,302);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);  //signboard-plate-2-sign-carbehind
glVertex2i(1287,310);
glVertex2i(1282,305);
glVertex2i(1287,300);
glEnd();

}

void road_signboard_car_forward()
{
glBegin(GL_QUADS);

glColor3ub(100,100,100);
glVertex2i(0, 103);          //road-border/river-start
glVertex2i(1300, 103);
glVertex2i(1300, 99);
glVertex2i(0, 99);

glColor3ub(99,96,96);
glVertex2i(590,350);
glVertex2i(600,350);
glVertex2i(600,100);             //signboard-stand-3-mid1-carforward
glVertex2i(590,100);

glVertex2i(590,350);
glVertex2i(680,400);             //signboard-stand-3-mid1-carforward
glVertex2i(690,400);
glVertex2i(600,350);

glColor3ub(0, 102, 51);
glVertex2i(690,400);
glVertex2i(690,360);              //signboard-stand-3-mid1-plate-1-carforward
glVertex2i(600,310);
glVertex2i(600,350);


glColor3ub(99,96,96);
glVertex2i(610,350);
glVertex2i(620,350);
glVertex2i(620,100);             //signboard-stand-3-mid2-carforward
glVertex2i(610,100);

glVertex2i(610,350);
glVertex2i(700,400);             //signboard-stand-3-mid2-carforward
glVertex2i(710,400);
glVertex2i(620,350);

glColor3ub(0, 102, 51);
glVertex2i(710,400);
glVertex2i(710,360);              //signboard-stand-3-mid1-plate-2-carforward
glVertex2i(620,310);
glVertex2i(620,350);

glColor3ub(255, 255, 255);
glVertex2i(707,396);
glVertex2i(707,362);              //signboard-stand-3-mid1-plate-2-carforward
glVertex2i(623,315);
glVertex2i(623,349);

glColor3ub(0, 102, 51);
glVertex2i(704,392);
glVertex2i(704,362);              //signboard-stand-3-mid1-plate-2-carforward
glVertex2i(626,319);
glVertex2i(626,348);

glColor3ub(255, 255, 255);
glVertex2i(640,352);
glVertex2i(645,355);              //signboard-stand-3-mid1-plate-2-sign1-carforward
glVertex2i(645,340);
glVertex2i(640,337);

glColor3ub(255, 255, 255);
glVertex2i(688,371);
glVertex2i(693,374);              //signboard-stand-3-mid1-plate-2-sign2-carforward
glVertex2i(693,359);
glVertex2i(688,356);

glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);  //signboard-stand-3-mid1-plate-2-sign1-carforward
glVertex2i(649,342);
glVertex2i(635,335);
glVertex2i(643.5,330);

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);  //signboard-stand-3-mid1-plate-2-sign2-carforward
glVertex2i(684,368);
glVertex2i(697,375);
glVertex2i(690,380);

glEnd();

glBegin(GL_QUADS);
glColor3ub(99,96,96);
glVertex2i(10,170);
glVertex2i(15,170);              //signboard-stand-3-carforward
glVertex2i(15,100);
glVertex2i(10,100);

glColor3ub(0, 102, 51);
glVertex2i(2,180);
glVertex2i(22,180);              //signboard-plate-3-carforward
glVertex2i(22,130);
glVertex2i(2,130);

glColor3ub(255,255,255);
glVertex2i(4,178);
glVertex2i(20,178);              //signboard-plate-3-carforward
glVertex2i(20,132);
glVertex2i(4,132);

glColor3ub(0, 102, 51);
glVertex2i(6,176);
glVertex2i(18,176);              //signboard-plate-3-carforward
glVertex2i(18,134);
glVertex2i(6,134);

glColor3ub(255,255,255);
glVertex2i(7,168);
glVertex2i(13,168);              //signboard-plate-3-sign-carforward
glVertex2i(13,162);
glVertex2i(7,162);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);       //signboard-plate-3-sign-carforward
glVertex2i(13,171);
glVertex2i(19,165);
glVertex2i(13,159);
glEnd();


glBegin(GL_QUADS);
glColor3ub(99,96,96);
glVertex2i(1285,170);
glVertex2i(1290,170);              //signboard-stand-4-carforward
glVertex2i(1290,100);
glVertex2i(1285,100);

glColor3ub(0, 102, 51);
glVertex2i(1278,180);
glVertex2i(1298,180);              //signboard-plate-4-carforward
glVertex2i(1298,130);
glVertex2i(1278,130);

glColor3ub(255,255,255);
glVertex2i(1280,178);
glVertex2i(1296,178);              //signboard-plate-4-carforward
glVertex2i(1296,132);
glVertex2i(1280,132);

glColor3ub(0, 102, 51);
glVertex2i(1282,176);
glVertex2i(1294,176);              //signboard-plate-4-carforward
glVertex2i(1294,134);
glVertex2i(1282,134);

glColor3ub(255,255,255);
glVertex2i(1283,168);
glVertex2i(1289,168);              //signboard-plate-4-sign-carforward
glVertex2i(1289,162);
glVertex2i(1283,162);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);       //signboard-plate-4-sign-carforward
glVertex2i(1289,171);
glVertex2i(1294,165);
glVertex2i(1289,159);
glEnd();

glBegin(GL_QUADS);
glColor3ub(73, 43, 0);
glVertex2i(0,92);
glVertex2i(0,99);

glColor3ub(167, 132, 88);   //river-bank
glVertex2i(1300,99);
glVertex2i(1300,92);


glEnd();

}

void boat()
{
glPushMatrix();
glTranslatef(run, 0.0, 0.0);

human_boat();

glBegin(GL_QUADS);   //boat lower part
glColor3ub (94, 124, 84);
glVertex2i(350,10);
glVertex2i(410,60);
glVertex2i(40,40);
glVertex2i(50,10);
glEnd();

glBegin(GL_QUADS);    //middle upper part
glColor3ub(238, 207, 161);
glVertex2i(250,50);
glVertex2i(275,50);
glVertex2i(270,60);
glVertex2i(250,60);
glEnd();

glBegin(GL_QUADS);   //lower upper part
glColor3ub(152,152,100);
glVertex2i(60,35);
glVertex2i(257,46);
glVertex2i(250,63);
glVertex2i(65,50);
glEnd();

glBegin(GL_QUADS);   //upper part
glColor3ub(238, 207, 161);
glVertex2i(90,50);
glVertex2i(200,58);
glVertex2i(180,85);
glVertex2i(95,85);
glEnd();

glBegin(GL_QUADS);    //all window
glColor3ub(8, 69, 112);
glVertex2i(150,83);
glVertex2i(178,83);
glVertex2i(196,60);
glVertex2i(150,57);

glVertex2i(125,80);
glVertex2i(145,80);
glVertex2i(145,65);
glVertex2i(125,65);

glVertex2i(100,80);
glVertex2i(120,80);
glVertex2i(120,65);
glVertex2i(100,65);

glEnd();


    glBegin(GL_QUADS);

     glColor3ub(150, 160, 170);
     glVertex2i(259,125);      //boat flag
     glVertex2i(262,125);
     glVertex2i(262,60);
     glVertex2i(259,60);

     glEnd();

     if(!night){
     glBegin(GL_QUADS);
     glColor3ub(0, 106, 78);
     glVertex2i(205,125);      //boat-flag-green
     glVertex2i(259,125);
     glVertex2i(259,90);
     glVertex2i(205,90);

    glEnd();

  glBegin(GL_POLYGON);            //boat flag-cir
    glColor3ub(244, 42, 65);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(232+cos(angle)*11,107.5+sin(angle)*11);

    }
    glEnd();
     }

glPopMatrix();
}

void cloud1()
{
    glPushMatrix();
    glTranslatef(run1, 80.0, 0.0);


    glBegin(GL_POLYGON);        //Cloud 1
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(500+cos(angle)*15,615+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(510+cos(angle)*15,625+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(520+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(532+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(545+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();

}

void cloud2()
{
    glPushMatrix();

glTranslatef(run2, 0.0, 0.0);                                //cloud-2

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(100+cos(angle)*15,615+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(110+cos(angle)*15,625+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(120+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(132+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(142+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
}

void cloud3()
{
        //cloud-3

glPushMatrix();

glTranslatef(run3, 30.0, 0.0);

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1000+cos(angle)*15,615+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1010+cos(angle)*15,625+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1020+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1032+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1042+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
}

void cloud4()
{
    glPushMatrix();

glTranslatef(run4+80, 70.0, 0.0);                                //cloud-2

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(100+cos(angle)*15,615+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(110+cos(angle)*15,625+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(120+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(132+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(142+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();
}

void cloud5()
{
    glPushMatrix();
    glTranslatef(run5+400, -20.0, 0.0);


    glBegin(GL_POLYGON);        //Cloud 1
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(500+cos(angle)*15,615+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(510+cos(angle)*15,625+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(520+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(532+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(545+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();
    glPopMatrix();

}


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);

sky();
sun_d();
sun_u();

Night();
star();
moon();

cloud1();
cloud2();
plane();
cloud3();
cloud4();
cloud5();

basepart();
grasspart();
playground();
mini_tree2();
mini_tree3();

watch_tower1();
watch_tower2();

hut1();
hut2();
hut3();
building();//Add Flag
building_complex();

grass();
human_building_front();
grass1();
grass2_heli();
grass3_heli();
grass4_heli();
grass5_heli();
grass6_heli();
grass7_heli();

//mini_tree1();

tree_upper_left();
tree_upper_middle();
tree_upper_right();
tree_uppermost_right();


memorial();
memorial_front_border();
memorial_lake();
memorial_flag();
flower();
helipad();

//Human-check
tree_middle_right();
tree_middle_left();

human_field();//added 25 people


//tree_upper_vertical();
//tree_lower_vertical();
//Human-check

river();
footpath() ;//Change color

human1();
human2();
human3();

fence();
human_walking();
human_walking_back();
heli();
human_heli();

road();
road_signboard_car_behind();
bus();
jeep();
road_signboard_car_forward();
boat();



glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.5, 0.8, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1300.0, 0.0, 750.0);
}


int main(int argc, char** argv)
{
    cout << endl;
    cout << "\t*********************Victory Day**********************\n";
    cout << "\t|Press P : For Sun Rise (Morning-Noon)               |\n";
    cout << "\t|Press O : For Sun Set (Noon-Evening)                |\n";
    cout << "\t|Press I : For Night Mode                            |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press R : For Rain                                  |\n";
    cout << "\t|Press T : To Stop The Rain                          |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press Q : To On-board Pilot inside the helicopter   |\n";
    cout << "\t|Press Q : To Fly the helicopter                     |\n";
    cout << "\t|Press W : To Land the helicopter                    |\n";
    cout << "\t|Press W : To Remove Pilot from the helicopter       |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press E : To Fly the Plane                          |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press D : To Forward the Jeep                       |\n";
    cout << "\t|Press A : To Backward the Jeep                      |\n";
    cout << "\t|Press S : To Stop the Jeep                          |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press C : To Backward the Bus                       |\n";
    cout << "\t|Press Z : To Forward the Bus                        |\n";
    cout << "\t|Press X : To Stop the Bus                           |\n";
    cout << "\t|----------------------------------------------------|\n";
    cout << "\t|Press Space : To On/Off all vehicle                 |\n";
    cout << "\t******************************************************\n";




glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (1300, 750);
glutInitWindowPosition (10, 10);
glutCreateWindow ("Victory Day");
glutDisplayFunc(myDisplay);
glutKeyboardFunc(myKeyboard);
glutTimerFunc(25, update, 0);
myInit ();
glutMainLoop();
return 0;
}
