//
// Created by perso on 17/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day17/JNZInstruction.h"

TEST(JNZInstruction_GetOpcode_Tests, shouldReturnCorrectValue) {
  // Given
  solutions::JNZInstruction instruction;
  // When
  int result = instruction.getOpcodeNumber();
  // Then
  ASSERT_EQ(3, result);
}

TEST(JNZInstruction_Execute_Tests, shouldDoNothingWhenAZero) {
  // Given
  solutions::JNZInstruction instruction;
  int registerA = 0;
  int registerB = 5;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(1, instructionPointer);
  ASSERT_EQ(0, registerA);
  ASSERT_EQ(5, registerB);
  ASSERT_EQ(1, registerC);
}


TEST(JNZInstruction_Execute_Tests, shouldMoveInstructionPointer) {
  // Given
  solutions::JNZInstruction instruction;
  int registerA = 1;
  int registerB = 5;
  int registerC = 1;
  int instructionPointer = 1;
  // When
  int result = instruction.execute(registerA, registerB, registerC, instructionPointer, 3);
  // Then
  ASSERT_EQ(-1, result);
  ASSERT_EQ(3, instructionPointer);
  ASSERT_EQ(1, registerA);
  ASSERT_EQ(5, registerB);
  ASSERT_EQ(1, registerC);
}

