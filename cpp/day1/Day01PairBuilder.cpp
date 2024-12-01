//
// Created by Jamie Briggs on 01/12/2024.
//

#include "Day01PairBuilder.h"

using namespace std;

void solutions::Day01PairBuilder::addToListOne(int number) {
  this->listOne.push_back(number);
}

void solutions::Day01PairBuilder::addToListTwo(int number) { this->listTwo.push_back(number); }
std::queue<core::Pair> solutions::Day01PairBuilder::getPairs()  {
  sort(listOne.begin(), listOne.end(), less());
  sort(listTwo.begin(), listTwo.end(), less());
  if(listOne.size() != listTwo.size()) {
    throw std::runtime_error("Lists are wrong size");
  }

  std::queue<core::Pair> pairs;
  for(int i = 0; i < listOne.size(); i++) {
    core::Pair pair(listOne[i], listTwo[i]);
    pairs.emplace(pair);
  }

  return pairs;
}
