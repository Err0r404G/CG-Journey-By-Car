#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;


/// **************************************************************************************************************************************************
/// ******************************************************** >>> SAKIB SADMAN<<< ************************************************************************
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

    // --- Window Initialization ---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(200, 50);
    glutCreateWindow(" A Journey By Car ");


    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
