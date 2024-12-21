//
// Created by Jamie Briggs on 20/12/2024.
//

#ifndef RACETRACKCHEATFINDER_H
#define RACETRACKCHEATFINDER_H
#include "../algorithms/pathfinding/MazeTile.h"

#include <vector>

#include "RaceTrack.h"

namespace solutions {

struct RaceTrackCheat {
  int totalCost;
  int savedTime;
  pathfinding::MazeTile * startCheat;
  pathfinding::MazeTile * finishCheat;
  core::Orientation orientation;
  pathfinding::FinalPath finalPath;
};

class RaceTrackCheatFinder {
public:
  static std::vector<RaceTrackCheat> findCheats(RaceTrack raceTrack);
};

} // solutions

#endif //RACETRACKCHEATFINDER_H
