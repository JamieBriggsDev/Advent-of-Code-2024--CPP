//
// Created by perso on 15/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/core/Orientation.h"
#include "../../cpp/day15/Box.h"
#include "../../cpp/day15/Robot.h"
#include "../../cpp/day15/Wall.h"
#include "../../cpp/day15/Warehouse.h"
#include "../testHelper/InputUtils.h"

using namespace std;

class WarehouseTestFixture : public ::testing::Test {
  protected:
    void SetUp() override {
      // Setup
      input = InputUtils::convertToVector(rawInput);
      secondInput = InputUtils::convertToVector(rawSecondInput);
    }

  void TearDown() override {
      // Tear down
      input.clear();
      secondInput.clear();
    }

  /*
   *For the bigger example!
  *
    "################\n"
    "##....[]..[]..##\n"
    "####@...[]....##\n"
    "##......[]....##\n"
    "##..##..[]....##\n"
    "##......[]....##\n"
    "##............##\n"
    "################\n";
   */
  string rawInput =
    "########\n"
    "#..O.O.#\n"
    "##@.O..#\n"
    "#...O..#\n"
    "#.#.O..#\n"
    "#...O..#\n"
    "#......#\n"
    "########";
  vector<string> input;

  /**
    ##############
    ##......##..##
    ##..........##
    ##....[][]@.##
    ##....[]....##
    ##..........##
    ##############
   */
  string rawSecondInput =
    "#######\n"
    "#...#.#\n"
    "#.....#\n"
    "#..OO@#\n"
    "#..O..#\n"
    "#.....#\n"
    "#######";
  vector<string> secondInput;
};

TEST_F(WarehouseTestFixture, ShouldInitializeWarehouseWalls) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(8, warehouse.getHorizontalLength());
  // Check for walls
  // North Wall
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][7]) != nullptr);
  // Middle Walls
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][7]) != nullptr);
  // South Wall
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][7]) != nullptr);
  // Weird Wals
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][2]) != nullptr);

}

TEST_F(WarehouseTestFixture, ShouldInitializeWarehouseBoxes) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(8, warehouse.getHorizontalLength());
  // Check for boxes
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][4]) != nullptr);
}


TEST_F(WarehouseTestFixture, ShouldInitializeRobot) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(8, warehouse.getHorizontalLength());
  // Check for boxes
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 2), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotRight) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false, true);
  // When
  warehouse.moveRobot(core::Orientation::EAST);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][3]) != nullptr);
  EXPECT_EQ(core::Pair(3, 2), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotUp) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // When
  warehouse.moveRobot(core::Orientation::NORTH);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[1][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 1), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotDown) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // When
  warehouse.moveRobot(core::Orientation::SOUTH);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[3][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 3), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldNotMoveRobotLeftDueToWall) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // When
  warehouse.moveRobot(core::Orientation::WEST);
  // Then
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 2 ), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldNotMoveRobotAndBoxUpDueToWall) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false, true);
  // When
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::NORTH);
  // Then
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][3]) != nullptr);
  EXPECT_EQ(core::Pair(3, 2 ), warehouse.getRobot()->getPosition());
  // Box still hasn't moved
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][3]) != nullptr);
  // Wall still there
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][3]) != nullptr);

}

TEST_F(WarehouseTestFixture, ShouldMoveRobotUpThenMoveBoxRight) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false);
  // When
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::EAST);
  // Then
  EXPECT_EQ(core::Pair(3, 1), warehouse.getRobot()->getPosition());
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[1][3]) != nullptr);
  // Box should have moved
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][4]) != nullptr);
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotUpThenMoveTwoBoxesRight) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false, true);
  // When
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  // Then
  EXPECT_EQ(core::Pair(4, 1), warehouse.getRobot()->getPosition());
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[1][4]) != nullptr);
  // Twp boxes should have moved
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][6]) != nullptr);
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotUpThenMoveTwoBoxesRightButStopOnThirdMoveRight) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false, true);
  // When
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  // Then
  EXPECT_EQ(core::Pair(4, 1), warehouse.getRobot()->getPosition());
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[1][4]) != nullptr);
  // Twp boxes should have moved
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][6]) != nullptr);
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotFullExample) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, false, true);
  // When
  //<^^>>>vv<v>>v<<
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::EAST);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::WEST);
  // Then
  EXPECT_EQ(core::Pair(4, 4), warehouse.getRobot()->getPosition());
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[4][4]) != nullptr);
  // Boxes should be in correct location
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[6][4]) != nullptr);
}

TEST_F(WarehouseTestFixture, ShouldInitializeWiderWarehouseWalls) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, true, false);
  warehouse.printWarehouseLayout();
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(16, warehouse.getHorizontalLength());
  // Check for walls

  // North Wall
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][8]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][9]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][10]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][11]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][12]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][13]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[0][15]) != nullptr);
  // Middle Walls
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[1][15]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][15]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[3][15]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][15]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[5][15]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[6][15]) != nullptr);
  // South Wall
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][8]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][9]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][10]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][11]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][12]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][13]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][14]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[7][15]) != nullptr);
  // Weird Walls
  /*
   *For the bigger example!
  *
    "################\n"
    "##....[]..[]..##\n"
    "####@...[]....##\n"
    "##......[]....##\n"
    "##..##..[]....##\n"
    "##......[]....##\n"
    "##............##\n"
    "################\n";
   */
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[2][3]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][4]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Wall*>(warehouse.getGrid()[4][5]) != nullptr);
}

TEST_F(WarehouseTestFixture, ShouldInitializeWiderWarehouseBoxes) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, true);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(16, warehouse.getHorizontalLength());
  // Check for boxes
  /*
   *For the bigger example!
  *
    "################\n"
    "##....[]..[]..##\n"
    "####@...[]....##\n"
    "##......[]....##\n"
    "##..##..[]....##\n"
    "##......[]....##\n"
    "##............##\n"
    "################\n";
   */
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][6]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][6])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][7]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][7])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][10]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][10])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][11]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[1][11])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][9]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][9])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][9]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][9])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][8])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][9]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][9])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][8])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][9]) != nullptr);
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][9])->getBoxSide());
}


TEST_F(WarehouseTestFixture, ShouldInitializeWiderRobot) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input, true, false);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(16, warehouse.getHorizontalLength());
  // Check for robot
  /*
   *For the bigger example!
  *
    "################\n"
    "##....[]..[]..##\n"
    "####@...[]....##\n"
    "##......[]....##\n"
    "##..##..[]....##\n"
    "##......[]....##\n"
    "##............##\n"
    "################\n";
   */
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][4]) != nullptr);
  EXPECT_EQ(core::Pair(4, 2), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldInitializeBiggerExample) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(secondInput, true, false);
  // Then
  ASSERT_EQ(7, warehouse.getVerticalLength());
  ASSERT_EQ(14, warehouse.getHorizontalLength());
  // Check for robot
  /*
   *For the bigger example!
    ##############
    ##......##..##
    ##..........##
    ##....[][]@.##
    ##....[]....##
    ##..........##
    ##############
   */
  // Robot location
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[3][10]) != nullptr);
  EXPECT_EQ(core::Pair(10, 3), warehouse.getRobot()->getPosition());
  // Box locations
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][9]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][9])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][7]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][6])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][7])->getBoxSide());
}

TEST_F(WarehouseTestFixture, ShouldMoveBiggerBoxesLeft) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(secondInput, true, true);
  // When
  warehouse.moveRobot(core::Orientation::WEST);
  /*
   *Should end like this
    ##############
    ##......##..##
    ##..........##
    ##...[][]@..##
    ##....[]....##
    ##..........##
    ##############
   */
  // Then
  ASSERT_EQ(7, warehouse.getVerticalLength());
  ASSERT_EQ(14, warehouse.getHorizontalLength());
  // Check for robot
  // Robot location
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[3][9]) != nullptr);
  EXPECT_EQ(core::Pair(9, 3), warehouse.getRobot()->getPosition());
  // Box locations
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][5])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][8])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][7]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][6])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[4][7])->getBoxSide());
}

TEST_F(WarehouseTestFixture, ShouldMoveBiggerBoxesUpPartial) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(secondInput, true, true);
  // When <vv<<^^
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::NORTH);
  /*
   *Should end like this
    ##############
    ##......##..##
    ##...[][]...##
    ##....[]....##
    ##.....@....##
    ##..........##
    ##############
   */
  // Then
  ASSERT_EQ(7, warehouse.getVerticalLength());
  ASSERT_EQ(14, warehouse.getHorizontalLength());
  // Check for robot
  // Robot location
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[4][7]) != nullptr);
  EXPECT_EQ(core::Pair(7, 4), warehouse.getRobot()->getPosition());
  // Box locations
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][6]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][5])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][6])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][7])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8])->getBoxSide());
}

TEST_F(WarehouseTestFixture, ShouldMoveBiggerBoxesUpPartialBlockedByWall) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(secondInput, true, true);
  // When <vv<<^^
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::SOUTH);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::WEST);
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::NORTH);
  warehouse.moveRobot(core::Orientation::NORTH);
  /*
   *Should end like this
    ##############
    ##......##..##
    ##...[][]...##
    ##....[]....##
    ##.....@....##
    ##..........##
    ##############
   */
  // Then
  ASSERT_EQ(7, warehouse.getVerticalLength());
  ASSERT_EQ(14, warehouse.getHorizontalLength());
  // Check for robot
  // Robot location
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[4][7]) != nullptr);
  EXPECT_EQ(core::Pair(7, 4), warehouse.getRobot()->getPosition());
  // Box locations
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][6])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[3][7])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][5]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][6]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][5])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][6])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][7]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][7])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[2][8])->getBoxSide());
}

TEST_F(WarehouseTestFixture, BiggerExamples) {
  // Given
  std::string biggerInputRaw =
    "####################\n"
    "##[]..[][]..[]..[]##\n"
    "##[]..........[]..##\n"
    "##.........@[][][]##\n"
    "##........[]..[]..##\n"
    "##..##[]..[]......##\n"
    "##...[].......[]..##\n"
    "##.....[]..[].[][]##\n"
    "##........[]......##\n"
    "####################";
  std::vector<std::string> biggerInput = InputUtils::convertToVector(biggerInputRaw);
  // Setting wider to false here, as I've already made the input wide..
  solutions::Warehouse warehouse = solutions::Warehouse(biggerInput, false, true);
  // When
  warehouse.moveRobot(core::SOUTH);
  // Then
  // Check two boxes have moved
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][10]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][11]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][10])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[5][11])->getBoxSide());
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[6][10]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Box*>(warehouse.getGrid()[6][11]) != nullptr);
  EXPECT_EQ(core::Orientation::WEST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[6][10])->getBoxSide());
  EXPECT_EQ(core::Orientation::EAST, dynamic_cast<warehouse::Box*>(warehouse.getGrid()[6][11])->getBoxSide());
}