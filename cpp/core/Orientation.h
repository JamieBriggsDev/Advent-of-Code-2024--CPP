//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef ORIENTATION_H
#define ORIENTATION_H
#include "Pair.h"

namespace core {
  enum Orientation {
    NORTH,
    EAST,
    SOUTH,
    WEST,
  };

  class Directions {
    public:
      Pair static toPair(Orientation orientation) {
        switch (orientation) {
          case NORTH:
            return {0, -1};
          case EAST:
            return {1, 0};
          case SOUTH:
            return {0, 1};
          case WEST:
            return {-1, 0};
          default:
            return {0,0};
        }
      }
  };
}

#endif //ORIENTATION_H
