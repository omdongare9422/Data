#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int xc = 320, yc = 240;
int radius;

void plot_point(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glVertex2i(-x + xc, y + yc);
    glVertex2i(-x + xc, -y + yc);
    glVertex2i(x + xc, -y + yc);
    glVertex2i(y + xc, x + yc);
    glVertex2i(-y + xc, x + yc);
    glVertex2i(-y + xc, -x + yc);
    glVertex2i(y + xc, -x + yc);
    glEnd();
}

void bresenham_circle(int r) {
    int x = 0, y = r;
    int s = 3 - (2 * r);
    plot_point(x, y);
    while (x <= y) {
        if (s <= 0) {
            s = s + (4 * x) + 6;
            x++;
        } else {
            s = s + (4 * x) - (4 * y) + 10;
            x++;
            y--;
        }
        plot_point(x, y);
    }
    glFlush();
}

void draw_circle() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham_circle(radius);
}

void Init() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv) {
    std::cout << "Enter radius: ";
    std::cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Bresenham Circle");
    Init();
    glutDisplayFunc(draw_circle);
    glutMainLoop();
    return 0;
}

