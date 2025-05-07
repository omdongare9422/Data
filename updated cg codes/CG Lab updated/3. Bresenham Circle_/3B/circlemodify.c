#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int X1,X2,Y2,Y1,R,R1,len;//y2,x2;


void Circle(int r)
{
		int xc,yc,s;

		xc=0;  //First point which will be on circumference of circle
		yc=r;

		s=3-(2*r);   //Decision parameter calculation

		glPointSize(4);        //To increase size of pixel
		glBegin(GL_POINTS);    //Points primitive started

		//glVertex2d(xc,yc);     
						//plotted first point using symmetry property
		glVertex2d(xc+X1,yc+Y1);  
		glVertex2d(-xc+X1,yc+Y1);  
		glVertex2d(-xc+X1,-yc+Y1);  		
		glVertex2d(xc+X1,-yc+Y1);  

		while(xc<=yc) 
		{
			if(s<=0)
			{
				//p=p+(2*xc)+1;
				s=s+(4*xc)+6;
				xc++;
			}
			else
			{
				//p=p+(2*(xc-yc))+1;
				s=s+(4*xc)-(4*yc)+10;
				xc++;
				yc--;
			}
			glVertex2d(xc+X1,yc+Y1);            //plotted new coordinates using symmetry property
			glVertex2d(-xc+X1,yc+Y1);
			glVertex2d(xc+X1,-yc+Y1);
			glVertex2d(-xc+X1,-yc+Y1);
			glVertex2d(yc+X1,xc+Y1);
			glVertex2d(-yc+X1,xc+Y1);
			glVertex2d(yc+X1,-xc+Y1);
			glVertex2i(-yc+X1,-xc+Y1);
		}
		glEnd();


}
void lineDDA(double a1,double b1, double a2,double b2)
{
	double dx=(a2-a1);
	double dy=(b2-b1);
	double steps;
	int k;
	float xInc,yInc,X=a1,Y=b1;
	steps=(abs(dx)>=abs(dy))?(abs(dx)):(abs(dy));
	xInc=dx/(float)steps;
	yInc=dy/(float)steps;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glVertex2d(X,Y);
	for(k=0;k<steps;k++)
	{
		X=X+xInc;
		Y+=yInc;
		glVertex2d(X,Y);
	}
}
void points()
{
	
	lineDDA(X2,Y2,X2+len,Y2);  //Base of triangle
	
	
	int newy = sqrt(pow(len,2)-pow((len/2),2));
	
	lineDDA(X2,Y2,X2+(len/2),newy+Y2);
	lineDDA(X2+len,Y2,X2+(len/2),newy+Y2);
	
	
	X1 = (X2+(X2+len)+(X2+(len/2)))/3; //Center coordinates calculation
	Y1 = (Y2+Y2+(newy+Y2))/3;
	

	R = (sqrt(3)*len)/3;  //Calculation of outer circle radius
	
	Circle(R);   //outer Circle
	R1 = (sqrt(3)*len)/6; //Calculation of Inner circle radius
	
	Circle(R1);  //Inner Circle
	glBegin(GL_LINES);
		glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,0);
                glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,glutGet(GLUT_WINDOW_HEIGHT)); 
		glVertex2i(0,glutGet(GLUT_WINDOW_HEIGHT)/2);
		glVertex2i(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)/2);
  glEnd();



	
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	points();
	
	glFlush();
}
void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv) 
{
	printf("\nEnter the length of the triangle:");
	scanf("%d",&len);
	printf("\nEnter starting coordinate for the triangle:");
	scanf("%d%d",&X2,&Y2);
	X2= X2+320;
	Y2=Y2+240;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Circle with Triangle");
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();
return(0);
}             







































