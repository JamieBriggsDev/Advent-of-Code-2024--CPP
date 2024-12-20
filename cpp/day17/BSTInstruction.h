//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef BSTINSTRUCTION_H
#define BSTINSTRUCTION_H
#include "Instruction.h"

namespace solutions {
  /**
   * The bst instruction (opcode 2) calculates the value of its combo operand
   * modulo 8 (thereby keeping only its lowest 3 bits), then
   * writes that value to the B register.
   */
  class BSTInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override {
      return 2;
    }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer, const int input) const override {
      int comboValue = getComboOperand(input, registerA, registerB, registerC);
      int result = comboValue % 8;
      registerB = result;
      return -1;
    }
  };
}

#endif //BSTINSTRUCTION_H
