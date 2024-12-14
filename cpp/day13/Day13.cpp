//
// Created by perso on 14/12/2024.
//

#include "Day13.h"

#include "ClawMachine.h"

namespace solutions {
  std::string Day13::solvePartOne(const helper::SolutionInput *input) {
    vector<vector<string>> inputs = input->getSplitTestInput("");
    int tokensSpent = 0;
    for (auto &rawInput : inputs) {
      ClawMachine machine(rawInput);
      core::Pair buttonPresses = machine.getCheapestWayToPrize();
      int toAdd = buttonPresses.x * 3 + buttonPresses.y;
      tokensSpent += buttonPresses.x * 3; // Button A costs 3 tokens :(
      tokensSpent += buttonPresses.y;
    }
    return std::to_string(tokensSpent);
  }
  std::string Day13::solvePartTwo(const helper::SolutionInput *input) {
    return "Solve me";
  }
} // solutions