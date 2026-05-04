#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

bool scenarioSAKIB = true;


/// **************************************************************************************************************************************************
/// ******************************************************** >>> SAKIB SADMAN <<< ************************************************************************
/// **************************************************************************************************************************************************
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}

void V_cloud3()
{
    glPushMatrix();
    glTranslatef(V_moveCloud3, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 700, y = 650, r = 20;
    circle(x, y-15, r);
    circle(x+25, y-10, r);
    circle(x-25, y-10, r);
    circle(x-50, y, r);
    circle(x+50, y, r);
    circle(x+30, y+15, r+5);
    circle(x, y+25, r+5);
    circle(x-30, y+15, r+5);

    glBegin(GL_QUADS);
    glVertex2f(650,630);
    glVertex2f(750,630);
    glVertex2f(750,670);
    glVertex2f(650,670);
    glEnd();

    glPopMatrix();
}

void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud3(int value)
{
    if(!V_cloudPaused3)
    {
        V_moveCloud3 -= V_cloudSpeed3;
        if (V_moveCloud3 < -800)
        {
            V_moveCloud3 = 420;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, V_updateCloud3, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

/// ##############################################################  Garden  ###############################################################
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
    /// Triangle Tree
    int shift = 70;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,205);
        glVertex2f(25 + shift * i,205);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(10  + shift * i,225);
        glVertex2f(30 + shift * i,225);
        glVertex2f(20 + shift * i,235);

        glVertex2f(10  + shift * i,230);
        glVertex2f(30 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }
}

/// ############################################################## Metro Flyover  ###############################################################
void flyOver()
{
    ///Pillar
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    for(int x = 50; x<1000; x+=100)
    {
        glVertex2f(x,   205);
        glVertex2f(x+15,205);
        glVertex2f(x+15,275);
        glVertex2f(x,   275);
    }
    glEnd();

    /// Pillar upper box
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_TRIANGLES);
    for(int x = 40; x<1000; x+=100)
    {
        glVertex2f(x,     275);
        glVertex2f(x+35,  275);
        glVertex2f(x+15,255);
    }
    glEnd();

    if(isDay)
        glColor3f(0.80f, 0.80f, 0.80f);
    else
        glColor3f(.4,.4,.4);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0,   275);
    glVertex2f(1000,275);
    glEnd();

    ///Bridge body
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(0,   277);
    glVertex2f(1000,277);
    glVertex2f(1000,288);
    glVertex2f(0,   288);
    glEnd();
}

/// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.839f, 0.443f, 0.235f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);

    for(int x = 10; x<1000; x+=20)
    {
        glVertex2f(x,170);
        glVertex2f(x,175);

        glVertex2f(x+10,175);
        glVertex2f(x+10,180);

        glVertex2f(x,180);
        glVertex2f(x,185);

        glVertex2f(x+10,185);
        glVertex2f(x+10,190);
    }

    glEnd();

    //Upper 2 lines
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(0,   200);
    glVertex2f(1000,200);

    glVertex2f(0,   205);
    glVertex2f(1000,205);

    for(int i = 0; i< 1000; i+=45)
    {
        glLineWidth(1);
        glVertex2f(i, 190);
        glVertex2f(i, 205);

        glVertex2f(i+5, 190);
        glVertex2f(i+5, 205);
    }
    glEnd();

}

/// ##############################################################  Road  ###############################################################
void road()
{
    if (isDay)
        glColor3f(.37f, .37f, .37f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.15f, 0.15f, 0.15f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// ####################################################################### Building ###########################################################

void building()
{
    /// 1st Building
    if(isDay)
        glColor3f(0.92f, 0.92f, 0.92f);
    else
        glColor3f(0.55f, 0.55f, 0.55f);

    // body
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    // Top
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // window
    glBegin(GL_QUADS);
    for(int x = 18; x<80; x+=27 )
    {
        for(int y = 500; y>200; y-=60)
        {
            if(isDay)
                glColor3f(1,1,1);
            else
                glColor3f(0.15f, 0.07f, 0.03f);

            glVertex2f(x-2,  y+7);
            glVertex2f(x+22, y+7);
            glVertex2f(x+22, y-20);
            glVertex2f(x-2,  y-20);

            if(isDay)
                glColor3f(0.52f, 0.78f, 0.96f);
            else
                glColor3f(1.0f, 1.0f, 0.5f);

            glVertex2f(x,  y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,  y-20);
        }
    }

    // Window white border
    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    for(int y = 480; y > 200; y -= 60 )
    {
        glVertex2f(5,   y   );
        glVertex2f(105, y   );
        glVertex2f(105, y-15);
        glVertex2f(5,   y-15);
    }
    glEnd();

    /// $$$$$$$$$$$$$$$$$$ 2nd Building $$$$$$$$$$$$$$
    glBegin(GL_QUADS);

    //body Left half
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);

    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    //right half
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glVertex2f(135,  200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135,  400);

    // Top
    if(isDay)
        glColor3f(0.45f, 0.24f, 0.13f);
    else
        glColor3f(0.25f, 0.15f, 0.10f);

    glVertex2f(90,  400);
    glVertex2f(180, 400);
    glVertex2f(165, 425);
    glVertex2f(105, 425);
    glEnd();

    // Left triangles
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(115, 400);
    glVertex2f(135, 425);
    glEnd();

    // Right triangles
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(155, 400);
    glVertex2f(135, 425);
    glEnd();

    // All border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(88, 400);
    glVertex2f(115, 400);

    glVertex2f(115, 398);
    glVertex2f(135, 427);

    glVertex2f(135, 427);
    glVertex2f(155, 400);

    glVertex2f(153, 400);
    glVertex2f(182, 400);

    //body Lines
    glVertex2f(90, 340);
    glVertex2f(180,340);

    glVertex2f(90, 280);
    glVertex2f(180,280);

    glVertex2f(90, 220);
    glVertex2f(180,220);

    glEnd();

    //window
    //Outer quad
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 100; x<180; x+=45)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }
    }

    if(isDay)
        glColor3f(0.67f, 0.77f, 0.89f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    //inner quad
    for(int x = 102; x<180; x+=45)
    {
        for(int y = 382; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+21, y);
            glVertex2f(x+21, y-25);
            glVertex2f(x,    y-25);
        }
    }
    glEnd();

    // On window border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x =100; x<180; x+=45)
        for(int y = 372; y>200; y-=60)
        {
            {
                glVertex2f(x,y);
                glVertex2f(x+25,y);

                glVertex2f(x+12.5,y+10);
                glVertex2f(x+12.5,y);
            }
        }

    glEnd();

    /// 3rd Building
    // Left side
    if (isDay)
        glColor3f(0.84f, 0.30f, 0.37f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    // Right side
    if (isDay)
        glColor3f(0.90f, 0.45f, 0.50f);
    else
        glColor3f(0.60f, 0.25f, 0.30f);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);
    ;
    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 198; x < 280; x += 47)
    {
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    }
    glEnd();

    // blue
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 202; x < 280; x += 47)
    {
        for(int y=450; y>220; y-=70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }
    }
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 198; x < 280; x += 47)
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x+13, y);
            glVertex2f(x+13, y-32);

            glVertex2f(x, y-13);
            glVertex2f(x+26, y-13);

            glVertex2f(x,    y-22);
            glVertex2f(x+26, y-22);

        }

    glEnd();

    ///              ***> 4th Building <***
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    //Top White
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    // Body white quard
    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200);
    glVertex2f(320, 510);

    glVertex2f(340, 200);
    glVertex2f(340, 520);

    glVertex2f(360, 200);
    glVertex2f(360, 530);

    glVertex2f(380, 200);
    glVertex2f(380, 535);

    if (isDay)
        glColor3f(0.30f, 0.42f, 0.51f);
    else
        glColor3f(0.18f, 0.28f, 0.36f);


    for(int y = 455; y> 200; y-=30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);


    glEnd();

    /// 6th Building
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    //Body
    glVertex2f(550, 200);
    glVertex2f(640, 200);
    glVertex2f(640, 400);
    glVertex2f(550, 400);

    //top red
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glVertex2f(550, 415);
    glVertex2f(640, 415);
    glVertex2f(640, 400);
    glVertex2f(550, 400);
    glEnd();

    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    for(int x = 555; x<640; x+=13)
        circle(x,400,7);

    //body red lines
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2f(550, 290);
    glVertex2f(640, 290);

    glVertex2f(550, 350);
    glVertex2f(640, 350);

    glVertex2f(550, 230);
    glVertex2f(640, 230);
    glEnd();

    // Window white color
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glBegin(GL_QUADS);
    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {

            glVertex2f(x,  y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,  y-30);
        }
    }
    // window blue glass
    if(isDay)
        glColor3f(0.44f, 0.63f, 0.78f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {
            glVertex2f(x+3,  y-3);
            glVertex2f(x+22, y-3);
            glVertex2f(x+22, y-27);
            glVertex2f(x+3,  y-27);
        }
    }
    glEnd();

    /// Window white line
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 561; x<640; x+=40)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,  y);
            glVertex2f(x+22, y);

            glVertex2f(x+12, y);
            glVertex2f(x+12, y-20);
        }
    }
    glEnd();

    /// 5th Building
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.96f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
    //Main Body
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    //Upper box
    glVertex2f(440, 440);
    glVertex2f(530, 440);
    glVertex2f(530, 480);
    glVertex2f(440, 480);

    glVertex2f(450, 495);
    glVertex2f(520, 495);
    glVertex2f(520, 505);
    glVertex2f(450, 505);

    glVertex2f(460, 505);
    glVertex2f(510, 505);
    glVertex2f(510, 515);
    glVertex2f(460, 515);

    //Top Bar
    glVertex2f(470, 515);
    glVertex2f(500, 515);
    glVertex2f(500, 525);
    glVertex2f(470, 525);

    glEnd();

    //Body white bar
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(417, 420);
    glVertex2f(553, 420);
    glEnd();

    //top white
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(435, 495);
    glVertex2f(535, 495);
    glVertex2f(535, 480);
    glVertex2f(435, 480);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(437, 479);
    glVertex2f(533, 479);
    glEnd();

    //blue glass
    if (isDay)
        glColor3f(0.38f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    //body
    glBegin(GL_QUADS);
    for(int x = 435; x<550; x+=40)
    {
        glVertex2f(x, 200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x, 400);
    }

    //top
    for(int x = 450; x<520; x+=20)
    {
        glVertex2f(x,    470);
        glVertex2f(x+11, 470);
        glVertex2f(x+11, 440);
        glVertex2f(x,    440);
    }
    glEnd();

    glColor3f(0.38f, 0.54f, 0.66f);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(455, 499);
    glVertex2f(515, 499);

    glVertex2f(465, 509);
    glVertex2f(505, 509);

    glVertex2f(475, 519);
    glVertex2f(495, 519);

    glEnd();

    //Flag
    if(isDay)
        glColor3f(0.00f, 0.42f, 0.31f);
    else
        glColor3f(0.00f, 0.25f, 0.18f);

    glBegin(GL_QUADS);
    glVertex2f(485, 555);
    glVertex2f(510, 555);
    glVertex2f(510, 540);
    glVertex2f(485, 540);
    glEnd();

    if(isDay)
        glColor3f(0.96f, 0.16f, 0.25f);
    else
        glColor3f(0.6f, 0.1f, 0.15f);

    circle(497.5, 547.5, 4);

    // Bamboo
    if(isDay)
        glColor3f(0.83f, 0.65f, 0.42f);
    else
        glColor3f(0.55f, 0.45f, 0.30f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(485, 525);
    glVertex2f(485, 555);
    glEnd();



    /// 7th Building
    if (isDay)
        glColor3f(0.84f, 0.74f, 0.62f);
    else
        glColor3f(0.50f, 0.40f, 0.30f);

    //body
    glBegin(GL_QUADS);
    glVertex2f(640, 200);
    glVertex2f(720, 200);
    glVertex2f(720, 380);
    glVertex2f(640, 380);

    //window
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int y = 373; y>200; y-=30)
    {
        glVertex2f(647, y);
        glVertex2f(713, y);
        glVertex2f(713, y-21);
        glVertex2f(647, y-21);
    }

    if (isDay)
        glColor3f(0.52f, 0.78f, 0.96f);
    else
        glColor3f(0.94f, 0.69f, 0.35f);

    for(int y = 370; y>200; y-=30)
    {
        glVertex2f(650, y);
        glVertex2f(710, y);
        glVertex2f(710, y-15);
        glVertex2f(650, y-15);
    }
    glEnd();

    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    // window lines
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 670; x<710; x+=20)
        for(int y = 370; y>200; y-=30)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-15);
        }
    glEnd();

    /// 8th Building
    if (isDay)
        glColor3f(0.39f, 0.30f, 0.32f);
    else
        glColor3f(0.19f, 0.15f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    // top bar
    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //4 corner window
    glBegin(GL_QUADS);
    for(int x=759; x<950; x+=150)
        for(int y = 400; y>250; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x, y-40);
        }
    // middle 2 window
    for(int x=743; x<950; x+=182)
    {
        glVertex2f(x,    340);
        glVertex2f(x+32, 340);
        glVertex2f(x+32, 300);
        glVertex2f(x,    300);
    }
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //window white circle
    //4 corner
    for(int x = 759; x<940; x+=150)
        for(int y = 360; y>200; y-=120)
            for(int xx = x; xx<x+34; xx+=8)
                circle(xx,y,4);
    for(int x = 743; x<950; x+=182)
        for(int xx = x; xx<x+34; xx+=8)
            circle(xx,300,4);

    if(isDay)
        glColor3f(0.44f, 0.65f, 0.80f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    // blue glass
    for(int x=763; x<950; x+=150)
        for(int y = 397; y>250; y-=120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }

    for(int x=747; x<950; x+=182)
    {
        glVertex2f(x,    337);
        glVertex2f(x+24, 337);
        glVertex2f(x+24, 303);
        glVertex2f(x,    303);
    }

    glEnd();

    // Lines of windows
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x<940; x+=150)
        for(int y = 400; y>200; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }

    // Middle window lines
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 759; x<950; x+=182)
    {
        glVertex2f(x, 340);
        glVertex2f(x, 300);
    }

    glEnd();

    /// ***> 9th Building <***
    if (isDay)
        glColor3f(0.51f, 0.73f, 0.75f);
    else
        glColor3f(0.29f, 0.42f, 0.43f);

    glBegin(GL_QUADS);
    glVertex2f(800, 200);
    glVertex2f(850, 200);
    glVertex2f(850, 480);
    glVertex2f(800, 480);

    if (isDay)
        glColor3f(0.47f, 0.67f, 0.69f);
    else
        glColor3f(0.23f, 0.34f, 0.35f);

    glVertex2f(850, 200);
    glVertex2f(900, 200);
    glVertex2f(900, 480);
    glVertex2f(850, 480);

    // Top bar
    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    glVertex2f(795, 490);
    glVertex2f(905, 490);
    glVertex2f(905, 475);
    glVertex2f(795, 475);

    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    for (int y = 410; y > 200; y -= 70)
    {
        glVertex2f(800, y);
        glVertex2f(900, y);
        glVertex2f(900, y - 10);
        glVertex2f(800, y - 10);
    }

    glEnd();

// Window
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for (int x = 810; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glVertex2f(x, y);
            glVertex2f(x + 26, y);
            glVertex2f(x + 26, y - 30);
            glVertex2f(x, y - 30);
        }
    }
    glEnd();

    halfCircle(823, 450, 13);
    halfCircle(877, 450, 13);
    halfCircle(823, 380, 13);
    halfCircle(877, 380, 13);
    halfCircle(823, 310, 13);
    halfCircle(877, 310, 13);
    halfCircle(823, 240, 13);
    halfCircle(877, 240, 13);

// Red
    glColor3f(1, 0, 0);
    for (int x = 814; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + 18, y);
            glVertex2f(x + 18, y - 27);
            glVertex2f(x, y - 27);
            glEnd();
        }
    }

    halfCircle(823, 450, 9);
    halfCircle(877, 450, 9);
    halfCircle(823, 380, 9);
    halfCircle(877, 380, 9);
    halfCircle(823, 310, 9);
    halfCircle(877, 310, 9);
    halfCircle(823, 240, 9);
    halfCircle(877, 240, 9);

    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 823; x<900; x+=54)
        for(int y = 460; y>200; y-=70)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);

            glVertex2f(x-13, y-12);
            glVertex2f(x+13, y-12);

            glVertex2f(x-13, y-25);
            glVertex2f(x+13, y-25);

        }
    glEnd();
}









/// ##############################################################  SAKIB DISPLAY  ###############################################################
void SAKIB()
{
    glDisable(GL_LIGHTING);
    sky();

    // ==========================================
    // SUN/MOON LIGHTING SETUP (GL_LIGHT0)
    // ==========================================

    if(isDay)
    {
        // DAY MODE: SUN
        float sunX_SAKIB = 50.0f + moveSun;
        float sunY_SAKIB = 650.0f;
        GLfloat lightPos[] = { sunX_SAKIB, sunY_SAKIB, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);
        GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }
    else
    {
        // NIGHT MODE: MOON
        float moonX_SAKIB = 850.0f + moveMoon;
        float moonY_SAKIB = 650.0f;
        GLfloat lightPos[] = { moonX_SAKIB, moonY_SAKIB, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat moonLightColor[] = { 0.4f, 0.4f, 0.5f, 1.0f }; // Dimmer light for night
        glLightfv(GL_LIGHT0, GL_DIFFUSE, moonLightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, moonLightColor);
        GLfloat ambientColor[] = { 0.25f, 0.25f, 0.3f, 1.0f }; // Increased ambient for brighter night
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }

    // Draw sun/moon (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    moon();
    sun();
    glEnable(GL_LIGHTING);
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();

    garden();
    flyOver();
    roadSideWall();
    road();


    building();

}


/// ##############################################################  CONTROL  ###############################################################

void selectKeyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }
}

void display()
{
    if(scenarioSAKIB) SAKIB();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{


    // ==========================================
    // 2. MAIN CITY CONTROLS
    // ==========================================
    cout<<"********** >>> Main City Specifics <<< **********"<<endl;
    cout<<"Press D / N    : (Day/Night)"<<endl;

    // --- Window Initialization ---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Going Through Places - A Journey By Car");

    // --- Graphics & Smoothing Setup ---
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Shade Model:
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);


    glEnable(GL_LIGHT0);   // Sun/Moon
    glEnable(GL_LIGHT1);   // Street Lamps Group 1
    glEnable(GL_LIGHT2);   // Street Lamps Group 2
    glEnable(GL_LIGHT3);   // CyberTruck Headlight

    glEnable(GL_COLOR_MATERIAL);

    // Set Initial Light Properties
    GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);

    // Ambient Light
    GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);

    // --- Projection Setup ---
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    // --- Callback Registration ---
    glutDisplayFunc(display);

    // Timers: SAKIB
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(16, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(16, V_updateCloud4, 0);
    glutTimerFunc(2, updateSun, 0);
    glutTimerFunc(16, updateMoon, 0);



    // Input Callbacks
    glutKeyboardFunc(selectKeyboard);



    glutMainLoop();

    return 0;
}

