//
// Created by perso on 10/12/2024.
//

#ifndef SIMPLEPATHFINDER_H
#define SIMPLEPATHFINDER_H
#include "PathFinder.h"

#include <queue>

using namespace std;

namespace pathfinding {
  class IncrementalPathFinder : public PathFinder {
    void findPath(std::vector<std::queue<Node *>> &result, std::queue<Node *> currentPath,
                  Node *start);
  public:
    std::vector<std::queue<Node *>> findAllPaths(Node *start) override;
    FinalPath findPath(Node *start, Node *finish, bool rotationAddsCost) override;
  };
}

#endif //SIMPLEPATHFINDER_H
