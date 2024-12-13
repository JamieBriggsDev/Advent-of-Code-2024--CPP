//
// Created by Jamie Briggs on 13/12/2024.
//

#include "Zone.h"

#include "../core/Orientation.h"

namespace algorithms {
  int Zone::getPerimeterLength() {
    int totalBorders = 0;
    auto directions =
      {
        core::Directions::toPair(core::NORTH),
        core::Directions::toPair(core::EAST),
        core::Directions::toPair(core::SOUTH),
        core::Directions::toPair(core::WEST)
      };
    for(auto loc : this->zoneLocations) {
      // Check each direction
      for(auto dir : directions) {
        // If not location in direction, add to border count
        if (!contains(loc + dir)) {
          totalBorders++;
        }
      }
    }
    return totalBorders;
  }
} // algorithms