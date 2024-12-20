//
// Created by Jamie Briggs on 15/12/2024.
//

#ifndef ROBOT_H
#define ROBOT_H
#include "Entity.h"

namespace warehouse {

class Robot : public Entity{
public:
  Robot(const int x, const int y) : Entity(x, y){};
  Pair getPosition() const { return static_cast<Pair>(*this); }
  char getSymbol() override {
    return '@';
  }
  bool isWall() override {
    return false;
  }
};

} // warehouse

#endif //ROBOT_H
