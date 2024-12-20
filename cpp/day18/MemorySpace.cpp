//
// Created by Jamie Briggs on 18/12/2024.
//

#include "MemorySpace.h"

namespace algorithms {
  solutions::Byte *MemorySpace::convertToObject(char c, int x, int y) { return nullptr; }
  void MemorySpace::addCorruptedByte(solutions::CorruptedByte *corruptedByte) {
    // Don't actually delete the free space, record it elsewhere but remove from
    //  grid
    int y = corruptedByte->y;
    int x = corruptedByte->x;
    solutions::FreeByte* freeByte =
      dynamic_cast<solutions::FreeByte*>(grid[y][x]);
    removedFreeBytes.emplace_back(freeByte);
    // Set grid location to corrupted byte
    grid[y][x] = corruptedByte;
    // Remove neighbours
    // North
    if (y > 0) {
      auto north = dynamic_cast<solutions::FreeByte *>(grid[y - 1][x]);
      if (north != nullptr) {
        north->removeNeighbour(freeByte);
      }
    }
    // East
    if (x < horizontalLength - 1) {
      auto east = dynamic_cast<solutions::FreeByte *>(grid[y][x + 1]);
      if (east != nullptr) {
        east->removeNeighbour(freeByte);
      }
    }
    // South
    if (y < verticalLength - 1) {
      auto south = dynamic_cast<solutions::FreeByte *>(grid[y + 1][x]);
      if (south != nullptr) {
        south->removeNeighbour(freeByte);
      }
    }
    // West
    if (x > 0) {
      auto west = dynamic_cast<solutions::FreeByte *>(grid[y][x - 1]);
      if (west != nullptr) {
        west->removeNeighbour(freeByte);
      }
    }
  }
  MemorySpace::MemorySpace(vector<string> input, int widthAndHeight) {
    // Allocate grid using widthAndHeight
    this->horizontalLength = widthAndHeight;
    this->verticalLength = widthAndHeight;
    grid = new solutions::Byte **[verticalLength];
    for (int y = 0; y < verticalLength; ++y) {
      grid[y] = new solutions::Byte *[horizontalLength];

      for (int x = 0; x < horizontalLength; ++x) {
        this->getGrid()[y][x] = new solutions::FreeByte(x, y);
      }
    }

    // For each node, add neighbour
    for (int y = 0; y < verticalLength; ++y) {
      for (int x = 0; x < horizontalLength; ++x) {
        solutions::FreeByte* byte = dynamic_cast<solutions::FreeByte*>(grid[y][x]);
        // Add north
        if (y > 0) {
          byte->addNeighbour(grid[y-1][x]);
        }
        // Add east
        if (x < horizontalLength - 1) {
          byte->addNeighbour(grid[y][x+1]);
        }
        // Add south
        if (y < verticalLength - 1) {
          byte->addNeighbour(grid[y+1][x]);
        }
        // Add west
        if (x > 0) {
          byte->addNeighbour(grid[y][x-1]);
        }
      }
    }

    // Store all the corrupted bytes in a queue
    const regex coord("([0-9]+),([0-9]+)");
    for (const auto &corr: input) {
      smatch match;
      regex_search(corr, match, coord);
      int x = stoi(match[1]);
      int y = stoi(match[2]);
      corruptedBytes.push(new solutions::CorruptedByte(x, y));
    }
  }
  solutions::CorruptedByte* MemorySpace::dropBytes(int totalBytesToDrop) {
    solutions::CorruptedByte* droppedByte = nullptr;
    for (int i = 0; i < totalBytesToDrop; i++) {
      droppedByte = corruptedBytes.front();
      addCorruptedByte(droppedByte);
      corruptedBytes.pop();
    }
    return droppedByte;
  }
} // algorithms