//
// Created by Jamie Briggs on 16/12/2024.
//

#include "Maze.h"

#include <iostream>

#include "PathFinder.h"



namespace pathfinding {
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
          if (north != nullptr && north->getIsWalkable()) {
            currTile->addNeighbour(north);
          }
        }
        // Get East
        if (x + 1 < this->horizontalLength) {
          auto *east = grid[y][x + 1];
          if (east != nullptr && east->getIsWalkable()) {
            currTile->addNeighbour(east);
          }
        }
        // Get South
        if (y + 1 < this->verticalLength) {
          auto *south = grid[y + 1][x];
          if (south != nullptr && south->getIsWalkable()) {
            currTile->addNeighbour(south);
          }
        }
        // Get West
        if (x - 1 >= 0) {
          auto *west = grid[y][x - 1];
          if (west != nullptr && west->getIsWalkable()) {
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
      this->startPosition = core::Pair(x, y);
    }
    if (c == 'E') {
      tile = new MazeTile(x, y, true);
      this->endPosition = core::Pair(x, y);
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

  /*void Maze::makeTileWalkable(int x, int y) {
    // Get tile making walkable
    auto tileBeingMadeWalkable = getTileInPosition(x, y);
    if (tileBeingMadeWalkable == nullptr) {
      throw core::AocException("Tile being made walkable is null!");
    }
    tileBeingMadeWalkable->setIsWalkable(true);

    // Add the tile to related tiles north east south and west if they're walkable
    auto north = getTileInPosition(x, y - 1);
    auto east = getTileInPosition(x + 1, y);
    auto south = getTileInPosition(x, y + 1);
    auto west = getTileInPosition(x - 1, y);
    if (north != nullptr && north->getIsWalkable()) {
      north->addNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->addNeighbour(north);
    }
    if (east != nullptr && east->getIsWalkable()) {
      east->addNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->addNeighbour(east);
    }
    if (south != nullptr && south->getIsWalkable()) {
      south->addNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->addNeighbour(south);
    }
    if (west != nullptr && west->getIsWalkable()) {
      west->addNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->addNeighbour(west);
    }
  }
  void Maze::makeTileUnwalkable(int x, int y) {
    // Get tile making walkable
    auto tileBeingMadeWalkable = getTileInPosition(x, y);
    if (tileBeingMadeWalkable == nullptr) {
      throw core::AocException("Tile being made walkable is null!");
    }
    if (walls[y][x] != true) {
      // If not a wall, keep walkable
      return;
    }
    tileBeingMadeWalkable->setIsWalkable(false);

    // Add the tile to related tiles north east south and west if they're walkable
    auto north = getTileInPosition(x, y - 1);
    auto east = getTileInPosition(x + 1, y);
    auto south = getTileInPosition(x, y + 1);
    auto west = getTileInPosition(x - 1, y);
    if (north != nullptr && north->getIsWalkable()) {
      north->removeNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->removeNeighbour(north);
    }
    if (east != nullptr && east->getIsWalkable()) {
      east->removeNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->removeNeighbour(east);
    }
    if (south != nullptr && south->getIsWalkable()) {
      south->removeNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->removeNeighbour(south);
    }
    if (west != nullptr && west->getIsWalkable()) {
      west->removeNeighbour(tileBeingMadeWalkable);
      tileBeingMadeWalkable->removeNeighbour(west);
    }
  }*/


  void Maze::printMaze(FinalPath finalPath) {
    vector path(this->getVerticalLength(), std::vector<pathfinding::Node *>(this->getHorizontalLength(), nullptr));
    while (!finalPath.path.empty()) {
      pathfinding::Node* node = finalPath.path.top();
      path[node->y][node->x] = node;
      finalPath.path.pop();
    }

    std::cout << std::endl;
    for(int y = 0; y < this->getVerticalLength(); y++) {
      for(int x = 0; x < this->getHorizontalLength(); x++) {
        pathfinding::Node * toDraw = path[y][x];
        if(toDraw != nullptr) {
          if (toDraw == this->getStartTile()) {
            std::cout << "S";
          }
          else if (toDraw == this->getEndTile()) {
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