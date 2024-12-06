//
// Created by Jamie Briggs on 06/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day6/LabGrid.h"
#include "../testHelper/InputUtils.h"

using namespace day6;

TEST(LabGuard_GetNextPosition_Tests, ShouldReturnNorthernPosition) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  // When
  core::Pair result = guard->getNextPosition();
  // Then
  // Y goes lower for north
  ASSERT_EQ(1, result.x);
  ASSERT_EQ(0, result.y);
  // Ensure not modifying old values
  ASSERT_EQ(1, guard->x);
  ASSERT_EQ(1, guard->y);
}

TEST(LabGuard_GetNextPosition_Tests, ShouldReturnEasternPosition) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  guard->orientation = core::EAST;
  // When
  core::Pair result = guard->getNextPosition();
  // Then
  ASSERT_EQ(2, result.x);
  ASSERT_EQ(1, result.y);
  // Ensure not modifying old values
  ASSERT_EQ(1, guard->x);
  ASSERT_EQ(1, guard->y);
}

TEST(LabGuard_GetNextPosition_Tests, ShouldReturnSouthernPosition) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  guard->orientation = core::SOUTH;
  // When
  core::Pair result = guard->getNextPosition();
  // Then
  ASSERT_EQ(1, result.x);
  ASSERT_EQ(2, result.y);
  // Ensure not modifying old values
  ASSERT_EQ(1, guard->x);
  ASSERT_EQ(1, guard->y);
}

TEST(LabGuard_GetNextPosition_Tests, ShouldReturnWesternPosition) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  guard->orientation = core::WEST;
  // When
  core::Pair result = guard->getNextPosition();
  // Then
  ASSERT_EQ(0, result.x);
  ASSERT_EQ(1, result.y);
  // Ensure not modifying old values
  ASSERT_EQ(1, guard->x);
  ASSERT_EQ(1, guard->y);
}


TEST(LabGuard_GetAdjacentPositions_Tests, ShouldReturnAllAdjacentPositions) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  // When
  std::vector<core::Pair> result = guard->getAdjacentPositions();
  // Then
  ASSERT_EQ(core::Pair(1, 0), result[0]);
  ASSERT_EQ(core::Pair(2, 1), result[1]);
  ASSERT_EQ(core::Pair(1, 2), result[2]);
  ASSERT_EQ(core::Pair(0, 1), result[3]);
}


TEST(LabGuard_GetAdjacentPositions_Tests, ShouldReturnAllAdjacentPositionsButNotIncludeStartingPosition) {
  // Given
  auto* guard = new day6::LabGuard(1, 1);
  guard->x = 2;
  guard->y = 1;
  // When
  std::vector<core::Pair> result = guard->getAdjacentPositions();
  // Then
  ASSERT_EQ(3, result.size());
  ASSERT_EQ(core::Pair(2, 0), result[0]);
  ASSERT_EQ(core::Pair(3, 1), result[1]);
  ASSERT_EQ(core::Pair(2, 2), result[2]);
}



