//
// Created by Jamie Briggs on 08/12/2024.
//

#include <string>


#include "Day08.h"

#include "AntennaGrid.h"


std::string solutions::Day08::solvePartOne(const helper::SolutionInput *input) {
  day8::AntennaGrid grid = day8::AntennaGrid(input->getTestInput());
  std::unordered_set<core::Pair> locations;
  for(const auto &antennaType : grid.getTypesOfAntennas()) {
    for(const auto & antinodeLocation : grid.getAntinodeLocations(antennaType)) {
      locations.emplace(antinodeLocation);
    }
  }
  return std::to_string(locations.size());
}
std::string solutions::Day08::solvePartTwo(const helper::SolutionInput *input) {
  return "Yet to solve";
}
