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

TEST(FarmGrid_Initialize_Test, ShouldInitialize2x2Neighbours) {
  // Given
  std::string inputRaw =
    "ab\n"
    "cd\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  // When
  solutions::FarmGrid grid(input);
  // Then
  // Assert locations
  ASSERT_EQ(solutions::Plant(0, 0, 'a'), grid(0, 0));
  ASSERT_EQ(solutions::Plant(1, 0, 'b'), grid(1, 0));
  ASSERT_EQ(solutions::Plant(0, 1, 'c'), grid(0, 1));
  ASSERT_EQ(solutions::Plant(1, 1, 'd'), grid(1, 1));
  // Check neighbours for (0,0)
  ASSERT_FALSE(grid(0,0).containsNeighbour(core::NORTH));
  ASSERT_TRUE(grid(0,0).containsNeighbour(core::EAST));
  ASSERT_EQ('b', grid(0,0).getNeighbourPlantLabel(core::EAST));
  ASSERT_TRUE(grid(0,0).containsNeighbour(core::SOUTH));
  ASSERT_EQ('c', grid(0,0).getNeighbourPlantLabel(core::SOUTH));
  ASSERT_FALSE(grid(0,0).containsNeighbour(core::WEST));
  // Check neighbours for (1,0)
  ASSERT_FALSE(grid(1,0).containsNeighbour(core::NORTH));
  ASSERT_FALSE(grid(1,0).containsNeighbour(core::EAST));
  ASSERT_TRUE(grid(1,0).containsNeighbour(core::SOUTH));
  ASSERT_EQ('d', grid(1,0).getNeighbourPlantLabel(core::SOUTH));
  ASSERT_TRUE(grid(1,0).containsNeighbour(core::WEST));
  ASSERT_EQ('a', grid(1,0).getNeighbourPlantLabel(core::WEST));
  // Check neighbours for (0,1)
  ASSERT_TRUE(grid(0,1).containsNeighbour(core::NORTH));
  ASSERT_EQ('a', grid(0,1).getNeighbourPlantLabel(core::NORTH));
  ASSERT_TRUE(grid(0,1).containsNeighbour(core::EAST));
  ASSERT_EQ('d', grid(0,1).getNeighbourPlantLabel(core::EAST));
  ASSERT_FALSE(grid(0,1).containsNeighbour(core::SOUTH));
  ASSERT_FALSE(grid(0,1).containsNeighbour(core::WEST));
  // Check neighbours for (1,1)
  ASSERT_TRUE(grid(1,1).containsNeighbour(core::NORTH));
  ASSERT_EQ('b', grid(1,1).getNeighbourPlantLabel(core::NORTH));
  ASSERT_FALSE(grid(1,1).containsNeighbour(core::EAST));
  ASSERT_FALSE(grid(1,1).containsNeighbour(core::SOUTH));
  ASSERT_TRUE(grid(1,1).containsNeighbour(core::WEST));
  ASSERT_EQ('c', grid(1,1).getNeighbourPlantLabel(core::WEST));
}
