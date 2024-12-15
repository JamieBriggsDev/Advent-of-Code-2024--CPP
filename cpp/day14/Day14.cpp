//
// Created by perso on 14/12/2024.
//

#include "Day14.h"

#include <thread> // Required for std::this_thread::sleep_for
#include <chrono> // Required for std::chrono::seconds
#include <iostream>
#include <ostream>
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
    int MAX_X = this->isTestMode ? 11 : 101;
    int MAX_Y = this->isTestMode ? 7 : 103;

    std::vector<Robot> robots;
    for (auto row: input->getTestInput()) {
      robots.emplace_back(row);
    }

    bool foundTree;
    long long currentMinSafetyFactor = 9999999999l;
    // Should be enough seconds
    int seconds = 1;
    for (; seconds <= 10000; seconds++) {
      for (auto &robot: robots) {
        robot.move();
        robot.teleportIfOutOfRange(MAX_X, MAX_Y);
      }

      long safetyFactor = getSafetyFactor(robots);
      if (safetyFactor < currentMinSafetyFactor) {
        currentMinSafetyFactor = safetyFactor;
        std::cout << "New minimum safety factor: " << currentMinSafetyFactor << std::endl;
        std::cout << "Total seconds: " << seconds << std::endl;
        printRobotLocations(robots);
      }

    }



    return std::to_string(seconds);
  }

  void Day14::printRobotLocations(std::vector<Robot> robots) {
    int MAX_X = this->isTestMode ? 11 : 101;
    int MAX_Y = this->isTestMode ? 7 : 103;
    std::vector<std::vector<bool>> grid(MAX_Y, std::vector<bool>(MAX_X, false));
    for (auto robot : robots) {
      grid[robot.getCurrentPosition().y][robot.getCurrentPosition().x] = true;
    }

    for (int y = 0; y < MAX_Y; y++) {
      for (int x = 0; x < MAX_X; x++) {
        std::cout << (grid[y][x] ? "#" : ".");
      }
      std::cout << std::endl;
    }
  }

  long Day14::getSafetyFactor(std::vector<Robot> robots) {
    int MAX_X = this->isTestMode ? 11 : 101;
    int MAX_Y = this->isTestMode ? 7 : 103;
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

    return robotsNE.size() * robotsSE.size() * robotsSW.size() * robotsNW.size();

  }
} // solutions