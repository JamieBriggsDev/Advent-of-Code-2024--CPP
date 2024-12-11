//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day11.h"

#include <iostream>
#include <unordered_map>

#include "PebbleRow.h"

namespace solutions {
  std::string Day11::solvePartOne(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    for (int totalBlinks = 1; totalBlinks <= 25; totalBlinks++) {

      for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
        bool flag = false;
        flag = pebbles.upgradeZeroEngraving(it);
        if(!flag) {
          flag = pebbles.splitPebbleIfEven(it);
        }
        if(!flag) {
          pebbles.multiplyPebbleByYear(it);
        }
      }

    }
    return std::to_string(pebbles.getTotalStones());
  }
  std::string Day11::solvePartTwo(const helper::SolutionInput *input) {
    PebbleRow pebbles = PebbleRow(input->getTestInput()[0]);

    for (int totalBlinks = 1; totalBlinks <= 75; totalBlinks++) {

      for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
        bool flag = false;
        flag = pebbles.upgradeZeroEngraving(it);
        if(!flag) {
          flag = pebbles.splitPebbleIfEven(it);
        }
        if(!flag) {
          pebbles.multiplyPebbleByYear(it);
        }
      }

    }
    return std::to_string(pebbles.getTotalStones());
  }
} // namespace solutions
