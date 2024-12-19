//
// Created by perso on 16/12/2024.
//

#include "Day19.h"

#include <iostream>

#include "../day20/Pattern.h"
#include "../day20/PatternFinder.h"
#include "../day20/PatternHolder.h"

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
  std::string Day19::solvePartTwo(const helper::SolutionInput *input) { return "Solve me!"; }
} // namespace solutions
