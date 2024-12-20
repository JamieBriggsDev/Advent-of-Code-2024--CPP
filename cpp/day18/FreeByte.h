//
// Created by Jamie Briggs on 18/12/2024.
//

#ifndef FREESPACE_H
#define FREESPACE_H
#include "Byte.h"

namespace solutions {

  class FreeByte : public Byte {
  public:
    FreeByte(int x, int y) : Byte(x, y, true) {}
  };

}

#endif //FREESPACE_H
