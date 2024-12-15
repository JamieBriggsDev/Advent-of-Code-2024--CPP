//
// Created by perso on 15/12/2024.
//

#include "Warehouse.h"

#include <iostream>
#include <ostream>

#include "Box.h"
#include "Wall.h"

#include <stack>

namespace solutions {
  warehouse::Entity *Warehouse::convertToObject(const char c, const int x, const int y) {
    if (c == '#') {
      return new warehouse::Wall(x, y);
    }
    if (c == 'O') {
      auto box = new warehouse::Box(x, y);
      this->boxes.push_back(box);
      return box;
    }
    if (c == '@') {
      this->robot = new warehouse::Robot(x, y);
      return this->robot;
    }
    return nullptr;
  }
  void Warehouse::moveRobot(core::Orientation orientation) {
    auto robot = this->robot;
    auto pairDirection = core::Directions::toPair(orientation);
    /*// Before moving robot, find if there is a wall next to the robot and just exit quickly
    if (dynamic_cast<warehouse::Wall *>(this->getGrid()[robot->y + pairDirection.y][robot->x + pairDirection.x]) !=
        nullptr) {
      // Return and do nothing
      return;
    }*/

    std::stack<warehouse::Entity *> stackToMove;
    stackToMove.emplace(robot);

    auto nextEntity = this->getGrid()[robot->y + pairDirection.y][robot->x + pairDirection.x];

    // Before moving robot, find boxes in direction
    while (nextEntity != nullptr && !nextEntity->isWall()) {
      if (nextEntity != nullptr && !nextEntity->isWall()) {
        stackToMove.emplace(nextEntity);
      }
      nextEntity = this->getGrid()[nextEntity->y + pairDirection.y][nextEntity->x + pairDirection.x];
    }

    // If next entity is null, then there is a gap to move all objects into! this is because as part
    //  of the above algorithm, it will exit the loop if there is either a gap, or a wall. If there
    //  is a wall, that means there is no more space between the robot, and the wall with boxes.
    bool foundGap = nextEntity == nullptr;

    // If gap not found, clear stack as nothing can't move!
    if (!foundGap) {
      while (!stackToMove.empty()) {
        stackToMove.pop();
      }
    }

    // Starting from top of the stack, move entities
    while (!stackToMove.empty()) {
      warehouse::Entity *toMove = stackToMove.top();
      // Remove reference to entity in Grid
      this->grid[toMove->y][toMove->x] = nullptr;
      // Set robot coordinates
      toMove->move(pairDirection);
      // Update grid to new robot location
      this->grid[toMove->y][toMove->x] = toMove;
      stackToMove.pop();
    }

    if (isDebug) {
      std::cout << "Move " << core::Directions::toArrow(orientation) << ":" << std::endl;
      this->printWarehouseLayout();
      std::cout << std::endl;
    }
  }
  void Warehouse::printWarehouseLayout() const {
    for (int y = 0; y < this->getVerticalLength(); y++) {
      for (int x = 0; x < this->getHorizontalLength(); x++) {
        if (this->grid[y][x] != nullptr) {
          std::cout << this->grid[y][x]->getSymbol();
        } else {
          std::cout << ".";
        }
      }
      std::cout << std::endl;
    }
  }
} // namespace solutions
