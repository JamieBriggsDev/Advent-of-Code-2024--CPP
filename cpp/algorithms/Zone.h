//
// Created by Jamie Briggs on 13/12/2024.
//

#ifndef ZONE_H
#define ZONE_H

#include <set>
#include <vector>

#include "../core/Pair.h"


namespace algorithms {

class Zone {
  std::vector<core::Pair> zoneLocations;
  char label;
public:
  Zone(char label) : label(label) {}
  Zone() : label('?') {}
  bool contains(core::Pair pair) {
    for (const auto &location: zoneLocations) {
      if (location == pair) {
        return true;
      }
    }
    return false;
  }
  void addLocation(core::Pair pair) {
    zoneLocations.push_back(pair);
  }
  int getHeight() {
    int height = 0;
    for (const auto &location: zoneLocations) {
      if (location.y > height) {
        height = location.y;
      }
    }
    return height;
  }
  int getWidth() {
    int width = 0;
    for (const auto &location: zoneLocations) {
      if (location.x > width) {
        width = location.x;
      }
    }
    return width;
  }


  /**
   * Gets the perimeter length for the area (2x2=8 fences)
   * @return The perimeter
   */
  [[nodiscard]] int getPerimeterLength();
  /**
   * Gets the total sides of the area (2x2=4 sides)
   * @return The total sides
   */
  [[nodiscard]] int getTotalSides();
  int size() const { return zoneLocations.size(); }
  char getLabel() {
    return label;
  }
};

} // algorithms

#endif //ZONE_H
