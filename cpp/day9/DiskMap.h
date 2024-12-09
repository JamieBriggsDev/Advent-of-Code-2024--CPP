//
// Created by perso on 09/12/2024.
//

#ifndef DISKMAP_H
#define DISKMAP_H

#include <string>
#include <vector>

#include "File.h"

namespace solutions {
  class DiskMap {
    std::vector<int> unfilteredContents;
    std::vector<File*> fileLocations;
    int mostLeftEmptyIndex = -1;
    int mostRightFileIndex = -1;
  public:
    DiskMap(std::string input);
    void performDefragStep();
    [[nodiscard]] std::vector<int> getContents() {
      return unfilteredContents;
    }
    [[nodiscard]] std::vector<File*> getFileLocations() {
      return fileLocations;
    }
    [[nodiscard]] int getLeftMostEmptyIndex() const {
      return mostLeftEmptyIndex;
    }
    [[nodiscard]] int getRightMostFileIndex() const {
      return mostRightFileIndex;
    }
    [[nodiscard]] bool hasCompletedDefrag() const {
      return mostLeftEmptyIndex > mostRightFileIndex;
    }
  };
}


#endif //DISKMAP_H
