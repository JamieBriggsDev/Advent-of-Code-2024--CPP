//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef DAY06_H
#define DAY06_H

#include "../Day.h"
#include "../helper/FileReader.h"

namespace solutions {

  class Day06 final : public Day{
  public:
    std::string solvePartOne(const helper::SolutionInput* input) override;
    std::string solvePartTwo(const helper::SolutionInput* input) override;
  };

} // namespace solutions


#endif // DAY06_H
