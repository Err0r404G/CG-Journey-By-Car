#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

<<<<<<< HEAD
bool scenarioSAKIB = true;


/// **************************************************************************************************************************************************
/// ******************************************************** >>> SAKIB SADMAN <<< ************************************************************************
/// **************************************************************************************************************************************************
bool isDay = true;

/// #############  Circle  #############
=======

/// **************************************************************************************************************************************************
/// ******************************************************** >>> SAKIB SADMAN<<< ************************************************************************
/// **************************************************************************************************************************************************

bool isDay = true;


/// #############  Circle  #############

>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
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

<<<<<<< HEAD
=======

>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
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
<<<<<<< HEAD
=======

>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
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
<<<<<<< HEAD
=======

>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
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

<<<<<<< HEAD
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
}

/// ##############################################################  Display  ###############################################################
void display()
{
    if(scenarioSAKIB) SAKIB();

    glutSwapBuffers();
}





int main(int argc, char** argv)
{


=======




void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Background color based on day/night
    if(isDay)
        glClearColor(0.5, 0.8, 1.0, 1.0); // Sky blue
    else
        glClearColor(0.05, 0.05, 0.2, 1.0); // Night

    sun();
    moon();

    glutSwapBuffers();
}
void setup()
{
    glClearColor(1,0,0,1);


}


int main(int argc, char** argv) {

>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
    // --- Window Initialization ---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(200, 50);
<<<<<<< HEAD
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


    glutMainLoop();

=======
    glutCreateWindow(" A Journey By Car ");


    glutDisplayFunc(display);

    glutMainLoop();
>>>>>>> 4d0cfefd661412edf0ece957fde93eff38783730
    return 0;
}
