//
// Created by Jamie Briggs on 13/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/algorithms/ZoneFinderFloodFill.h"
#include "../../cpp/day12/FarmGrid.h"
#include "../../cpp/algorithms/Zone.h"
#include "../testHelper/InputUtils.h"

TEST(Zone_FindPerimeterLength_Tests, ShouldReturn4) {
  // Given
  /*
  +-+
  |A|
  +-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  // When
  int perimeterLength = zone.getPerimeterLength();
  // Then
  ASSERT_EQ(4, perimeterLength);
}

TEST(Zone_FindPerimeterLength_Tests, ShouldReturn6) {
  // Given
  /*
  +-+
  |A|
  |A|
  +-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(0, 1));
  // When
  int perimeterLength = zone.getPerimeterLength();
  // Then
  ASSERT_EQ(6, perimeterLength);
}

TEST(Zone_FindPerimeterLength_Tests, ShouldReturn16) {
  // Given
  /*
  +-+-+-+
  |A A A|
  |A|=|A|
  |A A A|
  +-+-+-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(1, 0));
  zone.addLocation(core::Pair(2, 0));
  zone.addLocation(core::Pair(0, 1));
  zone.addLocation(core::Pair(2, 1));
  zone.addLocation(core::Pair(0, 2));
  zone.addLocation(core::Pair(1, 2));
  zone.addLocation(core::Pair(2, 2));
  // When
  int perimeterLength = zone.getPerimeterLength();
  // Then
  ASSERT_EQ(16, perimeterLength);
}

TEST(Zone_GetTotalSides_Tests, ShouldReturn4) {
  // Given
  /*
  +-+
  |A|
  +-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  // When
  int totalSides = zone.getTotalSides();
  // Then
  ASSERT_EQ(4, totalSides);
}

TEST(Zone_GetTotalSides_Tests, ShouldReturn4LongHeight) {
  // Given
  /*
  +-+
  |A|
  |A|
  +-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(0, 1));
  // When
  int totalSides = zone.getTotalSides();
  // Then
  ASSERT_EQ(4, totalSides);
}

TEST(Zone_GetTotalSides_Tests, ShouldReturn4Long) {
  // Given
  /*
  +-+-+
  |A A|
  +-+-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(1, 0));
  // When
  int totalSides = zone.getTotalSides();
  // Then
  ASSERT_EQ(4, totalSides);
}

TEST(Zone_GetTotalSides_Tests, ShouldReturn6LShape) {
  // Given
  /*
  +-+
  |A|_
  |A A|
  +-+-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(0, 1));
  zone.addLocation(core::Pair(1, 1));
  // When
  int totalSides = zone.getTotalSides();
  // Then
  ASSERT_EQ(6, totalSides);
}


TEST(Zone_GetTotalSides_Tests, ShouldReturn12EShape) {
  // Given
  /*
  +-+-+-+
  |E E E|
  |E|
  |E E|
  |E|___+
  |E E E|
  +-+-+-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0, 0));
  zone.addLocation(core::Pair(1, 0));
  zone.addLocation(core::Pair(2, 0));
  zone.addLocation(core::Pair(0, 1));
  zone.addLocation(core::Pair(0, 2));
  zone.addLocation(core::Pair(1, 2));
  zone.addLocation(core::Pair(0, 3));
  zone.addLocation(core::Pair(0, 4));
  zone.addLocation(core::Pair(1, 4));
  zone.addLocation(core::Pair(2, 4));
  // When
  int totalSides = zone.getTotalSides();
  // Then
  ASSERT_EQ(12, totalSides);
}

TEST(Zone_GetTotalSides_Tests, PartialExampleInput) {
  // Given
  std::string inputRaw =  "VVIVCCJJEE\n"
                          "VVIIICJJEE\n"
                          "MIIIIIJJEE\n"
                          "MIIISIJEEE\n"
                          "MMMISSJEEE\n";


  std::vector<std::string> input = InputUtils::convertToVector(inputRaw);
  solutions::FarmGrid grid(input);
  std::vector<algorithms::Zone> result = algorithms::ZoneFinderFloodFill::findAllZones(grid);
  // When
  int total_sides = result[2].getTotalSides();
  // Then
  ASSERT_EQ(8, result.size());
  ASSERT_EQ(16, total_sides);
  // Check zone I
}

