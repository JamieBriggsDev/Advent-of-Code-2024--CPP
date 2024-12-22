//
// Created by Jamie Briggs on 22/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day22/BananaSellingUtil.h"

TEST(BananaSellingUtil_GetLasDigitNumber_Tests, ShouldReturnCorrectValueA) {
  // Given
  long long input = 5;
  // When
  int result = solutions::BananaSellingUtil::getLastDigitNumber(input);
  // Then
  ASSERT_EQ(5, result);
}

TEST(BananaSellingUtil_GetLasDigitNumber_Tests, ShouldReturnCorrectValueB) {
  // Given
  long long input = 23;
  // When
  int result = solutions::BananaSellingUtil::getLastDigitNumber(input);
  // Then
  ASSERT_EQ(3, result);
}

TEST(BananaSellingUtil_GetLasDigitNumber_Tests, ShouldReturnCorrectValueC) {
  // Given
  long long input = 5000000000007;
  // When
  int result = solutions::BananaSellingUtil::getLastDigitNumber(input);
  // Then
  ASSERT_EQ(7, result);
}

TEST(BananaSellingUtil_GetDifferenceBetweenTwoNumbers_Tests, ShouldReturnCorrectValueA) {
  // Given;
  // When
  int result = solutions::BananaSellingUtil::getDifferenceBetweenTwoNumbers(5, 5);
  // Then
  ASSERT_EQ(0, result);
}

TEST(BananaSellingUtil_GetDifferenceBetweenTwoNumbers_Tests, ShouldFindDifferentOfZero) {
  // Given;
  // When
  int result = solutions::BananaSellingUtil::getDifferenceBetweenTwoNumbers(5, 5);
  // Then
  ASSERT_EQ(0, result);
}

TEST(BananaSellingUtil_GetDifferenceBetweenTwoNumbers_Tests, ShouldFindPositiveDifference) {
  // Given;
  // When
  int result = solutions::BananaSellingUtil::getDifferenceBetweenTwoNumbers(5, 8);
  // Then
  ASSERT_EQ(3, result);
}

TEST(BananaSellingUtil_GetDifferenceBetweenTwoNumbers_Tests, ShouldFindNegativeDifference) {
  // Given;
  // When
  int result = solutions::BananaSellingUtil::getDifferenceBetweenTwoNumbers(5, 4);
  // Then
  ASSERT_EQ(-1, result);
}