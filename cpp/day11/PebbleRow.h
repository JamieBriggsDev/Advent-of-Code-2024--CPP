//
// Created by Jamie Briggs on 11/12/2024.
//

#ifndef PEBBLES_H
#define PEBBLES_H

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace solutions {

class PebbleRow {
  /*
  std::list<long long> pebbleList;
  */
  std::unordered_map<long long, long long> pebbleQuantities;
  void addPebble(long long pebbleTotal);
public:
  PebbleRow(std::string rawInput);
  // Return reference to pebbleList.
  std::unordered_map<long long, long long> &getPebbleQuantities() {
    return pebbleQuantities;
  }
  bool containsPebble(long long pebbleValue);
  // The three things which can happen to pebbles
  bool upgradeZeroEngraving(std::list<long long>::iterator& idx);
  bool splitPebbleIfEven(std::list<long long>::iterator& idx);
  bool multiplyPebbleByYear(std::list<long long>::iterator& idx);

  void printToConsole();
};

} // solutions

#endif //PEBBLES_H
