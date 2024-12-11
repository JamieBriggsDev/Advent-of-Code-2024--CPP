//
// Created by Jamie Briggs on 11/12/2024.
//

#include "PebbleRow.h"

#include <iostream>
#include <sstream>

namespace solutions {
  PebbleRow::PebbleRow(std::string rawInput) {

    std::istringstream stream(rawInput);
    std::string token;
    while (std::getline(stream, token, ' ')) {
      // Attempt to convert each token to a long and add to pebbleList
      try {
        pebbleList.push_back(std::stol(token));
      } catch (const std::invalid_argument &e) {
        // Ignore invalid tokens that cannot be converted to a number
      }
    }
  }
  long PebbleRow::getPebbleAtIndex(int index) {
    auto front = this->pebbleList.begin();
    std::advance(front, index);
    return *front;
  }
  void PebbleRow::upgradeZeroEngraving(std::list<long>::iterator &idx) {
    if (*idx == 0) {
      *idx = 1;
    }
  }
  void PebbleRow::splitPebbleIfEven(std::list<long>::iterator &idx) {
    long currentValue = *idx;
    if(currentValue % 2 == 0) {
      std::string currentValueStr = std::to_string(currentValue);
      size_t halfSize = currentValueStr.size() / 2;

      // Handle if number has odd number of digits
      std::string firstHalf = currentValueStr.substr(0, halfSize);
      std::string secondHalf = currentValueStr.substr(halfSize);

      long one = std::stol(firstHalf);
      long two = std::stol(secondHalf);

      this->pebbleList.insert(idx, one);
      this->pebbleList.insert(idx, two);

      // Remove index, and update reference to iterator
      idx = this->pebbleList.erase(idx);
      // Move iterator to new last number inserted
      --idx;

      std::cout << "New idx: " << *idx << std::endl;
    }
  }
  void PebbleRow::multiplyPebbleByYear(std::list<long>::iterator &idx) {}

} // namespace solutions
