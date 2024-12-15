//
// Created by perso on 15/12/2024.
//

#ifndef BOX_H
#define BOX_H
#include "Entity.h"

namespace warehouse {

class Box : public Entity{
public:
  Box(int x, int y) : Entity(x, y) {}
  char getSymbol() override {
    return 'O';
  };
  bool isWall() override {
    return false;
  }
};

} // warehouse

#endif //BOX_H
