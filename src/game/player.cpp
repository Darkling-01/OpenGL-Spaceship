#include <GL/glut.h>
#include "../include/game/player.h"


void Player::drawPlayer() const{
   glColor3f(0.678f, 0.847f, 0.902f);	    // set drawing color
   glBegin(GL_LINE_LOOP);         // connects frist to last vertex
     glVertex2i(334, 300);
     glVertex2i(330, 300);
     glVertex2i(336, 310);
     glVertex2i(342, 300);
     glVertex2i(339, 300);
     glVertex2i(336, 295);
   glEnd();

   glutPostRedisplay();     // request a redisplay to refresh the screen
   
}

