#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

double X1, Y1, X2, Y2;

void LineDDA() {
    double dx = X2 - X1;
    double dy = Y2 - Y1;
    double steps = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);
    float xInc = dx / steps;
    float yInc = dy / steps;
    float x = X1;
    float y = Y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glBegin(GL_POINTS);
    for (int k = 0; k <= steps; k++) {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
    glFlush();
}

void Init() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    cout << "Enter Point1 (X1 Y1): ";
    cin >> X1 >> Y1;
    cout << "Enter Point2 (X2 Y2): ";
    cin >> X2 >> Y2;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("DDA Line");
    Init();
    glutDisplayFunc(LineDDA);
    glutMainLoop();
    return 0;
}

