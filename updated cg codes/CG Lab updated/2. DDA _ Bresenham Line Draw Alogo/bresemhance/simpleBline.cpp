#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

double X1, Y1, X2, Y2;

void LineBresenham() {
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int dx1 = abs(dx);
    int dy1 = abs(dy);
    int twodx1 = 2 * dx1;
    int twody1 = 2 * dy1;
    int twodx1_dy1 = twodx1 - dy1;
    int twody1_dx1 = twody1 - dx1;
    int x = X1;
    int y = Y1;

    int xInc = (dx >= 0) ? 1 : -1;
    int yInc = (dy >= 0) ? 1 : -1;

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glBegin(GL_POINTS);

    if (dx1 >= dy1) {
        int p = twody1 - dx1;
        while (x != X2) {
            glVertex2i(x, y);
            x += xInc;
            if (p >= 0) {
                y += yInc;
                p += twodx1;
            } else {
                p += twody1;
            }
        }
    } else {
        int p = twodx1 - dy1;
        while (y != Y2) {
            glVertex2i(x, y);
            y += yInc;
            if (p >= 0) {
                x += xInc;
                p += twody1;
            } else {
                p += twodx1;
            }
        }
    }

    glVertex2i(X2, Y2);

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
    glutCreateWindow("Bresenham Line");
    Init();
    glutDisplayFunc(LineBresenham);
    glutMainLoop();
    return 0;
}

