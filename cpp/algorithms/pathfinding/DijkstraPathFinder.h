//
// Created by perso on 18/12/2024.
//

#ifndef DFSPATHFINDER_H
#define DFSPATHFINDER_H
#include "PathFinder.h"

#include <vector>

namespace pathfinding {

class DijkstraPathFinder : public core::PathFinder {
  public:
    std::vector<std::queue<core::Node *>> findAllPaths(core::Node *start) override;
    core::FinalPath findPath(core::Node *start, core::Node *finish, bool rotationAddsCost = false) override;
    std::vector<core::FinalPath> findPaths(core::Node *start, core::Node *finish, bool rotationAddsCost = false);
  };

} // pathfinding

#endif //DFSPATHFINDER_H
