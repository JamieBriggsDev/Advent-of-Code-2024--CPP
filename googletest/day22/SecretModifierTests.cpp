//
// Created by Jamie Briggs on 22/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day22/SecretModifier.h"

TEST(SecretModifierTests, ShouldMixValues) {
  // Given
  long long secret = 42l;
  long long value = 15l;
  // When
  long long result = solutions::SecretModifier::mixValue(value, secret);
  // Then
  ASSERT_EQ(37, result);
}

TEST(SecretModifierTests, ShouldPruneValues) {
  // Given
  long long secret = 100000000l;
  // When
  long long result = solutions::SecretModifier::pruneValue(secret);
  // Then
  ASSERT_EQ(16113920l, result);
}