//
// Created by Jamie Briggs on 05/12/2023.
//

#include "SolutionInput.h"

using namespace helper;

vector<string> SolutionInput::getTestInput() const { return this->testInput; }
vector<vector<string>> SolutionInput::getSplitTestInput(std::string rowToSplitBy) const {

  vector<vector<string>> splitInput;
  vector<string> currentChunk;

  for (const auto &row: this->testInput) {
    if (row == rowToSplitBy) {
      if (!currentChunk.empty()) {
        splitInput.push_back(currentChunk);
        currentChunk.clear();
      }
    } else {
      currentChunk.push_back(row);
    }
  }

  if (!currentChunk.empty()) {
    splitInput.push_back(currentChunk);
  }

  return splitInput;
}

