//
// Created by Jamie Briggs on 01/12/2024.
//

#include "../../cpp/core/Pair.h"
#include "../../cpp/day1/Day01PairBuilder.h"

#include <gtest/gtest.h>

using namespace solutions;

TEST(Day01PairBuilder, ShouldAddToListOne)
{
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(5);
  // Then
  std::vector<int> result = builder->getListOne();
  EXPECT_EQ(true, result[0] == 5);
}

TEST(Day01PairBuilder, ShouldAddToListTwo)
{
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListTwo(7);
  // Then
  std::vector<int> result = builder->getListTwo();
  EXPECT_EQ(true, result[0] == 7);
}

TEST(Day01PairBuilder, ShouldAddToBothLists)
{
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(3);
  builder->addToListTwo(7);
  // Then
  std::vector<int> result = builder->getListOne();
  std::vector<int> resultTwo = builder->getListTwo();
  EXPECT_EQ(true, result[0] == 3);
  EXPECT_EQ(true, resultTwo[0] == 7);
}

TEST(Day01PairBuilder, ShouldCreateQueue) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(3);
  builder->addToListTwo(7);
  // Then
  std::queue<core::Pair> result = builder->getPairs();
  EXPECT_EQ(true, result.size() == 1);
  EXPECT_EQ(true, result.front() == core::Pair(3,7));
}

TEST(Day01PairBuilder, ShouldCreateQueueWithTwoValues) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(1);
  builder->addToListOne(2);
  builder->addToListTwo(3);
  builder->addToListTwo(4);
  // Then
  std::queue<core::Pair> result = builder->getPairs();
  EXPECT_EQ(true, result.size() == 2);
  EXPECT_EQ(core::Pair(1,3), result.front());
  result.pop();
  EXPECT_EQ(core::Pair(2,4), result.front());
}

TEST(Day01PairBuilder, ShouldCreateQueueInNumericalOrder) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(2);
  builder->addToListOne(1);
  builder->addToListTwo(4);
  builder->addToListTwo(3);
  // Then
  std::queue<core::Pair> result = builder->getPairs();
  EXPECT_EQ(true, result.size() == 2);
  EXPECT_EQ(core::Pair(1,3), result.front());
  result.pop();
  EXPECT_EQ(core::Pair(2,4), result.front());
}