//
// Created by perso on 16/12/2024.
//

#include "AStarPathFinder.h"

#include <iostream>
#include <ostream>

#include "../../core/AocException.h"

using namespace core;

namespace pathfinding {
  std::vector<std::queue<Node *>> AStarPathFinder::findAllPaths(Node *start) {
    std::vector<std::queue<Node *>> paths;
    // Shouldn't really use this method
    return paths;
  }
  FinalPath AStarPathFinder::findPath(Node *start, Node *finish, bool rotationAddsCost) {

    // 1. Initialize the open list
    std::vector<Node *> openList;
    // 2. Initialize the closed list
    std::vector<Node *> closedList;

    // 2a. Add start to open list to start off
    openList.emplace_back(start);

    // Variables explained
    // g = the movement cost to move from the starting point to a given square on the grid
    //    following the path generated to get there
    // h = the estimated movement cost to move from that given square to the final destination,
    //    also known as the heuristic. Worked out using Manhattan distance.
    // f = g + h
    // As part of the algorithm, pick the node with the smallest f value

    // 3. Whilst open list is not empty
    int iterations = 0;
    while (!openList.empty()) {
      // 3 - SETUP
      Node *q = nullptr;


      // 3a. Find Node with smallest F value
      double trackingF = LONG_LONG_MAX;
      //std::cout << "Iteration: " << iterations++ << std::endl;
      for (const auto node: openList) {
        //std::cout << node->getPosition().toString() << ": G(" << node->getG() << ") H(" << node->getH() << ") -> F("
        //          << node->getF() << ")" << std::endl;
        if (node->getF() < trackingF) {
          trackingF = node->getF();
          q = node;
        }
      }
      //std::cout << "Chose node: " << q->getPosition().toString() << std::endl << std::endl;
      // q should be true, if not throw an exception
      if (q == nullptr) {
        throw new AocException("Current is null, should've been found!");
      }

      // 3b. Remove q from the open list
      std::erase(openList, q);

      // 3c. Get Q's neighbours
      std::vector<Node *> neighbours = q->getNeighbourNodes();

      // 3d. Loop through each successor
      bool finishFound = false;
      for (auto &neighbour: neighbours) {
        // 0. Add parent whilst here
        if (neighbour->getPosition() == start->getPosition()) {
          continue;
        }
        neighbour->setParent(q);

        // i. If successor is the goal, stop the search!
        if (neighbour->getPosition() == finish->getPosition()) {
          finish->setParent(q);
          finish->setG(q->getG() + finish->getWeight());
          finishFound = true;
          break;
        }

        int scoreToAdd = 0;
        if (rotationAddsCost) {
          // ii. Compute the G and H for the successor
          Orientation directionOfNeighbour = Directions::fromPair(neighbour->getPosition() - q->getPosition());
          Orientation directionOfQ = q->getOrientation();
          neighbour->setOrientation(directionOfNeighbour);

          // Find total turns to make move
          int totalTurns = 0;
          Orientation trackingOrientation = directionOfQ;
          while (trackingOrientation != directionOfNeighbour) {
            trackingOrientation = Rotations::rotate90Degrees(trackingOrientation);
            totalTurns++;
          }
          if (totalTurns > 2) {
            totalTurns -= 2;
          }

          scoreToAdd = totalTurns * 1000;
        }

        long g = q->getG() + neighbour->getWeight() + scoreToAdd;
        double h = neighbour->heuristicDistance(finish->getPosition());
        neighbour->setG(g);
        neighbour->setH(h);

        // ii. If a node with the same position as successor is in the OPEN list
        //       which has a lower f than the successor, skip this successor
        bool shouldSkip = false;
        for (auto node: openList) {
          if (node->getPosition() == neighbour->getPosition()) {
            if (node->getF() < neighbour->getF()) {
              shouldSkip = true;
            }
          }
        }
        if (shouldSkip)
          continue;
        // iii. IF a node with the same position as successor is in the CLOSED
        //        list which has a lower f than successor, skip this successor.
        //        otherwise, add the note to the open list
        shouldSkip = false;
        for (auto node: closedList) {
          if (node->getPosition() == neighbour->getPosition()) {
            if (node->getF() < neighbour->getF()) {
              shouldSkip = true;
            }
          }
        }

        for (auto node: openList) {
          if (node->getPosition() == neighbour->getPosition()) {
            // Don't bother adding if already in open list
            shouldSkip = true;
          }
        }
        if (!shouldSkip) {
          openList.emplace_back(neighbour->copy());
        }
      }

      // 3di. Finish if finish node has been found
      if (finishFound) {
        break;
      }
      // Push Q to the closed list
      closedList.emplace_back(q->copy());
    }

    std::stack<Node *> path;
    Node *trackedNode = finish;
    while (trackedNode != nullptr) {
      path.push(trackedNode);
      trackedNode = trackedNode->getParent();
    }

    FinalPath result{path, finish->getG()};
    return result;
  }
} // namespace pathfinding
