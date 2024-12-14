//
// Created by perso on 14/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/day13/ClawMachine.h"
#include "../testHelper/InputUtils.h"

TEST(ClawMachine_Initialize_Test, ShouldInitializeWithInput) {
  std::string rawInput =
    "Button A: X+90, Y+25\n"
    "Button B: X+22, Y+34\n"
    "Prize: X=8400, Y=5400\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  // When
  solutions::ClawMachine result(input);
  // Then
  ASSERT_EQ(solutions::ClawMachineButton(90, 25), result.getButtonA());
  ASSERT_EQ(solutions::ClawMachineButton(22, 34), result.getButtonB());
  ASSERT_EQ(core::Pair(8400, 5400), result.getPrize());
}

TEST(ClawMachine_getCheapestWayToPrize_Test, ShouldReturnZero) {
  std::string rawInput =
    "Button A: X+90, Y+25\n"
    "Button B: X+22, Y+34\n"
    "Prize: X=0, Y=0\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  solutions::ClawMachine machine(input);
  // When
  core::Pair result = machine.getCheapestWayToPrize();
  // Then
  ASSERT_EQ(core::Pair(0,0), result);
}

TEST(ClawMachine_getCheapestWayToPrize_Test, ShouldReturnExampleOne) {
  std::string rawInput =
    "Button A: X+94, Y+34\n"
    "Button B: X+22, Y+67\n"
    "Prize: X=8400, Y=5400\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  solutions::ClawMachine machine(input);
  // When
  core::Pair result = machine.getCheapestWayToPrize();
  // Then
  ASSERT_EQ(core::Pair(80,40), result);
}

TEST(ClawMachine_getCheapestWayToPrize_Test, ShouldReturnExampleTwoImpossible) {
  std::string rawInput =
    "Button A: X+26, Y+66\n"
    "Button B: X+67, Y+21\n"
    "Prize: X=12748, Y=12176\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  solutions::ClawMachine machine(input);
  // When
  core::Pair result = machine.getCheapestWayToPrize();
  // Then
  ASSERT_EQ(core::Pair(0,0), result);
}

TEST(ClawMachine_getCheapestWayToPrize_Test, ShouldReturnExampleOneImpossibleLarge) {
  std::string rawInput =
    "Button A: X+94, Y+34\n"
    "Button B: X+22, Y+67\n"
    "Prize: X=8400, Y=5400\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  solutions::ClawMachine machine(input, true);
  // When
  core::Pair result = machine.getCheapestWayToPrize();
  // Then
  ASSERT_EQ(core::Pair(0,0), result);
}

TEST(ClawMachine_getCheapestWayToPrize_Test, ShouldReturnExampleTwoLarge) {
  std::string rawInput =
    "Button A: X+26, Y+66\n"
    "Button B: X+67, Y+21\n"
    "Prize: X=12748, Y=12176\n"
  ;
  std::vector<std::string> input = InputUtils::convertToVector(rawInput);
  solutions::ClawMachine machine(input, true);
  // When
  core::Pair result = machine.getCheapestWayToPrize();
  // Then
  ASSERT_EQ(core::Pair(118679050709l,103199174542l), result);
}