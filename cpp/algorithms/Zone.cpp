//
// Created by Jamie Briggs on 13/12/2024.
//

#include "Zone.h"

#include "../core/Orientation.h"

const auto directions = {core::Directions::toPair(core::NORTH), core::Directions::toPair(core::EAST),
                         core::Directions::toPair(core::SOUTH), core::Directions::toPair(core::WEST)};
const auto diagonol = {core::Directions::toPair(core::NORTH_EAST), core::Directions::toPair(core::SOUTH_EAST),
                       core::Directions::toPair(core::SOUTH_WEST), core::Directions::toPair(core::NORTH_WEST)};


namespace algorithms {
  int Zone::getPerimeterLength() {
    int totalBorders = 0;
    for (auto loc: this->zoneLocations) {
      // Check each direction
      for (auto dir: directions) {
        // If not location in direction, add to border count
        if (!contains(loc + dir)) {
          totalBorders++;
        }
      }
    }
    return totalBorders;
  }
  int Zone::getTotalSides() {
    int totalCorners = 0;
    for (auto loc: this->zoneLocations) {
      std::set<core::Orientation> sidesFound;
      // Check each direction
      for (auto dir: directions) {
        // If not location in direction, add to border count
        if (!contains(loc + dir)) {
          sidesFound.insert(core::Directions::fromPair(dir));
        }
      }

      // Check corners
      for (auto dir: diagonol) {
        // If not location in direction, add to border count
        if (!contains(loc + dir)) {
          sidesFound.insert(core::Directions::fromPair(dir));
        }
      }

      // If more than 1 side found, potential corner found! Total corners also means total sides!
      bool containsNorth = sidesFound.find(core::NORTH) != sidesFound.end();
      bool containsNorthEast = sidesFound.find(core::NORTH_EAST) != sidesFound.end();
      bool containsEast = sidesFound.find(core::EAST) != sidesFound.end();
      bool containsSouthEast = sidesFound.find(core::SOUTH_EAST) != sidesFound.end();
      bool containsSouth = sidesFound.find(core::SOUTH) != sidesFound.end();
      bool containsSouthWest = sidesFound.find(core::SOUTH_WEST) != sidesFound.end();
      bool containsWest = sidesFound.find(core::WEST) != sidesFound.end();
      bool containsNorthWest = sidesFound.find(core::NORTH_WEST) != sidesFound.end();
      // If North -> East Corner
      if (containsNorth && containsEast) {
        totalCorners++;
      }
      // Check for inverted corner
      else if (!containsNorth && !containsEast && containsNorthEast) {
        totalCorners++;
      }

      // If East -> South Corner
      if (containsEast && containsSouth) {
        totalCorners++;
      }
      // Check for inverted corner
      else if (!containsEast && !containsSouth && containsSouthEast) {
        totalCorners++;
      }

      // If South - West Corner
      if (containsSouth && containsWest) {
        totalCorners++;
      }
      // Check for inverted corner
      else if (!containsSouth && !containsWest && containsSouthWest) {
        totalCorners++;
      }

      // If West -> North Corner
      if (containsWest && containsNorth) {
        totalCorners++;
      }
      // Check for inverted corner
      else if (!containsWest && !containsNorth && containsNorthWest) {
        totalCorners++;
      }
    }


    return totalCorners;
  }
} // namespace algorithms
