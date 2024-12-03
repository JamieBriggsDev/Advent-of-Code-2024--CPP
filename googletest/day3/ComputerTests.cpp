//
// Created by Jamie Briggs on 03/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day3/Computer.h"
#include "../../cpp/day3/DoInstruction.h"
#include "../../cpp/day3/DontInstruction.h"

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

TEST(Computer_Mul_Tests, ShouldCreateComputerWithOneMultiplyCommand) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(1, computer->totalCommands());
  const auto * result = dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(1, result->getX());
  EXPECT_EQ(2, result->getY());
}

TEST(Computer_Mul_Tests, ShouldCreateComputerWithTwoMultiplyCommands) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)mul(3,4)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(2, computer->totalCommands());
  const auto * resultOne= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(1, resultOne->getX());
  EXPECT_EQ(2, resultOne->getY());
  const auto * resultTwo= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(3, resultTwo->getX());
  EXPECT_EQ(4, resultTwo->getY());
}
TEST(Computer_Mul_Tests, ShouldCreateComputerWithTwoMultiplyCommandsAndMispeltString) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("mul(1,2)ml(4,5mul(3,4)");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(2, computer->totalCommands());
  const auto * resultOne= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(1, resultOne->getX());
  EXPECT_EQ(2, resultOne->getY());
  const auto * resultTwo= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(3, resultTwo->getX());
  EXPECT_EQ(4, resultTwo->getY());
}
TEST(Computer_Mul_Tests, ShouldCreateComputerWithExampleMemory) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(4, computer->totalCommands());
  const auto* resultOne= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(2, resultOne->getX());
  EXPECT_EQ(4, resultOne->getY());
  const auto* resultTwo= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(5, resultTwo->getX());
  EXPECT_EQ(5, resultTwo->getY());
  const auto* resultThree= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(11, resultThree->getX());
  EXPECT_EQ(8, resultThree->getY());
  const auto* resultFour= dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_EQ(8, resultFour->getX());
  EXPECT_EQ(5, resultFour->getY());
}
TEST(Computer_Do_Tests, ShouldCreateComputerWithSingleDoCommand) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("do()");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(1, computer->totalCommands());
  EXPECT_NE(nullptr, dynamic_cast<DoInstruction*>(computer->peekNextCommand()));
}
TEST(Computer_Dont_Tests, ShouldCreateComputerWithSingleDontCommand) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("don't()");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(1, computer->totalCommands());
  EXPECT_NE(nullptr, dynamic_cast<DontInstruction*>(computer->peekNextCommand()));
}
TEST(Computer_Multi_Tests, ShouldCreateComputerWithMultipleCommands) {
  // Given
  auto* computer = new Computer();
  // When
  computer->loadMemory("xmul(2,4)%&mul[3,7]do()!@^do_not_mul(5,5)+mul(3a2,64]tdon't()hen(mul(11,8)mul(8,5))");
  // Then
  EXPECT_TRUE(computer->containsAnyCommands());
  EXPECT_EQ(6, computer->totalCommands());
  const auto* one = dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, one);
  EXPECT_EQ(2, one->getX());
  EXPECT_EQ(4, one->getY());
  const auto* two = dynamic_cast<DoInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, two);
  const auto* three = dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, three);
  EXPECT_EQ(5, three->getX());
  EXPECT_EQ(5, three->getY());
  const auto* four = dynamic_cast<DontInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, four);
  const auto* five = dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, five);
  EXPECT_EQ(11, five->getX());
  EXPECT_EQ(8, five->getY());
  const auto* six = dynamic_cast<MultiplyInstruction*>(computer->popNextCommand());
  EXPECT_NE(nullptr, six);
  EXPECT_EQ(8, six->getX());
  EXPECT_EQ(5, six->getY());
}