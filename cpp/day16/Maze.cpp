//
// Created by perso on 16/12/2024.
//

#include "Maze.h"

namespace solutions {
  MazeTile* Maze::convertToObject(char c, int x, int y) {
    // Not bothering with walls, they are just more stuff to hold for the sake
    //  of inheritance..
    MazeTile* tile = nullptr;
    if (c == 'S') {
      tile = new MazeTile(x, y);
      this->startTile = tile;
    }
    if (c == 'E') {
      tile = new MazeTile(x, y);
      this->endTile = tile;
    }
    if (c == '.') {
      tile = new MazeTile(x, y);
    }
    return tile;
  }
} // solutions