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
    }

  void TearDown() override {
      // Tear down
      input.clear();
    }

  string rawInput =
    "########\n"
    "#..O.O.#\n"
    "##@.O..#\n"
    "#...O..#\n"
    "#.#.O..#\n"
    "#...O..#\n"
    "#......#\n"
    "########\n";
  vector<string> input;
};

TEST_F(WarehouseTestFixture, ShouldInitializeWarehouseWalls) {
  // Given
  // When
  solutions::Warehouse warehouse = solutions::Warehouse(input);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input);
  // Then
  ASSERT_EQ(8, warehouse.getVerticalLength());
  ASSERT_EQ(8, warehouse.getHorizontalLength());
  // Check for boxes
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 2), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotRight) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input, true);
  // When
  warehouse.moveRobot(core::Orientation::EAST);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][3]) != nullptr);
  EXPECT_EQ(core::Pair(3, 2), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotUp) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input);
  // When
  warehouse.moveRobot(core::Orientation::NORTH);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[1][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 1), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldMoveRobotDown) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input);
  // When
  warehouse.moveRobot(core::Orientation::SOUTH);
  // Then
  EXPECT_FALSE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[3][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 3), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldNotMoveRobotLeftDueToWall) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input);
  // When
  warehouse.moveRobot(core::Orientation::WEST);
  // Then
  EXPECT_TRUE(dynamic_cast<warehouse::Robot*>(warehouse.getGrid()[2][2]) != nullptr);
  EXPECT_EQ(core::Pair(2, 2 ), warehouse.getRobot()->getPosition());
}

TEST_F(WarehouseTestFixture, ShouldNotMoveRobotAndBoxUpDueToWall) {
  // Given
  solutions::Warehouse warehouse = solutions::Warehouse(input);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input, true);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input, true);
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
  solutions::Warehouse warehouse = solutions::Warehouse(input, true);
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
