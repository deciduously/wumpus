#include "cave.h"
#include "room.h"

//this shouldn't happen
Room::Room() {}

Room::Room(int i)
{
  id = i;
  //get exits
  exits = connections[i - 1];
  wumpus = false;
  bat = false;
  pit = false;
}