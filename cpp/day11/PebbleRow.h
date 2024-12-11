//
// Created by Jamie Briggs on 11/12/2024.
//

#ifndef PEBBLES_H
#define PEBBLES_H

#include <list>
#include <string>

namespace solutions {

class PebbleRow {
  std::list<long> pebbleList;
public:
  PebbleRow(std::string rawInput);
  // Return reference to pebbleList.
  std::list<long> &getPebbleList() {
    return pebbleList;
  }
  long getPebbleAtIndex(int index);
  // The three things which can happen to pebbles
  void upgradeZeroEngraving(std::list<long>::iterator& idx);
  void splitPebbleIfEven(std::list<long>::iterator& idx);
  void multiplyPebbleByYear(std::list<long>::iterator& idx);
};

} // solutions

#endif //PEBBLES_H
