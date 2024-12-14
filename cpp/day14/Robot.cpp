//
// Created by perso on 14/12/2024.
//

#include "Robot.h"

#include <regex>

#include "../core/AocException.h"

namespace solutions {
  Robot::Robot(std::string input) {
    // Four capture groups
    //  posX: Any number digits
    //  posY: Any number digits
    //  velX: Any number digits and optional negative character '-'
    //  velY: Any number digits and optional negative character '-'

    std::regex robotPattern(R"(p=(\d+),(\d+) v=(-?\d+),(-?\d+))");
    std::smatch match;

    if (std::regex_search(input, match, robotPattern)) {
      int posX = std::stoi(match[1]);
      int posY = std::stoi(match[2]);
      int velX = std::stoi(match[3]);
      int vely = std::stoi(match[4]);
      this->initialPosition = {posX, posY};
      this->position = {posX, posY};
      this->velocity = {velX, vely};
    } else {
      throw new core::AocException("Could not parse robot input");
    }
  }
  void Robot::move() {
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;
    //this->position += this->velocity;
  }
  bool Robot::teleportIfOutOfRange(int maxXRange, int maxYRange) {
    bool hasTeleported = false;
    // Velocity might move a robot more than the range twice over, so keep doing until
    //  in range
    while (this->position.x >= maxXRange) {
      this->position.x -= maxXRange;
      hasTeleported = true;
    }
    while (this->position.x < 0) {
      this->position.x += maxXRange;
      hasTeleported = true;
    }
    while (this->position.y >= maxYRange) {
      this->position.y -= maxYRange;
      hasTeleported = true;
    }
    while (this->position.y < 0) {
      this->position.y += maxYRange;
      hasTeleported = true;
    }
    return hasTeleported;
  }
  core::Orientation Robot::whichQuadrant(int maxXRange, int maxYRange) {
    int middleX = (maxXRange - 1) / 2;
    int middleY = (maxYRange - 1) / 2;
    if (this->position.x == middleX || this->position.y == middleY) {
      return core::Orientation::NOWHERE;
    }
    if (this->position.x > middleX) {
      if (this->position.y < middleY) {
        return core::Orientation::NORTH_EAST;
      }
      return core::Orientation::SOUTH_EAST;
    }
    if (this->position.x < middleX) {
      if (this->position.y < middleY) {
        return core::Orientation::NORTH_WEST;
      }
      return core::Orientation::SOUTH_WEST;
    }

    return core::Orientation::NOWHERE;
  }
} // namespace solutions
