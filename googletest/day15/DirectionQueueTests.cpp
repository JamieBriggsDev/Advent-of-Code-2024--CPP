//
// Created by Jamie Briggs on 15/12/2024.
//

#include <gtest/gtest.h>
#include <queue>
#include <string>
#include <vector>

#include "../../cpp/day15/DirectionQueue.h"
#include "../testHelper/InputUtils.h"

using namespace std;

TEST(DirectionQueue_Tests, ShouldInitializeWithNorth) {
  // Given
  std::string rawInput = "^";
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(1, directionSize.size());
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
}

TEST(DirectionQueue_Tests, ShouldInitializeWithEast) {
  // Given
  std::string rawInput = ">";
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(1, directionSize.size());
  ASSERT_EQ(core::Orientation::EAST, directionSize.peekNext());
}

TEST(DirectionQueue_Tests, ShouldInitializeWithSouth) {
  // Given
  std::string rawInput = "v";
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(1, directionSize.size());
  ASSERT_EQ(core::Orientation::SOUTH, directionSize.peekNext());
}

TEST(DirectionQueue_Tests, ShouldInitializeWithWest) {
  // Given
  std::string rawInput = "<";
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(1, directionSize.size());
  ASSERT_EQ(core::Orientation::WEST, directionSize.peekNext());
}

TEST(DirectionQueue_Tests, ShouldInitializeWithNorthEastSouthWest) {
  // Given
  std::string rawInput = "^>v<";
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(4, directionSize.size());
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::EAST, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::SOUTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::WEST, directionSize.peekNext());
  directionSize.pop();
}

TEST(DirectionQueue_Tests, ShouldInitializeWithThreeRows) {
  // Given
  std::string rawInput =
    "^>v<\n"
    "<v>^\n"
    "^^^^\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::DirectionQueue directionSize(input);
  // Then
  ASSERT_EQ(12, directionSize.size());
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::EAST, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::SOUTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::WEST, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::WEST, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::SOUTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::EAST, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
  ASSERT_EQ(core::Orientation::NORTH, directionSize.peekNext());
  directionSize.pop();
}