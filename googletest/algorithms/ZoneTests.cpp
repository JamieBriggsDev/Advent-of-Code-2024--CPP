//
// Created by Jamie Briggs on 13/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/algorithms/Zone.h"

TEST(Zone_FindPerimeterLength_Tests, ShouldReturn4) {
  // Given
  /*
  +-+
  |A|
  +-+
   */
  algorithms::Zone zone;
  zone.addLocation(core::Pair(0,0));
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
  zone.addLocation(core::Pair(0,0));
  zone.addLocation(core::Pair(0,1));
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
  zone.addLocation(core::Pair(0,0));
  zone.addLocation(core::Pair(1,0));
  zone.addLocation(core::Pair(2,0));
  zone.addLocation(core::Pair(0,1));
  zone.addLocation(core::Pair(2,1));
  zone.addLocation(core::Pair(0,2));
  zone.addLocation(core::Pair(1,2));
  zone.addLocation(core::Pair(2,2));
  // When
  int perimeterLength = zone.getPerimeterLength();
  // Then
  ASSERT_EQ(16, perimeterLength);
}