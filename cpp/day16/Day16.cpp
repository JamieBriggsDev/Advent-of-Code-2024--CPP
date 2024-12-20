//
// Created by perso on 16/12/2024.
//

#include "Day16.h"

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "../algorithms/pathfinding/Maze.h"
#include "../algorithms/pathfinding/PathFinder.h"

namespace solutions {
  std::string Day16::solvePartOne(const helper::SolutionInput *input) {
    Maze maze = Maze(input->getTestInput());
    core::PathFinder *pathFinder = new pathfinding::AStarPathFinder();
    auto result = pathFinder->findPath(maze.getStartTile(), maze.getEndTile(), true);

    maze.printMaze(result);

    return to_string(result.cost);
  }
  std::string Day16::solvePartTwo(const helper::SolutionInput *input) { return "Solve me!"; }
} // namespace solutions
