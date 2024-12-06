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
    T createObjectFromChar(char c) const;
    T** grid;
    int verticalLength;
    int horizontalLength;
  public:
    explicit Grid(std::vector<std::string> rawRows) {
      // First initialize **grid
      // Get vertical length
      this->verticalLength = rawRows.size();
      // Get horizontal length
      this->horizontalLength = rawRows[0].size();
      // Initialize grid
      grid = new char *[this->verticalLength];
      for (int i = 0; i < this->verticalLength; ++i) {
        grid[i] = new char[this->horizontalLength];
        for (int j = 0; j < this->horizontalLength; ++j) {
          grid[i][j] = rawRows[i][j];
        }
      }

      for (int y = 0; y < this->verticalLength; ++y) {
        const std::string &row = rawRows[y];
        for (int x = 0; x < this->horizontalLength; ++x) {
          const char character = row[x];
          grid[y][x] = character;
        }
      }
    }
    virtual  T convertToObject(char c) const = 0;
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
