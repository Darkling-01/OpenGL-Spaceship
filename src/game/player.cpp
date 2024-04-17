#include <GL/glut.h>
#include "../include/game/player.h"


void Player::drawPlayer() const{
   
   float centerX = (334+330+336+342+339+336) / 6.0f;
   float centerY = (300+300+310+300+300+295) / 6.0f;

   glTranslatef(-centerX, -centerY, 0.0f);

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

