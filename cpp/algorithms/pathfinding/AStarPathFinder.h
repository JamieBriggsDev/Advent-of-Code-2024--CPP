//
// Created by perso on 16/12/2024.
//

#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H
#include "PathFinder.h"

namespace pathfinding {

class AStarPathFinder : public PathFinder {
  public:
    std::vector<std::queue<Node *>> findAllPaths(Node *start) override;
    FinalPath findPath(Node *start, Node *finish, bool rotationAddsCost) override;
};

} // pathfinding

#endif //ASTARPATHFINDER_H
