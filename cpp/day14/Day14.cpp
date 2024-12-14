//
// Created by perso on 14/12/2024.
//

#include "Day14.h"

#include <vector>

#include "Robot.h"


namespace solutions {
  std::string Day14::solvePartOne(const helper::SolutionInput *input) {

    int MAX_X = this->isTestMode ? 11 : 101;
    int MAX_Y = this->isTestMode ? 7 : 103;

    std::vector<Robot> robots;
    for (auto row : input->getTestInput()) {
      robots.emplace_back(row);
    }

    for (int seconds = 0; seconds < 100; seconds++) {
      for (auto &robot : robots) {
        robot.move();
        robot.teleportIfOutOfRange(MAX_X, MAX_Y);
      }
    }

    // Get quadrants
    std::vector<Robot> robotsNE, robotsSE, robotsSW, robotsNW, robotsNowhere;
    for (auto robot : robots) {
      switch (robot.whichQuadrant(MAX_X, MAX_Y)) {
        case core::NORTH_EAST:
          robotsNE.emplace_back(robot);
          break;
        case core::SOUTH_EAST:
          robotsSE.emplace_back(robot);
        break;
        case core::SOUTH_WEST:
          robotsSW.emplace_back(robot);
        break;
        case core::NORTH_WEST:
          robotsNW.emplace_back(robot);
        break;
        default:
          robotsNowhere.emplace_back(robot);
          ;
      }
    }

    long safetyFactor = robotsNE.size() * robotsSE.size() * robotsSW.size() * robotsNW.size();
    return std::to_string(safetyFactor);
  }
  std::string Day14::solvePartTwo(const helper::SolutionInput *input) {
    return "To solve";
  }
} // solutions