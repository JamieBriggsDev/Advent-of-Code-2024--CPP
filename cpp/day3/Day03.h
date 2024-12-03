//
// Created by Jamie Briggs on 03/12/2024.
//

#ifndef DAY_03_H
#define DAY_03_H

#include <string>

#include "../Day.h"
#include "../helper/SolutionInput.h"

using namespace helper;

namespace solutions {
    class Day03 final : public Day {
    public:
        std::string solvePartOne(const helper::SolutionInput* input) override;
        std::string solvePartTwo(const helper::SolutionInput* input) override;
    };
} // solutions

#endif //DAY_03_H
