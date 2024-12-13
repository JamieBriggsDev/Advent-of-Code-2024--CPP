//
// Created by Jamie Briggs on 12/12/2024.
//

#ifndef PLANT_H
#define PLANT_H


#include <unordered_map>

#include "../core/AocException.h"
#include "../core/Orientation.h"
#include "../core/Pair.h"

namespace solutions {

  struct Plant : public core::Pair {
    char plantLabel;
    std::unordered_map<core::Orientation, char> neighbourPlants;
  public:
    ~Plant() = default;
    Plant(int x, int y, char plant_label) : Pair(x, y), plantLabel(plant_label) {}
    Plant() : Pair(-1, -1), plantLabel('.') {}
    void addNeighbouringPlant(const core::Orientation &orientation, Plant other);
    [[nodiscard]] char getPlantLabel() const { return this->plantLabel; }
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
