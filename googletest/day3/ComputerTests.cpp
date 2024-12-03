//
// Created by Jamie Briggs on 03/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day3/Computer.h"

TEST(Computer_Tests, ShouldCreateComputerWithNoCommands) {
  // Given
  auto* computer = new Computer();
  // When
  // Then
  EXPECT_FALSE(computer->containsAnyCommands());
}

TEST(Computer_Tests, ShouldCreateComputerWithNoCommandsWhenNoneExist) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("abc");
  // Then
  EXPECT_FALSE(computer->containsAnyCommands());
}

TEST(Computer_Tests, ShouldCreateComputerWithOneMultiplyCommand) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(1, computer->totalCommands());
  EXPECT_EQ(MultiplyCommand(1,2), computer->peekNextCommand());
}

TEST(Computer_Tests, ShouldCreateComputerWithTwoMultiplyCommands) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)mul(3,4)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(2, computer->totalCommands());
  EXPECT_EQ(MultiplyCommand(1,2), computer->popNextCommand());
  EXPECT_EQ(MultiplyCommand(3,4), computer->popNextCommand());
}
TEST(Computer_Tests, ShouldCreateComputerWithTwoMultiplyCommandsAndMispeltString) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)ml(4,5mul(3,4)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(2, computer->totalCommands());
  EXPECT_EQ(MultiplyCommand(1,2), computer->popNextCommand());
  EXPECT_EQ(MultiplyCommand(3,4), computer->popNextCommand());
}
TEST(Computer_Tests, ShouldCreateComputerWithExampleMemory) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(4, computer->totalCommands());
  EXPECT_EQ(MultiplyCommand(2,4), computer->popNextCommand());
  EXPECT_EQ(MultiplyCommand(5,5), computer->popNextCommand());
  EXPECT_EQ(MultiplyCommand(11,8), computer->popNextCommand());
  EXPECT_EQ(MultiplyCommand(8,5), computer->popNextCommand());
}