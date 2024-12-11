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
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithTwoPebbles) {
  // Given
  std::string pebbleInput = "20 5";
  // When
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // Then
  ASSERT_EQ(2, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
  ASSERT_TRUE(pebbles.containsPebble(5l));
}

TEST(PebbleRow_Initialize_Test, ShouldInitializeWithThreePebbles) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  auto begin = pebbles.getPebbleQuantities().begin();
  std::advance(begin, pebbles.getPebbleQuantities().size());
  pebbles.splitPebbleIfEven(begin);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
  ASSERT_TRUE(pebbles.containsPebble(0l));
  ASSERT_TRUE(pebbles.containsPebble(5l));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldEngraveNumberToOne) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  std::advance(front, 1);
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
  ASSERT_TRUE(pebbles.containsPebble(1l));
  ASSERT_TRUE(pebbles.containsPebble(5l));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldNotModifyIfValueNotZero) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.upgradeZeroEngraving(front);
  // Then
  ASSERT_EQ(3, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
  ASSERT_TRUE(pebbles.containsPebble(0l));
  ASSERT_TRUE(pebbles.containsPebble(5l));
}

TEST(PebbleRow_UpgradeZeroEngraving_Test, ShouldModifyMultipleValues) {
  // Given
  std::string pebbleInput = "20 0 5";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
    pebbles.upgradeZeroEngraving(it);
  }
  // Then
  ASSERT_EQ(3, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(20l));
  ASSERT_TRUE(pebbles.containsPebble(1l));
  ASSERT_TRUE(pebbles.containsPebble(5l));
  ASSERT_TRUE(pebbles.containsPebble(1l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleHasOddNumberDigits) {
  // Given
  std::string pebbleInput = "213";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(213l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsOddLonger) {
  // Given
  std::string pebbleInput = "21575";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21575l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitPebbleIfEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.splitPebbleIfEven(front);
  // Then
  ASSERT_EQ(2, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21l));
  ASSERT_TRUE(pebbles.containsPebble(58l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigits) {
  // Given
  std::string pebbleInput = "2158 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(4, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21l));
  ASSERT_TRUE(pebbles.containsPebble(58l));
  ASSERT_TRUE(pebbles.containsPebble(51l));
  ASSERT_TRUE(pebbles.containsPebble(28l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenNumberDigitsLonger) {
  // Given
  std::string pebbleInput = "2158 512 5128";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(5, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21l));
  ASSERT_TRUE(pebbles.containsPebble(58l));
  ASSERT_TRUE(pebbles.containsPebble(512l));
  ASSERT_TRUE(pebbles.containsPebble(51l));
  ASSERT_TRUE(pebbles.containsPebble(28l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldSplitMultiplePebblesWhenEvenSuperLong) {
  // Given
  std::string pebbleInput = "2158512824";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
    pebbles.splitPebbleIfEven(it);
  }
  // Then
  ASSERT_EQ(2, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21585l));
  ASSERT_TRUE(pebbles.containsPebble(12824l));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsZero) {
  // Given
  std::string pebbleInput = "0";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(0));
}

TEST(PebbleRow_SplitPebble_Test, ShouldNotModifyIfPebbleIsEvenAmountOfDigits) {
  // Given
  std::string pebbleInput = "21";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(21));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldNotModifyIfPebbleIsEvenLonger) {
  // Given
  std::string pebbleInput = "2865";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(2865));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddTotalDigits) {
  // Given
  std::string pebbleInput = "1";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(2024));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLarger) {
  // Given
  std::string pebbleInput = "999";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  pebbles.multiplyPebbleByYear(front);
  // Then
  ASSERT_EQ(1, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(2021976L));
}

TEST(PebbleRow_MultiplyPebble_Test, ShouldModifyIfPebbleIsOddLargerLoop) {
  // Given
  std::string pebbleInput = "999 511";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  auto front = pebbles.getPebbleQuantities().begin();
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
    pebbles.multiplyPebbleByYear(it);
  }
  // Then
  ASSERT_EQ(2, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(2021976L));
  ASSERT_TRUE(pebbles.containsPebble(1034264L));
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExample) {
  // Given
  std::string pebbleInput = "125 17";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
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
  ASSERT_EQ(3, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(253000L));
  ASSERT_TRUE(pebbles.containsPebble(1L));
  ASSERT_TRUE(pebbles.containsPebble(7L));
}

TEST(PebbleRow_ModifyAll_Test, ShouldModifyExampleTwo) {
  // Given
  std::string pebbleInput = "253 0 2024 14168";
  PebbleRow pebbles = PebbleRow(pebbleInput);
  // When
  for (auto it = pebbles.getPebbleQuantities().begin(); it != pebbles.getPebbleQuantities().end(); ++it) {
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
  ASSERT_EQ(5, pebbles.getPebbleQuantities().size());
  ASSERT_TRUE(pebbles.containsPebble(512072L));
  ASSERT_TRUE(pebbles.containsPebble(1L));
  ASSERT_TRUE(pebbles.containsPebble(20L));
  ASSERT_TRUE(pebbles.containsPebble(24L));
  ASSERT_TRUE(pebbles.containsPebble(28676032L));
}