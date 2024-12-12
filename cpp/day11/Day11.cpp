//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day11.h"

#include <iostream>
#include <unordered_map>

#include "PebbleRow.h"

namespace solutions {
  std::string Day11::solvePartOne(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    long long result = pebbles.performBlinks(25, true);

    return std::to_string(result);
  }
  std::string Day11::solvePartTwo(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    long long result = pebbles.performBlinks(75, true);
    return std::to_string(result);
  }
} // namespace solutions
