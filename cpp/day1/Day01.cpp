//
// Created by Jamie Briggs on 05/12/2023.
//

#include "Day01.h"

#include "Day01PairBuilder.h"

#include <iostream>
#include <numeric>
#include <vector>

#include "../helper/SolutionInput.h"

#include <regex>

using namespace std;


namespace solutions {
  string Day01::solvePartOne(const helper::SolutionInput *input) {

    const regex listsRegex("([0-9]+)\\s+([0-9]+)");

    auto *builder = new Day01PairBuilder;

    // Make two lists in numerical order using Day01PairBuilderTests
    for (const auto &row: input->getTestInput()) {
      smatch m;
      regex_search(row, m, listsRegex);
      int a = std::stoi(m[1]);
      int b = std::stoi(m[2]);
      builder->addToListOne(a);
      builder->addToListTwo(b);
    }

    // Get a queue of all pairs
    queue<core::Pair> pairs = builder->getPairs();
    // Loop through pairs to get final sum
    int finalSum = 0;
    while (!pairs.empty()) {
      finalSum += pairs.front().distance();
      pairs.pop();
    }

    return std::to_string(finalSum);
  }


  string Day01::solvePartTwo(const helper::SolutionInput *input) { return "To complete!"; }
} // namespace solutions
