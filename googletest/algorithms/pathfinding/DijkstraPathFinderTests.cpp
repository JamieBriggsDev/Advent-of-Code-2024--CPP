//
// Created by Jamie Briggs on 18/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../cpp/algorithms/pathfinding/AStarPathFinder.h"
#include "../../../cpp/algorithms/pathfinding/DijkstraPathFinder.h"
#include "../../../cpp/algorithms/pathfinding/Maze.h"
#include "../../testHelper/InputUtils.h"

#include <unordered_set>


using namespace std;
using namespace solutions;
using namespace pathfinding;

class DijkstraPathFinderTestFixture : public ::testing::Test {
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

  string rawInputTwoPaths =
    "#####\n"
    "#..E#\n"
    "#.#.#\n"
    "#S..#\n"
    "#####\n"
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

string rawExampleTwo =
  "#################\n"
  "#...#...#...#..E#\n"
  "#.#.#.#.#.#.#.#.#\n"
  "#.#.#.#...#...#.#\n"
  "#.#.#.#.###.#.#.#\n"
  "#...#.#.#.....#.#\n"
  "#.#.#.#.#.#####.#\n"
  "#.#...#.#.#.....#\n"
  "#.#.#####.#.###.#\n"
  "#.#.#.......#...#\n"
  "#.#.###.#####.###\n"
  "#.#.#...#.....#.#\n"
  "#.#.#.#####.###.#\n"
  "#.#.#.........#.#\n"
  "#.#.#.#########.#\n"
  "#S#.............#\n"
  "#################\n"
  ;
protected:
  vector<string> inputEasyStartFinish;
  vector<string> inputModerateStartFinish;
  vector<string> inputTwoPaths;
  vector<string> inputLargerStartFinish;
  vector<string> inputLargerStartFinishExampleTwo;
  DijkstraPathFinder* pathFinder;

  // Setup after each
  void SetUp() override {
    pathFinder = new DijkstraPathFinder();
    inputEasyStartFinish = InputUtils::convertToVector(rawInputBasic);
    inputModerateStartFinish = InputUtils::convertToVector(rawInputHigherBasic);
    inputLargerStartFinish = InputUtils::convertToVector(rawInputLargeExample);
    inputTwoPaths = InputUtils::convertToVector(rawInputTwoPaths);
    inputLargerStartFinishExampleTwo = InputUtils::convertToVector(rawExampleTwo);
  }

  // TearDown after each test
  void TearDown() override {
    inputEasyStartFinish.clear();
    inputModerateStartFinish.clear();
    inputLargerStartFinish.clear();
    inputTwoPaths.clear();
    inputLargerStartFinishExampleTwo.clear();
  }
};

TEST_F(DijkstraPathFinderTestFixture, ShouldFindWithCostOne) {
  // Given
  Maze simpleMaze = Maze(inputEasyStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile(), true);
  // Then
  EXPECT_EQ(1, result.cost);
  EXPECT_EQ(2, result.path.size());
}

TEST_F(DijkstraPathFinderTestFixture, ShouldFindWithCost274) {
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

TEST_F(DijkstraPathFinderTestFixture, ShouldFindWithCost7036) {
  // Given
  Maze simpleMaze = Maze(inputLargerStartFinish);
  // When
  auto result = pathFinder->findPath(simpleMaze.getStartTile(), simpleMaze.getEndTile(), true);
  simpleMaze.printMaze(result);
  // Then
  EXPECT_EQ(7036, result.cost);
}

TEST_F(DijkstraPathFinderTestFixture, ShouldFindMultiplePaths) {
  // Given
  Maze simpleMaze = Maze(inputTwoPaths);
  // When
  auto result = pathFinder->findPaths(simpleMaze.getStartTile(), simpleMaze.getEndTile());
  // Then
  EXPECT_EQ(2, result.size());
}

TEST_F(DijkstraPathFinderTestFixture, ShouldFindMultiplePathsExampleOne) {
  // Given
  Maze maze = Maze(inputLargerStartFinish);
  // When
  auto result = pathFinder->findPaths(maze.getStartTile(), maze.getEndTile());
  // Then
  EXPECT_EQ(3, result.size());


  std::unordered_set<core::Pair> visited;
  vector<vector<bool>> paths(maze.getHorizontalLength(), std::vector<bool>(maze.getVerticalLength(), false));
  for (auto path : result) {
    while (!path.path.empty()) {
      visited.emplace(path.path.top()->getPosition());
      paths[path.path.top()->getPosition().x][path.path.top()->getPosition().y] = true;
      path.path.pop();
    }
  }

  cout << endl;
  for (int y = 0; y < maze.getVerticalLength(); y++) {
    for (int x = 0; x < maze.getHorizontalLength(); x++) {
      if (paths[x][y]) {
        cout << "O";
      } else {
        if (maze.getWalls()[y][x]) {
          cout << "#";
        }
        else {
          cout << ".";
        }
      }
    }
    cout << endl;
  }
}

TEST_F(DijkstraPathFinderTestFixture, DISABLED_ShouldFindMultiplePathsExampleTwo) {
  // Given
  Maze maze = Maze(inputLargerStartFinishExampleTwo);
  // When
  auto result = pathFinder->findPaths(maze.getStartTile(), maze.getEndTile());
  // Then
  EXPECT_EQ(3, result.size());


  std::unordered_set<core::Pair> visited;
  vector<vector<bool>> paths(maze.getHorizontalLength(), std::vector<bool>(maze.getVerticalLength(), false));
  for (auto path : result) {
    while (!path.path.empty()) {
      visited.emplace(path.path.top()->getPosition());
      paths[path.path.top()->getPosition().x][path.path.top()->getPosition().y] = true;
      path.path.pop();
    }
  }

  cout << endl;
  for (int y = 0; y < maze.getVerticalLength(); y++) {
    for (int x = 0; x < maze.getHorizontalLength(); x++) {
      if (paths[x][y]) {
        cout << "O";
      } else {
        if (maze.getWalls()[y][x]) {
          cout << "#";
        }
        else {
          cout << ".";
        }
      }
    }
    cout << endl;
  }
}