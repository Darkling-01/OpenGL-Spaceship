#include <GL/glut.h>
#include <GL/gl.h>
#include "../include/game/player.h"

const int screenWidth = 800;
const int screenHeight = 600;

float xr = 0, yr = 0;

void myInit(void){
   glClearColor(0.2f, 0.2f, 0.2f, 1.0f);  //set background darkgray
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

Player player;

void myDisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);   // clear the screen
   glPushMatrix();
   glTranslatef(xr, yr, 0);    // translate the coordinate system by xr and yr
   player.drawPlayer();     // draw the player object
   glPopMatrix();
   glFlush();       // forces all the drawing commands to be executed immediately
}


void myKeyboard(unsigned char theKey, int x, int y){
   switch(theKey){
     case 'e':
         exit(-1);   // exits the program
     default:
       break;

   }

}


// incrementing and decrementing are used to change game objects...
void specialKey(int key, int x, int y){
   switch(key){
     case GLUT_KEY_UP:
       yr++;
       glutPostRedisplay();  // trigger window refresh
       break;
     case GLUT_KEY_DOWN:
       yr--;
       glutPostRedisplay();
       break;
     case GLUT_KEY_RIGHT:
       xr++;
       glutPostRedisplay();
       break;
     case GLUT_KEY_LEFT:
       xr--;
       glutPostRedisplay();

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
   myInit();
   glutKeyboardFunc(myKeyboard);   
   glutSpecialFunc(specialKey);
   glutMainLoop();	// go into a perpetual loop
   
   return 0;
}

