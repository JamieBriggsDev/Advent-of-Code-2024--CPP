//
// Created by perso on 16/12/2024.
//

#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H
#include "PathFinder.h"

namespace pathfinding {

class AStarPathFinder : public core::PathFinder {
  public:
    std::vector<std::queue<core::Node *>> findAllPaths(core::Node *start) override;
    core::FinalPath findPath(core::Node *start, core::Node *finish) override;
};

} // pathfinding

#endif //ASTARPATHFINDER_H
