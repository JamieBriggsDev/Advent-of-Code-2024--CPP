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
    if (c == '[') {
      auto box = new warehouse::Box(x, y, core::WEST);
      this->boxes.push_back(box);
      return box;
    }
    if (c == ']') {
      auto box = new warehouse::Box(x, y, core::EAST);
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

    std::stack<warehouse::Entity *> stackToMove;
    stackToMove.emplace(robot);

    // Get next entity to check

    std::vector<warehouse::Entity *> rootMovementSources;
    rootMovementSources.push_back(robot);

    for (int i = 0; i < rootMovementSources.size(); i++) {

      auto nextEntity =
          this->getGrid()[rootMovementSources[i]->y + pairDirection.y][rootMovementSources[i]->x + pairDirection.x];

      // At this point, nextEntity should be a box or wall. If it's empty, end of the line for that
      //  root as every box from the root movement or robot can be moved
      while (nextEntity != nullptr) {
        if (nextEntity != nullptr && nextEntity->isWall()) {
          // Return without moving. Things can't move due to blockage!
          return;
        }

        // Add mext entity to stack!
        stackToMove.emplace(nextEntity);

        // If left or right, find next entity
        if (orientation == core::Orientation::WEST || orientation == core::Orientation::EAST) {
          nextEntity = this->getGrid()[nextEntity->y + pairDirection.y][nextEntity->x + pairDirection.x];
        }

        // If up or down, may have to add more root movement sources as boxes can take up two
        //  spaces. If source tries to push right of box, add the left of the box to the
        //  rootMovementSources list
        if (orientation == core::Orientation::NORTH || orientation == core::Orientation::SOUTH) {
          // Get Box, and is larger, add other side of box to rootMovementSources
          auto box = dynamic_cast<warehouse::Box *>(nextEntity);
          if (box->getBoxSide() != core::NOWHERE) {
            // Find otherside to box
            warehouse::Entity *otherSide = nullptr;
            if (box->getBoxSide() == core::WEST) {
              otherSide = this->getGrid()[nextEntity->y][nextEntity->x + 1];
            }
            if (box->getBoxSide() == core::EAST) {
              otherSide = this->getGrid()[nextEntity->y][nextEntity->x - 1];
            }
            // Add otherSide to rootMovementSources and stackToMove.
            stackToMove.emplace(otherSide);
            rootMovementSources.push_back(otherSide);
          }

          nextEntity = this->getGrid()[nextEntity->y + pairDirection.y][nextEntity->x + pairDirection.x];
        }
      }
    }

    // Starting from top of the stack, move entities
    // Ensure that when something has been moved, it isn't moved a second time
    std::set<core::Pair *> moved;
    while (!stackToMove.empty()) {
      warehouse::Entity *toMove = stackToMove.top();
      if (!moved.contains(toMove)) {
        moved.emplace(toMove);
        // Remove reference to entity in Grid
        this->grid[toMove->y][toMove->x] = nullptr;
        // Set robot coordinates
        toMove->move(pairDirection);
        // Update grid to new robot location
        this->grid[toMove->y][toMove->x] = toMove;
      }
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
