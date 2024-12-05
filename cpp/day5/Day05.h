//
// Created by Jamie Briggs on 05/12/2024.
//

#ifndef DAY05_H
#define DAY05_H

#include "../Day.h"
#include "../helper/FileReader.h"

namespace solutions {

  class Day05 final : public Day{
  public:
    std::string solvePartOne(const helper::SolutionInput* input) override;
    std::string solvePartTwo(const helper::SolutionInput* input) override;
  };

} // namespace solutions


#endif // DAY05_H
