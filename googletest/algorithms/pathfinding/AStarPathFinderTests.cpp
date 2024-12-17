//
// Created by perso on 16/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../cpp/algorithms/pathfinding/AStarPathFinder.h"
#include "../../../cpp/day16/Maze.h"
#include "../../testHelper/InputUtils.h"


using namespace std;
using namespace solutions;

class AStarPathFinderTestFixture : public ::testing::Test {
  string rawInputBasic =
    "####\n"
    "#SE#\n"
    "####\n"
  ;

  string rawInputHigherBasic =
    "####\n"
    "#.E#\n"
    "#..#\n"
    "#S.#\n"
    "####\n"
  ;
protected:
  vector<string> inputEasyStartFinish;
  vector<string> inputModerateStartFinish;
  core::PathFinder* pathFinder;

  // Setup after each
  void SetUp() override {
    pathFinder = new pathfinding::AStarPathFinder();
    inputEasyStartFinish = InputUtils::convertToVector(rawInputBasic);
    inputModerateStartFinish = InputUtils::convertToVector(rawInputHigherBasic);
  }

  // TearDown after each test
  void TearDown() override {
    inputEasyStartFinish.clear();
    inputModerateStartFinish.clear();
  }
};

TEST_F(AStarPathFinderTestFixture, ShouldFindWithCostOne) {
  // Given
  Maze simpleMaze = Maze(inputEasyStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile());
  // Then
  EXPECT_EQ(1, result.cost);
  EXPECT_EQ(2, result.path.size());
}

TEST_F(AStarPathFinderTestFixture, ShouldFindWithCost274) {
  // Given
  Maze simpleMaze = Maze(inputModerateStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile());
  // Then
  // TODO: This won't actually be 3, it will be 274 (rotate 3 times = 90 * 3)
  EXPECT_EQ(3, result.cost);
  EXPECT_EQ(4, result.path.size());
  EXPECT_EQ(core::Pair(1,3), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,3), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,2), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,1), result.path.top()->getPosition());
}
