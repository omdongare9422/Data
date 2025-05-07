#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

typedef struct {
    float x;
    float y;
} PT;

int n;
PT p1, p2, p[20], pp[20];
int i, j;

void left() {
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].x < p1.x && p[i + 1].x >= p1.x) {
            pp[j].y = (p[i + 1].x - p[i].x != 0)
                      ? (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p1.x - p[i].x) + p[i].y
                      : p[i].y;
            pp[j++].x = p1.x;
            pp[j] = p[i + 1];
            j++;
        } else if (p[i].x >= p1.x && p[i + 1].x >= p1.x) {
            pp[j++] = p[i + 1];
        } else if (p[i].x >= p1.x && p[i + 1].x < p1.x) {
            pp[j].y = (p[i + 1].x - p[i].x != 0)
                      ? (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p1.x - p[i].x) + p[i].y
                      : p[i].y;
            pp[j++].x = p1.x;
        }
    }
    for (i = 0; i < j; i++) p[i] = pp[i];
    p[j] = pp[0];
    n = j;
}

void right() {
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].x > p2.x && p[i + 1].x <= p2.x) {
            pp[j].y = (p[i + 1].x - p[i].x != 0)
                      ? (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p2.x - p[i].x) + p[i].y
                      : p[i].y;
            pp[j++].x = p2.x;
            pp[j] = p[i + 1];
            j++;
        } else if (p[i].x <= p2.x && p[i + 1].x <= p2.x) {
            pp[j++] = p[i + 1];
        } else if (p[i].x <= p2.x && p[i + 1].x > p2.x) {
            pp[j].y = (p[i + 1].x - p[i].x != 0)
                      ? (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p2.x - p[i].x) + p[i].y
                      : p[i].y;
            pp[j++].x = p2.x;
        }
    }
    for (i = 0; i < j; i++) p[i] = pp[i];
    p[j] = pp[0];
    n = j;
}

void top() {
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].y > p2.y && p[i + 1].y <= p2.y) {
            pp[j].x = (p[i + 1].y - p[i].y != 0)
                      ? (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p2.y - p[i].y) + p[i].x
                      : p[i].x;
            pp[j++].y = p2.y;
            pp[j] = p[i + 1];
            j++;
        } else if (p[i].y <= p2.y && p[i + 1].y <= p2.y) {
            pp[j++] = p[i + 1];
        } else if (p[i].y <= p2.y && p[i + 1].y > p2.y) {
            pp[j].x = (p[i + 1].y - p[i].y != 0)
                      ? (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p2.y - p[i].y) + p[i].x
                      : p[i].x;
            pp[j++].y = p2.y;
        }
    }
    for (i = 0; i < j; i++) p[i] = pp[i];
    p[j] = pp[0];
    n = j;
}

void bottom() {
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].y < p1.y && p[i + 1].y >= p1.y) {
            pp[j].x = (p[i + 1].y - p[i].y != 0)
                      ? (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p1.y - p[i].y) + p[i].x
                      : p[i].x;
            pp[j++].y = p1.y;
            pp[j] = p[i + 1];
            j++;
        } else if (p[i].y >= p1.y && p[i + 1].y >= p1.y) {
            pp[j++] = p[i + 1];
        } else if (p[i].y >= p1.y && p[i + 1].y < p1.y) {
            pp[j].x = (p[i + 1].y - p[i].y != 0)
                      ? (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p1.y - p[i].y) + p[i].x
                      : p[i].x;
            pp[j++].y = p1.y;
        }
    }
    for (i = 0; i < j; i++) p[i] = pp[i];
    p[j] = pp[0];
    n = j;
}

void drawpolygon() {
    glColor3f(1.0, 0.0, 0.0);
    for (i = 0; i < n - 1; i++) {
        glBegin(GL_LINES);
        glVertex2f(p[i].x, p[i].y);
        glVertex2f(p[i + 1].x, p[i + 1].y);
        glEnd();
    }
    glBegin(GL_LINES);
    glVertex2f(p[n - 1].x, p[n - 1].y);
    glVertex2f(p[0].x, p[0].y);
    glEnd();
}

void myMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p1.x, p2.y);
        glEnd();
        left();
        right();
        top();
        bottom();
        drawpolygon();
        glFlush();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p1.x, p2.y);
    glEnd();
    drawpolygon();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
    cout << "Enter clipping window (left,bottom) and (right,top):\n";
    cout << "Left x: "; cin >> p1.x;
    cout << "Bottom y: "; cin >> p1.y;
    cout << "Right x: "; cin >> p2.x;
    cout << "Top y: "; cin >> p2.y;

    cout << "Enter number of polygon vertices: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << " - x: ";
        cin >> p[i].x;
        cout << "Vertex " << i + 1 << " - y: ";
        cin >> p[i].y;
    }
    p[n] = p[0];

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sutherland-Hodgman Polygon Clipping");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutMainLoop();

    return 0;
}


