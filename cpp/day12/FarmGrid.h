//
// Created by Jamie Briggs on 12/12/2024.
//

#ifndef FARMGRID_H
#define FARMGRID_H
#include "../core/Grid.h"
#include "Plant.h"
#include <vector>
#include <string>

namespace solutions {

class FarmGrid : public core::Grid<Plant>{
protected:
  Plant convertToObject(char c, int x, int y) override;
public:
  explicit FarmGrid(std::vector<std::string> rawRows) {
    this->init(std::move(rawRows));
  }
};

} // solutions

#endif //FARMGRID_H
