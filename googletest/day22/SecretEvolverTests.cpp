//
// Created by Jamie Briggs on 22/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day22/SecretEvolver.h"

TEST(SecretEvolverTests, ShouldEvolveNumberOnce) {
  // Given
  constexpr long long secret = 123l;
  // When
  const auto result = solutions::SecretEvolver::evolveSecret(secret);
  // Then
  ASSERT_EQ(15887950l, result);
}

TEST(SecretEvolverTests, ShouldEvolveNumberTwice) {
  // Given
  long long secret = 123l;
  // When
  for(int i = 0; i < 2; i++) {
    secret = solutions::SecretEvolver::evolveSecret(secret);
  }
  // Then
  ASSERT_EQ(16495136l, secret);
}

TEST(SecretEvolverTests, ShouldEvolveNumberFiveTimes) {
  // Given
  long long secret = 123l;
  // When
  for(int i = 0; i < 5; i++) {
    secret = solutions::SecretEvolver::evolveSecret(secret);
  }
  // Then
  ASSERT_EQ(1553684l, secret);
}

TEST(SecretEvolverTests, ShouldEvolveNumber2000Times) {
  // Given
  long long secret = 1l;
  // When
  for(int i = 0; i < 2000; i++) {
    secret = solutions::SecretEvolver::evolveSecret(secret);
  }
  // Then
  ASSERT_EQ(8685429l, secret);
}