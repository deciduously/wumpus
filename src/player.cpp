#include <iostream>
#include "cave.h"
#include "player.h"

Player::Player(Cave cave)
{
  cave = cave;
  currentRoom = &cave.rooms[0];
  arrows = 5;
  alive = true;
}

void Player::CheckHazards()
{
  for (auto adjacent : currentRoom->exits)
  {
    Room active = cave.rooms[adjacent-1];
    if (active.wumpus)
      std::cout<<"You smell something horrific and rancid."<<std::endl;
    else if (active.pit)
      std::cout<<"You feel a cold updraft from a nearby cavern."<<std::endl;
    else if (active.bat)
      std::cout<<"You hear a faint but distinct flapping of wings."<<std::endl;
  }
}

void Player::Display()
{
  std::cout << "You are in room " << currentRoom->id << std::endl;
  std::cout << "Exits: ";
  for (auto exit : currentRoom->exits)
    std::cout << exit << " ";
  std::cout << std::endl;
  Player::CheckHazards();
}
