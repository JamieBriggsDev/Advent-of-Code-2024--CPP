//
// Created by Jamie Briggs on 04/12/2024.
//

#include "Day04.h"

#include "../core/WordSearchGrid.h"
#include "MasSearchGrid.h"
std::string solutions::Day04::solvePartOne(const helper::SolutionInput *input) {

  int totalXmas = 0;
  auto* grid = new WordSearchGrid(input->getTestInput());

  totalXmas += grid->findTotalHorizontalInstances("XMAS");
  totalXmas += grid->findTotalVerticalInstances("XMAS");
  totalXmas += grid->findTotalDiagonalInstances("XMAS");

  return std::to_string(totalXmas);
}
std::string solutions::Day04::solvePartTwo(const helper::SolutionInput *input) {
  auto* grid = new MasSearchGrid(input->getTestInput());

  int totalXmas = grid->findTotalOccurrencesOfXMas();

  return std::to_string(totalXmas);
}
