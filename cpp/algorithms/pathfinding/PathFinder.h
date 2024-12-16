//
// Created by perso on 10/12/2024.
//

#ifndef PATHFINDER_H
#define PATHFINDER_H


#include <queue>
#include "Node.h"


namespace core {
  class PathFinder {
  public:
    virtual ~PathFinder() = default;
    virtual std::vector<std::queue<Node *>> findAllPaths(Node *start) = 0;
  };
}

#endif //PATHFINDER_H
