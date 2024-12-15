//
// Created by perso on 14/12/2024.
//

#include "Day15.h"

#include <iostream>

#include "DirectionQueue.h"
#include "Warehouse.h"

namespace solutions {
  std::string Day15::solvePartOne(const helper::SolutionInput *input) {
    // Split input
    auto bothInputs = input->getSplitTestInput("");
    // Create warehouse
    Warehouse warehouse(bothInputs[0]);
    // Get list of directions
    DirectionQueue directionQueue(bothInputs[1]);
    // Loop through directions and move all boxes
    while (directionQueue.size() > 0) {
      warehouse.moveRobot(directionQueue.peekNext());
      directionQueue.pop();
    }

    // Print for fun!
    std::cout << "\n";
    warehouse.printWarehouseLayout();

    // Loop through all boxes and get GPS coordinates
    long long totalGPSValues = 0l;
    for (auto box : warehouse.getBoxes()) {
      totalGPSValues += (100l * box->y) + box->x;
    }
    return std::to_string(totalGPSValues);
  }
  std::string Day15::solvePartTwo(const helper::SolutionInput *input) {return "To solve"; }
} // solutions