//
// Created by Jamie Briggs on 04/12/2024.
//

#ifndef DAY04_H
#define DAY04_H

#include "../Day.h"
#include "../helper/FileReader.h"

namespace solutions {

  class Day04 final : public Day{
  public:
    std::string solvePartOne(const helper::SolutionInput* input) override;
    std::string solvePartTwo(const helper::SolutionInput* input) override;
  };

} // namespace solutions


#endif // DAY04_H
