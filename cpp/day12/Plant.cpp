//
// Created by Jamie Briggs on 12/12/2024.
//

#include "Plant.h"

namespace solutions {
  void Plant::addNeighbouringPlant(const core::Orientation &orientation, Plant other) {
    this->neighbourPlants[orientation] = other.getZoneLabel();
  }
} // solutions