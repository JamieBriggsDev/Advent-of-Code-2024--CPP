//
// Created by Jamie Briggs on 04/12/2024.
//

#ifndef WORDSEARCHGRID_H
#define WORDSEARCHGRID_H
#include <vector>

#include "WordSearchRow.h"


class WordSearchGrid {
protected:
  char** grid;
  int verticalLength;
  int horizontalLength;
public:
  explicit WordSearchGrid(std::vector<std::string> rawRows);
  [[nodiscard]] char** getGrid() const {
    return grid;
  }
  [[nodiscard]] int getVerticalLength() const {
    return verticalLength;
  }
  [[nodiscard]] int getHorizontalLength() const {
    return horizontalLength;
  }
  [[nodiscard]] int findTotalHorizontalInstances(const std::string& word) const;
  [[nodiscard]] int findTotalVerticalInstances(const std::string& word) const;
  [[nodiscard]] int findTotalDiagonalInstances(const std::string& word) const;
};



#endif //WORDSEARCHGRID_H
