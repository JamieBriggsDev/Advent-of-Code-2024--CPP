//
// Created by Jamie Briggs on 04/12/2024.
//

#include "../core/WordSearchGrid.h"

using namespace core;

int WordSearchGrid::findTotalHorizontalInstances(const std::string& word) const {

  int count = 0;
  for (int y = 0; y < this->verticalLength; ++y) {


    // This is a more optimized (but horrific way) of horizontal search
    /*int count = 0;
    char* row = grid[0];
    int wordLength = word.size();

    for (int y = 0; y < this->verticalLength; ++y) {
      char *row = grid[y];
      for (int x = 0; x <= this->horizontalLength - wordLength; ++x) {
        bool match = true;
        for (int k = 0; k < wordLength; ++k) {
          if (row[x + k] != word[k]) {
            match = false;
            break;
          }
        }
        if (match) {
          ++count;
        }
      }
    }

    return count;*/

    const auto srow = std::string(grid[y]);
    count += WordSearchRow(srow).findTotalMatches(word);
  }
  return count;
}
int WordSearchGrid::findTotalVerticalInstances(const std::string &word) const {
  int count = 0;

  for (int x = 0; x < this->horizontalLength; ++x) {
    // Create vertical string
    std::string column;
    for (int y = 0; y < this->verticalLength; ++y) {
      column += grid[y][x];
    }
    count += WordSearchRow(column).findTotalMatches(word);
  }

  return count;
}
int WordSearchGrid::findTotalDiagonalInstances(const std::string &word) const {
  int count = 0;
  for(int y = 0; y < this->verticalLength; ++y) {
    for (int x = 0; x < this->horizontalLength; ++x) {
      // Find character in position
      char sPos = this->grid[y][x];
      if(sPos == word[0]) {
        // This character could be the start of this word!
        // Search NW -> SE
        for(int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if(y + wordIndex >= this->verticalLength || x + wordIndex >= this->horizontalLength) {
            break;
          }
          char nextChar = this->grid[y+wordIndex][x+wordIndex];
          if(nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if(wordIndex == word.size()-1) {
            // Word found!
            count++;
          }
        }

        // Search SE -> NW
        for(int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if(y - wordIndex < 0 || x - wordIndex < 0) {
            break;
          }
          char nextChar = this->grid[y-wordIndex][x-wordIndex];
          if(nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if(wordIndex == word.size()-1) {
            // Word found!
            count++;
          }
        }

        // Search NE -> SW
        for(int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if(y + wordIndex >= this->verticalLength || x - wordIndex < 0) {
            break;
          }
          char nextChar = this->grid[y+wordIndex][x-wordIndex];
          if(nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if(wordIndex == word.size()-1) {
            // Word found!
            count++;
          }
        }

        // Search SW -> NE
        for(int wordIndex = 1; wordIndex < word.size(); ++wordIndex) {
          if(y - wordIndex < 0 || x + wordIndex >= this->horizontalLength) {
            break;
          }
          char nextChar = this->grid[y-wordIndex][x+wordIndex];
          if(nextChar != word[wordIndex]) {
            break; // Break out of for loop
          }
          // Will only reach here if character matches word
          if(wordIndex == word.size()-1) {
            // Word found!
            count++;
          }
        }
      }
    }
  }

  return count;
}
