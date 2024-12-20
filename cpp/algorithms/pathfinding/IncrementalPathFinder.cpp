//
// Created by Jamie Briggs on 10/12/2024.
//

#include "IncrementalPathFinder.h"


using namespace pathfinding;

void IncrementalPathFinder::findPath(std::vector<std::queue<Node *>> &result,
                                           std::queue<Node *> currentPath, Node *start) {
  // Add this path to the result
  std::queue<Node *> copyOfCurrentPath = currentPath;
  Node *current = start;
  while (current != nullptr) {
    copyOfCurrentPath.push(current);
    if (!current->getNeighbourNodes().empty()) {
      // If node has more than 1, create new paths from second parents
      for (int idx = 1; idx < current->getNeighbourNodes().size(); idx++) {
        // If in here, well done you've found more potential routes!
        findPath(result, copyOfCurrentPath, current->getNeighbourNodes()[idx]);
      }
      // Update current afterwards. If done before, reference would've changed
      current = current->getNeighbourNodes()[0];
    } else {
      current = nullptr;
    }
  }
  result.push_back(copyOfCurrentPath);
}

std::vector<std::queue<Node *>> IncrementalPathFinder::findAllPaths(Node *start) {
  std::vector<std::queue<Node *>> result;
  std::queue<Node *> path;

  findPath(result, path, start);

  return result;
}
FinalPath IncrementalPathFinder::findPath(Node *start, Node *finish, bool rotationAddsCost) {
  std::stack<Node *> path;

  FinalPath result { path, 0};
  return result;
}

