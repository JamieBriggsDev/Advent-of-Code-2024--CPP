//
// Created by perso on 08/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day8/AntennaGrid.h"
#include "../testHelper/InputUtils.h"


TEST(AntennaGrid_Initialize_Tests, ShouldCreateEmptyRow) {
  // Given
  std::vector<std::string> rawInput =
    InputUtils::convertToVector("....");
  // When
  auto grid = day8::AntennaGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
}

TEST(AntennaGrid_Initialize_Tests, ShouldCreateRowWithOneAntenna) {
  // Given
  std::vector<std::string> rawInput =
    InputUtils::convertToVector(".A..");
  // When
  auto grid = day8::AntennaGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[0][1] != nullptr);
  ASSERT_EQ(1, grid.getGrid()[0][1]->x);
  ASSERT_EQ(0, grid.getGrid()[0][1]->y);
  ASSERT_EQ('A', grid.getGrid()[0][1]->getIdentifier());
  ASSERT_EQ(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
}

TEST(AntennaGrid_Initialize_Tests, ShouldCreateWithTwoRowWithTwoAntenna) {
  // Given
  std::vector<std::string> rawInput =
    InputUtils::convertToVector(".A..\n...A");
  // When
  auto grid = day8::AntennaGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[0][1]);
  ASSERT_EQ(1, grid.getGrid()[0][1]->x);
  ASSERT_EQ(0, grid.getGrid()[0][1]->y);
  ASSERT_EQ('A', grid.getGrid()[0][1]->getIdentifier());
  ASSERT_EQ(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(3, grid.getGrid()[1][3]->x);
  ASSERT_EQ(1, grid.getGrid()[1][3]->y);
  ASSERT_EQ('A', grid.getGrid()[1][3]->getIdentifier());

  // TODO: Fix test to use getAntennaLocations method to assert
}


TEST(AntennaGrid_GetAntinode_Tests, ShouldFindZeroAntinodes) {
  // Given
  std::string rawInput =
    "....\n"
    "....\n"
    ".BA.\n"
    "....\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_EQ(0, antinodeLocations.size());
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodes) {
  // Given
  std::string rawInput =
    "....\n"
    ".AB.\n"
    ".BA.\n"
    "....\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[0][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(2, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,3), antinodeLocations[1]);
}