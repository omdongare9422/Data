#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int points[3][2] = { {100, 100}, {300, 100}, {200, 300} }; // Vertices of the triangle
int n = 3; // Number of points in the triangle

void draw_triangle() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++) {
        glVertex2i(points[i][0], points[i][1]);
    }
    glEnd();
}

void flood_fill(int x, int y, int oldColor[3], int newColor[3]) {
    GLubyte pixel[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);

    if (pixel[0] == oldColor[0] && pixel[1] == oldColor[1] && pixel[2] == oldColor[2]) {
        glBegin(GL_POINTS);
        glColor3ub(newColor[0], newColor[1], newColor[2]);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        flood_fill(x + 1, y, oldColor, newColor);
        flood_fill(x - 1, y, oldColor, newColor);
        flood_fill(x, y + 1, oldColor, newColor);
        flood_fill(x, y - 1, oldColor, newColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Draw the triangle in black
    draw_triangle();

    int oldColor[3] = {255, 255, 255}; // Assuming white background
    int newColor[3] = {255, 147, 10}; 
    flood_fill(200, 200, oldColor, newColor); // Start flood-fill at (200, 200)

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    gluOrtho2D(0, 640, 0, 480); // Set 2D orthogonal view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple Triangle and Flood Fill");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

