//
// Created by perso on 18/12/2024.
//

#ifndef MEMORYSPACE_H
#define MEMORYSPACE_H
#include <queue>
#include <regex>
#include <string>
#include <vector>

#include "../core/Grid.h"
#include "Byte.h"
#include "CorruptedByte.h"

#include "FreeByte.h"

using namespace std;

namespace algorithms {

  class MemorySpace : public core::Grid<solutions::Byte *> {
  protected:
    solutions::Byte *convertToObject(char c, int x, int y);
    vector<solutions::FreeByte*> removedFreeBytes;

    void addCorruptedByte(solutions::CorruptedByte* corruptedByte);

  public:
    MemorySpace(vector<string> input, int widthAndHeight);
    ~MemorySpace() override {
      // Delete everything from grid
      for (int y = 0; y < this->getVerticalLength(); ++y) {
        for (int x = 0; x < this->getHorizontalLength(); ++x) {
          delete this->getGrid()[y][x];
        }
      }
      // Delete everything from removedFreeBytes
      for (solutions::FreeByte* freeByte : this->removedFreeBytes) {
        delete freeByte;
      }
    }
    void dropBytes(int totalBytesToDrop);
    vector<solutions::FreeByte*> getRemovedFreeBytes() {
      return removedFreeBytes;
    }
    solutions::FreeByte* getStart() const {
      return dynamic_cast<solutions::FreeByte*>(this->getGrid()[0][0]);
    }
    solutions::FreeByte* getFinish() const {
      return dynamic_cast<solutions::FreeByte*>(this->getGrid()[verticalLength-1][horizontalLength-1]);
    }
  };

} // namespace algorithms

#endif // MEMORYSPACE_H
