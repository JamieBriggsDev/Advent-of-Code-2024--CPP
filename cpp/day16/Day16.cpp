//
// Created by Jamie Briggs on 16/12/2024.
//

#include "Day16.h"

#include <iostream>

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "../algorithms/pathfinding/DijkstraPathFinder.h"
#include "../algorithms/pathfinding/Maze.h"
#include "../algorithms/pathfinding/PathFinder.h"

#include <unordered_set>


namespace solutions {
  std::string Day16::solvePartOne(const helper::SolutionInput *input) {
    pathfinding::Maze maze = pathfinding::Maze(input->getTestInput());
    auto *pathFinder = new pathfinding::DijkstraPathFinder();
    auto result = pathFinder->findPath(maze.getStartTile(), maze.getEndTile(), true);

    maze.printMaze(result);

    return to_string(result.cost);
  }
  std::string Day16::solvePartTwo(const helper::SolutionInput *input) {
    pathfinding::Maze maze = pathfinding::Maze(input->getTestInput());
    auto *pathFinder = new pathfinding::DijkstraPathFinder();
    auto result = pathFinder->findPaths(maze.getStartTile(), maze.getEndTile(), true);

    std::unordered_set<core::Pair> visited;
    vector<vector<bool>> paths(maze.getHorizontalLength(), std::vector<bool>(maze.getVerticalLength(), false));
    for (auto path : result) {
      while (!path.path.empty()) {
        visited.emplace(path.path.top()->getPosition());
        paths[path.path.top()->getPosition().x][path.path.top()->getPosition().y] = true;
        path.path.pop();
      }
    }

    cout << endl;
    for (int y = 0; y < maze.getVerticalLength(); y++) {
      for (int x = 0; x < maze.getHorizontalLength(); x++) {
        if (paths[x][y]) {
          cout << "O";
        } else {
          if (maze.getWalls()[y][x]) {
            cout << "#";
          }
          else {
            cout << ".";
          }
        }
      }
      cout << endl;
    }

    return to_string(visited.size());
  }
} // namespace solutions
