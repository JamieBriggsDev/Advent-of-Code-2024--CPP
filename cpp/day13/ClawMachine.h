//
// Created by Jamie Briggs on 14/12/2024.
//

#ifndef CLAWMACHINE_H
#define CLAWMACHINE_H
#include "../core/Pair.h"

#include <string>
#include <vector>

namespace solutions {

  struct ClawMachineButton : core::Pair {
    ClawMachineButton(int x, int y) : core::Pair(x, y) {}
  };

  class ClawMachine {
    ClawMachineButton buttonA;
    ClawMachineButton buttonB;
    core::Pair prize;
  public:
    explicit ClawMachine(std::vector<std::string> input, bool withCorrectMeasurements = false);

    [[nodiscard]] ClawMachineButton getButtonA() const {
      return buttonA;
    }
    [[nodiscard]] ClawMachineButton getButtonB() const {
      return buttonB;
    }
    [[nodiscard]] core::Pair getPrize() const {
      return prize;
    }

    core::Pair getCheapestWayToPrize();
  };

} // namespace solutions

#endif // CLAWMACHINE_H
