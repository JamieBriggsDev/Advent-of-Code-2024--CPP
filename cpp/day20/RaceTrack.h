//
// Created by Jamie Briggs on 20/12/2024.
//

#ifndef RACETRACK_H
#define RACETRACK_H
#include "../algorithms/pathfinding/Maze.h"

namespace solutions {

class RaceTrack final : public pathfinding::Maze {
  public:
    explicit RaceTrack(const vector<string> &input) : Maze(input) {}
  };

} // solutions

#endif //RACETRACK_H
