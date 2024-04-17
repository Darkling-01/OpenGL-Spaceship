#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>

#include "../include/game/player.h"

const int screenWidth = 800;
const int screenHeight = 600;

Player player;

float xr = 0.0f, yr = 0.0f;
float playerAngle = 0.0f;


void myInit(void){
   glClearColor(0.2f, 0.2f, 0.2f, 1.0f);  //set background darkgray
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
}


void myDisplay(void){
   glColor3f(0.678f, 0.847f, 0.902f);       // set drawing color
   glClear(GL_COLOR_BUFFER_BIT);   // clear the screen

   glPushMatrix();
   glTranslatef(xr, yr, 0.0f);    // translate the coordinate system by xr and yr
   glRotatef(playerAngle, 0.0f, 0.0f, 1.0f);
   player.drawPlayer();     // draw the player object
   glPopMatrix();

   glFlush();       // forces all the drawing commands to be executed immediately
}


void myKeyboard(unsigned char Key, int x, int y){
   switch(Key){
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
       yr+=player.speed;
       playerAngle = 0.0f;
       break;
     case GLUT_KEY_DOWN:
       yr-=player.speed;
       playerAngle = 180.0f;
       break;
     case GLUT_KEY_RIGHT:
       xr+=player.speed;
       playerAngle = -90.0f;
       break;
     case GLUT_KEY_LEFT:
       xr-=player.speed;
       playerAngle = 90.0f;
       break;
     default:
       break;   

  }
  glutPostRedisplay();    //trigger window refresh
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
   glutSpecialFunc(specialKey);
   myInit();
   glutMainLoop();	// go into a perpetual loop
   
   return 0;
}

