//
// Created by Jamie Briggs on 08/12/2024.
//

#ifndef DAY08_H
#define DAY08_H

#include "../Day.h"
#include "../helper/FileReader.h"

namespace solutions {

  class Day08 final : public Day{
  public:
    std::string solvePartOne(const helper::SolutionInput* input) override;
    std::string solvePartTwo(const helper::SolutionInput* input) override;
  };

} // namespace solutions


#endif // DAY08_H
