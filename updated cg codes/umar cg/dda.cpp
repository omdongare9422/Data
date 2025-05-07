#include <GL/glut.h>
#include <cmath>
#include <vector>

using namespace std;

int lineType = 2; // 1: Simple, 2: Dotted, 3: Dashed, 4: Solid
vector<pair<int, int>> points;

// Set screen width and height
const int width = 800;
const int height = 800;

// Convert mouse click to OpenGL coordinates
int convertX(int x) {
    return x - width / 2;
}

int convertY(int y) {
    return height / 2 - y;
}

// Function to plot a pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// DDA Line Drawing Algorithm with style
void drawDDA(int x1, int y1, int x2, int y2, int style) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        bool draw = false;

        switch (style) {
            case 1: draw = true; break;                  // Simple Line
            case 2: draw = (i % 5 == 0); break;          // Dotted Line
            case 3: draw = ((i / 5) % 2 == 0); break;    // Dashed Line
            case 4: draw = true; break;                  // Solid Line
        }

        if (draw)
            drawPixel(round(x), round(y));

        x += xInc;
        y += yInc;
    }
}

// Draw X and Y axis
void drawAxes() {
    glColor3f(1, 1, 1);
    drawDDA(-width / 2, 0, width / 2, 0, 4);  // X-Axis
    drawDDA(0, -height / 2, 0, height / 2, 4); // Y-Axis
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(0, 1, 0);
    if (points.size() == 2) {
        drawDDA(points[0].first, points[0].second, points[1].first, points[1].second, lineType);
    }

    glFlush();
}

// Mouse callback
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

// Keyboard callback to switch line type
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1': lineType = 1; break; // Simple
        case '2': lineType = 2; break; // Dotted
        case '3': lineType = 3; break; // Dashed
        case '4': lineType = 4; break; // Solid
    }
    glutPostRedisplay();
}

// Initialize OpenGL
void init() {
    glClearColor(0, 0, 0, 0); // Black background
    glColor3f(0, 1, 0);       // Line color
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("DDA Line Drawing with Styles - Mouse Interface");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

