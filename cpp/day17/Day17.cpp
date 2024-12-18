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
    std::string program = "";
    for (int i = 0; i < computer.getProgram().size(); i++) {
      program += to_string(computer.getProgram()[i]);
      if (i < computer.getProgram().size() - 1) {
        program += ",";
      }
    }

    int i = 0;
    while (true) {
      // Due to the modula 8 operation, taking an assumption and going up in 8s. This is
      //   VERY brute force...
      // Perhaps the solution to this is to work backwards?
      i += 8;

      ChronospatialComputer computerToCheck(input->getTestInput());
      computerToCheck.setRegisterAValue(i);
      vector<int> output = computerToCheck.run();
      string result = "";
      for (int i = 0; i < output.size(); i++) {
        result += to_string(output[i]);
        if (i < output.size() - 1) {
          result += ",";
        }
      }

      if (result == program) {
        return to_string(i);
      }
    }

    // Not 167430506
    return "Not found :(";
  }
} // namespace solutions
