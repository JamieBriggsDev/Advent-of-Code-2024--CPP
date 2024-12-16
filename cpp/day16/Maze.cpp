//
// Created by perso on 16/12/2024.
//

#include "Maze.h"

namespace solutions {
  Maze::Maze(vector<string> input) {
    this->init(input);

    // Add neighbours
    for (int y = 0; y < this->verticalLength; y++) {
      for (int x = 0; x < this->horizontalLength; x++) {
        auto currTile = grid[y][x];
        // Don't care if the tile is null!
        if (currTile == nullptr) { continue; }
        if (y - 1 >= 0) {
          auto *north = grid[y-1][x];
          if (north != nullptr) {
            currTile->addNeighbour(north);
          }
        }
        // Get East
        if (x + 1 < this->horizontalLength) {
          auto *east = grid[y][x+1];
          if (east != nullptr) {
            currTile->addNeighbour(east);
          }
        }
        // Get South
        if(y + 1 < this->verticalLength) {
          auto *south = grid[y+1][x];
          if (south != nullptr) {
            currTile->addNeighbour(south);
          }
        }
        // Get West
        if(x - 1 >= 0) {
          auto *west = grid[y][x-1];
          if (west != nullptr) {
            currTile->addNeighbour(west);
          }
        }
      }
    }
  }

  MazeTile *Maze::convertToObject(char c, int x, int y) {
    // Not bothering with walls, they are just more stuff to hold for the sake
    //  of inheritance..
    MazeTile *tile = nullptr;
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