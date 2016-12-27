#ifndef __PLAYER_H_INCLUDED
#define __PLAYER_H_INCLUDED

#include "cave.h"

struct Player
{
  Cave cave;
  bool alive;
  Room *currentRoom;
  int arrows;

public:
  Player(Cave);
  void Action();
  void Display();
  
private:
  void CheckHazards();
};
#endif