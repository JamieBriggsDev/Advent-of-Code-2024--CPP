//
// Created by perso on 18/12/2024.
//

#include "DijkstraPathFinder.h"

#include <unordered_set>


namespace pathfinding {
  struct ComparePair {
    bool operator()(const std::pair<int, core::Node*>& a, const std::pair<int, core::Node*>& b) {
      return a.first > b.first; // Compare by distance (smaller distance = higher priority)
    }
  };

  std::vector<std::queue<core::Node *>> DijkstraPathFinder::findAllPaths(core::Node *start) {
    return {};
  }
  core::FinalPath DijkstraPathFinder::findPath(core::Node *start, core::Node *finish, bool rotationAddsCost) {
    return findPaths(start, finish, rotationAddsCost)[0];
  }
  std::vector<core::FinalPath> DijkstraPathFinder::findPaths(core::Node *start, core::Node *finish, bool rotationAddsCost) {

    using NodeDistPair = std::pair<int, core::Node*>;

    std::priority_queue<NodeDistPair, std::vector<NodeDistPair>, ComparePair> priorityQueue;
    // Distance map doesn't keep copies of nodes with their specific orientation at the time of distance.
    //  This means that rotation cost doesn't get calculated correctly.
    std::unordered_map<core::Node*, int> distanceMap;
    // This second map aims to remember the best facing orientation when entering a node and whenever
    //   the next smallest distance is found
    std::unordered_map<core::Node*, core::Orientation> orientationMap;
    std::unordered_map<core::Node*, core::Node*> previousMap;
    std::unordered_set<core::Node*> visitedNodes;

    start->setOrientation(core::EAST);
    // Initialize distance of zero for starting node
    distanceMap[start] = 0;
    orientationMap[start] = core::EAST;
    // Push start to priority queue
    priorityQueue.push(std::pair(1, start));

    // Loop until priority queue is empty
    while (!priorityQueue.empty()) {
      // Pop the node with the lowest distance
      core::Node* node = priorityQueue.top().second;
      priorityQueue.pop();

      // If finish found, stop!
      /*if (node == finish) {
        break;
      }*/

      // If visited, skip this node, otherwise add it
      if (visitedNodes.contains(node)) {
        continue;
      }
      visitedNodes.insert(node);

      // Check each neighbor
      for (auto neighbour : node->getNeighbourNodes()) {
        // Calculate distance to neighbor
        int scoreToAdd = 0;
        core::Orientation directionOfNeighbour =
              core::Directions::fromPair(neighbour->getPosition() - node->getPosition());
        if (rotationAddsCost) {
          // ii. Compute the G and H for the successor
          core::Orientation directionOfQ = orientationMap[node];
          neighbour->setOrientation(directionOfNeighbour);

          // Find total turns to make move
          int totalTurns = 0;
          core::Orientation trackingOrientation = directionOfQ;
          while (trackingOrientation != directionOfNeighbour) {
            trackingOrientation = core::Rotations::rotate90Degrees(trackingOrientation);
            totalTurns++;
          }
          if (totalTurns > 2) {
            totalTurns -= 2;
          }

          scoreToAdd = totalTurns * 1000;
        }
        auto distance = distanceMap[node] + neighbour->getWeight() + scoreToAdd;

        // If neighbor distance not added, add it
        if (!distanceMap.contains(neighbour)) {
          distanceMap.insert(std::pair(neighbour, INT_MAX));
          orientationMap.insert(std::pair(neighbour, directionOfNeighbour));
          priorityQueue.push(std::pair(distance, neighbour));
        }
        // If neighbor has not previous, add it
        if (!previousMap.contains(neighbour)) {
          previousMap.insert(std::pair(neighbour, node));
        }

        // Check if distance map needs updating
        if (distanceMap[neighbour] > distance) {
          distanceMap[neighbour] = distance;
          orientationMap.insert(std::pair(neighbour, directionOfNeighbour));
          // Update previous map here as new better distance has been found
          previousMap[neighbour] = node;
          //    Also push this neighbour to the priority queue with the new nicer
          //    distance
          priorityQueue.push(std::pair(distance, neighbour));
        }

      }


    }

    std::vector<core::Node*> reconstructedPath;
    core::Node *current = finish;
    while (previousMap.contains(current)) {
      reconstructedPath.emplace_back(current);
      current = previousMap[current];
      if (current == start) {
        break;
      }
    }
    
    std::stack<core::Node*> stack;
    //stack.emplace(st);
    for (int i = 0; i < reconstructedPath.size(); i++) {
      stack.push(reconstructedPath[i]);
    }
    stack.emplace(start);

    core::FinalPath path = { stack, distanceMap[finish]};
    std::vector paths = {path};
    return paths;
  }
} // pathfinding