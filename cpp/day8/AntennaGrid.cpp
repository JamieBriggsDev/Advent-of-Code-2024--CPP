//
// Created by perso on 08/12/2024.
//

#include "AntennaGrid.h"

namespace day8 {
  Antenna *AntennaGrid::convertToObject(const char c, const int x, const int y) {
    if (c == '.') {
      return nullptr;
    } else {
      // Add to antenna map if not added yet
      auto antenna = new Antenna(x, y, c);
      if (!this->antennas.contains(c)) {
        this->antennas[c].emplace(antenna);
      } else {
        this->antennas[c].emplace(antenna);
      }

      return antenna;
    }
  }
  std::vector<core::Pair> AntennaGrid::getAntinodeLocations(char c) {
    std::vector<core::Pair> antinode_locations;
    return antinode_locations;
  }
} // day8