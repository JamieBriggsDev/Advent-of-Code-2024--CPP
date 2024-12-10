//
// Created by Jamie Briggs on 10/12/2024.
//

#include "TopographicMap.h"

namespace core {
  Node* TopographicMap::convertToObject(char c, int x, int y) {
    auto path = new Node(c - '0', x, y);
    if(path->getHeight() == 0) {
      this->startingPaths.push_back(path);
    }
    return path;
  }
} // Day10