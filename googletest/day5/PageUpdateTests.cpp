//
// Created by Jamie Briggs on 05/12/2024.
//


#include <gtest/gtest.h>

#include "../../cpp/day5/PageUpdate.h"

TEST(PageUpdate_Initialize_Tests, ShouldLoadRawUpdate) {
  // Given
  auto* updates = new day5::PageUpdate("1,2,3,4,5,6");
  // When
  std::vector<int> result = updates->getUpdates();
  // Then
  ASSERT_EQ(1, result[0]);
  ASSERT_EQ(2, result[1]);
  ASSERT_EQ(3, result[2]);
  ASSERT_EQ(4, result[3]);
  ASSERT_EQ(5, result[4]);
  ASSERT_EQ(6, result[5]);
}

TEST(PageUpdate_Initialize_Tests, ShouldLoadRawUpdateWithOneNumber) {
  // Given
  auto* updates = new day5::PageUpdate("1");
  // When
  std::vector<int> result = updates->getUpdates();
  // Then
  ASSERT_EQ(1, result[0]);
}


TEST(PageUpdate_GetMiddleNumber_Tests, ShouldGetTheOnlyNumberIfOnlyOneNumber) {
  // Given
  auto* updates = new day5::PageUpdate("1");
  // When
  int result = updates->getMiddleNumber();
  // Then
  ASSERT_EQ(1, result);
}

TEST(PageUpdate_GetMiddleNumber_Tests, ShouldGetMiddleNumberWhenFiveNumbers) {
  // Given
  auto* updates = new day5::PageUpdate("1,2,3,4,5");
  // When
  int result = updates->getMiddleNumber();
  // Then
  ASSERT_EQ(3, result);
}

TEST(PageUpdate_GetMiddleNumber_Tests, ShouldGetMiddleNumberWhenNineNumbers) {
  // Given
  auto* updates = new day5::PageUpdate("1,2,3,4,20,6,7,8,9");
  // When
  int result = updates->getMiddleNumber();
  // Then
  ASSERT_EQ(20, result);
}

TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnTrueIfInCorrectOrderSimple) {
  // Given
  auto* updates = new day5::PageUpdate("1,2");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("1|2");
  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(true, result);
}

TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnFalseIfNotInCorrectOrderSimple) {
  // Given
  auto* updates = new day5::PageUpdate("2,1");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("1|2");
  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(false, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnTrueIfCorrectOrderThreeRules) {
  // Given
  auto* updates = new day5::PageUpdate("1,2,3,4");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("1|2");
  rules.importPageOrderingRule("1|3");
  rules.importPageOrderingRule("1|4");
  rules.importPageOrderingRule("2|3");
  rules.importPageOrderingRule("2|4");
  rules.importPageOrderingRule("3|4");
  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(true, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnFalseIfIncorrectOrder) {
  // Given
  auto* updates = new day5::PageUpdate("1,2,4,3");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("1|2");
  rules.importPageOrderingRule("3|4");
  rules.importPageOrderingRule("2|3");
  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(false, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnTrueExampleOne) {
  // Given
  auto* updates = new day5::PageUpdate("75,47,61,53,29");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("47|53");
  rules.importPageOrderingRule("97|13");
  rules.importPageOrderingRule("97|61");
  rules.importPageOrderingRule("97|47");
  rules.importPageOrderingRule("75|29");
  rules.importPageOrderingRule("61|13");
  rules.importPageOrderingRule("75|53");
  rules.importPageOrderingRule("29|13");
  rules.importPageOrderingRule("97|29");
  rules.importPageOrderingRule("53|29");
  rules.importPageOrderingRule("61|53");
  rules.importPageOrderingRule("97|53");
  rules.importPageOrderingRule("61|29");
  rules.importPageOrderingRule("47|13");
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("97|75");
  rules.importPageOrderingRule("47|61");
  rules.importPageOrderingRule("75|61");
  rules.importPageOrderingRule("47|29");
  rules.importPageOrderingRule("75|13");
  rules.importPageOrderingRule("53|13");
  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(true, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnTrueExampleTwo) {
  // Given
  auto* updates = new day5::PageUpdate("97,61,53,29,13");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("47|53");
  rules.importPageOrderingRule("97|13");
  rules.importPageOrderingRule("97|61");
  rules.importPageOrderingRule("97|47");
  rules.importPageOrderingRule("75|29");
  rules.importPageOrderingRule("61|13");
  rules.importPageOrderingRule("75|53");
  rules.importPageOrderingRule("29|13");
  rules.importPageOrderingRule("97|29");
  rules.importPageOrderingRule("53|29");
  rules.importPageOrderingRule("61|53");
  rules.importPageOrderingRule("97|53");
  rules.importPageOrderingRule("61|29");
  rules.importPageOrderingRule("47|13");
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("97|75");
  rules.importPageOrderingRule("47|61");
  rules.importPageOrderingRule("75|61");
  rules.importPageOrderingRule("47|29");
  rules.importPageOrderingRule("75|13");
  rules.importPageOrderingRule("53|13");

  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(true, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnTrueExampleThree) {
  // Given
  auto* updates = new day5::PageUpdate("75,29,13");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("47|53");
  rules.importPageOrderingRule("97|13");
  rules.importPageOrderingRule("97|61");
  rules.importPageOrderingRule("97|47");
  rules.importPageOrderingRule("75|29");
  rules.importPageOrderingRule("61|13");
  rules.importPageOrderingRule("75|53");
  rules.importPageOrderingRule("29|13");
  rules.importPageOrderingRule("97|29");
  rules.importPageOrderingRule("53|29");
  rules.importPageOrderingRule("61|53");
  rules.importPageOrderingRule("97|53");
  rules.importPageOrderingRule("61|29");
  rules.importPageOrderingRule("47|13");
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("97|75");
  rules.importPageOrderingRule("47|61");
  rules.importPageOrderingRule("75|61");
  rules.importPageOrderingRule("47|29");
  rules.importPageOrderingRule("75|13");
  rules.importPageOrderingRule("53|13");

  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(true, result);
}
TEST(PageUpdate_IsInCorrectOrder_Tests, ShouldReturnFalseExampleFour) {
  // Given
  auto* updates = new day5::PageUpdate("75,97,47,61,53");
  day5::PageOrderingRules rules = day5::PageOrderingRules();
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("47|53");
  rules.importPageOrderingRule("97|13");
  rules.importPageOrderingRule("97|61");
  rules.importPageOrderingRule("97|47");
  rules.importPageOrderingRule("75|29");
  rules.importPageOrderingRule("61|13");
  rules.importPageOrderingRule("75|53");
  rules.importPageOrderingRule("29|13");
  rules.importPageOrderingRule("97|29");
  rules.importPageOrderingRule("53|29");
  rules.importPageOrderingRule("61|53");
  rules.importPageOrderingRule("97|53");
  rules.importPageOrderingRule("61|29");
  rules.importPageOrderingRule("47|13");
  rules.importPageOrderingRule("75|47");
  rules.importPageOrderingRule("97|75");
  rules.importPageOrderingRule("47|61");
  rules.importPageOrderingRule("75|61");
  rules.importPageOrderingRule("47|29");
  rules.importPageOrderingRule("75|13");
  rules.importPageOrderingRule("53|13");

  // When
  bool result = updates->isInCorrectOrder(rules);
  // Then
  ASSERT_EQ(false, result);
}