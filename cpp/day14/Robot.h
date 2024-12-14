//
// Created by perso on 14/12/2024.
//

#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include "../core/Pair.h"

#include "../core/Orientation.h"

namespace solutions {

class Robot {
  core::Pair initialPosition;
  core::Pair position;
  core::Pair velocity;
public:
  Robot(std::string input);
  core::Pair getInitialPosition() {
    return initialPosition;
  }
  core::Pair getVelocity() {
    return velocity;
  }
  core::Pair getCurrentPosition() {
    return position;
  }
  void move();
  bool teleportIfOutOfRange(int maxXRange, int maxYRange);

  core::Orientation whichQuadrant(int maxXRange, int maxYRange);
};

} // solutions

#endif //ROBOT_H
