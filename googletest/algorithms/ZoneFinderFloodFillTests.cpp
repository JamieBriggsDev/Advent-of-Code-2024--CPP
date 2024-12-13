//
// Created by Jamie Briggs on 13/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/algorithms/ZoneFinderFloodFill.h"
#include "../../cpp/day12/FarmGrid.h"
#include "../testHelper/InputUtils.h"


TEST(ZoneFinderFloodFill_CountZones_Tests, ShouldCountOneZone) {
  // Given
  std::string inputRaw =
    "aa\n"
    "aa\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  int result = algorithms::ZoneFinderFloodFill::countZones(grid);
  // Then
  ASSERT_EQ(1, result);
}

TEST(ZoneFinderFloodFill_CountZones_Tests, ShouldCountTwoZones) {
  // Given
  std::string inputRaw =
    "aa\n"
    "bb\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  int result = algorithms::ZoneFinderFloodFill::countZones(grid);
  // Then
  ASSERT_EQ(2, result);
}

TEST(ZoneFinderFloodFill_FindZones_Tests, FindsSingleZone) {
  // Given
  std::string inputRaw =
    "a\n";
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // Then
  ASSERT_EQ(1, result.size());
  // Check zone a
  ASSERT_EQ(1, result[0].size());
  ASSERT_TRUE(result[0].contains(core::Pair(0,0)));
}

TEST(ZoneFinderFloodFill_FindZones_Tests, FindsTwoZones) {
  // Given
  std::string inputRaw =
    "a\n"
    "b\n";
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // Then
  ASSERT_EQ(2, result.size());
  // Check zone a
  ASSERT_EQ(1, result[0].size());
  ASSERT_TRUE(result[0].contains(core::Pair(0,0)));
  // Check zone b
  ASSERT_EQ(1, result[1].size());
  ASSERT_TRUE(result[1].contains(core::Pair(0,1)));
}

TEST(ZoneFinderFloodFill_FindZones_Tests, FindsTwoZonesLarger) {
  // Given
  std::string inputRaw =
    "aa\n"
    "bb\n";
  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // Then
  ASSERT_EQ(2, result.size());
  // Check zone a
  ASSERT_EQ(2, result[0].size());
  ASSERT_TRUE(result[0].contains(core::Pair(0,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(1,0)));
  // Check zone b
  ASSERT_EQ(2, result[1].size());
  ASSERT_TRUE(result[1].contains(core::Pair(0,1)));
  ASSERT_TRUE(result[1].contains(core::Pair(1,1)));
}

TEST(ZoneFinderFloodFill_FindZones_Tests, FindsTwoZones9Tiles) {
  // Given
  std::string inputRaw =
    "aaa\n"
    "bba\n"
    "bba\n";

  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // Then
  ASSERT_EQ(2, result.size());
  // Check zone a
  ASSERT_EQ(5, result[0].size());
  ASSERT_TRUE(result[0].contains(core::Pair(0,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(1,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,1)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,2)));
  // Check zone b
  ASSERT_EQ(4, result[1].size());
  ASSERT_TRUE(result[1].contains(core::Pair(0,1)));
  ASSERT_TRUE(result[1].contains(core::Pair(1,1)));
  ASSERT_TRUE(result[1].contains(core::Pair(0,2)));
  ASSERT_TRUE(result[1].contains(core::Pair(1,2)));
}

TEST(ZoneFinderFloodFill_FindZones_Tests, FindTwoZonesComplex) {
  // Given
  std::string inputRaw =
    "aaa\n"
    "aza\n"
    "aaa\n";

  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  // When
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // Then
  ASSERT_EQ(2, result.size());
  // Check zone a
  ASSERT_EQ(8, result[0].size());
  ASSERT_TRUE(result[0].contains(core::Pair(0,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(1,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,0)));
  ASSERT_TRUE(result[0].contains(core::Pair(0,1)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,1)));
  ASSERT_TRUE(result[0].contains(core::Pair(0,2)));
  ASSERT_TRUE(result[0].contains(core::Pair(1,2)));
  ASSERT_TRUE(result[0].contains(core::Pair(2,2)));
  // Check zone b
  ASSERT_EQ(1, result[1].size());
  ASSERT_TRUE(result[1].contains(core::Pair(1,1)));
}
