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
  ASSERT_EQ(core::Pair(1,0), grid.getAntennaLocations()[0]);
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
  ASSERT_EQ(core::Pair(1,0), grid.getAntennaLocations()[0]);
  ASSERT_EQ(core::Pair(3,1), grid.getAntennaLocations()[1]);
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
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[2][1]);
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_EQ(2, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,3), antinodeLocations[1]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodesAlt) {
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
  auto antinodeLocations = grid.getAntinodeLocations('B');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[2][1]);
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_EQ(2, antinodeLocations.size());
  ASSERT_EQ(core::Pair(3,0), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(0,3), antinodeLocations[1]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodesLarger) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A.B..\n"
    ".......\n"
    "..B.A..\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_TRUE(grid.getGrid()[2][4]);
  ASSERT_TRUE(grid.getGrid()[4][4]);
  ASSERT_EQ(2, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(6,6), antinodeLocations[1]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapNorth) {
  // Given
  std::string rawInput =
    ".......\n"
    "..A....\n"
    ".......\n"
    "..A....\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[3][2]);
  ASSERT_EQ(1, antinodeLocations.size());
  ASSERT_EQ(core::Pair(2,5), antinodeLocations[0]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapEast) {
  // Given
  std::string rawInput =
    "......\n"
    "..A.A.\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[1][4]);
  ASSERT_EQ(1, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,1), antinodeLocations[0]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapSouth) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A....\n"
    ".......\n"
    "..A....\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_EQ(1, antinodeLocations.size());
  ASSERT_EQ(core::Pair(2,0), antinodeLocations[0]);
}


TEST(AntennaGrid_GetAntinode_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapWest) {
  // Given
  std::string rawInput =
    "......\n"
    ".A.A..\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(1, antinodeLocations.size());
  ASSERT_EQ(core::Pair(5,1), antinodeLocations[0]);
}


TEST(AntennaGrid_GetAntinode_Tests, ShouldCreateWithFourAntennas) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A.A..\n"
    ".......\n"
    "..A.A..\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_TRUE(grid.getGrid()[2][4]);
  ASSERT_TRUE(grid.getGrid()[4][4]);
  ASSERT_EQ(12, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,2), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(6,2), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(2,0), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(2,6), antinodeLocations[3]);
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[4]);
  ASSERT_EQ(core::Pair(6,6), antinodeLocations[5]);
  ASSERT_EQ(core::Pair(6,0), antinodeLocations[6]);
  ASSERT_EQ(core::Pair(0,6), antinodeLocations[7]);
  ASSERT_EQ(core::Pair(4,0), antinodeLocations[8]);
  ASSERT_EQ(core::Pair(4,6), antinodeLocations[9]);
  ASSERT_EQ(core::Pair(0,4), antinodeLocations[10]);
  ASSERT_EQ(core::Pair(6,4), antinodeLocations[11]);
}

TEST(AntennaGrid_GetAntinode_Tests, ShouldNotContainDuplicates) {
  // Given
  std::string rawInput =
    "......\n"
    ".A.A..\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocations('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(1, antinodeLocations.size());
  ASSERT_EQ(core::Pair(5,1), antinodeLocations[0]);
}


TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldFindZeroAntinodes) {
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
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_EQ(0, antinodeLocations.size());
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodes) {
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
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[2][1]);
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_EQ(4, antinodeLocations.size());
  ASSERT_EQ(core::Pair(2,2), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,3), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(1,1), antinodeLocations[3]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodesAlt) {
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
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('B');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[2][1]);
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_EQ(4, antinodeLocations.size());
  ASSERT_EQ(core::Pair(0,3), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,0), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(1,2), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(2,1), antinodeLocations[3]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldCreateWithTwoRowWithTwoAntennaAndAntinodesLarger) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A.B..\n"
    ".......\n"
    "..B.A..\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_TRUE(grid.getGrid()[2][4]);
  ASSERT_TRUE(grid.getGrid()[4][4]);
  ASSERT_EQ(4, antinodeLocations.size());
  ASSERT_EQ(core::Pair(4,4), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(6,6), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(0,0), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(2,2), antinodeLocations[3]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapNorth) {
  // Given
  std::string rawInput =
    ".......\n"
    "..A....\n"
    ".......\n"
    "..A....\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[3][2]);
  ASSERT_EQ(3, antinodeLocations.size());
  ASSERT_EQ(core::Pair(2,5), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(2,3), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(2,1), antinodeLocations[2]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapEast) {
  // Given
  std::string rawInput =
    "......\n"
    "..A.A.\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][2]);
  ASSERT_TRUE(grid.getGrid()[1][4]);
  ASSERT_EQ(3, antinodeLocations.size());
  ASSERT_EQ(core::Pair(4,1), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(0,1), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(2,1), antinodeLocations[2]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapSouth) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A....\n"
    ".......\n"
    "..A....\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_EQ(3, antinodeLocations.size());
  ASSERT_EQ(core::Pair(2,4), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(2,0), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(2,2), antinodeLocations[2]);
}


TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldNotContainNodesWhichHaveFallenOffTheMapWest) {
  // Given
  std::string rawInput =
    "......\n"
    ".A.A..\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(3, antinodeLocations.size());
  ASSERT_EQ(core::Pair(5,1), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,1), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(1,1), antinodeLocations[2]);
}


TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldCreateWithFourAntennas) {
  // Given
  std::string rawInput =
    ".......\n"
    ".......\n"
    "..A.A..\n"
    ".......\n"
    "..A.A..\n"
    ".......\n"
    ".......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[2][2]);
  ASSERT_TRUE(grid.getGrid()[4][2]);
  ASSERT_TRUE(grid.getGrid()[2][4]);
  ASSERT_TRUE(grid.getGrid()[4][4]);
  ASSERT_EQ(16, antinodeLocations.size());
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldNotContainDuplicates) {
  // Given
  std::string rawInput =
    "......\n"
    ".A.A..\n"
    "......\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(3, antinodeLocations.size());
  ASSERT_EQ(core::Pair(5,1), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(3,1), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(1,1), antinodeLocations[2]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldFindMultipleInDistanceEast) {
  // Given
  std::string rawInput =
    "............\n"
    ".A.A........\n"
    "............\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][1]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_EQ(6, antinodeLocations.size());
  ASSERT_EQ(core::Pair(11,1), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(7,1), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(5,1), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(9,1), antinodeLocations[3]);
  ASSERT_EQ(core::Pair(3,1), antinodeLocations[4]);
  ASSERT_EQ(core::Pair(1,1), antinodeLocations[5]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldFindMultipleInDistanceWest) {
  // Given
  std::string rawInput =
    "............\n"
    "........A.A.\n"
    "............\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('A');
  // Then
  ASSERT_TRUE(grid.getGrid()[1][8]);
  ASSERT_TRUE(grid.getGrid()[1][10]);
  ASSERT_EQ(6, antinodeLocations.size());
  ASSERT_EQ(core::Pair(10,1), antinodeLocations[0]);
  ASSERT_EQ(core::Pair(0,1), antinodeLocations[1]);
  ASSERT_EQ(core::Pair(4,1), antinodeLocations[2]);
  ASSERT_EQ(core::Pair(6,1), antinodeLocations[3]);
  ASSERT_EQ(core::Pair(2,1), antinodeLocations[4]);
  ASSERT_EQ(core::Pair(8,1), antinodeLocations[5]);
}

TEST(AntennaGrid_GetAntinodeLocationsUpdates_Tests, ShouldFindMultipleInDistanceExample) {
  // Given
  std::string rawInput =
                         "T.........\n"
                         "...T......\n"
                         ".T........\n"
                         "..........\n"
                         "..........\n"
                         "..........\n"
                         "..........\n"
                         "..........\n"
                         "..........\n"
                         "..........\n"
  ;
  std::vector<std::string> input =
    InputUtils::convertToVector(rawInput);
  auto grid = day8::AntennaGrid(input);
  // When
  auto antinodeLocations = grid.getAntinodeLocationsUpdated('T');
  // Then
  ASSERT_TRUE(grid.getGrid()[0][0]);
  ASSERT_TRUE(grid.getGrid()[1][3]);
  ASSERT_TRUE(grid.getGrid()[2][1]);
  // Should include position of antennas
  ASSERT_EQ(9, antinodeLocations.size());
}