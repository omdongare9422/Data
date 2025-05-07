#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init() {
    glClearColor(1, 0, 0, 0);
    glColor3f(0, 0, 1);
    gluOrtho2D(0, 640, 0, 480);
}

void renderBitmapString(float x, float y, const char* text) {
    const char* c;
    glRasterPos3f(x, y, 0);
    for (c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    const char* text = "SITS";

    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2i(glutGet(GLUT_WINDOW_WIDTH) / 2, 0);
        glVertex2i(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT));
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(0, glutGet(GLUT_WINDOW_HEIGHT) / 2);
        glVertex2i(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) / 2);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);
        glVertex2i(200, 100);
        glVertex2i(200, 200);
        glVertex2i(150, 300);
        glVertex2i(100, 200);
    glEnd();

    renderBitmapString(400, 350, text);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Pentagon Assignment");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

