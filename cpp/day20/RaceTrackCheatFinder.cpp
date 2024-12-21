//
// Created by Jamie Briggs on 20/12/2024.
//

#include "RaceTrackCheatFinder.h"

#include <iostream>

#include <ostream>
#include <set>

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "../algorithms/pathfinding/BFSPathFinder.h"

namespace solutions {
  std::vector<RaceTrackCheat> RaceTrackCheatFinder::findCheats(RaceTrack raceTrack) {

    vector<RaceTrackCheat> cheats;

    pathfinding::BFSPathFinder pathFinder;
    // First find without cheats
    auto normalSolution = pathFinder.findPath(raceTrack.getStartTile(), raceTrack.getEndTile(), false);
    // Next get list of source cheat locations
    auto sourceCheatLocations = raceTrack.findAllCheatSourceOptions();


    int totalLocations = sourceCheatLocations.size();
    int itt = 0;
    // Iterate through each source
    for (auto sourceCheatLocation: sourceCheatLocations) {

      cout << "Cheat " << itt++ << " of " << totalLocations << endl;

      auto cheatPosition = sourceCheatLocation.first->getPosition();
      auto cheatDirection = sourceCheatLocation.second;

      /*
       *  If cheat position is 0,0, and direction is east
       *   - Add 1,0 to 0,0 neighbours
       *   - Add 2,0 to 1,0 neighbours
       *
       *  // On end remove neighbours
       *   - Remove 1,0 from 0,0
       *   - Remove 2,0 from 1,0
       */
      auto posOne = cheatPosition + core::Directions::toPair(cheatDirection);
      auto posTwo = cheatPosition + core::Directions::toPair(cheatDirection) + core::Directions::toPair(cheatDirection);

      auto wallTile = raceTrack.getTileInPosition(posOne.x, posOne.y);
      auto finishTile = raceTrack.getTileInPosition(posTwo.x, posTwo.y);

      // Add new neighbours
      sourceCheatLocation.first->addNeighbour(wallTile);
      wallTile->addNeighbour(finishTile);
      // Make wall walkable
      wallTile->setIsWalkable(true);

      // Do path finding and store value
      auto pathResult = pathFinder.findPath(raceTrack.getStartTile(), raceTrack.getEndTile(), false);
      RaceTrackCheat cheat(pathResult.cost, normalSolution.cost - pathResult.cost,
        sourceCheatLocation.first, finishTile, sourceCheatLocation.second,
        pathResult);
      cheats.push_back(cheat);


      // Make wall walkable
      //raceTrack.makeTileWalkable(cheatPosition.x, cheatPosition.y);

      /*// Get possible scenarios
      set<pathfinding::MazeTile *> possibleScenarios;
      // North
      possibleScenarios.insert(raceTrack.getTileInPosition(cheatPosition.x, cheatPosition.y - 1));
      // East
      possibleScenarios.insert(raceTrack.getTileInPosition(cheatPosition.x + 1, cheatPosition.y));
      // South
      possibleScenarios.insert(raceTrack.getTileInPosition(cheatPosition.x, cheatPosition.y + 1));
      // West
      possibleScenarios.insert(raceTrack.getTileInPosition(cheatPosition.x - 1, cheatPosition.y));
      // Check every scenario
      for (auto scenario: possibleScenarios) {
        if (scenario == nullptr || !scenario->getIsWalkable()) {
          continue;
        }

        // Do path finding and store value
        auto pathResult = pathFinder.findPath(raceTrack.getStartTile(), raceTrack.getEndTile(), false);
        RaceTrackCheat cheat(pathResult.cost, normalSolution.cost - pathResult.cost, sourceCheatLocation.first, scenario);
        cheats.push_back(cheat);
      }
      // Make wall not walkable
      raceTrack.makeTileUnwalkable(cheatPosition.x, cheatPosition.y);*/

      // Remove neighbours
      sourceCheatLocation.first->removeNeighbour(wallTile);
      wallTile->removeNeighbour(finishTile);
      // Make wall walkable
      wallTile->setIsWalkable(false);

    }
    return cheats;
  }
} // namespace solutions
