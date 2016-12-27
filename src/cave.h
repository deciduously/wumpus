#ifndef __CAVE_H_INCLUDED
#define __CAVE_H_INCLUDED

#include <array>
#include <vector>
#include "room.h"

struct Cave;

constexpr int caveSize = 20; //it's gotta be 20 - map is hardcoded
extern const std::array<std::array<int, 3>, caveSize> connections;

struct Cave
{
  std::array<Room, caveSize> rooms;

public:
  Cave();
};
#endif