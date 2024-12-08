//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef DAY01PAIRBUILDER_H
#define DAY01PAIRBUILDER_H
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#include "../core/Pair.h"

namespace solutions {
class Day01PairBuilder {
  std::vector<int> listOne;
  std::vector<int> listTwo;
public:
  void addToListOne(int number);
  void addToListTwo(int number);
  std::vector<int> getListOne() {
    return listOne;
  }
  std::vector<int> getListTwo() {
    return listTwo;
  }
  std::queue<core::Pair> getPairs();
  std::unordered_map <int, int> getListTwoQuantities();

};
}


#endif //DAY01PAIRBUILDER_H
