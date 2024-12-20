//
// Created by Jamie Briggs on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/ADVInstruction.h"

TEST(ADVInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::ADVInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(0, result);
}

TEST(ADVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperand) {
  // Given
  solutions::ADVInstruction instruction;
  int registerA = 4;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in A = 4 / 2^2 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(ADVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperandTruncate) {
  // Given
  solutions::ADVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in A = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(2, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(ADVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandC) {
  // Given
  solutions::ADVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 4;
  int instructionPointer = 6;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 6);
  // Then
  // Should store in A = 9 / 2^4 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(4, registerC);
}

TEST(ADVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandBTruncate) {
  // Given
  solutions::ADVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 3;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 5);
  // Then
  // Should store in A = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(2, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(3, registerC);
}


