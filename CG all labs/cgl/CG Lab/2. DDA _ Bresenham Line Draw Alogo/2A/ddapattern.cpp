#include<iostream>

#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

double X1, Y1, X2, Y2;

/*float round_value(float v)
{
  return floor(v + 0.5);
}*/
void LineDDA(void)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>=abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  /* Clears buffers to preset values */
  glClear(GL_COLOR_BUFFER_BIT);
glPointSize(4);
  /* Plot the points */
  glBegin(GL_POINTS);
  /* Plot the first point */
  glVertex2d(x,y);
  int k,j;
  /* For every step, find an intermediate vertex */
  for(k=1;k<=steps;k++)
  {
    x+=xInc;
    y+=yInc;
//glVertex2d(x,y);
/*for(j=0;j<15;j++)
{
	glVertex2d(x+j,y+j);
}
*/
    
			if(k%16<=8)
			{
				glVertex2d(x,y);
			}
			
		
			/*if(k%4==2)
			{
				glVertex2d(x,y);
			}
			
		
			if(k%16<=4)
			{
				glVertex2d(x,y);
			}
			if(k%8==2)
			{
				glVertex2d(x,y);
			}*/
		
	
 	 

  
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
void Init()
{
  /* Set clear color to white */
  glClearColor(0.0,1.0,0.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{ 
 /*cout<<"\nDDA Line Draw Algorithm\n";
 cout<<"\n1. Simple Line\n";
 cout<<"\n2. Dashed Line\n";
 cout<<"\n3. Center Line\n";
cout"\nEnteryour choice\n";
	cin>>ch;*/	
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
  glutCreateWindow("DDA_Line");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(LineDDA);

 /* Keep displaying untill the program is closed */
  glutMainLoop();
return 0;
}

