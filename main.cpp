#include <iostream>
#include <chrono>

#include "cpp/day.h"
#include "cpp/helper/AOCInitializer.h"
#include "cpp/helper/StringUtils.h"

using namespace helper;
using namespace solutions;


int main(int argc, char* argv[]) {
  // Setup
  const auto day = AOCInitializer::getDay(StringUtils::toInt(argv[1]));
  const auto inputOne = AOCInitializer::getInput(StringUtils::toInt(argv[1]), argc > 2, 1);
  const auto inputTwo = AOCInitializer::getInput(StringUtils::toInt(argv[1]), argc > 2, 2);

  // Solve part one of solution
  printf("Solving Part 1 of solution...");
  const auto solve_part_one = day->solvePartOne(inputOne);
  printf("\nPart 1 solution: %s\n", solve_part_one.c_str());

  cout << endl;

  // Solve part two of solution
  printf("\nSolving Part 2 of solution...");
  const auto solve_part_two = day->solvePartTwo(inputTwo);
  printf("\nPart 2 solution: %s\n", solve_part_two.c_str());
  return 0;
}


