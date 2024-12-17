//
// Created by perso on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/BXCInstruction.h"

TEST(BXCInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::BXCInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(4, result);
}

TEST(BXCInstruction_Execute_Tests, shouldPerformBitwiseXORAndStoreInB) {
  // Given
  solutions::BXCInstruction instruction;
  int registerA = 1;
  int registerB = 5;
  int registerC = 3;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(6, registerB);
  ASSERT_EQ(3, registerC);
}

TEST(BXCInstruction_Execute_Tests, shouldPerformBitwiseXORAndStoreInBTwo) {
  // Given
  solutions::BXCInstruction instruction;
  int registerA = 3;
  int registerB = 29;
  int registerC = 7;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(3, registerA);
  ASSERT_EQ(26, registerB);
  ASSERT_EQ(7, registerC);
}

