//
// Created by perso on 15/12/2024.
//

#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "../core/Grid.h"
#include "../core/Orientation.h"
#include "../day15/Robot.h"
#include "Box.h"
#include "Entity.h"


namespace solutions {

  class Warehouse : public core::Grid<warehouse::Entity *> {
  protected:
    warehouse::Entity *convertToObject(char c, int x, int y) override;
    warehouse::Robot * robot;
    std::vector<warehouse::Box*> boxes;
    bool isDebug;
  public:
    Warehouse(std::vector<std::string> input, bool isDebug = false) {
      this->init(input);
      this->isDebug = isDebug;
    }
    warehouse::Robot *getRobot() { return robot; }
    void moveRobot(core::Orientation orientation);
    void printWarehouseLayout() const;
    [[nodiscard]] std::vector<warehouse::Box*> getBoxes() {
      return boxes;
    }
  };


} // namespace solutions

#endif // WAREHOUSE_H
