//
// Created by Jamie Briggs on 12/12/2024.
//

#ifndef PLANT_H
#define PLANT_H


#include <unordered_map>

#include "../core/AocException.h"
#include "../core/Orientation.h"
#include "../core/Pair.h"
#include "../algorithms/ZonedCell.h"

namespace solutions {

  struct Plant : algorithms::ZonedCell {
    std::unordered_map<core::Orientation, char> neighbourPlants;
    Plant(int x, int y, char plantLabel) : ZonedCell(x, y, plantLabel) {}
    Plant() : ZonedCell(-1, -1, '.') {}
    void addNeighbouringPlant(const core::Orientation &orientation, Plant other);
    [[nodiscard]] bool containsNeighbour(const core::Orientation orientation) const {
      return this->neighbourPlants.contains(orientation);
    };
    [[nodiscard]] char getNeighbourPlantLabel(const core::Orientation orientation) const {
      if(!containsNeighbour(orientation)) {
        throw core::AocException("No neighbour plant");
      }
      return this->neighbourPlants.at(orientation);
    }
  };

} // namespace solutions

#endif // PLANT_H
