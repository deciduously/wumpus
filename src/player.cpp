#include <iostream>
#include "cave.h"
#include "player.h"

Player::Player(Cave c)
{
  cave = &c;
  currentRoom = &c.rooms[0];
  arrows = 5;
  alive = true;
}

void Player::Action()
{
  char choice;
  do
  {
    std::cout << "(m)ove or (s)hoot: ";
    std::cin >> choice;
  } while (choice != 'm' && choice != 's');

  int num;
  do
  {
    std::cout << "(" << currentRoom->exits[0] << ") (" << currentRoom->exits[1] << ") (" << currentRoom->exits[2] << "): ";
    std::cin >> num;
  } while (num != currentRoom->exits[0] && num != currentRoom->exits[1] && num != currentRoom->exits[2]);

  if (choice == 'm')
    Player::Move(num);
  else if (choice == 's')
  {
    if (Player::Shoot(num))
    {
      std::cout << "With a sickening, satisfying thwack, your arrow finds its mark.  You're gonna eat you a WUMPUS tonight!  Good game." << std::endl;
      alive = false;
    }
    else
    {
      std::cout << "Your arrow whistles aimlessly into the void.";
      if (arrows <= 0)
        std::cout <<std::endl << "You fired your very last arrow - you are now wumpus food."<<std::endl;
      //TODO 75% chance you scare the wumpus
    }
  }
}

void Player::CheckHazards()
{
  for (auto adjacent : currentRoom->exits)
  {
    Room active = cave->rooms[adjacent - 1];
    if (active.wumpus)
      std::cout << "You smell something horrific and rancid." << std::endl;
    else if (active.pit)
      std::cout << "You feel a cold updraft from a nearby cavern." << std::endl;
    else if (active.bat)
      std::cout << "You hear a faint but distinct flapping of wings." << std::endl;
  }
}

void Player::Display()
{
  std::cout << "You are in room " << currentRoom->id << " holding ";
  (arrows > 1) ? std::cout<< arrows << " arrows." << std::endl : std::cout<<"one arrow."<<std::endl;
  std::cout << "Exits: ";
  for (auto exit : currentRoom->exits)
    std::cout << exit << " ";
  std::cout << std::endl;
  Player::CheckHazards();
}

void Player::Move(int n)
{
  currentRoom = &cave->rooms[n - 1];
  if (currentRoom->wumpus)
  {
    alive = false;
    std::cout << "You have been eaten slowly and painfully by the wumpus." << std::endl;
  }
  else if (currentRoom->pit)
  {
    alive = false;
    std::cout << "You have walked straight into a gaping pit and now must wait to die, bloodied and broken, with no hope of rescue." << std::endl;
  }
  else if (currentRoom->bat)
  {
    std::cout << "A gigantic bat whisks you off your feet and in a blur deposits you elsewhere before you can even blink." << std::endl;
    int newPlayerRoom, newBatRoom;
    do
    {
      newPlayerRoom = rand() % caveSize;
    } while (cave->rooms[newPlayerRoom].bat || cave->rooms[newPlayerRoom].pit || cave->rooms[newPlayerRoom].wumpus);
    do
    {
      newBatRoom = rand() % caveSize;
    } while (cave->rooms[newBatRoom].bat || cave->rooms[newBatRoom].pit || cave->rooms[newBatRoom].wumpus);
    currentRoom->bat = false;
    cave->rooms[newBatRoom].bat = true;
    currentRoom = &cave->rooms[newPlayerRoom];
  }
}

bool Player::Shoot(int n)
{
  if (cave->rooms[n - 1].wumpus)
    return true;
  --arrows;
  if (arrows <= 0)
  {
    alive = false;
  }
  return false;
}

void Player::Turn()
{
  std::cout << std::endl
            << "---------------------------------------------------------------------" << std::endl;
  Player::Display();
  Player::Action();
}