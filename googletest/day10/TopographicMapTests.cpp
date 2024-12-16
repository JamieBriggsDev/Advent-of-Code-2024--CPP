//
// Created by Jamie Briggs on 10/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/day10/TopographicMap.h"
#include "../testHelper/InputUtils.h"

TEST(TopographicMap_Initialize_Tests, ShouldInitializeWithGrid) {
  // Given
  std::string inputRaw =
    "0123\n"
    "6654\n"
    "7889\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  // When
  core::TopographicMap topographicMap = core::TopographicMap(input);
  // Then
  ASSERT_EQ(0, topographicMap.getGrid()[0][0]->getWeight());
  ASSERT_EQ(1, topographicMap.getGrid()[0][1]->getWeight());
  ASSERT_EQ(2, topographicMap.getGrid()[0][2]->getWeight());
  ASSERT_EQ(3, topographicMap.getGrid()[0][3]->getWeight());
  ASSERT_EQ(6, topographicMap.getGrid()[1][0]->getWeight());
  ASSERT_EQ(6, topographicMap.getGrid()[1][1]->getWeight());
  ASSERT_EQ(5, topographicMap.getGrid()[1][2]->getWeight());
  ASSERT_EQ(4, topographicMap.getGrid()[1][3]->getWeight());
  ASSERT_EQ(7, topographicMap.getGrid()[2][0]->getWeight());
  ASSERT_EQ(8, topographicMap.getGrid()[2][1]->getWeight());
  ASSERT_EQ(8, topographicMap.getGrid()[2][2]->getWeight());
  ASSERT_EQ(9, topographicMap.getGrid()[2][3]->getWeight());
}

TEST(TopographicMap_Initialize_Tests, ShouldReturnWithStartingPaths) {
  // Given
  std::string inputRaw =
    "0110\n"
    "3223\n"
    "4567\n"
    "9887\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  core::TopographicMap topographicMap = core::TopographicMap(input);
  // When
  auto startingPaths = topographicMap.getStartingPositions();
  // Then
  ASSERT_EQ(0, startingPaths[0]->x);
  ASSERT_EQ(0, startingPaths[0]->y);
  ASSERT_EQ(3, startingPaths[1]->x);
  ASSERT_EQ(0, startingPaths[1]->y);

}