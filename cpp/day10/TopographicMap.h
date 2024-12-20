//
// Created by perso on 10/12/2024.
//

#ifndef TOPOGRAPHICMAP_H
#define TOPOGRAPHICMAP_H

#include <string>
#include <vector>
#include "../core/Grid.h"

#include "../algorithms/pathfinding/Node.h"

namespace core {

  class TopographicMap : public core::Grid<pathfinding::Node *> {
  protected:
    pathfinding::Node *convertToObject(char c, int x, int y) override;
    std::vector<pathfinding::Node *> startingPaths;
  public:
    ~TopographicMap() override {
      for (int y = 0; y < this->getVerticalLength(); ++y) {
        for (int x = 0; x < this->getHorizontalLength(); ++x) {
          delete this->getGrid()[y][x];
        }
      }
    }
    explicit TopographicMap(std::vector<std::string> input);
    std::vector<pathfinding::Node *> getStartingPositions() {
      return startingPaths;
    }
  };

} // namespace day10

#endif // TOPOGRAPHICMAP_H
