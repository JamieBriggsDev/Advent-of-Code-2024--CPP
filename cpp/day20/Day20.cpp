//
// Created by Jamie Briggs on 16/12/2024.
//

#include "Day20.h"

#include "../algorithms/pathfinding/AStarPathFinder.h"
#include "RaceTrack.h"

#include <iostream>

#include "RaceTrackCheatFinder.h"

namespace solutions {
  std::string Day20::solvePartOne(const helper::SolutionInput *input) {
    RaceTrack track(input->getTestInput());

    auto cheats = RaceTrackCheatFinder::findCheats(track);

    unordered_map<int, int> cheatMap;
    vector<RaceTrackCheat> cheatList;

    for (auto cheat : cheats) {

      // Stupid cheat!!
      if (cheat.savedTime == 0) { continue; }


      if (cheat.savedTime >= 100) {
        cheatList.emplace_back(cheat);
      }

      if (!cheatMap.contains(cheat.savedTime)) {
        cheatMap[cheat.savedTime] = 0;
      }
      cheatMap[cheat.savedTime]++;
    }

    cout << endl;
    // Print all the saved times!
    for (auto cheat : cheatMap) {
      cout << "There are " << cheat.second << " cheats that save " << cheat.first << " picoseconds." << endl;
    }

    // 1501 too low
    // 1503 too low
    return to_string(cheatList.size());
  }
  std::string Day20::solvePartTwo(const helper::SolutionInput *input) {
    return "Solve me!";
  }
} // namespace solutions
