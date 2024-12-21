//
// Created by Jamie Briggs on 16/12/2024.
//

#include <../../lib/googletest/include/gtest/gtest.h>
#include <string>
#include <vector>

#include "../../../cpp/algorithms/pathfinding/Maze.h"
#include "../../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;
using namespace pathfinding;

class MazeTests : public ::testing::Test {
private:
  string rawInputBasic = "####\n"
                         "#.E#\n"
                         "#..#\n"
                         "#S.#\n"
                         "####\n";

  string rawSquare = "...\n"
                     ".#.\n"
                     "...\n";

  string rawCornerWall =
                     "..\n"
                     "#.\n";

  string rawOpenPlan = "...\n"
                       "...\n"
                       "...\n";

protected:
  vector<string> inputBasic;
  vector<string> inputSquare;
  vector<string> inputCornerWall;
  vector<string> inputOpen;

  // Setup after each
  void SetUp() override {
    inputBasic = InputUtils::convertToVector(rawInputBasic);
    inputSquare = InputUtils::convertToVector(rawSquare);
    inputCornerWall = InputUtils::convertToVector(rawCornerWall);
    inputOpen = InputUtils::convertToVector(rawOpenPlan);
  }

  // TearDown after each test
  void TearDown() override {
    inputSquare.clear();
    inputBasic.clear();
    inputOpen.clear();
    inputCornerWall.clear();
  }
};


TEST_F(MazeTests, ShouldInitializeMaze) {
  // Given
  // When
  Maze maze(inputBasic);
  // Then
  ASSERT_EQ(4, maze.getHorizontalLength());
  ASSERT_EQ(5, maze.getVerticalLength());
  EXPECT_FALSE(maze.isTileWalkable(0, 0));
  EXPECT_FALSE(maze.isTileWalkable(1, 0));
  EXPECT_FALSE(maze.isTileWalkable(2, 0));
  EXPECT_FALSE(maze.isTileWalkable(3, 0));
  EXPECT_FALSE(maze.isTileWalkable(0, 1));
  EXPECT_TRUE(maze.isTileWalkable(1, 1));
  EXPECT_TRUE(maze.isTileWalkable(2, 1));
  EXPECT_FALSE(maze.isTileWalkable(3, 1));
  EXPECT_FALSE(maze.isTileWalkable(0, 2));
  EXPECT_TRUE(maze.isTileWalkable(1, 2));
  EXPECT_TRUE(maze.isTileWalkable(2, 2));
  EXPECT_FALSE(maze.isTileWalkable(3, 2));
  EXPECT_FALSE(maze.isTileWalkable(0, 3));
  EXPECT_TRUE(maze.isTileWalkable(1, 3));
  EXPECT_TRUE(maze.isTileWalkable(2, 3));
  EXPECT_FALSE(maze.isTileWalkable(3, 3));
  EXPECT_FALSE(maze.isTileWalkable(0, 4));
  EXPECT_FALSE(maze.isTileWalkable(1, 4));
  EXPECT_FALSE(maze.isTileWalkable(2, 4));
  EXPECT_FALSE(maze.isTileWalkable(3, 4));
  ASSERT_EQ(core::Pair(1, 3), maze.getStartTile()->getPosition());
  ASSERT_EQ(core::Pair(2, 1), maze.getEndTile()->getPosition());
}

TEST_F(MazeTests, ShouldInitializePaths) {
  // Given
  // When
  Maze maze(inputBasic);
  // Then
  auto oneOne = maze.getTileInPosition(1, 1);
  EXPECT_TRUE(oneOne != nullptr);
  ASSERT_EQ(core::Pair(2, 1), oneOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1, 2), oneOne->getNeighbourNodes()[1]->getPosition());
  auto twoOne = maze.getTileInPosition(2, 1);
  EXPECT_TRUE(twoOne != nullptr);
  ASSERT_EQ(core::Pair(2, 2), twoOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1, 1), twoOne->getNeighbourNodes()[1]->getPosition());
  auto oneTwo = maze.getTileInPosition(1, 2);
  EXPECT_TRUE(oneTwo != nullptr);
  ASSERT_EQ(core::Pair(1, 1), oneTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2, 2), oneTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1, 3), oneTwo->getNeighbourNodes()[2]->getPosition());
  auto twoTwo = maze.getTileInPosition(2, 2);
  EXPECT_TRUE(twoTwo != nullptr);
  ASSERT_EQ(core::Pair(2, 1), twoTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2, 3), twoTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1, 2), twoTwo->getNeighbourNodes()[2]->getPosition());
  auto oneThree = maze.getTileInPosition(1, 3);
  EXPECT_TRUE(oneThree != nullptr);
  ASSERT_EQ(core::Pair(1, 2), oneThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2, 3), oneThree->getNeighbourNodes()[1]->getPosition());
  auto twoThree = maze.getTileInPosition(2, 3);
  EXPECT_TRUE(twoThree != nullptr);
  ASSERT_EQ(core::Pair(2, 2), twoThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1, 3), twoThree->getNeighbourNodes()[1]->getPosition());
}

/*TEST_F(MazeTests, ShouldMakeWallWalkable) {
  // Given
  Maze maze(inputSquare);
  // When
  maze.makeTileWalkable(1,1);
  // Then
  auto middle = maze.getTileInPosition(1,1);
  ASSERT_TRUE(middle->getIsWalkable());
  ASSERT_EQ(4, middle->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(2, 1)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(1, 2)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(0, 1)->getNeighbourNodes().size());
}

TEST_F(MazeTests, ShouldMakeWallWalkableThenUnwalkable) {
  // Given
  Maze maze(inputSquare);
  maze.makeTileWalkable(1,1);
  // Check was made walkable first
  ASSERT_TRUE(maze.getTileInPosition(1,1)->getIsWalkable());
  ASSERT_EQ(4, maze.getTileInPosition(1,1)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(2, 1)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(1, 2)->getNeighbourNodes().size());
  ASSERT_EQ(3, maze.getTileInPosition(0, 1)->getNeighbourNodes().size());

  // When
  maze.makeTileUnwalkable(1,1);
  auto middle = maze.getTileInPosition(1,1);
  ASSERT_FALSE(middle->getIsWalkable());
  ASSERT_EQ(0, middle->getNeighbourNodes().size());
  ASSERT_EQ(2, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  ASSERT_TRUE(maze.getTileInPosition(1, 0)->getIsWalkable());
  ASSERT_EQ(2, maze.getTileInPosition(2, 1)->getNeighbourNodes().size());
  ASSERT_TRUE(maze.getTileInPosition(2, 1)->getIsWalkable());
  ASSERT_EQ(2, maze.getTileInPosition(1, 2)->getNeighbourNodes().size());
  ASSERT_TRUE(maze.getTileInPosition(1, 2)->getIsWalkable());
  ASSERT_EQ(2, maze.getTileInPosition(0, 1)->getNeighbourNodes().size());
  ASSERT_TRUE(maze.getTileInPosition(0, 1)->getIsWalkable());
}

TEST_F(MazeTests, ShouldKeepWalkableTileWalkable) {
  // Given
  Maze maze(inputSquare);
  maze.makeTileWalkable(0,0);
  maze.makeTileUnwalkable(0,0);
  // When
  ASSERT_TRUE(maze.getTileInPosition(0,0)->getIsWalkable());
}

TEST_F(MazeTests, ShouldMakeWallWalkableCorner) {
  // Given
  Maze maze(inputCornerWall);
  // When         ..
  // Bottom Left  #.
  maze.makeTileWalkable(0,1);
  // Then
  auto corner = maze.getTileInPosition(0,1);
  ASSERT_TRUE(corner->getIsWalkable());
  ASSERT_EQ(2, corner->getNeighbourNodes().size());
  // North of wall
  ASSERT_EQ(2, maze.getTileInPosition(0, 0)->getNeighbourNodes().size());
  // Not next to corner but check anyways
  ASSERT_EQ(2, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  // East of wall
  ASSERT_EQ(2, maze.getTileInPosition(1, 1)->getNeighbourNodes().size());
}

TEST_F(MazeTests, ShouldMakeWallWalkableCornerThenUnwalkable) {
  // Given
  Maze maze(inputCornerWall);
  maze.makeTileWalkable(0,1);
  ASSERT_TRUE(maze.getTileInPosition(0,1)->getIsWalkable());
  ASSERT_EQ(2, maze.getTileInPosition(0,1)->getNeighbourNodes().size());
  ASSERT_EQ(2, maze.getTileInPosition(0, 0)->getNeighbourNodes().size());
  ASSERT_EQ(2, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  ASSERT_EQ(2, maze.getTileInPosition(1, 1)->getNeighbourNodes().size());

  // When
  maze.makeTileUnwalkable(0,1);
  // Then
  auto corner = maze.getTileInPosition(0,1);
  ASSERT_FALSE(corner->getIsWalkable());
  ASSERT_EQ(0, corner->getNeighbourNodes().size());
  // North of wall
  ASSERT_EQ(1, maze.getTileInPosition(0, 0)->getNeighbourNodes().size());
  // Not next to corner but check anyways
  ASSERT_EQ(2, maze.getTileInPosition(1, 0)->getNeighbourNodes().size());
  // East of wall
  ASSERT_EQ(1, maze.getTileInPosition(1, 1)->getNeighbourNodes().size());
}*/