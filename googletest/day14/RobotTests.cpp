//
// Created by Jamie Briggs on 14/12/2024.
//

#include <gtest/gtest.h>
#include <string>

#include "../../cpp/day14/Robot.h"

TEST(Robot_ShouldInitialize_Tests, ShouldInitializeRobot) {
  // Given
  std::string input = "p=0,4 v=3,-3";
  // When
  solutions::Robot robot(input);
  // Then
  EXPECT_EQ(core::Pair(0,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(0,4), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(3,-3), robot.getVelocity());
}


TEST(Robot_ShouldMove_Tests, ShouldNotMoveDueToEmptyVelocity) {
  // Given
  std::string input = "p=0,4 v=0,0";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(0,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(0,4), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(0,0), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveOneStep) {
  // Given
  std::string input = "p=0,4 v=1,1";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(0,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(1,5), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(1,1), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveMultipleSteps) {
  // Given
  std::string input = "p=0,4 v=1,1";
  solutions::Robot robot(input);
  // When
  robot.move();
  robot.move();
  robot.move();
  robot.move();
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(0,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(5,9), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(1,1), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveNE) {
  // Given
  std::string input = "p=2,4 v=53,-12";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(55,-8), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(53,-12), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveSE) {
  // Given
  std::string input = "p=2,4 v=43,12";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(45,16), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(43,12), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveSW) {
  // Given
  std::string input = "p=2,4 v=-62,12";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(-60,16), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(-62,12), robot.getVelocity());
}

TEST(Robot_ShouldMove_Tests, ShouldShouldMoveNW) {
  // Given
  std::string input = "p=2,4 v=-32,-34";
  solutions::Robot robot(input);
  // When
  robot.move();
  // Then
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(-30,-30), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(-32,-34), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldDoNothingIfWithinRange) {
  // Given
  std::string input = "p=2,4 v=0,0";
  solutions::Robot robot(input);
  // When
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(false, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(2,4), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(0,0), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldDoNothingIfWithinRangeAfterMove) {
  // Given
  std::string input = "p=2,4 v=50,50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(false, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(52,54), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(50,50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfXTooLarge) {
  // Given
  std::string input = "p=2,4 v=150,50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(51,54), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(150,50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfXTooLargeTwo) {
  // Given
  std::string input = "p=2,4 v=300,50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(100,54), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(300,50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfXLessThanZero) {
  // Given
  std::string input = "p=2,4 v=-50,50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(53,54), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(-50,50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfXLessThanZeroTwo) {
  // Given
  std::string input = "p=2,4 v=-150,50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(54,54), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(-150,50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfYTooLarge) {
  // Given
  std::string input = "p=2,4 v=50,150";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(52,51), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(50,150), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfYTooLargeTwo) {
  // Given
  std::string input = "p=2,4 v=50,300";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(52,98), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(50,300), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfYLessThanZero) {
  // Given
  std::string input = "p=2,4 v=50,-50";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(52,57), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(50,-50), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfYLessThanZeroTwo) {
  // Given
  std::string input = "p=2,4 v=50,-150";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(52,60), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(50,-150), robot.getVelocity());
}

TEST(Robot_ShouldTeleport_Tests, ShouldTeleportIfBothXYTooLarge) {
  // Given
  std::string input = "p=2,4 v=300,300";
  solutions::Robot robot(input);
  // When
  robot.move();
  bool result = robot.teleportIfOutOfRange(101, 103);
  // Then
  EXPECT_EQ(true, result);
  EXPECT_EQ(core::Pair(2,4), robot.getInitialPosition());
  EXPECT_EQ(core::Pair(100,98), robot.getCurrentPosition());
  EXPECT_EQ(core::Pair(300,300), robot.getVelocity());
}


TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleSmallGrid) {
  // Given
  std::string input = "p=1,1 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(3, 3);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleLargerGrid) {
  // Given
  std::string input = "p=50,51 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(101, 103);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleTop) {
  // Given
  std::string input = "p=0,51 v=0,0";
  solutions::Robot robot(input);
  // When
  core::Orientation result = robot.whichQuadrant(101, 103);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleRight) {
  // Given
  std::string input = "p=50,0 v=0,0";
  solutions::Robot robot(input);
  // When
  core::Orientation result = robot.whichQuadrant(101, 103);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleBottom) {
  // Given
  std::string input = "p=50,103 v=0,0";
  solutions::Robot robot(input);
  // When
  core::Orientation result = robot.whichQuadrant(101, 103);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNoWhereWhenMiddleLeft) {
  // Given
  std::string input = "p=0,51 v=0,0";
  solutions::Robot robot(input);
  // When
  core::Orientation result = robot.whichQuadrant(101, 103);
  // Then
  EXPECT_EQ(core::NOWHERE, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNESmallGrid) {
  // Given
  std::string input = "p=2,0 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(3, 3);
  // Then
  EXPECT_EQ(core::NORTH_EAST, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeSESmallGrid) {
  // Given
  std::string input = "p=2,2 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(3, 3);
  // Then
  EXPECT_EQ(core::SOUTH_EAST, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeSWSmallGrid) {
  // Given
  std::string input = "p=0,2 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(3, 3);
  // Then
  EXPECT_EQ(core::SOUTH_WEST, result);
}

TEST(Robot_WhichQuadrant_Tests, ShouldBeNWSmallGrid) {
  // Given
  std::string input = "p=0,0 v=0,0";
  solutions::Robot robot(input);
  // When (3x3 grid)
  core::Orientation result = robot.whichQuadrant(3, 3);
  // Then
  EXPECT_EQ(core::NORTH_WEST, result);
}