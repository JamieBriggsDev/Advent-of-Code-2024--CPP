//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef GRID_H
#define GRID_H


#include <vector>
#include <string>

namespace core {

  template <typename T>
  class Grid {
  protected:
    virtual T convertToObject(char c, int x, int y) = 0;
    T** grid;
    int verticalLength;
    int horizontalLength;
  public:
    void init (std::vector<std::string> rawRows) {
      // First initialize **grid
      // Get vertical length
      this->verticalLength = rawRows.size();
      // Get horizontal length
      this->horizontalLength = rawRows[0].size();
      // Initialize grid
      grid = new T *[this->verticalLength];
      for (int y = 0; y < this->verticalLength; ++y) {
        grid[y] = new T[this->horizontalLength];
        for (int x = 0; x < this->horizontalLength; ++x) {
          grid[y][x] = convertToObject(rawRows[y][x], x, y);
        }
      }

    }
    [[nodiscard]] T** getGrid() const {
      return grid;
    }
    [[nodiscard]] int getVerticalLength() const {
      return verticalLength;
    }
    [[nodiscard]] int getHorizontalLength() const {
      return horizontalLength;
    }
  };

} // namespace core


#endif // GRID_H
