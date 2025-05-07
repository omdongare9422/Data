#include <GL/glut.h>
#include <cmath>
#include <vector>
using namespace std;

int width = 800, height = 800;
int lineType = 1; // 1: Simple, 2: Dotted, 3: Dashed, 4: Solid
vector<pair<int, int>> points;

int convertX(int x) {
    return x - width / 2;
}

int convertY(int y) {
    return height / 2 - y;
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Bresenham's Line Drawing Algorithm with styling
void drawBresenham(int x1, int y1, int x2, int y2, int style) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;
    bool isSteep = dy > dx;

    if (isSteep) {
        swap(dx, dy);
    }

    int p = 2 * dy - dx;
    int x = x1, y = y1;

    for (int i = 0; i <= dx; ++i) {
        bool draw = false;
        switch (style) {
            case 1: draw = true; break;
            case 2: draw = (i % 5 == 0); break;
            case 3: draw = ((i / 5) % 2 == 0); break;
            case 4: draw = true; break;
        }

        if (draw) drawPixel(x, y);

        if (p >= 0) {
            if (isSteep)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }

        if (isSteep)
            y += sy;
        else
            x += sx;

        p += 2 * dy;
    }
}

void drawAxes() {
    glColor3f(1, 1, 1);
    drawBresenham(-width / 2, 0, width / 2, 0, 4);  // X-axis
    drawBresenham(0, -height / 2, 0, height / 2, 4); // Y-axis
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(0, 1, 0);
    if (points.size() == 2) {
        drawBresenham(points[0].first, points[0].second, points[1].first, points[1].second, lineType);
    }

    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (points.size() < 2) {
            points.emplace_back(convertX(x), convertY(y));
        } else {
            points.clear();
            points.emplace_back(convertX(x), convertY(y));
        }
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1': lineType = 1; break;
        case '2': lineType = 2; break;
        case '3': lineType = 3; break;
        case '4': lineType = 4; break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 1, 0);
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Bresenham Line Drawing with Styles - Mouse Interface");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

