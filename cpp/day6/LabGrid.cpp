//
// Created by Jamie Briggs on 06/12/2024.
//

#include "LabGrid.h"
bool day6::LabGrid::moveGuard() {
  core::Pair currPosition = core::Pair(this->_guard->x, this->_guard->y);
  core::Pair nextPosition = this->_guard->getNextPosition();

  // Check if next position is within area
  if (nextPosition.x < 0 || nextPosition.y < 0 || nextPosition.x >= this->horizontalLength ||
      nextPosition.y >= this->verticalLength) {
    return true;
  }

  // Check is next position clear
  if (containsObstacle(nextPosition.x, nextPosition.y)) {
    // Add obstacle to history
    obstaclesRunInto.push_back(nextPosition);
    // Rotate guard
    _guard->rotate90Degrees();
    return false;
  }


  // Move the guard
  if (dynamic_cast<LabGuard *>(grid[this->_guard->y][this->_guard->x]) != nullptr) {
    // Point the destination address to gaurd
    grid[nextPosition.y][nextPosition.x] = _guard;
    _guard->x = nextPosition.x;
    _guard->y = nextPosition.y;
    _guard->positionsVisited.emplace(nextPosition.x, nextPosition.y);
    // Remove old reference from old address
    grid[currPosition.y][currPosition.x] = nullptr;
  }


  return false;
}
void day6::LabGrid::resetState() {
  // Point starting position address to guard
  grid[_guard->startY][_guard->startX] = _guard;
  // Set original position to nullptr if x and y are different
  if(_guard->x != _guard->startX || _guard->y != _guard->startY) {
    grid[_guard->y][_guard->x] = nullptr;
  }
  // Reset guard attributes
  _guard->x = _guard->startX;
  _guard->y = _guard->startY;
  _guard->positionsVisited.clear();
  _guard->positionsVisited.emplace(_guard->startX, _guard->startY);
  _guard->orientation = core::NORTH;
  // Remove temp obstacle
  tempObstruction.x = -1;
  tempObstruction.y = -1;
  // Remove obstacle history
  obstaclesRunInto.clear();
}
bool day6::LabGrid::loopDetected() {
  if(obstaclesRunInto.size() >= 8) {

    // If obstacles run into is this large, it's probably a loop as well
    if(obstaclesRunInto.size() > _obstacles.size() * 3) {
      return true;
    }


    if (obstaclesRunInto.size() >= 8) {
      // Take the last 8 obstacles that the guard ran into.
      std::vector<core::Pair> lastEight(obstaclesRunInto.end() - 8, obstaclesRunInto.end());
      // If the 1st and 5th element are the same, then the same obstacle has been run into.
      // The same check is done on the 2nd/6th, 3rd/7th, 4th/8th. If true, then the guard has
      // Hit the same 4 obstacles twice in a row confirming a loop.
      return lastEight[0] == lastEight[4]
      && lastEight[1] == lastEight[5]
      && lastEight[2] == lastEight[6]
      && lastEight[3] == lastEight[7];
    }

  }
  return false;
}
