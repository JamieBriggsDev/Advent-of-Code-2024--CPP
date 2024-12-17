//
// Created by perso on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/BSTInstruction.h"

TEST(BSTInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::BSTInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(2, result);
}

TEST(BSTInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperand) {
  // Given
  solutions::BSTInstruction instruction;
  int registerA = 1;
  int registerB = 5;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(3, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(BSTInstruction_Execute_Tests, shouldExecuteInstructionComboOperand) {
  // Given
  solutions::BSTInstruction instruction;
  int registerA = 1;
  int registerB = 5;
  int registerC = 9;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 6);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(1, registerB);
  ASSERT_EQ(9, registerC);
}

