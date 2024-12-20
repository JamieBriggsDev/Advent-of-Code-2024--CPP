//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef JNZINSTRUCTION_H
#define JNZINSTRUCTION_H
#include "Instruction.h"

namespace solutions {

  /**
   * The jnz instruction (opcode 3) does nothing if the A register is
   * 0. However, if the A register is not zero, it jumps by setting the
   * instruction pointer to the value of its literal operand; if this
   * instruction jumps, the instruction pointer is not increased by 2
   * after this instruction.
   */
  class JNZInstruction : public Instruction {
public:
  int getOpcodeNumber() const override {
    return 3;
  }
  int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer, const int input) const override {
    if (registerA != 0) {
      instructionPointer = input;
    }
    return -1;
  }
};
}

#endif //JNZINSTRUCTION_H
