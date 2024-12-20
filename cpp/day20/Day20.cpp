//
// Created by Jamie Briggs on 16/12/2024.
//

#include "Day20.h"

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "RaceTrack.h"

#include <iostream>

namespace solutions {
  std::string Day20::solvePartOne(const helper::SolutionInput *input) {
    RaceTrack track(input->getTestInput());

    pathfinding::AStarPathFinder aStarPathFinder;
    auto path = aStarPathFinder.findPath(track.getStartTile(), track.getEndTile(), false);

    std::cout << "Initial path without cheats found: " << std::endl;
    track.printMaze(path);

    return to_string(path.cost);
  }
  std::string Day20::solvePartTwo(const helper::SolutionInput *input) {
    return "Solve me!";
  }
} // namespace solutions
