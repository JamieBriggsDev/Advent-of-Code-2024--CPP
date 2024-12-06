//
// Created by Jamie Briggs on 06/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day6/LabGrid.h"
#include "../../cpp/day6/LabEntity.h"
#include "../testHelper/InputUtils.h"


TEST(LabGrid_Initialize_Tests, ShouldCreateEmptyRow) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("....");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
}

TEST(LabGrid_Initialize_Tests, ShouldCreateTwoEmptyRows) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("....\n....");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][3]);
}

TEST(LabGrid_Initialize_Tests, ShouldCreateRowWithObstacle) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("..#.");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_TRUE(dynamic_cast<day6::LabObstacle *>(grid.getGrid()[0][2]) != nullptr);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
}

TEST(LabGrid_Initialize_Tests, ShouldCreateRowWithGuard) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("..^.");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_TRUE(dynamic_cast<day6::LabGuard *>(grid.getGrid()[0][2]) != nullptr);
  ASSERT_EQ(core::Orientation::NORTH, dynamic_cast<day6::LabGuard *>(grid.getGrid()[0][2])->orientation);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
}

TEST(LabGrid_Initialize_Tests, ShouldCreateTwoRowsWithObstacles) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("..#.\n#..#");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(nullptr, grid.getGrid()[0][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][1]);
  ASSERT_NE(nullptr, grid.getGrid()[0][2]);
  ASSERT_EQ(nullptr, grid.getGrid()[0][3]);
  ASSERT_NE(nullptr, grid.getGrid()[1][0]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][1]);
  ASSERT_EQ(nullptr, grid.getGrid()[1][2]);
  ASSERT_NE(nullptr, grid.getGrid()[1][3]);
}

TEST(LabGrid_ContainsObstacle_Tests, ShouldReturnCorrectValues) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("..#.\n#..#");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(false, grid.containsObstacle(0, 0));
  ASSERT_EQ(false, grid.containsObstacle(1, 0));
  ASSERT_EQ(true, grid.containsObstacle(2, 0));
  ASSERT_EQ(false, grid.containsObstacle(3, 0));
  ASSERT_EQ(true, grid.containsObstacle(0, 1));
  ASSERT_EQ(false, grid.containsObstacle(1, 1));
  ASSERT_EQ(false, grid.containsObstacle(2, 1));
  ASSERT_EQ(true, grid.containsObstacle(3, 1));
}

TEST(LabGrid_ContainsObstacle_Tests, ShouldDetectTemporaryObstacle) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector("....\n....");
  // When
  auto grid = day6::LabGrid(rawInput);
  grid.setTemporaryObstruction(1,1);
  // Then
  ASSERT_EQ(false, grid.containsObstacle(0, 0));
  ASSERT_EQ(false, grid.containsObstacle(1, 0));
  ASSERT_EQ(false, grid.containsObstacle(2, 0));
  ASSERT_EQ(false, grid.containsObstacle(3, 0));
  ASSERT_EQ(false, grid.containsObstacle(0, 1));
  ASSERT_EQ(true, grid.containsObstacle(1, 1));
  ASSERT_EQ(false, grid.containsObstacle(2, 1));
  ASSERT_EQ(false, grid.containsObstacle(3, 1));
}

TEST(LabGrid_ContainsObstacle_Tests, ShouldReturnFalseIfGuard) {
  // Given
  std::vector<std::string> rawInput = InputUtils::convertToVector(".#^.");
  // When
  auto grid = day6::LabGrid(rawInput);
  // Then
  ASSERT_EQ(false, grid.containsObstacle(0, 0));
  ASSERT_EQ(true, grid.containsObstacle(1, 0));
  ASSERT_EQ(false, grid.containsObstacle(2, 0));
  ASSERT_EQ(false, grid.containsObstacle(3, 0));
}


TEST(LabGrid_MoveGuard_Tests, GaurdShouldNotMove) {
  // Given
  std::string input =
    ".\n"
    ".\n"
    "^\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  // When
  //  Don't move
  // Then
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(2, grid.getGuard()->y);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveOnce) {
  // Given
  std::string input =
    ".\n"
    ".\n"
    "^\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftArea = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftArea);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(1, grid.getGuard()->y);
  ASSERT_EQ(2l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[1][0]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[2][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveTwice) {
  // Given
  std::string input =
    ".\n"
    ".\n"
    "^\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_FALSE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(3l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[2][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveRight) {
  // Given
  std::string input =
    "^.."
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::EAST;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(1, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(2l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][1]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveRightTwice) {
  // Given
  std::string input =
    "^.."
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::EAST;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_FALSE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(2, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(3l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][2]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveSouthOnce) {
  // Given
  std::string input =
    "^\n"
    ".\n"
    ".\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::SOUTH;
  // When
  bool hasLeftArea = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftArea);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(1, grid.getGuard()->y);
  ASSERT_EQ(2l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[1][0]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveSouthTwice) {
  // Given
  std::string input =
    "^\n"
    ".\n"
    ".\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::SOUTH;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_FALSE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(2, grid.getGuard()->y);
  ASSERT_EQ(3l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[2][0]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveLeft) {
  // Given
  std::string input =
    "..^"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::WEST;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(1, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(2l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][1]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][2]) != nullptr);
}

TEST(LabGrid_MoveGuard_Tests, GuardShouldMoveLeftTwice) {
  // Given
  std::string input =
    "..^"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::WEST;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_FALSE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(3l, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][2]) != nullptr);
}

TEST(LabGrid_MoveGuard_Rotate_Tests, GuardShouldRotateNorthToEast) {
  // Given
  std::string input =
    "#.\n"
    "^.\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::NORTH;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(1, grid.getGuard()->y);
  ASSERT_EQ(1, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[1][0]) != nullptr);
  ASSERT_EQ(guard->orientation, core::EAST);
}

TEST(LabGrid_MoveGuard_Rotate_Tests, GuardShouldRotateEastToSouth) {
  // Given
  std::string input =
    "^#\n"
    "..\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::EAST;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(1, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][0]) != nullptr);
  ASSERT_EQ(guard->orientation, core::SOUTH);
}

TEST(LabGrid_MoveGuard_Rotate_Tests, GuardShouldRotateSouthToWest) {
  // Given
  std::string input =
    ".^\n"
    ".#\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::SOUTH;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(1, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(1, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][1]) != nullptr);
  ASSERT_EQ(guard->orientation, core::WEST);
}

TEST(LabGrid_MoveGuard_Rotate_Tests, GuardShouldRotateWestToNorth) {
  // Given
  std::string input =
    "..\n"
    "#^\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::WEST;
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(1, grid.getGuard()->x);
  ASSERT_EQ(1, grid.getGuard()->y);
  ASSERT_EQ(1, grid.getGuard()->totalPositionVisits());
  // Check grid information
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[1][1]) != nullptr);
  ASSERT_EQ(guard->orientation, core::NORTH);
}

TEST(LabGrid_MoveGuard_LeftArea_Tests, GuardShouldNotLeaveArea) {
  // Given
  std::string input =
    "..\n"
    "^.\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftOne = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  // Check guard information
  ASSERT_EQ(0, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(2, grid.getGuard()->totalPositionVisits());
}

TEST(LabGrid_MoveGuard_LeftArea_Tests, GuardShouldLeaveAreaNorth) {
  // Given
  std::string input =
    "..\n"
    "^.\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_TRUE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(2, grid.getGuard()->totalPositionVisits());
}

TEST(LabGrid_MoveGuard_LeftArea_Tests, GuardShouldLeaveAreaEast) {
  // Given
  std::string input =
    "^.\n"
    "..\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::EAST;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_TRUE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(2, grid.getGuard()->totalPositionVisits());
}

TEST(LabGrid_MoveGuard_LeftArea_Tests, GuardShouldLeaveAreaSouth) {
  // Given
  std::string input =
    ".^\n"
    "..\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::SOUTH;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_TRUE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(2, grid.getGuard()->totalPositionVisits());
}

TEST(LabGrid_MoveGuard_LeftArea_Tests, GuardShouldLeaveAreaWest) {
  // Given
  std::string input =
    ".^\n"
    "..\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::WEST;
  // When
  bool hasLeftOne = grid.moveGuard();
  bool hasLeftTwo = grid.moveGuard();
  // Then
  ASSERT_FALSE(hasLeftOne);
  ASSERT_TRUE(hasLeftTwo);
  // Check guard information
  ASSERT_EQ(2, grid.getGuard()->totalPositionVisits());
}

TEST(LabGrid_Reset_Tests, GridShouldReset) {
  // Given
  std::string input =
    "#..^\n"
    "....\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  guard->orientation = core::WEST;
  // When
  grid.setTemporaryObstruction(1, 1);
  bool moveOne = grid.moveGuard();
  bool moveTwo = grid.moveGuard();
  grid.resetState();
  // Then
  ASSERT_FALSE(moveOne);
  ASSERT_FALSE(moveTwo);
  // Guard should be reset
  ASSERT_EQ(1, grid.getGuard()->totalPositionVisits());
  ASSERT_EQ(3, grid.getGuard()->x);
  ASSERT_EQ(0, grid.getGuard()->y);
  ASSERT_EQ(3, grid.getGuard()->startX);
  ASSERT_EQ(0, grid.getGuard()->startY);
  ASSERT_EQ(core::NORTH, grid.getGuard()->orientation);
  // Guard should be on correct position in grid
  ASSERT_TRUE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][3]));
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][2]));
  ASSERT_FALSE(dynamic_cast<day6::LabGuard*>(grid.getGrid()[0][1]));
  ASSERT_TRUE(dynamic_cast<day6::LabObstacle*>(grid.getGrid()[0][0]));
  // Temporary obstacle should be removed
  ASSERT_FALSE(grid.containsObstacle(1, 1));
  // Remove history of obstacles
  ASSERT_EQ(0, grid.getObstaclesRunInto().size());

}

TEST(LabGrid_DetectLoop, ShouldNotDetectLoop) {
  // Given
  std::string input =
    ".#....\n"
    ".....#\n"
    "......\n"
    "......\n"
    "......\n"
    ".^..#.\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_FALSE(hasFoundLoop);
  ASSERT_TRUE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoop) {
  // Given
  std::string input =
    ".#....\n"
    ".....#\n"
    "......\n"
    "......\n"
    "#.....\n"
    ".^..#.\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleOne) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#.0^...+.\n"
      "........#.\n"
      "#.........\n"
      "......#...\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(3, 6);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleTwo) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#..^...+.\n"
      "......0.#.\n"
      "#.........\n"
      "......#...\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(6, 7);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleThree) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#..^...+.\n"
      ".......0#.\n"
      "#.........\n"
      "......#...\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(7, 7);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleFour) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#..^...+.\n"
      "........#.\n"
      "#0........\n"
      "......#...\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(1, 8);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleFive) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#..^...+.\n"
      "........#.\n"
      "#..0......\n"
      "......#...\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(3, 8);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 10000) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}

TEST(LabGrid_DetectLoop, ShouldDetectLoopExampleSix) {
  // Given
  std::string input =
      "....#.....\n"
      ".........#\n"
      "..........\n"
      "..#.......\n"
      ".......#..\n"
      "..........\n"
      ".#..^...+.\n"
      "........#.\n"
      "#.........\n"
      "......#0..\n"
  ;
  std::vector<std::string> rawInput = InputUtils::convertToVector(input);
  auto grid = day6::LabGrid(rawInput);
  day6::LabGuard* guard = grid.getGuard();
  // When
  grid.setTemporaryObstruction(7, 9);
  bool hasLeftMap = false;
  bool hasFoundLoop = false;
  int count = 0; // In case test fails
  while(!hasLeftMap && !hasFoundLoop && count < 100) {
    hasLeftMap = grid.moveGuard();
    hasFoundLoop = grid.loopDetected();
    count++;
  }
  // Then
  ASSERT_TRUE(hasFoundLoop);
  ASSERT_FALSE(hasLeftMap);
}
