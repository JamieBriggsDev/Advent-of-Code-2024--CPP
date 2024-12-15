//
// Created by perso on 15/12/2024.
//

#ifndef WALL_H
#define WALL_H
#include "Entity.h"

namespace warehouse {

class Wall final : public Entity{
public:
  Wall(int x, int y) : Entity(x, y) {}
  char getSymbol() {
    return '#';
  };
  bool isWall() override {
    return true;
  }
};

} // warehouse

#endif //WALL_H
