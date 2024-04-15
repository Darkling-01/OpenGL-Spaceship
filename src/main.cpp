#include <GL/glut.h>
#include <GL/gl.h>
//#include "player.h"

const int screenWidth = 800;
const int screenHeight = 600;

void myInit(void){
   glClearColor(1.0, 1.0, 1.0, 0.0);	//set white background color
   glColor3f(0.0f, 0.0f, 0.0f);		//set the drawing color
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);   
}


void myDisplay(void){
  // Player player;
  //player.drawHouse();
   glClear(GL_COLOR_BUFFER_BIT);	//clear the screen
   glBegin(GL_LINE_STRIP);
    glVertex2i(40, 40);			//draw the house
    glVertex2i(40, 90);
    glVertex2i(70, 120);
    glVertex2i(100, 90);
    glVertex2i(100, 40);
   glEnd();
   glFlush();		//send all output to display
}


int  main(int argc, char** argv)
{
   glutInit(&argc, argv);	// initialize the tookkit
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	   // set display mode
   glutInitWindowSize(screenWidth, screenHeight);  // set window size
   glutInitWindowPosition(160, 110);   // set window position on screen
   glutCreateWindow("Space Shooter");  // open the screen window
   glutDisplayFunc(myDisplay);    // register redraw function
    
   myInit();
    
   glutMainLoop();	// go into a perpetual loop
}

