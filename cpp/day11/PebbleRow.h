//
// Created by Jamie Briggs on 11/12/2024.
//

#ifndef PEBBLES_H
#define PEBBLES_H

#include <list>
#include <unordered_map>

namespace solutions {

class PebbleRow {
  std::list<long long> stoneList;
  long long performBlinks(int totalBlinks, std::list<long long> stoneCopyList);
  long long performBlinks(int totalBlinks, std::unordered_map<long long, long long> stoneCopyList);

  void static addToStoneMap(long long engraving, long long total, std::unordered_map<long long, long long>& stoneMap);
  void static removeTotalFromStoneMap(long long engraving, long long total, std::unordered_map<long long, long long>& stoneMap);
public:
  PebbleRow(std::string rawInput);
  // Return reference to pebbleList.
  std::list<long long> &getStoneList() {
    return stoneList;
  }
  long long getStoneEngravingAtIndex(int index);
  // The three things which can happen to pebbles
  long long performBlinks(int totalBlinks, bool optimized = false);

  bool upgradeZeroEngraving(std::list<long long>::iterator& idx);
  bool splitStoneIfEven(std::list<long long>::iterator& idx, std::list<long long>& owningList);
  bool multiplyStoneEngravingByYear(std::list<long long>::iterator& idx);
  bool upgradeZeroEngraving(std::unordered_map<long long, long long>::iterator& idx, std::unordered_map<long long, long long>& stoneMap);
  bool splitStoneIfEven(std::unordered_map<long long, long long>::iterator& idx, std::unordered_map<long long, long long>& stoneMap);
  bool multiplyStoneEngravingByYear(std::unordered_map<long long, long long>::iterator& idx, std::unordered_map<long long, long long>& stoneMap);

  void printToConsole();

  int getTotalStones();
};

} // solutions

#endif //PEBBLES_H
