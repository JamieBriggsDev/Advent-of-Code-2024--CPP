//
// Created by Jamie Briggs on 16/12/2024.
//

#ifndef MAZETILE_H
#define MAZETILE_H
#include "Node.h"

namespace pathfinding {

class MazeTile : public Node {

  public:
    // Weight is 1 as every node has equal distance to each other in a Maze!
    MazeTile(int x, int y, bool isWalkable) : Node(1, x, y, isWalkable) {}
  };

} // solutions

#endif //MAZETILE_H
