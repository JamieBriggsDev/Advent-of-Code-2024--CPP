//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef ORIENTATION_H
#define ORIENTATION_H
#include "AocException.h"
#include "Pair.h"

namespace core {
  enum Orientation {
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    NOWHERE
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
          case NORTH_EAST:
            return {1, -1};
          case SOUTH_EAST:
            return {1, 1};
          case SOUTH_WEST:
            return {-1, 1};
          case NORTH_WEST:
            return {-1, -1};
          default:
            return {0,0};
        }
      }
      static Orientation fromPair(const Pair &pair) {
        if (pair == Pair(0, -1)) {
          return NORTH;
        }
        if (pair == Pair(1, 0)) {
          return EAST;
        }
        if (pair == Pair(0, 1)) {
          return SOUTH;
        }
        if (pair == Pair(-1, 0)) {
          return WEST;
        }


        if (pair == Pair(1, -1)) {
          return NORTH_EAST;
        }
        if (pair == Pair(-1, -1)) {
          return NORTH_WEST;
        }
        if (pair == Pair(1, 1)) {
          return SOUTH_EAST;
        }
        if (pair == Pair(-1, 1)) {
          return SOUTH_WEST;
        }
        throw AocException("Invalid pair for orientation");
      }
  };
}

#endif //ORIENTATION_H
