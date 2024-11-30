//
// Created by Jamie Briggs on 05/12/2023.
//

#ifndef DAY_H
#define DAY_H
#include <string>

#include "helper/SolutionInput.h"

namespace solutions {
    class Day{
    public:
        virtual std::string solvePartOne(const helper::SolutionInput* input) = 0;
        virtual std::string solvePartTwo(const helper::SolutionInput* input) = 0;
    };
}
#endif //DAY_H
