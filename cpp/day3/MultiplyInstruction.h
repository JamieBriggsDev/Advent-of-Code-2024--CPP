//
// Created by Jamie Briggs on 03/12/2024.
//

#ifndef MULTIPLYINSTRUCTION_H
#define MULTIPLYINSTRUCTION_H
#include "Instruction.h"


class MultiplyInstruction : public Instruction {
  const int x;
  const int y;
public:
  MultiplyInstruction(int x, int y) : x(x), y(y) {}
  [[nodiscard]] long result() const{
    return x * y;
  }
  [[nodiscard]] int getX() const {
    return x;
  }
  [[nodiscard]] int getY() const {
    return y;
  }

  bool operator==(const MultiplyInstruction &other) const {
    return (x == other.x && y == other.y);
  }
  bool operator==(const MultiplyInstruction * other) const {
    return (x == other->x && y == other->y);
  }
};



#endif //MULTIPLYINSTRUCTION_H
