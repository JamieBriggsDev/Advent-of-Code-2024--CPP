//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include <queue>

#include "../day18/CorruptedByte.h"
#include "Pair.h"

namespace core {

  template <typename T>
  class Grid {
  protected:
    virtual T convertToObject(char c, int x, int y) = 0;
    T** grid;
    int verticalLength;
    int horizontalLength;
    std::queue<solutions::CorruptedByte*> corruptedBytes;
    [[nodiscard]] bool isPairValid(core::Pair pair) const {
      return pair.x >= 0 && pair.y >= 0 && pair.x < getHorizontalLength() && pair.y < getVerticalLength();
    }
    virtual ~Grid() {
    }
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

    // Override operator() to enable 2D array-like access to the grid property
    T &operator()(int x, int y) {
      return grid[y][x]; // Implement column-row access order
    }

    const T &operator()(int x, int y) const {
      return grid[y][x]; // Implement column-row access order for const objects
    }
  };

} // namespace core


#endif // GRID_H
