//
// Created by Jamie Briggs on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/BXLInstruction.h"

TEST(BXLInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::BXLInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(1, result);
}

TEST(BXLInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperand) {
  // Given
  solutions::BXLInstruction instruction;
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
  ASSERT_EQ(6, registerB);
  ASSERT_EQ(1, registerC);
}


TEST(BXLInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperandExample) {
  // Given
  solutions::BXLInstruction instruction;
  int registerA = 1;
  int registerB = 29;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 7);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(26, registerB);
  ASSERT_EQ(1, registerC);
}
