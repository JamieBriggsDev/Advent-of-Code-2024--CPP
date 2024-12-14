//
// Created by perso on 14/12/2024.
//

#include "ClawMachine.h"

#include <string>
#include <regex>

namespace solutions {
  ClawMachine::ClawMachine(std::vector<std::string> input) : buttonA(0, 0), buttonB(0, 0) {
    std::regex buttonPattern(R"(Button (A|B): X\+(\d+), Y\+(\d+))");

    std::smatch buttonOneMatches;
    if (std::regex_search(input[0], buttonOneMatches, buttonPattern)) {
      // Convert matched strings to integers
      int num1 = std::stoi(buttonOneMatches[2].str());
      int num2 = std::stoi(buttonOneMatches[3].str());
      buttonA = ClawMachineButton(num1, num2);
    }
    std::smatch buttonTwoMatches;
    if (std::regex_search(input[1], buttonTwoMatches, buttonPattern)) {
      // Convert matched strings to integers
      int num1 = std::stoi(buttonTwoMatches[2].str());
      int num2 = std::stoi(buttonTwoMatches[3].str());
      buttonB = ClawMachineButton(num1, num2);
    }

    std::regex prizePattern(R"(Prize: X\=(\d+), Y\=(\d+))");
    std::smatch prizeMatches;
    if (std::regex_search(input[2], prizeMatches, prizePattern)) {
      // Convert matched strings to integers
      int num1 = std::stoi(prizeMatches[1].str());
      int num2 = std::stoi(prizeMatches[2].str());
      prize = core::Pair(num1, num2);
    }
  }
  core::Pair ClawMachine::getCheapestWayToPrize() {
    // Turn into simultaneous equation
    // ba94 + bb22 = 8400
    // ba34 + bb67 = 5400

    // Doing Cramer's rule!!
    // Coefficients
    double a1 = buttonA.x, b1 = buttonB.x, c1 = prize.x;
    double a2 = buttonA.y, b2 = buttonB.y, c2 = prize.y;

    // Solving for both
    double totalButtonA, totalButtonB;

    // Cramer
    totalButtonA = (c1 * b2 - b1 * c2) / (a1 * b2 - a2 * b1);
    totalButtonB = (a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2);


    // Ensure totalButtonA and totalButtonB are integers
    if (totalButtonA != static_cast<int>(totalButtonA) ||
      totalButtonB != static_cast<int>(totalButtonB)) {
      return core::Pair(0, 0);
    }
    return core::Pair(totalButtonA, totalButtonB);
  }
} // solutions