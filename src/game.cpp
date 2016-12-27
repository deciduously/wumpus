#include <iostream>
#include "cave.h"
#include "player.h"

int main()
{
  Cave cave;
  Player player(cave);

  std::cout << "You've entered a clammy, dark cave, armed with 5 arrows.  You are very hungry." << std::endl;
  while (player.alive)
  {
    player.Turn();
  }
}