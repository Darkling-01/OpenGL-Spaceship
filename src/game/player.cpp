#include <GL/glut.h>
#include "player.h"


void Player::drawHouse() const{
   
   glBegin(GL_LINE_STRIP);
    glVertex2i(40, 40);
    glVertex2i(40, 90);
    glVertex2i(70, 120);
    glVertex2i(100, 90);
    glVertex2i(100, 40);
   glEnd();

}

