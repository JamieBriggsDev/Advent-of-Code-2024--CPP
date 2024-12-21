//
// Created by Jamie Briggs on 21/12/2024.
//

#include "BFSPathFinder.h"

#include <queue>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>


using namespace std;

namespace pathfinding {
  std::vector<std::queue<Node *>> BFSPathFinder::findAllPaths(Node *start) {
    vector<queue<Node *>> result;
    return result;
  }
  FinalPath BFSPathFinder::findPath(Node *start, Node *finish, bool rotationAddsCost) {

    if (!start || !finish) {
      return {};
    }

    std::queue<Node *> queue; // BFS queue
    std::unordered_set<core::Pair> visited; // Tracks visited nodes
    std::unordered_map<core::Pair, Node*> predecessors; // Map to reconstruct path

    // Initialize BFS
    queue.push(start);
    visited.insert(start->getPosition());

    while (!queue.empty()) {

      // Get current Node in queue
      Node *current = queue.front();
      queue.pop();

      // Goal check
      if (current->getPosition() == finish->getPosition()) {
        // Reconstruct the path
        std::stack<Node*> path;
        Node* node = finish;
        while (node != start) {
          path.emplace(node);
          auto it = predecessors.find(node->getPosition());
          if (it != predecessors.end()) {
            node = it->second;
          }else {
            node = nullptr;
          }
        }
        FinalPath final_path(path, path.size());
        return final_path;
      }

      // Add any unvisited neighbours to the queue
      for (Node * neighbour : current->getNeighbourNodes()) {
        if (neighbour->getIsWalkable()) {
          if (visited.find(neighbour->getPosition()) == visited.end()) {
            queue.push(neighbour);
            visited.insert(neighbour->getPosition());
            predecessors[neighbour->getPosition()] = current;
          }
        }
      }

    }


    // TODO: Return a proper object!
    return {};
  }
} // namespace pathfinding
