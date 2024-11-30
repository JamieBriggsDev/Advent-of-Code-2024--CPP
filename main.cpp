#include <iostream>
#include <chrono>

#include "cpp/day.h"
#include "cpp/helper/AOCInitializer.h"
#include "cpp/helper/StringUtils.h"

using namespace helper;
using namespace solutions;


int main(int argc, char* argv[]) {
  // Get the start time point
  const auto start = std::chrono::high_resolution_clock::now();

  const auto startInput = std::chrono::high_resolution_clock::now();
  const auto day = AOCInitializer::getDay(StringUtils::toInt(argv[1]));
  const auto inputOne = AOCInitializer::getInput(StringUtils::toInt(argv[1]), argc > 2, 1);
  const auto inputTwo = AOCInitializer::getInput(StringUtils::toInt(argv[1]), argc > 2, 2);
  const auto endInput = std::chrono::high_resolution_clock::now();

  // List time elapsed to load data
  const auto inputDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endInput - startInput);
  printf("\nTook %lldms to load data", inputDuration);

  // Solve part one of solution
  printf("Solving Part 1 of solution...");
  const auto startPartOne = std::chrono::high_resolution_clock::now();
  const auto solve_part_one = day->solvePartOne(inputOne);
  const auto endPartOne = std::chrono::high_resolution_clock::now();
  const auto partOneDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endPartOne - startPartOne);
  printf("\nPart 1 solution: %s", solve_part_one.c_str());
  printf("\nPart 1 took %lldms to solve\n", partOneDuration);

  cout << endl;

  // Solve part two of solution
  printf("\nSolving Part 2 of solution...");
  const auto startPartTwo = std::chrono::high_resolution_clock::now();
  const auto solve_part_two = day->solvePartTwo(inputTwo);
  const auto endPartTwo = std::chrono::high_resolution_clock::now();
  const auto partTwoDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endPartTwo - startPartTwo);
  printf("\nPart 2 solution: %s\n", solve_part_two.c_str());
  printf("\nPart 2 took %lldms to solve\n", partTwoDuration);
  return 0;
}


