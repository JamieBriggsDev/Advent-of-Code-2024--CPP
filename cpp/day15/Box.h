//
// Created by perso on 15/12/2024.
//

#ifndef BOX_H
#define BOX_H
#include "Entity.h"

namespace warehouse {

  class Box : public Entity {
  private:
    core::Orientation orientation;

  public:
    Box(int x, int y) : Entity(x, y) { orientation = core::Orientation::NOWHERE; }
    Box(int x, int y, core::Orientation boxSide) : Entity(x, y) { orientation = boxSide; }
    char getSymbol() override {
      if (orientation == core::Orientation::EAST) {
        return ']';
      }
      if (orientation == core::Orientation::WEST) {
        return '[';
      }
      return 'O';
    };
    core::Orientation getBoxSide() { return orientation; }
    bool isWall() override { return false; }
  };

} // namespace warehouse

#endif // BOX_H
