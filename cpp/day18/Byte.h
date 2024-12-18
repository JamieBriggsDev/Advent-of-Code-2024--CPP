//
// Created by perso on 18/12/2024.
//

#ifndef BYTE_H
#define BYTE_H

#include "../algorithms/pathfinding/Node.h"

namespace solutions {

  class Byte : public core::Node {
  public:
    virtual ~Byte() = default;
    Byte(int x, int y) : Node(1, x, y) {}
  };

}


#endif //BYTE_H
