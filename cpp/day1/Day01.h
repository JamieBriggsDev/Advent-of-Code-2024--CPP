//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef DAY_01_H
#define DAY_01_H

#include <string>

#include "../Day.h"
#include "../helper/SolutionInput.h"

using namespace helper;

namespace solutions {
    class Day01 final : public Day {
    public:
        std::string solvePartOne(const helper::SolutionInput* input) override;
        std::string solvePartTwo(const helper::SolutionInput* input) override;
    };
} // solutions

#endif //DAY_01_H
