//
// Created by Jamie Briggs on 11/12/2024.
//

#include <gtest/gtest.h>
#include <list>
#include <string>

#include "../../cpp/day11/PebbleRow.h"

using namespace solutions;

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithSinglePebble) {
  // Given
  std::string pebbleInput = "20";
  // When
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithTwoPebbles) {
  // Given
  std::string pebbleInput = "20 5";
  // When
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // Then
  ASSERT_EQ(2, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithThreePebbles) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  auto begin = pebbles.getPebbleList().begin();
  std::advance(begin, pebbles.getPebbleList().size());
  pebbles.splitPebbleIfEven(begin);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(0l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldEngraveNumberToOne) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleList().begin();
  std::advance(front, 1);
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldNotModifyIfValueNotZero) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleList().begin();
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(0l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldModifyMultipleValues) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleList().begin(); it != pebbles.getPebbleList().end(); ++it) {
    pebbles.upgradeZeroEngraving(it);
  }
  // Then
  ASSERT_EQ(3, pebbles.getPebbleList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsOdd) {
  // Given
  std::string pebbleInput = "21";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsOddLonger) {
  // Given
  std::string pebbleInput = "2157";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleList().size());
  ASSERT_EQ(2157l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitPebbleIfEven) {
  // Given
  std::string pebbleInput = "2158";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(2, pebbles.getPebbleList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(58l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEven) {
  // Given
  std::string pebbleInput = "2158 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleList().begin(); it != pebbles.getPebbleList().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(4, pebbles.getPebbleList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(58l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(51l, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(28l, pebbles.getPebbleAtIndex(3));
}
