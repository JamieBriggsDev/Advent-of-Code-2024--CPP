//
// Created by Jamie Briggs on 05/12/2024.
//


#include <gtest/gtest.h>

#include "../../cpp/day5/PageOrderingRules.h"

using namespace day5;

TEST(PageOrderingRules_ImportPageOrderingRule_Tests, ShouldLoadARule) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  // When
  pageOrderingRules->importPageOrderingRule("47|53");
  // Then
  bool secondNumberIsInFirstNumberAfter = pageOrderingRules->getRules()[47].pagesAfter.contains(53);
  bool secondNumberIsInFirstNumberBefore = pageOrderingRules->getRules()[47].pagesBefore.contains(53);
  bool firstNumberIsInSecondNumberBefore = pageOrderingRules->getRules()[53].pagesBefore.contains(47);
  bool firstNumberIsInSecondNumberAfter = pageOrderingRules->getRules()[53].pagesAfter.contains(47);

  ASSERT_EQ(true, secondNumberIsInFirstNumberAfter);
  ASSERT_EQ(false, secondNumberIsInFirstNumberBefore);
  ASSERT_EQ(true, firstNumberIsInSecondNumberBefore);
  ASSERT_EQ(false, firstNumberIsInSecondNumberAfter);
}

TEST(PageOrderingRules_IsSubjectNumberAfterTargetNumber_Tests, ShouldBeTrue) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberAfterTargetNumber(47, 53);
  // Then
  ASSERT_EQ(true, result);
}

TEST(PageOrderingRules_IsSubjectNumberAfterTargetNumber_Tests, ShouldBeFalse) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberAfterTargetNumber(53, 47);
  // Then
  ASSERT_EQ(false, result);
}

TEST(PageOrderingRules_IsSubjectNumberAfterTargetNumber_Tests, ShouldBeFalseIfSubjectDontExist) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberAfterTargetNumber(50, 47);
  // Then
  ASSERT_EQ(false, result);
}

TEST(PageOrderingRules_IsSubjectNumberAfterTargetNumber_Tests, ShouldBeFalseIfTargetDontExist) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberAfterTargetNumber(53, 50);
  // Then
  ASSERT_EQ(false, result);
}
TEST(PageOrderingRules_IsSubjectNumberBeforeTargetNumber_Tests, ShouldBeTrue) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberBeforeTargetNumber(53, 47);
  // Then
  ASSERT_EQ(true, result);
}

TEST(PageOrderingRules_IsSubjectNumberBeforeTargetNumber_Tests, ShouldBeFalse) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberBeforeTargetNumber(47, 53);
  // Then
  ASSERT_EQ(false, result);
}

TEST(PageOrderingRules_IsSubjectNumberBeforeTargetNumber_Tests, ShouldBeFalseIfSubjectDontExist) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberBeforeTargetNumber(50, 53);
  // Then
  ASSERT_EQ(false, result);
}

TEST(PageOrderingRules_IsSubjectNumberBeforeTargetNumber_Tests, ShouldBeFalseIfTargetDontExist) {
  // Given
  auto* pageOrderingRules = new PageOrderingRules();
  pageOrderingRules->importPageOrderingRule("47|53");
  // When
  bool result = pageOrderingRules->isSubjectNumberBeforeTargetNumber(47, 50);
  // Then
  ASSERT_EQ(false, result);
}

