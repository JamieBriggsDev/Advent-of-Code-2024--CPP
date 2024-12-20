//
// Created by Jamie Briggs on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/CDVInstruction.h"

TEST(CDVInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::CDVInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(7, result);
}

TEST(CDVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperand) {
  // Given
  solutions::CDVInstruction instruction;
  int registerA = 4;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in c = 4 / 2^2 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(4, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(CDVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperandTruncate) {
  // Given
  solutions::CDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in C = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(2, registerC);
}

TEST(CDVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandC) {
  // Given
  solutions::CDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 3;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 6);
  // Then
  // Should store in C = 9 / 3^3 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(CDVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandBTruncate) {
  // Given
  solutions::CDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 3;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 5);
  // Then
  // Should store in C = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(2, registerC);
}


