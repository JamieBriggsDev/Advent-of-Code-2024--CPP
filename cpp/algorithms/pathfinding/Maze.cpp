//
// Created by perso on 16/12/2024.
//

#include "Maze.h"

#include <iostream>

#include "PathFinder.h"

namespace solutions {
  Maze::Maze(vector<string> input) {
    const vector walls(input.size(), vector<bool>(input[0].size(), false));
    this->walls = walls;
    this->init(input);
    // Add neighbours
    for (int y = 0; y < this->verticalLength; y++) {
      for (int x = 0; x < this->horizontalLength; x++) {
        auto currTile = grid[y][x];
        // Don't care if the tile is null!
        if (currTile == nullptr) {
          continue;
        }
        if (y - 1 >= 0) {
          auto *north = grid[y - 1][x];
          if (north != nullptr) {
            currTile->addNeighbour(north);
          }
        }
        // Get East
        if (x + 1 < this->horizontalLength) {
          auto *east = grid[y][x + 1];
          if (east != nullptr) {
            currTile->addNeighbour(east);
          }
        }
        // Get South
        if (y + 1 < this->verticalLength) {
          auto *south = grid[y + 1][x];
          if (south != nullptr) {
            currTile->addNeighbour(south);
          }
        }
        // Get West
        if (x - 1 >= 0) {
          auto *west = grid[y][x - 1];
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
      tile = new MazeTile(x, y, true);
      tile->setOrientation(core::EAST);
      this->startTile = tile;
    }
    if (c == 'E') {
      tile = new MazeTile(x, y, true);
      this->endTile = tile;
    }
    if (c == '.') {
      tile = new MazeTile(x, y, true);
    }
    if (c == '#') {
      walls[y][x] = true;
      tile = new MazeTile(x, y, false);
    }
    return tile;
  }

  void Maze::printMaze(core::FinalPath finalPath) {
    vector path(this->getVerticalLength(), std::vector<core::Node *>(this->getHorizontalLength(), nullptr));;
    while (!finalPath.path.empty()) {
      core::Node* node = finalPath.path.top();
      path[node->y][node->x] = node;
      finalPath.path.pop();
    }
    for(int y = 0; y < this->getVerticalLength(); y++) {
      for(int x = 0; x < this->getHorizontalLength(); x++) {
        core::Node * toDraw = path[y][x];
        if(toDraw != nullptr) {
          if (toDraw == this->startTile) {
            std::cout << "S";
          }
          else if (toDraw == this->endTile) {
            std::cout << "E";
          }
          else if(toDraw->getOrientation() == core::NORTH) {
            std::cout << "^";
          }else if(toDraw->getOrientation() == core::SOUTH) {
            std::cout << "v";
          }else if(toDraw->getOrientation() == core::EAST) {
            std::cout << ">";
          }else if(toDraw->getOrientation() == core::WEST) {
            std::cout << "<";
          }
        }else {
          if (this->walls[y][x]) {
            std::cout << "#";
          }else {
            std::cout << ".";
          }
        }

      }
      std::cout << std::endl;
    }
  }



} // solutions