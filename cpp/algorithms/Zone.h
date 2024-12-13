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
public:
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
  [[nodiscard]] int getPerimeterLength();
  int size() const {
    return zoneLocations.size();
  }
};

} // algorithms

#endif //ZONE_H
