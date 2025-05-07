#include<iostream>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
using namespace std;

//double X1, Y1, X2, Y2;
int X1,Y1,X2,Y2;

int sign(int a){
	if(a>0){
		return 1;
	}
	else if(a<0){
		return -1;
	}
	else{
		return 0;
	}
}	

void LineBR(void){
	int dx=abs(X2-X1);
	int dy=abs(Y2-Y1);
	int steps;
	int k;
	int X=X1,Y=Y1;
	steps=((dx)>=(dy))?((dx)):((dy));
	int g=(2*dy)-dx;
	int s1=sign(X2-X1);
	int s2=sign(Y2-Y1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(X,Y);
	for(k=1;k<=steps;k++){
		//glVertex2d(X,Y);
		if(g>=0){
			Y=Y+s2;
			g=g-(2*dx);
			X=X+s1;
			g=g+(2*dy);
			glVertex2i(X,Y);
		}
		else{
		X=X+s1;
		g=g+(2*dy);
		glVertex2i(X,Y);
		}
	}
    glEnd();
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,0);
    glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,glutGet(GLUT_WINDOW_HEIGHT)); 
	glVertex2i(0,glutGet(GLUT_WINDOW_HEIGHT)/2);
	glVertex2i(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)/2);
    glEnd();
	glFlush();
}

void Init(){
  /* Set clear color to white */
  glClearColor(0.0,1.0,0.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv){
    cout<<"Enter two end points of the line to be drawn:\n";
    //printf("\n************************************");
    cout<<"Enter Point1( X1 , Y1):\n";
    cin>>X1>>Y1;
    cout<<"Enter Point1( X2 , Y2):\n";
    cin>>X2>>Y2;
    X1=X1+320;
    Y1=Y1+240;
    X2=X2+320;
    Y2=Y2+240;
    /* Initialise GLUT library */
    glutInit(&argc,argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("Bresenham's_Line");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(LineBR);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}

