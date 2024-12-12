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
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithTwoPebbles) {
  // Given
  std::string pebbleInput = "20 5";
  // When
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(5l, pebbles.getStoneEngravingAtIndex(1));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithThreePebbles) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  auto begin = pebbles.getStoneList().begin();
  std::advance(begin, pebbles.getStoneList().size());
  pebbles.splitStoneIfEven(begin, pebbles.getStoneList());
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(0l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(5l, pebbles.getStoneEngravingAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldEngraveNumberToOne) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  std::advance(front, 1);
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(1l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(5l, pebbles.getStoneEngravingAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldNotModifyIfValueNotZero) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(0l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(5l, pebbles.getStoneEngravingAtIndex(2));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldModifyMultipleValues) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.upgradeZeroEngraving(it);
  }
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(1l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(5l, pebbles.getStoneEngravingAtIndex(2));
  ASSERT_EQ(1l, pebbles.getStoneEngravingAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleHasOddNumberDigits) {
  // Given
  std::string pebbleInput = "213";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitStoneIfEven(front, pebbles.getStoneList());
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(213l, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsOddLonger) {
  // Given
  std::string pebbleInput = "21575";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitStoneIfEven(front, pebbles.getStoneList());
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(21575l, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitPebbleIfEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitStoneIfEven(front, pebbles.getStoneList());
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(21l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(58l, pebbles.getStoneEngravingAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitStoneIfEven(it, pebbles.getStoneList());
  }
  // Then
  ASSERT_EQ(4, pebbles.getStoneList().size());
  // Order doesn't actually matter
  ASSERT_EQ(51l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(28l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(21l, pebbles.getStoneEngravingAtIndex(2));
  ASSERT_EQ(58l, pebbles.getStoneEngravingAtIndex(3));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigitsLonger) {
  // Given
  std::string pebbleInput = "2158 512 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitStoneIfEven(it, pebbles.getStoneList());
  }
  // Then
  ASSERT_EQ(5, pebbles.getStoneList().size());
  ASSERT_EQ(51l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(28l, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(21l, pebbles.getStoneEngravingAtIndex(2));
  ASSERT_EQ(58l, pebbles.getStoneEngravingAtIndex(3));
  ASSERT_EQ(512l, pebbles.getStoneEngravingAtIndex(4));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenSuperLong) {
  // Given
  std::string pebbleInput = "2158512824";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitStoneIfEven(it, pebbles.getStoneList());
  }
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(21585l, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(12824l, pebbles.getStoneEngravingAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsZero) {
  // Given
  std::string pebbleInput = "0";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyStoneEngravingByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(0, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsEvenAmountOfDigits) {
  // Given
  std::string pebbleInput = "21";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyStoneEngravingByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(21, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldNotModifyIfPebbleIsEvenLonger) {
  // Given
  std::string pebbleInput = "2865";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyStoneEngravingByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2865, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddTotalDigits) {
  // Given
  std::string pebbleInput = "1";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyStoneEngravingByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2024, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLarger) {
  // Given
  std::string pebbleInput = "999";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyStoneEngravingByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2021976L, pebbles.getStoneEngravingAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLargerLoop) {
  // Given
  std::string pebbleInput = "999 511";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.multiplyStoneEngravingByYear(it);
  }
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(2021976L, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(1034264L, pebbles.getStoneEngravingAtIndex(1));
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExample) {
  // Given
  std::string pebbleInput = "125 17";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  long long result = pebbles.performBlinks(1);
  // Then
  ASSERT_EQ(3l, result);
  /*ASSERT_EQ(3l, pebbles.getStoneList().size());
  ASSERT_EQ(253000L, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(1L, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(7L, pebbles.getStoneEngravingAtIndex(2));*/
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExampleTwo) {
  // Given
  std::string pebbleInput = "253 0 2024 14168";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  long long result = pebbles.performBlinks(1);
  // Then
  //ASSERT_EQ(5l, pebbles.getStoneList().size());
  ASSERT_EQ(5l, result);
  /*ASSERT_EQ(512072L, pebbles.getStoneEngravingAtIndex(0));
  ASSERT_EQ(1L, pebbles.getStoneEngravingAtIndex(1));
  ASSERT_EQ(20L, pebbles.getStoneEngravingAtIndex(2));
  ASSERT_EQ(24L, pebbles.getStoneEngravingAtIndex(3));
  ASSERT_EQ(28676032L, pebbles.getStoneEngravingAtIndex(4));*/
}

TEST(PebbleRow_ModifyAll_Test, ShouldBeOptimized) {
  // Given
  std::string pebbleInput = "253 0 2024 14168";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  auto start = std::chrono::high_resolution_clock::now();
  long long result = pebbles.performBlinks(35, true);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  // Then
  // Assert that the task took less than 50ms
  ASSERT_LT(duration, 50);
  // Existing assertion
  ASSERT_EQ(6157954208l, result);
}