//
// Created by perso on 18/12/2024.
//

#ifndef BYTE_H
#define BYTE_H

#include "../algorithms/pathfinding/Node.h"

namespace solutions {

  class Byte : public pathfinding::Node {
  public:
    virtual ~Byte() = default;
    Byte(int x, int y, bool isWalkable) : Node(1, x, y, isWalkable) {}
  };

}


#endif //BYTE_H
