//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef CHRONOSPATIALCOMPUTER_H
#define CHRONOSPATIALCOMPUTER_H
#include <regex>
#include <string>
#include <vector>

#include "Instruction.h"

using namespace std;

namespace solutions {

  class ChronospatialComputer {
    int a;
    int b;
    int c;
    // This value starts at 0. Is used to identify the position in the program from which
    //     the next opcode will be read. Apart from jump operations, this number increases by
    //     2 each time a operand has been read.
    int instructionPointer = 0;
    vector<int> program;
    vector<Instruction *> instructions;


  public:
    ChronospatialComputer(std::vector<string> input);
    ~ChronospatialComputer() {
      for (auto &instruction : instructions) {
        delete instruction;
      }
      instructions.clear();
    }
    [[nodiscard]] int getRegisterAValue() const { return a; }
    void setRegisterAValue(int value) { a = value; }
    [[nodiscard]] int getRegisterBValue() const { return b; }
    [[nodiscard]] int getRegisterCValue() const { return c; }
    [[nodiscard]] int getInstructionPointer() const { return instructionPointer; }
    [[nodiscard]] vector<int> getProgram() const { return program; }
    [[nodiscard]] vector<int> run();

    Instruction *getInstruction(int opcodeNumber);
  };

} // namespace solutions

#endif // CHRONOSPATIALCOMPUTER_H
