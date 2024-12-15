//
// Created by perso on 15/12/2024.
//

#ifndef WAREHOUSEENTITY_H
#define WAREHOUSEENTITY_H

#include "../core/Pair.h"

namespace warehouse {
  class Entity : public core::Pair{
  public:
    Entity(int x, int y) : core::Pair(x, y) {};
    virtual ~Entity() = 0; // Pure virtual destructor to make the class abstract
    void move(core::Pair pair) {
      this->x += pair.x;
      this->y += pair.y;
    }
    // Really, this is a bit of a bad practice, but it's more efficient than doing a cast
    //   each time to see if it's a wall object. If I were to do this solution again, I
    //   also probably wouldn't use multiple classes, the reason I did this initially was
    //   because I was expecting the object types needing a lot more logic then they actually
    //   do need...
    virtual bool isWall() = 0;
    virtual char getSymbol() = 0;
  };

  inline Entity::~Entity(){}
}

#endif // WAREHOUSEENTITY_H
