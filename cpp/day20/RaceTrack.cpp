//
// Created by Jamie Briggs on 20/12/2024.
//

#include "RaceTrack.h"

#include <iostream>

namespace solutions {

  /**
   *
   * @return a list of walls which could complete a path from A to B
   */
  vector<std::pair<pathfinding::MazeTile *, core::Orientation>> RaceTrack::findAllCheatSourceOptions() {
    vector<std::pair<pathfinding::MazeTile *, core::Orientation>> validCheatPoints;

    // Loop through all walls
    for (int y = 0; y < this->getVerticalLength(); y++) {
      for (int x = 0; x < this->getHorizontalLength(); x++) {
        // If wall
        /*if (this->walls[y][x]) {
          // Check if there is a walkable tile north east south or west,
          //  then it's valid for source of cheat!
          auto north = getTileInPosition(x, y-1);
          auto east = getTileInPosition(x + 1, y);
          auto south = getTileInPosition(x, y + 1);
          auto west = getTileInPosition(y, x - 1);

          // Check if tile north of wall is walkable
          if (north != nullptr && north->getIsWalkable()) {
            validWalls.push_back(getTileInPosition(x, y));
          }
          // Check if tile east of wall is walkable
          else if (east != nullptr && east->getIsWalkable()) {
            validWalls.push_back(getTileInPosition(x, y));
          }
          // Check if tile south of wall is walkable
          else if (south != nullptr && south->getIsWalkable()) {
            validWalls.push_back(getTileInPosition(x, y));
          }
          // Check if tile west of wall is walkable
          else if (west != nullptr && west->getIsWalkable()) {
            validWalls.push_back(getTileInPosition(x, y));
          }
        }*/

        auto tileChecking = getTileInPosition(x, y);

        // If not a wall
        if (this->walls[y][x] == false) {
          // Check North
          // Check Up two tiles
          auto northOne = getTileInPosition(x, y - 1);
          auto northTwo = getTileInPosition(x, y - 2);
          if (northOne != nullptr && !northOne->getIsWalkable() && northTwo != nullptr && northTwo->getIsWalkable()) {
            // Add tileChecking and EAST to validCheatPoints
            validCheatPoints.push_back(std::make_pair(tileChecking, core::Orientation::NORTH));
          }

          // Check East
          // Check right two tiles
          auto eastOne = getTileInPosition(x + 1, y);
          auto eastTwo = getTileInPosition(x + 2, y);
          if (eastOne != nullptr && !eastOne->getIsWalkable() && eastTwo != nullptr && eastTwo->getIsWalkable()) {
            // Add tileChecking and EAST to validCheatPoints
            validCheatPoints.push_back(std::make_pair(tileChecking, core::Orientation::EAST));
          }

          // Check South
          // Check down two tiles
          auto southOne = getTileInPosition(x, y + 1);
          auto southTwo = getTileInPosition(x, y + 2);
          if (southOne != nullptr && !southOne->getIsWalkable() && southTwo != nullptr && southTwo->getIsWalkable()) {
            // Add tileChecking and EAST to validCheatPoints
            validCheatPoints.push_back(std::make_pair(tileChecking, core::Orientation::SOUTH));
          }

          // Check West
          // Check left two tiles
          auto westOne = getTileInPosition(x - 1, y);
          auto westTwo = getTileInPosition(x - 2, y);
          if (westOne != nullptr && !westOne->getIsWalkable() && westTwo != nullptr && westTwo->getIsWalkable()) {
            // Add tileChecking and EAST to validCheatPoints
            validCheatPoints.push_back(std::make_pair(tileChecking, core::Orientation::WEST));
          }
        }
      }
    }


    // Print all coordinates in validWalls
    /*for (const auto &wall: validWalls) {
      auto position = wall->getPosition();
      std::cout << "Valid Wall at: " << position.toString() << std::endl;
    }*/
    
    return validCheatPoints;
  }
} // solutions