//
// Created by Jamie Briggs on 11/12/2024.
//

#ifndef PEBBLES_H
#define PEBBLES_H

#include <list>
#include <string>

namespace solutions {

class PebbleRow {
  std::list<long long> stoneList;
public:
  PebbleRow(std::string rawInput);
  // Return reference to pebbleList.
  std::list<long long> &getStoneList() {
    return stoneList;
  }
  long long getStoneEngravingAtIndex(int index);
  // The three things which can happen to pebbles
  long long performBlinks(int totalBlinks);
  bool upgradeZeroEngraving(std::list<long long>::iterator& idx);
  bool splitStoneIfEven(std::list<long long>::iterator& idx);
  bool multiplyStoneEngravingByYear(std::list<long long>::iterator& idx);

  void printToConsole();

  int getTotalStones();
};

} // solutions

#endif //PEBBLES_H
