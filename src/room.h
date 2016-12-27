#ifndef __ROOM_H_INCLUDED
#define __ROOM_H_INCLUDED

#include <array>

struct Room;

struct Room
{
  int id;
  bool wumpus, bat, pit;
  std::array<int, 3> exits;

public:
  Room(); //this shouldn't happen
  Room(int);
};
#endif