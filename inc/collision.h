#ifndef COLLISION
#define COLLISION

#include <vector>

#include "globals.h"
#include "tile.h"

class Collision
{
public:
  static bool check(Command *command, Vector2 position, std::vector<Tile *> tiles);
};

bool Collision::check(Command *command, Vector2 position, std::vector<Tile *> tiles)
{
  bool nCheck = (tiles[0]->isWall && position.y - CELL_SIZE < tiles[0]->position.y);
  bool eCheck = (tiles[2]->isWall && position.x + CELL_SIZE > tiles[2]->position.x);
  bool sCheck = (tiles[4]->isWall && position.y + CELL_SIZE > tiles[4]->position.y);
  bool wCheck = (tiles[6]->isWall && position.x - CELL_SIZE < tiles[6]->position.x);

  bool neCheck = (tiles[1]->isWall && position.y - CELL_SIZE < tiles[1]->position.y && position.x + CELL_SIZE > tiles[1]->position.x);
  bool seCheck = (tiles[3]->isWall && position.y + CELL_SIZE > tiles[3]->position.y && position.x + CELL_SIZE > tiles[3]->position.x);
  bool swCheck = (tiles[5]->isWall && position.y + CELL_SIZE > tiles[5]->position.y && position.x - CELL_SIZE < tiles[5]->position.x);
  bool nwCheck = (tiles[7]->isWall && position.y - CELL_SIZE < tiles[7]->position.y && position.x - CELL_SIZE < tiles[7]->position.x);

  switch (*command)
  {
  case Command::N:
    return nwCheck || nCheck || neCheck;
  case Command::NE:
    return nCheck || neCheck || eCheck;
  case Command::E:
    return neCheck || eCheck || seCheck;
  case Command::SE:
    return eCheck || seCheck || sCheck;
  case Command::S:
    return seCheck || sCheck || swCheck;
  case Command::SW:
    return sCheck || swCheck || wCheck;
  case Command::W:
    return swCheck || wCheck || nwCheck;
  case Command::NW:
    return wCheck || nwCheck || nCheck;
  default:
    return false;
  }
}

#endif
