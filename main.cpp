#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0);

    glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex2f(0.0, 0.0);
        glColor3f(0,1,1);
        glVertex2f(0.9, 0.9);
        glEnd();


    glFlush();
}
void setup()
{
    glClearColor(1,0,0,1);


}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Pronoy");
    setup();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
