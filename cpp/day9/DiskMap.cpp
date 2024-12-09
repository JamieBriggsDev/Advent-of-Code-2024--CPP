//
// Created by perso on 09/12/2024.
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
  File* file = this->fileLocations[this->mostRightFileIndex];
  // Move to missing address
  this->fileLocations[this->mostLeftEmptyIndex] = file;
  // Remove original referrence
  this->fileLocations[this->mostRightFileIndex] = nullptr;

  // Clean up
  // Find target next missing node
  bool foundNextMissing = false;
  while(!foundNextMissing && this->mostLeftEmptyIndex <= this->fileLocations.size()) {
    this->mostLeftEmptyIndex++;
    if(this->fileLocations[this->mostLeftEmptyIndex] == nullptr) {
      foundNextMissing = true;
    }
  }
  // Find next target file address to move
  bool foundNextFileLocation = false;
  while(!foundNextFileLocation && this->mostRightFileIndex >= this->mostLeftEmptyIndex) {
    this->mostRightFileIndex--;
    if(this->fileLocations[this->mostRightFileIndex] != nullptr) {
      foundNextFileLocation = true;
    }
  }
}
