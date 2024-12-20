//
// Created by Jamie Briggs on 20/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../../cpp/algorithms/pathfinding/Maze.h"
#include "../../cpp/day20/RaceTrack.h"
#include "../../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;
using namespace pathfinding;

class RaceTrackTests : public ::testing::Test {
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


TEST_F(RaceTrackTests, ShouldInitializeMaze) {
  // Given
  // When
  RaceTrack raceTrack(inputBasic);
  // Then
  ASSERT_EQ(4, raceTrack.getHorizontalLength());
  ASSERT_EQ(5, raceTrack.getVerticalLength());
  EXPECT_FALSE(raceTrack.isTileWalkable(0,0));
  EXPECT_FALSE(raceTrack.isTileWalkable(1,0));
  EXPECT_FALSE(raceTrack.isTileWalkable(2,0));
  EXPECT_FALSE(raceTrack.isTileWalkable(3,0));
  EXPECT_FALSE(raceTrack.isTileWalkable(0,1));
  EXPECT_TRUE(raceTrack.isTileWalkable(1,1));
  EXPECT_TRUE(raceTrack.isTileWalkable(2,1));
  EXPECT_FALSE(raceTrack.isTileWalkable(3,1));
  EXPECT_FALSE(raceTrack.isTileWalkable(0,2));
  EXPECT_TRUE(raceTrack.isTileWalkable(1,2));
  EXPECT_TRUE(raceTrack.isTileWalkable(2,2));
  EXPECT_FALSE(raceTrack.isTileWalkable(3,2));
  EXPECT_FALSE(raceTrack.isTileWalkable(0,3));
  EXPECT_TRUE(raceTrack.isTileWalkable(1,3));
  EXPECT_TRUE(raceTrack.isTileWalkable(2,3));
  EXPECT_FALSE(raceTrack.isTileWalkable(3,3));
  EXPECT_FALSE(raceTrack.isTileWalkable(0,4));
  EXPECT_FALSE(raceTrack.isTileWalkable(1,4));
  EXPECT_FALSE(raceTrack.isTileWalkable(2,4));
  EXPECT_FALSE(raceTrack.isTileWalkable(3,4));
  ASSERT_EQ(core::Pair(1, 3), raceTrack.getStartTile()->getPosition());
  ASSERT_EQ(core::Pair(2, 1), raceTrack.getEndTile()->getPosition());
}

TEST_F(RaceTrackTests, ShouldInitializePaths) {
  // Given
  // When
  RaceTrack raceTrack(inputBasic);
  // Then
  auto oneOne = raceTrack.getTileInPosition(1,1);
  EXPECT_TRUE(oneOne != nullptr);
  ASSERT_EQ(core::Pair(2,1), oneOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,2), oneOne->getNeighbourNodes()[1]->getPosition());
  auto twoOne = raceTrack.getTileInPosition(2,1);
  EXPECT_TRUE(twoOne != nullptr);
  ASSERT_EQ(core::Pair(2,2), twoOne->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,1), twoOne->getNeighbourNodes()[1]->getPosition());
  auto oneTwo = raceTrack.getTileInPosition(1,2);
  EXPECT_TRUE(oneTwo != nullptr);
  ASSERT_EQ(core::Pair(1,1), oneTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,2), oneTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1,3), oneTwo->getNeighbourNodes()[2]->getPosition());
  auto twoTwo = raceTrack.getTileInPosition(2,2);
  EXPECT_TRUE(twoTwo != nullptr);
  ASSERT_EQ(core::Pair(2,1), twoTwo->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,3), twoTwo->getNeighbourNodes()[1]->getPosition());
  ASSERT_EQ(core::Pair(1,2), twoTwo->getNeighbourNodes()[2]->getPosition());
  auto oneThree = raceTrack.getTileInPosition(1,3);
  EXPECT_TRUE(oneThree != nullptr);
  ASSERT_EQ(core::Pair(1,2), oneThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(2,3), oneThree->getNeighbourNodes()[1]->getPosition());
  auto twoThree = raceTrack.getTileInPosition(2,3);
  EXPECT_TRUE(twoThree != nullptr);
  ASSERT_EQ(core::Pair(2,2), twoThree->getNeighbourNodes()[0]->getPosition());
  ASSERT_EQ(core::Pair(1,3), twoThree->getNeighbourNodes()[1]->getPosition());
}

