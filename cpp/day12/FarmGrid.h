//
// Created by Jamie Briggs on 12/12/2024.
//

#ifndef FARMGRID_H
#define FARMGRID_H
#include <string>
#include <vector>
#include "../core/Grid.h"
#include "Plant.h"

namespace solutions {

  class FarmGrid : public core::Grid<Plant> {
  protected:
    Plant convertToObject(char c, int x, int y) override;

  public:
    explicit FarmGrid(std::vector<std::string> rawRows) {
      this->init(std::move(rawRows));
      // Check all plants and add neighbours
      for (int y = 0; y < this->verticalLength; y++) {
        for (int x = 0; x < this->horizontalLength; x++) {
          // Get North
          if (y - 1 >= 0) {
            grid[y][x].addNeighbouringPlant(core::NORTH, grid[y - 1][x]);
          }
          // Get East
          if (x + 1 < this->horizontalLength) {
            grid[y][x].addNeighbouringPlant(core::EAST, grid[y][x + 1]);
          }
          // Get South
          if(y + 1 < this->verticalLength) {
            grid[y][x].addNeighbouringPlant(core::SOUTH, grid[y + 1][x]);
          }
          // Get West
          if(x - 1 >= 0) {
            grid[y][x].addNeighbouringPlant(core::WEST, grid[y][x - 1]);
          }
        }
      }
    }
  };

} // namespace solutions

#endif // FARMGRID_H
