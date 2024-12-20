//
// Created by perso on 16/12/2024.
//

#include "Day18.h"

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "../algorithms/pathfinding/PathFinder.h"
#include "MemorySpace.h"

namespace solutions {
  std::string Day18::solvePartOne(const helper::SolutionInput *input) {
    int widthHeight = this->isTestMode ? 7 : 71;
    int totalToDrop = this->isTestMode ? 12 : 1024;
    algorithms::MemorySpace memorySpace(input->getTestInput(), widthHeight);

    memorySpace.dropBytes(totalToDrop);

    pathfinding::AStarPathFinder pathFinder;

    auto foundPath = pathFinder.findPath(memorySpace.getStart(), memorySpace.getFinish(), false);
    //pathfinding::FinalPath foundPath;
    memorySpace.printPath(foundPath);
    // Remove 1 as don't include the start as a step
    return to_string(foundPath.path.size() - 1);
  }
  std::string Day18::solvePartTwo(const helper::SolutionInput *input) {
    int widthHeight = this->isTestMode ? 7 : 71;



    // Set initial lower and upper limit
    int lowerLimit = this->isTestMode ? 12 : 1024;
    int upperLimit = input->getTotalRowsInInput();
    pathfinding::AStarPathFinder pathFinder;

    // Rather than iterating through every possible drop, check via estimation.
    // Example:
    // |                                        |
    // Can Leave -> |         | <- Can't Leave
    // Can Leave -----> |  | <- Can't Leave
    //        Optimized!  |
    int totalAttempts = 0;

    core::Pair result(-1, -1);
    while (lowerLimit != upperLimit) {
      int currentDropAttempt = (upperLimit - lowerLimit) / 2 + lowerLimit;
      // Create memory space
      algorithms::MemorySpace memorySpace(input->getTestInput(), widthHeight);
      // Drop and remember result incase this is answer
      CorruptedByte* lastDrop = memorySpace.dropBytes(currentDropAttempt);

      auto findPath = pathFinder.findPath(memorySpace.getStart(), memorySpace.getFinish(), false);

      std::cout << "Current attempt: " << totalAttempts++ << std::endl;
      std::cout << "Total drops in attempt: " << currentDropAttempt << std::endl;
      std::cout << "Corrupted Byte: " << lastDrop->getPosition().toString() << std::endl;
      std::cout << "Path found: " << findPath.pathFound() << std::endl;
      auto foundPath = findPath.pathFound();
      if (foundPath) {
        memorySpace.printPath(findPath);
        lowerLimit = currentDropAttempt + 1;
      }else {
        upperLimit = currentDropAttempt;
      }

      result.x = lastDrop->getPosition().x;
      result.y = lastDrop->getPosition().y;
    }

    // Remove 1 as don't include the start as a step
    return result.toString();
  }
} // namespace solutions
