//
// Created by Jamie Briggs on 04/12/2024.
//

#include "MasSearchGrid.h"

#include <unordered_map>


int MasSearchGrid::findTotalOccurrencesOfXMas() {
  const std::string word = "MAS";
  std::unordered_map<core::Pair, int> occurrences;

  for (int y = 0; y < this->verticalLength; ++y) {
    for (int x = 0; x < this->horizontalLength; ++x) {
      // Find character in position
      char sPos = this->grid[y][x];
      if (sPos == word[0]) {
        // This character could be the start of this word!
        // Search NW -> SE
        for (int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if (y + wordIndex >= this->verticalLength || x + wordIndex >= this->horizontalLength) {
            break;
          }
          char nextChar = this->grid[y + wordIndex][x + wordIndex];
          if (nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if (wordIndex == word.size() - 1) {
            // Add 'A' location to occurrences if found
            int aXPos = x + 1;
            int aYPos = y + 1;
            if (occurrences.find(core::Pair(aYPos, aXPos)) != occurrences.end()) {
              occurrences[core::Pair(aYPos, aXPos)] += 1;
            } else {
              occurrences[core::Pair(aYPos, aXPos)] = 1;
            }
          }
        }

        // Search SE -> NW
        for (int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if (y - wordIndex < 0 || x - wordIndex < 0) {
            break;
          }
          char nextChar = this->grid[y - wordIndex][x - wordIndex];
          if (nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if (wordIndex == word.size() - 1) {
            // Add 'A' location to occurrences if found
            int aXPos = x - 1;
            int aYPos = y - 1;
            if (occurrences.find(core::Pair(aYPos, aXPos)) != occurrences.end()) {
              occurrences[core::Pair(aYPos, aXPos)] += 1;
            } else {
              occurrences[core::Pair(aYPos, aXPos)] = 1;
            }
          }
        }

        // Search NE -> SW
        for (int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if (y + wordIndex >= this->verticalLength || x - wordIndex < 0) {
            break;
          }
          char nextChar = this->grid[y + wordIndex][x - wordIndex];
          if (nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if (wordIndex == word.size() - 1) {
            // Add 'A' location to occurrences if found
            int aXPos = x - 1;
            int aYPos = y + 1;
            if (occurrences.find(core::Pair(aYPos, aXPos)) != occurrences.end()) {
              occurrences[core::Pair(aYPos, aXPos)] += 1;
            } else {
              occurrences[core::Pair(aYPos, aXPos)] = 1;
            }
          }
        }

        // Search SW -> NE
        for (int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if (y - wordIndex < 0 || x + wordIndex >= this->horizontalLength) {
            break;
          }
          char nextChar = this->grid[y - wordIndex][x + wordIndex];
          if (nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if (wordIndex == word.size() - 1) {
            // Add 'A' location to occurrences if found
            int aXPos = x + 1;
            int aYPos = y - 1;
            if (occurrences.find(core::Pair(aYPos, aXPos)) != occurrences.end()) {
              occurrences[core::Pair(aYPos, aXPos)] += 1;
            } else {
              occurrences[core::Pair(aYPos, aXPos)] = 1;
            }
          }
        }
      }
    }
  }


  int count = 0;
  // Iterate over the occurrences map and count entries with values greater than 1
  for (const auto &entry: occurrences) {
    if (entry.second > 1) {
      ++count;
    }
  }
  return count;
}
