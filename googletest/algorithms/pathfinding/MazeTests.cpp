//
// Created by perso on 16/12/2024.
//

#include <../../lib/googletest/include/gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../cpp/algorithms/pathfinding/Maze.h"
#include "../../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;

class MazeTests : public ::testing::Test {
private:
  string rawInputBasic =
    "####\n"
    "#.E#\n"
    "#..#\n"
    "#S.#\n"
    "####\n"
  ;
  protected:
  vector<string> inputBasic;

  // Setup after each
  void SetUp() override {
    inputBasic = InputUtils::convertToVector(rawInputBasic);
  }

  // TearDown after each test
  void TearDown() override {
    inputBasic.clear();
  }
};


TEST_F(MazeTests, ShouldInitializeMaze) {
  // Given
  // When
  Maze maze(inputBasic);
  // Then
  ASSERT_EQ(4, maze.getHorizontalLength());
  ASSERT_EQ(5, maze.getVerticalLength());
  EXPECT_FALSE(maze.isTileWalkable(0,0));
  EXPECT_FALSE(maze.isTileWalkable(1,0));
  EXPECT_FALSE(maze.isTileWalkable(2,0));
  EXPECT_FALSE(maze.isTileWalkable(3,0));
  EXPECT_FALSE(maze.isTileWalkable(0,1));
  EXPECT_TRUE(maze.isTileWalkable(1,1));
  EXPECT_TRUE(maze.isTileWalkable(2,1));
  EXPECT_FALSE(maze.isTileWalkable(3,1));
  EXPECT_FALSE(maze.isTileWalkable(0,2));
  EXPECT_TRUE(maze.isTileWalkable(1,2));
  EXPECT_TRUE(maze.isTileWalkable(2,2));
  EXPECT_FALSE(maze.isTileWalkable(3,2));
  EXPECT_FALSE(maze.isTileWalkable(0,3));
  EXPECT_TRUE(maze.isTileWalkable(1,3));
  EXPECT_TRUE(maze.isTileWalkable(2,3));
  EXPECT_FALSE(maze.isTileWalkable(3,3));
  EXPECT_FALSE(maze.isTileWalkable(0,4));
  EXPECT_FALSE(maze.isTileWalkable(1,4));
  EXPECT_FALSE(maze.isTileWalkable(2,4));
  EXPECT_FALSE(maze.isTileWalkable(3,4));
  ASSERT_EQ(core::Pair(1, 3), maze.getStartTile()->getPosition());
  ASSERT_EQ(core::Pair(2, 1), maze.getEndTile()->getPosition());
}

TEST_F(MazeTests, ShouldInitializePaths) {
  // Given
  // When
  Maze maze(inputBasic);
  // Then
  auto oneOne = maze.getTileInPosition(1,1);
  EXPECT_TRUE(oneOne != nullptr);
  ASSERT_EQ(core::Pair(2,1), oneOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,2), oneOne->getNeighbourNodes()[1]->getPosition());
  auto twoOne = maze.getTileInPosition(2,1);
  EXPECT_TRUE(twoOne != nullptr);
  ASSERT_EQ(core::Pair(2,2), twoOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,1), twoOne->getNeighbourNodes()[1]->getPosition());
  auto oneTwo = maze.getTileInPosition(1,2);
  EXPECT_TRUE(oneTwo != nullptr);
  ASSERT_EQ(core::Pair(1,1), oneTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,2), oneTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1,3), oneTwo->getNeighbourNodes()[2]->getPosition());
  auto twoTwo = maze.getTileInPosition(2,2);
  EXPECT_TRUE(twoTwo != nullptr);
  ASSERT_EQ(core::Pair(2,1), twoTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,3), twoTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1,2), twoTwo->getNeighbourNodes()[2]->getPosition());
  auto oneThree = maze.getTileInPosition(1,3);
  EXPECT_TRUE(oneThree != nullptr);
  ASSERT_EQ(core::Pair(1,2), oneThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,3), oneThree->getNeighbourNodes()[1]->getPosition());
  auto twoThree = maze.getTileInPosition(2,3);
  EXPECT_TRUE(twoThree != nullptr);
  ASSERT_EQ(core::Pair(2,2), twoThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,3), twoThree->getNeighbourNodes()[1]->getPosition());
}

