//
// Created by Jamie Briggs on 18/12/2024.
//

#include "DijkstraPathFinder.h"

#include <unordered_set>


namespace pathfinding {
  struct ComparePair {
    bool operator()(const std::pair<int, Node *> &a, const std::pair<int, Node *> &b) {
      return a.first > b.first; // Compare by distance (smaller distance = higher priority)
    }
  };


  void reconstructPaths(Node* current, Node* start,
                      std::unordered_map<Node*, std::vector<Node*>>& previousMap,
                      std::vector<Node*>& currentPath,
                      std::vector<FinalPath>& allPaths,
                      int totalCost) {
    // Add current node to the path
    currentPath.push_back(current);

    // If we've reached the start, finalize this path
    if (current == start) {
      std::stack<Node*> finalStack;
      for (auto it = currentPath.rbegin(); it != currentPath.rend(); ++it) {
        finalStack.push(*it);
      }
      allPaths.emplace_back(FinalPath{finalStack, totalCost});
    } else {
      // Explore all previous nodes recursively
      for (Node* prev : previousMap[current]) {
        reconstructPaths(prev, start, previousMap, currentPath, allPaths, totalCost);
      }
    }

    

    // Backtrack: remove current node from the path
    currentPath.pop_back();
  }

  std::vector<std::queue<Node *>> DijkstraPathFinder::findAllPaths(Node *start) {return {}; }
  FinalPath DijkstraPathFinder::findPath(Node *start, Node *finish, bool rotationAddsCost) {
    return findPaths(start, finish, rotationAddsCost)[0];
  }
  std::vector<FinalPath> DijkstraPathFinder::findPaths(Node *start, Node *finish, bool rotationAddsCost) {

    using NodeDistPair = std::pair<int, Node*>;

    std::priority_queue<NodeDistPair, std::vector<NodeDistPair>, ComparePair> priorityQueue;
    // Distance map doesn't keep copies of nodes with their specific orientation at the time of distance.
    //  This means that rotation cost doesn't get calculated correctly.
    std::unordered_map<Node*, int> distanceMap;
    // This second map aims to remember the best facing orientation when entering a node and whenever
    //   the next smallest distance is found
    std::unordered_map<Node*, core::Orientation> orientationMap;
    std::unordered_map<Node*, std::vector<Node*>> previousMap;
    std::unordered_set<Node*> visitedNodes;

    start->setOrientation(core::EAST);
    // Initialize distance of zero for starting node
    distanceMap[start] = 0;
    orientationMap[start] = core::EAST;
    // Push start to priority queue
    priorityQueue.push(std::pair(1, start));

    // Loop until priority queue is empty
    while (!priorityQueue.empty()) {
      // Pop the node with the lowest distance
      Node* node = priorityQueue.top().second;
      priorityQueue.pop();

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


        if (distanceMap[neighbour] == distance) {
          previousMap[neighbour].push_back(node);
        }else if (distanceMap[neighbour] > distance) {
          distanceMap[neighbour] = distance;
          previousMap[neighbour] = {node}; // This will replace all existing nodes with shortest path
          orientationMap[neighbour] = directionOfNeighbour;
          priorityQueue.push(std::pair(distance, neighbour));
        }

        /*// If neighbor has not previous, add it
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
        }*/
      }
    }

    /*std::vector<Node*> reconstructedPath;
    Node *current = finish;
    while (previousMap.contains(current)) {
      reconstructedPath.emplace_back(current);
      current = previousMap[current];
      if (current == start) {
        break;
      }
    }
    
    std::stack<Node*> stack;

    for (int i = 0; i < reconstructedPath.size(); i++) {
      stack.push(reconstructedPath[i]);
    }
    stack.emplace(start);

    FinalPath path = { stack, distanceMap[finish]};
    std::vector paths = {path};*/
    std::vector<FinalPath> allPaths;
    std::vector<Node*> currentPath;

    // Start recursive reconstruction from the target node
    reconstructPaths(finish, start, previousMap, currentPath, allPaths, distanceMap[finish]);

    // Reverse all paths. There's a better way of doing this but time constrained
    for (auto &path : allPaths) {
      std::stack<Node*> reversedPath;
      while (path.path.size() > 0) {
        reversedPath.push(path.path.top());
        path.path.pop();
      }
      path.path = reversedPath;
    }
    return allPaths;
  }
} // pathfinding