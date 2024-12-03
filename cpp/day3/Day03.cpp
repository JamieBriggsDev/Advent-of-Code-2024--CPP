//
// Created by Jamie Briggs on 03/12/2024.
//

#include "Day03.h"
#include "Computer.h"

#include <iostream>
#include <vector>

#include "../helper/SolutionInput.h"


using namespace std;


namespace solutions {
  string Day03::solvePartOne(const helper::SolutionInput *input) {
    auto* computer = new Computer();
    for(const auto& row : input -> getTestInput()) {
      computer->loadMemory(row);
    }

    long sum = 0l;
    while(computer->containsAnyCommands()) {
      // Get the next loaded command and fetch it's result
      sum += computer->popNextCommand().result();
    }

    return std::to_string(sum);
  }


  string Day03::solvePartTwo(const helper::SolutionInput *input) {
    return "solve me";
  }
} // namespace solutions
