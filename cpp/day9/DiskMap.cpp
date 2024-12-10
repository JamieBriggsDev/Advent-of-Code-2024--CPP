//
// Created by Jamie Briggs on 09/12/2024.
//

#include "DiskMap.h"
solutions::DiskMap::DiskMap(std::string input) {
  bool isFileFlag = true;
  int currIdx = 0;
  int currFile = 0;
  for (const char number: input) {
    int size = number - '0';
    // Add number to unfilteredContents
    unfilteredContents.push_back(size);

    // Start adding files
    if (isFileFlag) {
      fileIdCurrentlyChecking = currFile;
      File *file = new File(currFile++, size);
      for (int x = currIdx; x < currIdx + size; x++) {
        // Reference file in location
        this->fileLocations.emplace_back(file);
        this->mostRightFileIndex = x;
      }
    } else {
      for (int x = currIdx; x < currIdx + size; x++) {
        if (this->mostLeftEmptyIndex == -1) {
          this->mostLeftEmptyIndex = x;
        }
        this->fileLocations.emplace_back(nullptr);
      }
    }
    // Toggle file flag
    isFileFlag = !isFileFlag;

    // Update current IDX
    currIdx += size;
  }
}
void solutions::DiskMap::performDefragStep() {
  // Get file to move
  File *file = this->fileLocations[this->mostRightFileIndex];
  // Move to missing address
  this->fileLocations[this->mostLeftEmptyIndex] = file;
  // Remove original referrence
  this->fileLocations[this->mostRightFileIndex] = nullptr;

  // Clean up
  // Find target next missing node
  bool foundNextMissing = false;
  while (!foundNextMissing && this->mostLeftEmptyIndex <= this->fileLocations.size()) {
    this->mostLeftEmptyIndex++;
    if (this->fileLocations[this->mostLeftEmptyIndex] == nullptr) {
      foundNextMissing = true;
    }
  }
  // Find next target file address to move
  bool foundNextFileLocation = false;
  while (!foundNextFileLocation && this->mostRightFileIndex >= this->mostLeftEmptyIndex) {
    this->mostRightFileIndex--;
    if (this->fileLocations[this->mostRightFileIndex] != nullptr) {
      foundNextFileLocation = true;
    }
  }
}
void solutions::DiskMap::performDefragFullFileStep() {
  // Get file to move
  // Find idx of last id
  File *file = nullptr;
  int startOfFileToMoveIdx = INT_MAX;
  for (int idx = 0; idx < this->fileLocations.size(); idx++) {
    file = this->fileLocations[idx];
    if (file != nullptr && file->id == fileIdCurrentlyChecking) {
      startOfFileToMoveIdx = idx;
      break;
    }
  }


  if (startOfFileToMoveIdx != INT_MAX) {
    // Get file size
    int fileSize = file->fileSize;

    // Find first empty spot which fits
    bool foundSpot = false;
    int startOfFoundEmptySpot = -1;
    int totalCountOfInstance = 0;
    // Less than file locations size, hasn't found spot, and lower than file to move IDX
    for (int idx = 0; idx < this->fileLocations.size() && !foundSpot && idx < startOfFileToMoveIdx; idx++) {
      if (this->fileLocations[idx] == nullptr) {
        totalCountOfInstance++;
        if (totalCountOfInstance >= fileSize) {
          foundSpot = true;
          startOfFoundEmptySpot = idx - (fileSize - 1);
        }
      } else {
        totalCountOfInstance = 0;
      }
    }

    if (foundSpot) {
      for (int i = 0; i < file->fileSize; i++) {
        // Move to missing address
        this->fileLocations[startOfFoundEmptySpot + i] = file;
        // Remove original reference
        this->fileLocations[startOfFileToMoveIdx + i] = nullptr;
      }
    }
  }
  // Reduce by 1
  fileIdCurrentlyChecking -= 1;
}
