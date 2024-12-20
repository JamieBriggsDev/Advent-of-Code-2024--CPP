//
// Created by Jamie Briggs on 18/12/2024.
//

#ifndef DFSPATHFINDER_H
#define DFSPATHFINDER_H
#include "PathFinder.h"

#include <vector>

namespace pathfinding {

class DijkstraPathFinder : public PathFinder {
  public:
    std::vector<std::queue<Node *>> findAllPaths(Node *start) override;
    FinalPath findPath(Node *start, Node *finish, bool rotationAddsCost = false) override;
    std::vector<FinalPath> findPaths(Node *start, Node *finish, bool rotationAddsCost = false);
  };

} // pathfinding

#endif //DFSPATHFINDER_H
