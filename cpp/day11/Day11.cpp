//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day11.h"

#include <iostream>

#include "PebbleRow.h"

namespace solutions {
  std::string Day11::solvePartOne(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    std::cout << "Initial arrangement:" << std::endl;
    pebbles.printToConsole();

    for (int totalBlinks = 1; totalBlinks <= 25; totalBlinks++) {

      for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
        bool flag = false;
        flag = pebbles.upgradeZeroEngraving(it);
        if(!flag) {
          flag = pebbles.splitPebbleIfEven(it);
        }
        if(!flag) {
          pebbles.multiplyPebbleByYear(it);
        }
      }

      //std::cout << "After " << totalBlinks << "  blinks:" << std::endl;
      //pebbles.printToConsole();
    }
    return std::to_string(pebbles.getPebbleQuantities().size());
  }
  std::string Day11::solvePartTwo(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    std::cout << "Initial arrangement:" << std::endl;
    pebbles.printToConsole();

    for (int totalBlinks = 1; totalBlinks <= 75; totalBlinks++) {

      for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
        bool flag = false;
        flag = pebbles.upgradeZeroEngraving(it);
        if(!flag) {
          flag = pebbles.splitPebbleIfEven(it);
        }
        if(!flag) {
          pebbles.multiplyPebbleByYear(it);
        }
      }

      //std::cout << "After " << totalBlinks << "  blinks:" << std::endl;
      //pebbles.printToConsole();
    }
    return std::to_string(pebbles.getPebbleQuantities().size());
  }
} // namespace solutions
