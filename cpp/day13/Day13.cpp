//
// Created by Jamie Briggs on 14/12/2024.
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
      tokensSpent += buttonPresses.x * 3; // Button A costs 3 tokens :(
      tokensSpent += buttonPresses.y;
    }
    return std::to_string(tokensSpent);
  }
  std::string Day13::solvePartTwo(const helper::SolutionInput *input) {
    vector<vector<string>> inputs = input->getSplitTestInput("");
    long long tokensSpent = 0L;
    for (auto &rawInput : inputs) {
      ClawMachine machine(rawInput, true);
      core::Pair buttonPresses = machine.getCheapestWayToPrize();
      tokensSpent += buttonPresses.x * 3; // Button A costs 3 tokens :(
      tokensSpent += buttonPresses.y;
    }
    return std::to_string(tokensSpent);
  }
} // solutions