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

  string rawInputLargeExample =
    "###############\n"
    "#.......#....E#\n"
    "#.#.###.#.###.#\n"
    "#.....#.#...#.#\n"
    "#.###.#####.#.#\n"
    "#.#.#.......#.#\n"
    "#.#.#####.###.#\n"
    "#...........#.#\n"
    "###.#.#####.#.#\n"
    "#...#.....#.#.#\n"
    "#.#.#.###.#.#.#\n"
    "#.....#...#.#.#\n"
    "#.###.#.#.#.#.#\n"
    "#S..#.....#...#\n"
    "###############\n"
  ;
protected:
  vector<string> inputEasyStartFinish;
  vector<string> inputModerateStartFinish;
  vector<string> inputLargerStartFinish;
  core::PathFinder* pathFinder;

  // Setup after each
  void SetUp() override {
    pathFinder = new pathfinding::AStarPathFinder();
    inputEasyStartFinish = InputUtils::convertToVector(rawInputBasic);
    inputModerateStartFinish = InputUtils::convertToVector(rawInputHigherBasic);
    inputLargerStartFinish = InputUtils::convertToVector(rawInputLargeExample);
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
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile(), true);
  // Then
  EXPECT_EQ(1, result.cost);
  EXPECT_EQ(2, result.path.size());
}

TEST_F(AStarPathFinderTestFixture, ShouldFindWithCost274) {
  // Given
  Maze simpleMaze = Maze(inputModerateStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile(), true);
  // Then
  EXPECT_EQ(1003, result.cost);
  EXPECT_EQ(4, result.path.size());
  EXPECT_EQ(core::Pair(1,3), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,3), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,2), result.path.top()->getPosition());
  result.path.pop();
  EXPECT_EQ(core::Pair(2,1), result.path.top()->getPosition());
}

TEST_F(AStarPathFinderTestFixture, ShouldFindWithCost7036) {
  // Given
  Maze simpleMaze = Maze(inputLargerStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile(), true);
  simpleMaze.printMaze(result);
  // Then
  EXPECT_EQ(7036, result.cost);
}
