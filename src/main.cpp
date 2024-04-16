#include <GL/glut.h>
#include <GL/gl.h>
#include "../include/game/player.h"

const int screenWidth = 800;
const int screenHeight = 600;

void myInit(void){
   glClearColor(0.2f, 0.2f, 0.2f, 1.0f);  //set background darkgray
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);   // clear the screen
   Player player;
   player.drawPlayer();
}


void myKeyboard(unsigned char theKey, int x, int y){
   switch(theKey){
     case 'e':
         exit(-1);   // exits the program
     default:
       break;

   }

}



int  main(int argc, char** argv)
{
   glutInit(&argc, argv);	// initialize the tookkit
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	   // set display mode
   glutInitWindowSize(screenWidth, screenHeight);  // set window size
   glutInitWindowPosition(160, 110);   // set window position on screen
   glutCreateWindow("Space Shooter");  // open the screen window    
   
   //register the callback functions
   glutDisplayFunc(myDisplay);
   glutKeyboardFunc(myKeyboard);   

   myInit();
 
   glutMainLoop();	// go into a perpetual loop
}

