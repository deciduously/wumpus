#ifndef __PLAYER_H_INCLUDED
#define __PLAYER_H_INCLUDED

#include "cave.h"

struct Player
{
  Cave *cave;
  bool alive;
  Room *currentRoom;
  int arrows;

public:
  Player(Cave);
  void Turn();

private:
  void CheckHazards();
  void Action();
  void Display();
  void Move(int);
  bool Shoot(int);
};
#endif