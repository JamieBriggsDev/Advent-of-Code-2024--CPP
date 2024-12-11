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
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithTwoPebbles) {
  // Given
  std::string pebbleInput = "20 5";
  // When
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithThreePebbles) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  auto begin = pebbles.getStoneList().begin();
  std::advance(begin, pebbles.getStoneList().size());
  pebbles.splitPebbleIfEven(begin);
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(0l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
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
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
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
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(0l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
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
  ASSERT_EQ(20l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(5l, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(1l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleHasOddNumberDigits) {
  // Given
  std::string pebbleInput = "213";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(213l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsOddLonger) {
  // Given
  std::string pebbleInput = "21575";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(21575l, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitPebbleIfEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(58l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(4, pebbles.getStoneList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(58l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(51l, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(28l, pebbles.getPebbleAtIndex(3));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigitsLonger) {
  // Given
  std::string pebbleInput = "2158 512 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(5, pebbles.getStoneList().size());
  ASSERT_EQ(21l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(58l, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(512l, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(51l, pebbles.getPebbleAtIndex(3));
  ASSERT_EQ(28l, pebbles.getPebbleAtIndex(4));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenSuperLong) {
  // Given
  std::string pebbleInput = "2158512824";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(21585l, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(12824l, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsZero) {
  // Given
  std::string pebbleInput = "0";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(0, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsEvenAmountOfDigits) {
  // Given
  std::string pebbleInput = "21";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(21, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldNotModifyIfPebbleIsEvenLonger) {
  // Given
  std::string pebbleInput = "2865";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2865, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddTotalDigits) {
  // Given
  std::string pebbleInput = "1";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2024, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLarger) {
  // Given
  std::string pebbleInput = "999";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getStoneList().size());
  ASSERT_EQ(2021976L, pebbles.getPebbleAtIndex(0));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLargerLoop) {
  // Given
  std::string pebbleInput = "999 511";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getStoneList().begin();
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    pebbles.multiplyPebbleByYear(it);
  }
  // Then
  ASSERT_EQ(2, pebbles.getStoneList().size());
  ASSERT_EQ(2021976L, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1034264L, pebbles.getPebbleAtIndex(1));
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExample) {
  // Given
  std::string pebbleInput = "125 17";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    bool flag = false;
    flag = pebbles.upgradeZeroEngraving(it);
    if(!flag) {
      flag = pebbles.splitPebbleIfEven(it);
    }
    if(!flag) {
      pebbles.multiplyPebbleByYear(it);
    }
  }
  // Then
  ASSERT_EQ(3, pebbles.getStoneList().size());
  ASSERT_EQ(253000L, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1L, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(7L, pebbles.getPebbleAtIndex(2));
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExampleTwo) {
  // Given
  std::string pebbleInput = "253 0 2024 14168";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getStoneList().begin(); it != pebbles.getStoneList().end(); ++it) {
    bool flag = false;
    flag = pebbles.upgradeZeroEngraving(it);
    if(!flag) {
      flag = pebbles.splitPebbleIfEven(it);
    }
    if(!flag) {
      pebbles.multiplyPebbleByYear(it);
    }
  }
  // Then
  ASSERT_EQ(5, pebbles.getStoneList().size());
  ASSERT_EQ(512072L, pebbles.getPebbleAtIndex(0));
  ASSERT_EQ(1L, pebbles.getPebbleAtIndex(1));
  ASSERT_EQ(20L, pebbles.getPebbleAtIndex(2));
  ASSERT_EQ(24L, pebbles.getPebbleAtIndex(3));
  ASSERT_EQ(28676032L, pebbles.getPebbleAtIndex(4));
}