#include <stdlib.h>
#include <time.h>
#include "cave.h"
#include "player.h"

const std::array<std::array<int, 3>, caveSize> connections{{{{2, 5, 8}},
                                                            {{1, 3, 10}},
                                                            {{2, 4, 12}},
                                                            {{3, 5, 14}},
                                                            {{1, 4, 6}},
                                                            {{5, 7, 15}},
                                                            {{6, 8, 17}},
                                                            {{1, 7, 11}},
                                                            {{10, 12, 19}},
                                                            {{2, 9, 11}},
                                                            {{8, 10, 20}},
                                                            {{3, 9, 13}},
                                                            {{12, 14, 18}},
                                                            {{4, 13, 15}},
                                                            {{6, 14, 16}},
                                                            {{15, 17, 18}},
                                                            {{7, 16, 20}},
                                                            {{13, 16, 19}},
                                                            {{9, 18, 20}},
                                                            {{11, 17, 19}}}};

Cave::Cave()
{
  srand(time(NULL));
  //create rooms
  for (int i = 0; i < caveSize; ++i)
  {
    rooms[i] = Room::Room(i + 1);
  }

  //place wumpus
  int wumpLoc = rand() % caveSize;
  rooms[wumpLoc].wumpus = true;

  //place 2 pits
  for (int i = 0; i < 2; ++i)
  {
    int pitLoc;
    do
    {
      pitLoc = rand() % caveSize;
    } while (rooms[pitLoc].wumpus || rooms[pitLoc].pit);
    rooms[pitLoc].pit = true;
  }

  //place 2 bats
  for (int i = 0; i < 2; i++)
  {
    int batLoc;
    do
    {
      batLoc = rand() % caveSize;
    } while (rooms[batLoc].wumpus || rooms[batLoc].pit || rooms[batLoc].bat);
    rooms[batLoc].bat = true;
  }
}

//returns the id of the new room for collision check
int Cave::MoveWumpus()
{
  //find wumpus
  Room *wumpusRoom;
  for (auto room : rooms)
  {
    if (room.wumpus)
      wumpusRoom = &room;
  }
  //choose direction
  int randomExit = rand() % 3;
  Room *newWumpusRoom = &rooms[wumpusRoom->exits[randomExit]];

  //move wumpus
  wumpusRoom->wumpus = false;
  newWumpusRoom->wumpus = true;

  return newWumpusRoom->id;
}