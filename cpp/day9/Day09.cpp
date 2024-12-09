//
// Created by perso on 09/12/2024.
//

#include "Day09.h"

#include "DiskMap.h"

namespace solutions {
  std::string Day09::solvePartOne(const helper::SolutionInput *input) {
    // For this solution, only care about row 1
    DiskMap diskMap = DiskMap(input->getTestInput()[0]);
    while (!diskMap.hasCompletedDefrag()) {
      diskMap.performDefragStep();
    }

    long long finalSum = 0l;
    for(long x = 0; x <= diskMap.getRightMostFileIndex(); x++) {
      long fileIdNumber =  diskMap.getFileLocations()[x]->id;
      finalSum += (x * fileIdNumber);
    }
    return std::to_string(finalSum);
  }
  std::string Day09::solvePartTwo(const helper::SolutionInput *input) { return "Solve"; }
} // solutions