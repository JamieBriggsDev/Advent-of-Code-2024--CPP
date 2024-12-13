//
// Created by Jamie Briggs on 13/12/2024.
//

#include "ZoneFinderFloodFill.h"

#include <queue>

namespace algorithms {
  Zone ZoneFinderFloodFill::floodFill(const solutions::FarmGrid& grid, std::vector<std::vector<bool>>& visited, int x, int y,
                                                char label) {
    Zone toReturn(label);
    // Directions
    std::vector directions = {core::Directions::toPair(core::NORTH), core::Directions::toPair(core::EAST),
                              core::Directions::toPair(core::SOUTH), core::Directions::toPair(core::WEST)};

    std::queue<core::Pair> q;
    q.emplace(x, y);

    core::Pair toAdd = {x, y};
    visited[y][x] = true;
    toReturn.addLocation(toAdd);

    // Perform BFS
    while (!q.empty()) {
      // Get front
      auto [cx, cy] = q.front();
      // Remove front
      q.pop();

      // If not the correct character, continue
      if(grid.getGrid()[cy][cx].getZoneLabel() != label) {
        continue;
      }

      for (const auto &dir: directions) {
        int nx = cx + dir.x;
        int ny = cy + dir.y;


        // Check neighbor is valid and has not been visited. Also check
        //  if has the same value as the starting cell.
        if(nx >= 0 && nx < grid.getHorizontalLength()
          && ny >= 0 && ny < grid.getVerticalLength()
          && !visited[ny][nx]
          && grid.getGrid()[ny][nx].getZoneLabel() == label) {
          visited[ny][nx] = true;

          if(!toReturn.contains(core::Pair(nx, ny))) {
            toReturn.addLocation(core::Pair(nx, ny));
          }

          q.emplace(nx, ny);
        }
      }
    }

    return toReturn;
  }
  std::vector<Zone> ZoneFinderFloodFill::findAllZones(solutions::FarmGrid grid) {
    std::vector<Zone> zones;
    int cols = grid.getHorizontalLength();
    int rows = grid.getVerticalLength();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    for(int x = 0; x < cols; ++x) {
      for(int y = 0; y < rows; ++y) {
        // If cell is unvisted, start a new flood
        if(!visited[y][x]) {
          // Get type to start flood with
          char zoneLabel = grid.getGrid()[y][x].getZoneLabel();
          // Perform flood fill
          zones.emplace_back(floodFill(grid, visited, x, y, zoneLabel));
        }
      }
    }
    return zones;
  }
  int ZoneFinderFloodFill::countZones(solutions::FarmGrid grid) {
    return findAllZones(grid).size();
  }
} // namespace algorithms
