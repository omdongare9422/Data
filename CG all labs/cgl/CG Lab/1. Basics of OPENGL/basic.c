#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init()
{
glClearColor(1,0,0,0);// Background Color
glColor3f(0,0,1); //Foreground Color
gluOrtho2D(0,640,0,480);
}




void renderBitmapString(float x,float y, char *text) 
{  
  char *c;
  glRasterPos3f(x, y,0);  //When you draw a text you have to define “Where” it will be drawn, this              					function is responsible for this role 
  for (c=text; *c != '\0'; c++) 
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
  }
}



/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18 */


void draw()
{
glClear(GL_COLOR_BUFFER_BIT);

char *text;
text = "SITS";

/*glBegin(GL_LINES);
glVertex2i(320,0);
glVertex2i(320,480);
glVertex2i(0,240);
glVertex2i(640,240);
glEnd();*/
glLineWidth(4);
glBegin(GL_LINES);
	
		glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,0);
                glVertex2i(glutGet(GLUT_WINDOW_WIDTH)/2,glutGet(GLUT_WINDOW_HEIGHT)); 
glEnd();
	
glBegin(GL_LINES);	
		glVertex2i(0,glutGet(GLUT_WINDOW_HEIGHT)/2);
                glVertex2i(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)/2); 
  glEnd();


//glLineWidth(4);
glBegin(GL_LINE_LOOP);
glVertex2i(100,100);
glVertex2i(200,100);
glVertex2i(200,200);
glVertex2i(150,300);
glVertex2i(100,200);
glEnd();


/*glBegin(GL_LINE_STRIP);
glVertex2i(200,100);
glVertex2i(400,100);
glVertex2i(500,300);
glVertex2i(300,500);
glVertex2i(100,300);
glEnd();*/

renderBitmapString(400,350, text);
	
glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);

glutCreateWindow("pentagon Assignment");

init();

glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
