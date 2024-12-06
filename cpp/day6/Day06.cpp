//
// Created by Jamie Briggs on 06/12/2024.
//

#include <string>


#include "Day06.h"

#include "LabGrid.h"


std::string solutions::Day06::solvePartOne(const helper::SolutionInput *input) {
  day6::LabGrid labGrid = day6::LabGrid(input->getTestInput());
  day6::LabGuard* guard = labGrid.getGuard();

  bool hasLeftMap = false;
  while(!hasLeftMap) {
    hasLeftMap = labGrid.moveGuard();
  }

  return std::to_string(guard->totalPositionVisits());
}
std::string solutions::Day06::solvePartTwo(const helper::SolutionInput *input) {
  day6::LabGrid labGrid = day6::LabGrid(input->getTestInput());
  day6::LabGuard* guard = labGrid.getGuard();

  unordered_set<core::Pair> adjacentPositionsForPotentialObstruction;
  // First run the original solution to find potential adjacent positions
  bool hasLeftMap = false;
  while(!hasLeftMap) {
    auto adjacentPositions = guard->getAdjacentPositions();
    adjacentPositionsForPotentialObstruction.insert(adjacentPositions.begin(), adjacentPositions.end());
    // Before moving, get potential positions
    hasLeftMap = labGrid.moveGuard();
  }

  vector<core::Pair> possibilities;
  // Time for some long brute force. Run the guard path again, but for each
  //  potential adjacent position. Each loop, add a temporary obstruction. If
  //  there is a loop, break out and add to final result
  int totalChecked = 0;
  for (const auto &position: adjacentPositionsForPotentialObstruction) {
    // Before doing anything, reset grid state
    labGrid.resetState();
    // Add temporary obstruction
    labGrid.setTemporaryObstruction(position.x, position.y);
    // Run guard
    bool hasLeftMapInCheck = false;
    bool hasFoundLoop = false;
    bool hasFoundBadRoute = false;
    while(!hasLeftMapInCheck && !hasFoundLoop && !hasFoundBadRoute) {
      int guardX = guard->x;
      int guardY = guard->y;
      hasLeftMapInCheck = labGrid.moveGuard();
      hasFoundLoop = labGrid.loopDetected();
      // It's also possible that a loop is made but not via the normal circular route.
      //  For example, it may be possible for the guard to go on a goose chase amongst 10
      //  obstacles and coincidentally end up at the start. For that reason, break out if
      //  the history is twice the size of obstacles on the map.
      hasFoundBadRoute = false;
    }

    // Check if loop was found, and add to count
    if(hasFoundLoop) {
      possibilities.emplace_back(position);
    }

    totalChecked++;

  }


  return std::to_string(possibilities.size());
}
