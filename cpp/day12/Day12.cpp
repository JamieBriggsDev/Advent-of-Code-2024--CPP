//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day12.h"

#include "../algorithms/ZoneFinderFloodFill.h"
#include "FarmGrid.h"

namespace solutions {
  std::string Day12::solvePartOne(const helper::SolutionInput *input) {
    // Create farm
    FarmGrid farmGrid(input->getTestInput());
    // Find areas
    auto zones = algorithms::ZoneFinderFloodFill::findAllZones(farmGrid);
    // Find cost of every area
    long result = 0l;
    for(auto zone : zones) {
      long cost = zone.size() * zone.getPerimeterLength();
      result += cost;
    }
    return std::to_string(result);
  }
  std::string Day12::solvePartTwo(const helper::SolutionInput *input) { return "Solve me"; }
} // solutions