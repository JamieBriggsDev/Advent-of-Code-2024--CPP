//
// Created by Jamie Briggs on 11/12/2024.
//

#include "PebbleRow.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

namespace solutions {
  PebbleRow::PebbleRow(std::string rawInput) {

    std::istringstream stream(rawInput);
    std::string token;
    while (std::getline(stream, token, ' ')) {
      // Attempt to convert each token to a long and add to pebbleList
      try {
        stoneList.push_back(std::stoll(token));
      } catch (const std::invalid_argument &e) {
        // Ignore invalid tokens that cannot be converted to a number
      }
    }
  }


  long long PebbleRow::getStoneEngravingAtIndex(int index) {
    auto front = this->stoneList.begin();
    std::advance(front, index);
    return *front;
  }


  long long PebbleRow::performBlinks(int totalBlinks, std::list<long long> stoneListCopy) {
    int totalStones = 0;
    for (int i = 0; i < totalBlinks; i++) {
      for (auto it = stoneListCopy.begin(); it != stoneListCopy.end(); ++it) {
        bool flag = false;
        flag = this->upgradeZeroEngraving(it);
        if (!flag) {
          flag = this->splitStoneIfEven(it, stoneListCopy);
        }
        if (!flag) {
          this->multiplyStoneEngravingByYear(it);
        }
      }
    }

    totalStones += stoneListCopy.size();
    return totalStones;
  }


  long long PebbleRow::performBlinks(int totalBlinks, std::unordered_map<long long, long long> stoneCopyMap) {
    // Each iteration, make a copy and ammend the stoneCopyList
    std::unordered_map stoneListCopy(stoneCopyMap.begin(), stoneCopyMap.end());

    for (int i = 0; i < totalBlinks; i++) {
      std::unordered_map<long long, long long> copyOfMap = stoneListCopy;
      for (auto it = copyOfMap.begin(); it != copyOfMap.end(); ++it) {
        if (it->second == 0)
          continue; // Don't do if no stones with specific engraving exist
        bool flag = false;
        flag = this->upgradeZeroEngraving(it, stoneListCopy);
        if (!flag) {
          flag = this->splitStoneIfEven(it, stoneListCopy);
        }
        if (!flag) {
          this->multiplyStoneEngravingByYear(it, stoneListCopy);
        }
      }
    }

    long long total = 0;
    for (auto it = stoneListCopy.begin(); it != stoneListCopy.end(); ++it) {
      if (it->second != 0) {
        //std::cout << "Found " << it->second << " stones with " << it->first << " engraved on them" << std::endl;
        total += it->second;
      }
    }

    return total;
  }


  void PebbleRow::addToStoneMap(long long engraving, long long total,
                                std::unordered_map<long long, long long> &stoneMap) {
    if (stoneMap.contains(engraving)) {
      stoneMap[engraving] += total;
    } else {
      stoneMap[engraving] = total;
    }
  }
  void PebbleRow::removeTotalFromStoneMap(long long engraving, long long total, std::unordered_map<long long, long long> &stoneMap) {
    stoneMap[engraving] -= total;
  }


  long long PebbleRow::performBlinks(int totalBlinks, bool optimized) {
    if (!optimized) {
      auto stoneListCopy = this->getStoneList();
      return performBlinks(totalBlinks, stoneListCopy);
    }

    // Do optimized method
    auto stoneListCopy = this->getStoneList();
    // Create map
    auto stoneMap = std::unordered_map<long long, long long>();
    for (auto stone: this->getStoneList()) {
      addToStoneMap(stone, 1, stoneMap);
    }
    return performBlinks(totalBlinks, stoneMap);
  }

  bool PebbleRow::upgradeZeroEngraving(std::list<long long>::iterator &idx) {
    if (*idx == 0) {
      *idx = 1;
      return true;
    }
    return false;
  }
  bool PebbleRow::upgradeZeroEngraving(std::unordered_map<long long, long long>::iterator &idx,
                                       std::unordered_map<long long, long long> &stoneMap) {
    if (idx->first == 0) {
      // Remove all zeros
      removeTotalFromStoneMap(0, idx->second, stoneMap);
      // Add all ones
      addToStoneMap(1, idx->second, stoneMap);
      return true;
    }
    return false;
  }


  bool PebbleRow::splitStoneIfEven(std::list<long long>::iterator &idx, std::list<long long> &owningList) {
    long long currentValue = *idx;
    std::string currentValueStr = std::to_string(currentValue);
    if (currentValueStr.length() % 2 == 0) {
      size_t halfSize = currentValueStr.size() / 2;

      // Handle if number has odd number of digits
      std::string firstHalf = currentValueStr.substr(0, halfSize);
      std::string secondHalf = currentValueStr.substr(halfSize);

      long long one = std::stoll(firstHalf);
      long long two = std::stoll(secondHalf);

      // Don't actually need to go next to removed element, order doesn't matter in the stone
      //     row!
      owningList.emplace_front(two);
      owningList.emplace_front(one);

      // Remove index, and update reference to iterator
      idx = owningList.erase(idx);
      // Move iterator to new last number inserted
      --idx;
      return true;
    }
    return false;
  }
  bool PebbleRow::splitStoneIfEven(std::unordered_map<long long, long long>::iterator &idx,
                                   std::unordered_map<long long, long long> &stoneMap) {
    long long currentValue = idx->first;
    std::string currentValueStr = std::to_string(currentValue);
    if (currentValueStr.length() % 2 == 0) {
      size_t halfSize = currentValueStr.size() / 2;

      // Handle if number has odd number of digits
      std::string firstHalf = currentValueStr.substr(0, halfSize);
      std::string secondHalf = currentValueStr.substr(halfSize);

      long long one = std::stoll(firstHalf);
      long long two = std::stoll(secondHalf);

      // Add the two numbers to the stone map
      addToStoneMap(one, idx->second, stoneMap);
      addToStoneMap(two, idx->second, stoneMap);

      // Remove stones which were split, and update reference to iterator
      removeTotalFromStoneMap(idx->first, idx->second, stoneMap);
      return true;
    }
    return false;
  }


  bool PebbleRow::multiplyStoneEngravingByYear(std::list<long long>::iterator &idx) {
    long long currentValue = *idx;
    std::string currentValueStr = std::to_string(currentValue);
    if (currentValue > 0 && currentValueStr.length() % 2 != 0) {
      *idx *= 2024;
      return true;
    }
    return false;
  }
  bool PebbleRow::multiplyStoneEngravingByYear(std::unordered_map<long long, long long>::iterator &idx,
                                               std::unordered_map<long long, long long> &stoneMap) {
    long long currentValue = idx->first;
    std::string currentValueStr = std::to_string(currentValue);
    if (currentValue > 0 && currentValueStr.length() % 2 != 0) {
      // Get new engraving value
      long long newEngraving = idx->first * 2024;
      // Remove old engravings
      removeTotalFromStoneMap(idx->first, idx->second, stoneMap);
      // Add new engraving to stone map
      addToStoneMap(newEngraving, idx->second, stoneMap);
      return true;
    }
    return false;
  }

  void PebbleRow::printToConsole() {
    for (auto it = this->getStoneList().begin(); it != this->getStoneList().end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << "" << std::endl << std::endl;
  }
  int PebbleRow::getTotalStones() { return this->getStoneList().size(); }

} // namespace solutions
