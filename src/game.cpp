#include <iostream>
#include "cave.h"
#include "player.h"

int main()
{
  Cave cave;
  Player player(cave);

  player.Display();
}