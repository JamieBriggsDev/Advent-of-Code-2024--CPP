//
// Created by Jamie Briggs on 13/12/2024.
//

#ifndef ZONEDCELL_H
#define ZONEDCELL_H
#include "../core/Pair.h"

namespace algorithms {
  struct ZonedCell : core::Pair{
    char zoneLetter;
  public:
    ~ZonedCell() = default;
    ZonedCell(int x, int y, char zoneLetter) : Pair(x,y), zoneLetter(zoneLetter) {}
    [[nodiscard]] char getZoneLabel() const { return this->zoneLetter; }

  };
}

#endif //ZONEDCELL_H
