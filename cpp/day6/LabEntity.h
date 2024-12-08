//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef LABENTITY_H
#define LABENTITY_H

namespace day6 {


  struct LabEntity {
    int x;
    int y;
    LabEntity(int x, int y) : x(x), y(y) {}
    virtual ~LabEntity(){};
  };
  struct LabObstacle : LabEntity {
    LabObstacle(int x, int y) : LabEntity(x, y) {}
  };
  struct LabGuard : LabEntity {
    int startX;
    int startY;
    core::Orientation orientation;
    std::unordered_set<core::Pair> positionsVisited;
    LabGuard(int x, int y) : LabEntity(x, y) {
      // Starts facing UP
      orientation = core::NORTH;
      // Add starting position
      positionsVisited.emplace(x, y);
      startX = x;
      startY = y;
    }
    core::Pair getNextPosition() {
      switch (orientation) {
        case core::NORTH:
          return {x, (y - 1)};
        case core::EAST:
          return core::Pair(x + 1, y);
        case core::SOUTH:
          return core::Pair(x, y + 1);
        case core::WEST:
          return core::Pair(x - 1, y);
        default:
          return core::Pair(x, y);
      }
    }
    void rotate90Degrees() {
      switch (orientation) {
        case core::NORTH:
          orientation = core::EAST;
          break;
        case core::EAST:
          orientation = core::SOUTH;
          break;
        case core::SOUTH:
          orientation = core::WEST;
          break;
        case core::WEST:
          orientation = core::NORTH;
          break;
        default:
          // Do nothing
          break;
      }
    }
    [[nodiscard]] unsigned long totalPositionVisits() const { return positionsVisited.size(); }
    std::vector<core::Pair> getAdjacentPositions() {
      std::vector<core::Pair> adjacentPositions;
      if (!(x == startX && y - 1 == startY)) {
        adjacentPositions.emplace_back(x, y - 1); // Position above
      }
      if (!(x + 1 == startX && y == startY)) {
        adjacentPositions.emplace_back(x + 1, y); // Position to the right
      }
      if (!(x == startX && y + 1 == startY)) {
        adjacentPositions.emplace_back(x, y + 1); // Position below
      }
      if (!(x - 1 == startX && y == startY)) {
        adjacentPositions.emplace_back(x - 1, y); // Position to the left
      }
      return adjacentPositions;
    }
  };

} // namespace day6

#endif // LABENTITY_H
