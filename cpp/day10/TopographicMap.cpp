//
// Created by Jamie Briggs on 10/12/2024.
//

#include "TopographicMap.h"

namespace core {
  Node *TopographicMap::convertToObject(char c, int x, int y) {
    auto path = new Node(c - '0', x, y, true);
    if (path->getWeight() == 0) {
      this->startingPaths.push_back(path);
    }
    return path;
  }
  TopographicMap::TopographicMap(std::vector<std::string> input) {
    this->init(std::move(input));

    // Once added, loop through each node in grid and add neighbour as a parent if they are viable
    for (int y = 0; y < this->verticalLength; y++) {
      for (int x = 0; x < this->horizontalLength; x++) {
        Node *node = this->grid[y][x];
        // Get neighbours
        Node *north = nullptr;
        Node *east = nullptr;
        Node *south = nullptr;
        Node *west = nullptr;
        if ((y - 1) >= 0) {
          north = this->grid[y - 1][x];
        }
        if (x + 1 < this->horizontalLength) {
          east = this->grid[y][x + 1];
        }
        if (y + 1 < this->verticalLength) {
          south = this->grid[y + 1][x];
        }
        if (x - 1 >= 0) {
          west = this->grid[y][x - 1];
        }
        // Check each neighbour if viable neighbour
        if (north != nullptr && north->getWeight() == node->getWeight() + 1) {
          node->addNeighbour(north);
        }
        if (east != nullptr && east->getWeight() == node->getWeight() + 1) {
          node->addNeighbour(east);
        }
        if (south != nullptr && south->getWeight() == node->getWeight() + 1) {
          node->addNeighbour(south);
        }
        if (west != nullptr && west->getWeight() == node->getWeight() + 1) {
          node->addNeighbour(west);
        }
      }
    }
  }
} // namespace core
