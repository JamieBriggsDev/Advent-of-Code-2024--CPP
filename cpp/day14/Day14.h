//
// Created by Jamie Briggs on 14/12/2024.
//

#ifndef DAY14_H
#define DAY14_H
#include "../Day.h"

#include <vector>

#include "Robot.h"

namespace solutions {

class Day14 : public Day {
  public:
    std::string solvePartOne(const helper::SolutionInput *input) override;
    std::string solvePartTwo(const helper::SolutionInput *input) override;

    void printRobotLocations(std::vector<Robot> robots);
    long getSafetyFactor(std::vector<Robot> robots);
  };

} // solutions

#endif //DAY14_H
