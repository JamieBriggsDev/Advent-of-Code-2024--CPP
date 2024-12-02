//
// Created by Jamie Briggs on 01/12/2024.
//

#include "../../cpp/core/Pair.h"
#include "../../cpp/day1/Day01PairBuilder.h"

#include <gtest/gtest.h>

using namespace solutions;

TEST(Day01PairBuilder_Tests, ShouldAddToListOne)
{
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListOne(5);
  // Then
  std::vector<int> result = builder->getListOne();
  EXPECT_EQ(true, result[0] == 5);
}

TEST(Day01PairBuilder_Tests, ShouldAddToListTwo)
{
  // Given
  auto* builder = new Day01PairBuilder();
  // When
  builder->addToListTwo(7);
  // Then
  std::vector<int> result = builder->getListTwo();
  EXPECT_EQ(true, result[0] == 7);
}

TEST(Day01PairBuilder_Tests, ShouldAddToBothLists)
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

TEST(Day01PairBuilder_Tests, ShouldCreateQueue) {
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

TEST(Day01PairBuilder_Tests, ShouldCreateQueueWithTwoValues) {
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

TEST(Day01PairBuilder_Tests, ShouldCreateQueueInNumericalOrder) {
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

TEST(Day01PairBuilder_Tests, ShouldCreateAndReturnEmptyDictionary) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When I do nothing
  // Then
  std::unordered_map<int, int> result = builder->getListTwoQuantities();
  EXPECT_EQ(true, result.empty());
}

TEST(Day01PairBuilder_Tests, ShouldCreateAndReturnDictionaryWithOneItem) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When I do nothing
  builder->addToListTwo(2);
  // Then
  std::unordered_map<int, int> result = builder->getListTwoQuantities();
  EXPECT_EQ(1, result.size());
  EXPECT_EQ(1, result[2]);
}

TEST(Day01PairBuilder_Tests, ShouldCreateAndReturnDictionaryWithTwoItems) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When I do nothing
  builder->addToListTwo(2);
  builder->addToListTwo(3);
  // Then
  std::unordered_map<int, int> result = builder->getListTwoQuantities();
  EXPECT_EQ(2, result.size());
  EXPECT_EQ(1, result[2]);
  EXPECT_EQ(1, result[3]);
}

TEST(Day01PairBuilder_Tests, ShouldCreateAndReturnDictionaryWithTwoItemsButDuplicates) {
  // Given
  auto* builder = new Day01PairBuilder();
  // When I do nothing
  builder->addToListTwo(2);
  builder->addToListTwo(3);
  builder->addToListTwo(2);
  // Then
  std::unordered_map<int, int> result = builder->getListTwoQuantities();
  EXPECT_EQ(2, result.size());
  EXPECT_EQ(2, result[2]);
  EXPECT_EQ(1, result[3]);
}