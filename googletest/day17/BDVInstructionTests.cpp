//
// Created by perso on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/BDVInstruction.h"

TEST(BDVInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::BDVInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(6, result);
}

TEST(BDVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperand) {
  // Given
  solutions::BDVInstruction instruction;
  int registerA = 4;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in B = 4 / 2^2 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(4, registerA);
  ASSERT_EQ(1, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(BDVInstruction_Execute_Tests, shouldExecuteInstructionLiteralOperandTruncate) {
  // Given
  solutions::BDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 1;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 2);
  // Then
  // Should store in B = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(BDVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandC) {
  // Given
  solutions::BDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 3;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 6);
  // Then
  // Should store in B = 9 / 3^3 = 1
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(1, registerB);
  ASSERT_EQ(3, registerC);
}

TEST(BDVInstruction_Execute_Tests, shouldExecuteInstructionComboOperandBTruncate) {
  // Given
  solutions::BDVInstruction instruction;
  int registerA = 9;
  int registerB = 2;
  int registerC = 3;
  int instructionPointer = 1;

  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 5);
  // Then
  // Should store in B = 9 / 2^2 = 2.25 = 2
  ASSERT_EQ(-1, result);
  ASSERT_EQ(9, registerA);
  ASSERT_EQ(2, registerB);
  ASSERT_EQ(3, registerC);
}


