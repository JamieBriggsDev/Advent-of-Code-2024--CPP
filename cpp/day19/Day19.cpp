//
// Created by perso on 16/12/2024.
//

#include "Day19.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "Pattern.h"
#include "PatternFinder.h"
#include "PatternHolder.h"

namespace solutions {
  std::string Day19::solvePartOne(const helper::SolutionInput *input) {
    auto lines = input->getSplitTestInput("");
    PatternHolder holder(lines[1], lines[0][0]);

    int totalPossibleDesigns = 0;
    std::cout << std::endl;
    for (const auto design : holder.getDesigns()) {
      if (PatternFinder::patternCanBeMade(design, holder.getTowels())) {
        totalPossibleDesigns++;
      }
    }

    std::cout << "Total possible designs: " << totalPossibleDesigns << std::endl;
    return to_string(totalPossibleDesigns);
  }
  std::string Day19::solvePartTwo(const helper::SolutionInput *input) {
    auto lines = input->getSplitTestInput("");
    PatternHolder holder(lines[1], lines[0][0]);

    long long totalPossibleDesigns = 0;
    std::cout << std::endl;
    for (const auto design : holder.getDesigns()) {
      long long totalTowels =
          PatternFinder::countTotalWaysPatternCanBeMade(design, holder.getTowels());
      std::cout << totalTowels << " => ";
      totalPossibleDesigns += totalTowels;
      std::cout << totalPossibleDesigns << std::endl;
    }

    std::cout << "Total possible designs: " << totalPossibleDesigns << std::endl;
    // not 1806150113
    // not 156424972769 too low
    // not 156424972769 too low
    return to_string(totalPossibleDesigns);
  }
} // namespace solutions
