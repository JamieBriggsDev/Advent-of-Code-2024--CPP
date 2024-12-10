//
// Created by Jamie Briggs on 08/12/2024.
//

#include "AntennaGrid.h"
#include <set>

namespace day8 {
  Antenna *AntennaGrid::convertToObject(const char c, const int x, const int y) {
    if (c == '.') {
      return nullptr;
    } else {
      // Add to antenna map if not added yet
      auto antenna = new Antenna(x, y, c);
      if (!this->antennas.contains(c)) {
        this->antennas[c].emplace_back(antenna);
      } else {
        this->antennas[c].emplace_back(antenna);
      }

      return antenna;
    }
  }

  std::vector<core::Pair> AntennaGrid::getAntinodeLocations(char c) {
    std::vector<core::Pair> antinodeLocations;
    std::vector<Antenna *> antennas = this->antennas[c];
    if (antennas.size() < 2) {
      return antinodeLocations;
    }
    for (int i = 0; i < antennas.size(); i++) {
      // Find antinode locations using all antennas
      for (int j = i + 1; j < antennas.size(); j++) {
        Antenna *one = antennas[i];
        Antenna *two = antennas[j];
        // Get distance
        core::Pair distance = *one - *two;
        // Add to list
        core::Pair locationOne = core::Pair(one->x + distance.x, one->y + distance.y);
        if (isPairValid(locationOne)) {
          antinodeLocations.emplace_back(locationOne);
        }
        core::Pair locationTwo = core::Pair(two->x - distance.x, two->y - distance.y);
        if (isPairValid(locationTwo)) {
          antinodeLocations.emplace_back(locationTwo);
        }
      }
    }

    return antinodeLocations;
  }
  std::vector<core::Pair> AntennaGrid::getAntinodeLocationsUpdated(char c) {
    std::vector<core::Pair> antinodeLocations;
    std::set<core::Pair> antinodeLocationsSet;
    std::vector<Antenna *> antennas = this->antennas[c];
    if (antennas.size() < 2) {
      return antinodeLocations;
    }
    for (int i = 0; i < antennas.size(); i++) {
      // Find antinode locations using all antennas
      for (int j = i + 1; j < antennas.size(); j++) {
        Antenna *one = antennas[i];
        Antenna *two = antennas[j];
        // Get distance
        core::Pair distance = *one - *two;
        // Add to list

        // Handle direction one
        bool ranOutOfSpaceOne = false;
        int oneIdx = 0;
        while(!ranOutOfSpaceOne) {
          core::Pair locationOne = core::Pair(one->x + (distance.x * oneIdx), one->y + (distance.y * oneIdx));
          if (isPairValid(locationOne)) {
            antinodeLocationsSet.insert(locationOne);
            oneIdx++;
          }else {
            ranOutOfSpaceOne = true;
          }
        }

        // Handle direction two
        bool ranOutOfSpaceTwo = false;
        int twoIdx = 0;
        while(!ranOutOfSpaceTwo) {
          core::Pair locationTwo = core::Pair(two->x - (distance.x * twoIdx), two->y - (distance.y * twoIdx));
          if (isPairValid(locationTwo)) {
            antinodeLocationsSet.insert(locationTwo);
            twoIdx++;
          }
          else {
            ranOutOfSpaceTwo = true;
          }
        }
      }
    }

    antinodeLocations.assign(antinodeLocationsSet.begin(), antinodeLocationsSet.end());

    return antinodeLocations;
  }
  std::vector<core::Pair> AntennaGrid::getAntennaLocations() {

    std::vector<core::Pair> antenna_locations;
    for (const auto &[key, antenna_set]: this->antennas) {
      for (const auto &antenna: antenna_set) {
        antenna_locations.emplace_back(antenna->x, antenna->y);
      }
    }
    return antenna_locations;
  }
} // day8