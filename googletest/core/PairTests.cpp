//
// Created by Jamie Briggs on 01/12/2024.
//

#include "../../cpp/core/Pair.h"

#include <gtest/gtest.h>

using namespace core;

TEST(PairTest, ShouldReturnDistanceOfZero)
{
  // Given
  Pair myPair(0,0);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(0, result);
}

TEST(PairTest, ShouldReturnDistanceOfFiveWhenFirstValueSmaller)
{
  // Given
  Pair myPair(0,5);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(5, result);
}


TEST(PairTest, ShouldReturnDistanceOfFiveWhenSecondValueSmaller)
{
  // Given
  Pair myPair(5,0);
  // When
  int result = myPair.distance();
  // Then
  EXPECT_EQ(5, result);
}
