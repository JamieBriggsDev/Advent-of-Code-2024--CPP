//
// Created by Jamie Briggs on 04/12/2024.
//

#include "InputUtils.h"

#include <sstream>
std::vector<std::string> InputUtils::convertToVector(const std::string &input) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string line;

  while (std::getline(ss, line)) {
    result.push_back(line);
  }

  return result;
}
