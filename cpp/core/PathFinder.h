//
// Created by perso on 10/12/2024.
//

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stack>

#include "Node.h"
#include <queue>


namespace core {
  class PathFinder {
  public:
    virtual ~PathFinder() = default;
    virtual std::vector<std::queue<core::Node *>> findAllPaths(core::Node *start) = 0;
  };
}

#endif //PATHFINDER_H
