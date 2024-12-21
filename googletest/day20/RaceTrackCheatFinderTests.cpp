//
// Created by Jamie Briggs on 20/12/2024.
//


#include "../../cpp/day20/RaceTrackCheatFinder.h"


#include <gtest/gtest.h>
#include <string>
#include <unordered_set>
#include <vector>
#include "../../../cpp/algorithms/pathfinding/Maze.h"
#include "../../cpp/day20/RaceTrack.h"
#include "../../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;
using namespace pathfinding;

class RaceTrackCheatFinderTests : public ::testing::Test {

  string rawInputBasicCheatInput = "...\n"
                                   ".#.\n"
                                   ".#.\n"
                                   "S#E\n"
                                   "###\n";

protected:
  vector<string> inputBasicCheat;

  // Setup after each
  void SetUp() override {
    inputBasicCheat = InputUtils::convertToVector(rawInputBasicCheatInput);
  }

  // TearDown after each test
  void TearDown() override {
    inputBasicCheat.clear();
  }
};


TEST_F(RaceTrackCheatFinderTests, ShouldReturnAllPossibleCheatSolutionsBasic) {
  // Given
  RaceTrack raceTrack(inputBasicCheat);
  // When
  auto result = RaceTrackCheatFinder::findCheats(raceTrack);
  // Then
  // Find the cheapest cheat
  RaceTrackCheat cheapestSolution(INT_MAX, INT_MAX);
  for (auto cheat : result) {
    if (cheat.totalCost < cheapestSolution.totalCost) {
      cheapestSolution = cheat;
    }
  }
  ASSERT_EQ(2, cheapestSolution.totalCost);
  ASSERT_EQ(6, cheapestSolution.savedTime);
  ASSERT_EQ(6, result.size());
}