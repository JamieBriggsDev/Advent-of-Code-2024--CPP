//
// Created by perso on 16/12/2024.
//

#include "Day17.h"

#include "ChronospatialComputer.h"

namespace solutions {
  std::string Day17::solvePartOne(const helper::SolutionInput *input) {
    ChronospatialComputer computer(input->getTestInput());
    vector<int> output = computer.run();
    string result = "";
    for (int i = 0; i < output.size(); i++) {
      result += to_string(output[i]);
      if (i < output.size() - 1) {
        result += ",";
      }
    }

    // Not 167430506
    return result;
  }
  std::string Day17::solvePartTwo(const helper::SolutionInput *input) {
    ChronospatialComputer computer(input->getTestInput());
    computer.setRegisterAValue(117440);
    vector<int> output = computer.run();
    string result = "";
    for (int i = 0; i < output.size(); i++) {
      result += to_string(output[i]);
      if (i < output.size() - 1) {
        result += ",";
      }
    }

    // Not 167430506
    return result;
  }
} // namespace solutions
