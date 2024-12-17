//
// Created by perso on 17/12/2024.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../../cpp/day17/ADVInstruction.h"
#include "../../cpp/day17/BXLInstruction.h"
#include "../../cpp/day17/BSTInstruction.h"
#include "../../cpp/day17/JNZInstruction.h"
#include "../../cpp/day17/BXCInstruction.h"
#include "../../cpp/day17/OUTInstruction.h"
#include "../../cpp/day17/BDVInstruction.h"
#include "../../cpp/day17/CDVInstruction.h"
#include "../../cpp/day17/ChronospatialComputer.h"
#include "../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;

class ChronospatialComputerTests : public ::testing::Test {
  string rawInputExample = "Register A: 729\n"
                           "Register B: 0\n"
                           "Register C: 0\n"
                           "\n"
                           "Program: 0,1,5,4,3,0\n";

  string rawInputExampleSmallOne =  "Register A: 10\n"
                                    "Register B: 0\n"
                                    "Register C: 0\n"
                                    "\n"
                                    "Program: 5,0,5,1,5,4\n";
  string rawInputExampleSmallTwo =  "Register A: 2024\n"
                                    "Register B: 0\n"
                                    "Register C: 0\n"
                                    "\n"
                                    "Program: 0,1,5,4,3,0\n";
  string rawInputExampleSmallThree =  "Register A: 729\n"
                                      "Register B: 0\n"
                                      "Register C: 0\n"
                                      "\n"
                                      "Program: 0,1,5,4,3,0\n";

protected:
  vector<string> inputExample;
  vector<string> inputExampleOne;
  vector<string> inputExampleTwo;
  vector<string> inputExampleThree;

  // Setup after each
  void SetUp() override {
    inputExample = InputUtils::convertToVector(rawInputExample);
    inputExampleOne = InputUtils::convertToVector(rawInputExampleSmallOne);
    inputExampleTwo = InputUtils::convertToVector(rawInputExampleSmallTwo);
    inputExampleThree = InputUtils::convertToVector(rawInputExampleSmallThree);
  }

  void TearDown() override {
    inputExample.clear();
    inputExampleOne.clear();
    inputExampleTwo.clear();
    inputExampleThree.clear();
  }
};

TEST_F(ChronospatialComputerTests, ShouldInitialize) {
  // Given
  // When
  ChronospatialComputer computer(inputExample);
  // Then
  ASSERT_EQ(729, computer.getRegisterAValue());
  ASSERT_EQ(0, computer.getRegisterBValue());
  ASSERT_EQ(0, computer.getRegisterCValue());
  ASSERT_EQ(0, computer.getInstructionPointer());
  ASSERT_EQ(6, computer.getProgram().size());
  ASSERT_EQ(0, computer.getProgram()[0]);
  ASSERT_EQ(1, computer.getProgram()[1]);
  ASSERT_EQ(5, computer.getProgram()[2]);
  ASSERT_EQ(4, computer.getProgram()[3]);
  ASSERT_EQ(3, computer.getProgram()[4]);
  ASSERT_EQ(0, computer.getProgram()[5]);
}

TEST_F(ChronospatialComputerTests, ShouldReturnCorrectInstruction) {
  // Given
  // When
  ChronospatialComputer computer(inputExample);
  // Then
  ASSERT_TRUE(dynamic_cast<ADVInstruction*>(computer.getInstruction(0)) != nullptr);
  ASSERT_TRUE(dynamic_cast<BXLInstruction*>(computer.getInstruction(1)) != nullptr);
  ASSERT_TRUE(dynamic_cast<BSTInstruction*>(computer.getInstruction(2)) != nullptr);
  ASSERT_TRUE(dynamic_cast<JNZInstruction*>(computer.getInstruction(3)) != nullptr);
  ASSERT_TRUE(dynamic_cast<BXCInstruction*>(computer.getInstruction(4)) != nullptr);
  ASSERT_TRUE(dynamic_cast<OUTInstruction*>(computer.getInstruction(5)) != nullptr);
  ASSERT_TRUE(dynamic_cast<BDVInstruction*>(computer.getInstruction(6)) != nullptr);
  ASSERT_TRUE(dynamic_cast<CDVInstruction*>(computer.getInstruction(7)) != nullptr);
}


TEST_F(ChronospatialComputerTests, ShouldRunProgramExampleOne) {
  // Given
  ChronospatialComputer computer(inputExampleOne);
  // When
  vector<int> result = computer.run();
  // Then
  ASSERT_EQ(3, result.size());
  ASSERT_EQ(0, result[0]);
  ASSERT_EQ(1, result[1]);
  ASSERT_EQ(2, result[2]);
}



TEST_F(ChronospatialComputerTests, ShouldRunProgramExampleTwo) {
  // Given
  ChronospatialComputer computer(inputExampleTwo);
  // When
  vector<int> result = computer.run();
  // Then
  //4,2,5,6,7,7,7,7,3,1,0
  ASSERT_EQ(11, result.size());
  ASSERT_EQ(4, result[0]);
  ASSERT_EQ(2, result[1]);
  ASSERT_EQ(5, result[2]);
  ASSERT_EQ(6, result[3]);
  ASSERT_EQ(7, result[4]);
  ASSERT_EQ(7, result[5]);
  ASSERT_EQ(7, result[6]);
  ASSERT_EQ(7, result[7]);
  ASSERT_EQ(3, result[8]);
  ASSERT_EQ(1, result[9]);
  ASSERT_EQ(0, result[10]);
  ASSERT_EQ(0, computer.getRegisterAValue());
}

TEST_F(ChronospatialComputerTests, ShouldRunProgramExampleThree) {
  // Given
  ChronospatialComputer computer(inputExampleThree);
  // When
  vector<int> result = computer.run();
  // Then
  // 4,6,3,5,6,3,5,2,1,0
  ASSERT_EQ(10, result.size());
  ASSERT_EQ(4, result[0]);
  ASSERT_EQ(6, result[1]);
  ASSERT_EQ(3, result[2]);
  ASSERT_EQ(5, result[3]);
  ASSERT_EQ(6, result[4]);
  ASSERT_EQ(3, result[5]);
  ASSERT_EQ(5, result[6]);
  ASSERT_EQ(2, result[7]);
  ASSERT_EQ(1, result[8]);
  ASSERT_EQ(0, result[9]);
}
