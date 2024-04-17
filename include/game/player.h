#ifndef PLAYER_H
#define PLAYER_H

class Player{

private:
  
   float damage = 19;
   float health = 100;

public:  
   int speed = 5;
   void drawPlayer() const;  //declare function to draw house
   //other member function and variables...

};


#endif

