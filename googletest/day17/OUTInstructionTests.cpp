//
// Created by Jamie Briggs on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/OUTInstruction.h"

TEST(OUTInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::OUTInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(5, result);
}

TEST(OUTInstruction_Execute_Tests, shouldOutputModuloLiteralValue) {
  // Given
  solutions::OUTInstruction instruction;
  int registerA = 0;
  int registerB = 5;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(3, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(5, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(OUTInstruction_Execute_Tests, shouldOutputModuloComboValueA) {
  // Given
  solutions::OUTInstruction instruction;
  int registerA = 0;
  int registerB = 5;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 4);
  // Then
  ASSERT_EQ(0, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(5, registerB);
  ASSERT_EQ(1, registerC);
}

TEST(OUTInstruction_Execute_Tests, shouldOutputModuloComboValueB) {
  // Given
  solutions::OUTInstruction instruction;
  int registerA = 0;
  int registerB = 10;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 5);
  // Then
  ASSERT_EQ(2, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(10, registerB);
  ASSERT_EQ(1, registerC);
}


TEST(OUTInstruction_Execute_Tests, shouldOutputModuloComboValueC) {
  // Given
  solutions::OUTInstruction instruction;
  int registerA = 0;
  int registerB = 10;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 6);
  // Then
  ASSERT_EQ(1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(10, registerB);
  ASSERT_EQ(1, registerC);
}

