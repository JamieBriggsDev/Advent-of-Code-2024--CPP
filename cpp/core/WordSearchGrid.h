//
// Created by Jamie Briggs on 04/12/2024.
//

#ifndef WORDSEARCHGRID_H
#define WORDSEARCHGRID_H
#include <utility>
#include <vector>

#include "Grid.h"
#include "WordSearchRow.h"

namespace core {

class WordSearchGrid : public Grid<char> {
protected:
  [[nodiscard]] char convertToObject(const char c, const int x, const int y) override {
    return c;
  }
public:
  explicit WordSearchGrid(std::vector<std::string> rawRows) {
    this->init(std::move(rawRows));
  };
  [[nodiscard]] int findTotalHorizontalInstances(const std::string& word) const;
  [[nodiscard]] int findTotalVerticalInstances(const std::string& word) const;
  [[nodiscard]] int findTotalDiagonalInstances(const std::string& word) const;
};

}


#endif //WORDSEARCHGRID_H
