//
// Created by Jamie Briggs on 06/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "AOCInitializer.h"

#include <format>
#include <stdexcept>

#include "../day1/Day01.h"
#include "FileReader.h"

namespace helper {
solutions::Day *AOCInitializer::getDay(int dayNumber) {
  switch (dayNumber) {
  case 1:
    return new solutions::Day01();
  default:
    printf("Unknown day passed %d", dayNumber);
    throw std::invalid_argument("Day could not be found");
  }
}

SolutionInput *AOCInitializer::getInput(int dayNumber) {
  auto file_location = std::format("../input/day{}.txt", dayNumber);
  return FileReader::readFile(file_location);
}

SolutionInput *AOCInitializer::getInput(int dayNumber, bool test, int part) {
  if (!test) {
    return getInput(dayNumber);
  }
  bool multipleTestInputs = FileReader::fileExists(
      std::format("../sample_input/day{}-part2.txt", dayNumber));
  string path = multipleTestInputs && part == 2
                    ? std::format("../sample_input/day{}-part2.txt", dayNumber)
                    : std::format("../sample_input/day{}.txt", dayNumber);
  return FileReader::readFile(path);
}
} // namespace helper
