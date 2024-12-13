//
// Created by Jamie Briggs on 13/12/2024.
//

#ifndef ZONEFINDERFLOODFILL_H
#define ZONEFINDERFLOODFILL_H

#include <set>
#include <vector>

#include "../day12/FarmGrid.h"
#include "../algorithms/Zone.h"

namespace algorithms {

  class ZoneFinderFloodFill {
    static Zone floodFill(const solutions::FarmGrid &grid, std::vector<std::vector<bool>>& visited, int x, int y, char label);

  public:
    // TODO: After solution or if needed again, change FarmGrid param to abstract
    //    class.
    std::vector<Zone> static findAllZones(solutions::FarmGrid grid);
    int static countZones(solutions::FarmGrid grid);
  };

} // namespace algorithms

#endif // ZONEFINDERFLOODFILL_H
