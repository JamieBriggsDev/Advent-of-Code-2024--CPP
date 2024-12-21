//
// Created by Jamie Briggs on 21/12/2024.
//

#ifndef BFSPATHFINDER_H
#define BFSPATHFINDER_H
#include "PathFinder.h"

namespace pathfinding {

class BFSPathFinder : public PathFinder {
  public:
    std::vector<std::queue<Node *>> findAllPaths(Node *start) override;
    FinalPath findPath(Node *start, Node *finish, bool rotationAddsCost) override;
  };

} // pathfinding

#endif //BFSPATHFINDER_H
