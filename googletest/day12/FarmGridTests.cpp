//
// Created by Jamie Briggs on 12/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/day12/FarmGrid.h"
#include "../testHelper/InputUtils.h"


TEST(FarmGrid_Initialize_Test, ShouldInitializeWith3x3) {
  // Given
  std::string inputRaw =
    "aab\n"
    "abb\n"
    "ccc\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  // When
  solutions::FarmGrid grid(input);
  // Then
  ASSERT_EQ(solutions::Plant(0, 0, 'a'), grid(0, 0));
  ASSERT_EQ(solutions::Plant(1, 0, 'a'), grid(1, 0));
  ASSERT_EQ(solutions::Plant(2, 0, 'b'), grid(2, 0));
  ASSERT_EQ(solutions::Plant(0, 1, 'a'), grid(0, 1));
  ASSERT_EQ(solutions::Plant(1, 1, 'b'), grid(1, 1));
  ASSERT_EQ(solutions::Plant(2, 1, 'b'), grid(2, 1));
  ASSERT_EQ(solutions::Plant(0, 2, 'c'), grid(0, 2));
  ASSERT_EQ(solutions::Plant(1, 2, 'c'), grid(1, 2));
  ASSERT_EQ(solutions::Plant(2, 2, 'c'), grid(2, 2));
}