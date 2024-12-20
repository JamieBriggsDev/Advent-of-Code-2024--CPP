//
// Created by Jamie Briggs on 09/12/2024.
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
    long fileIdCurrentlyChecking = -1;
  public:
    DiskMap(std::string input);
    void performDefragStep();
    void performDefragFullFileStep();
    [[nodiscard]] bool hasFinishedFullDefrag() {
      return fileIdCurrentlyChecking <= 0;
    }
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
    [[nodiscard]] std::string getCurrentLayout() {
      std::string layout;
      for(int i = 0; i < fileLocations.size(); i++) {
        if(fileLocations[i] != nullptr) {
          layout += std::to_string(fileLocations[i]->id);
        }else {
          layout += ".";
        }
      }
      return layout;
    }
  };
}


#endif //DISKMAP_H
