//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day12.h"

#include "../algorithms/ZoneFinderFloodFill.h"
#include "FarmGrid.h"
#include <iostream>

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
  std::string Day12::solvePartTwo(const helper::SolutionInput *input) {
    // Create farm
    FarmGrid farmGrid(input->getTestInput());
    // Find areas
    auto zones = algorithms::ZoneFinderFloodFill::findAllZones(farmGrid);
    // Find cost of every area
    long result = 0l;
    int totalSizeFound = 0;
    for(auto zone : zones) {
      int totalSides = zone.getTotalSides();
      int size = zone.size();
      totalSizeFound += size;
      long cost = size * totalSides;
      std::cout << "A region of " << zone.getLabel() << " plants with a price " << size << " * " << totalSides << " = " << cost << std::endl;
      result += cost;
    }

    std::cout << "Total size found: " << totalSizeFound << std::endl;

    return std::to_string(result);
  }
} // solutions