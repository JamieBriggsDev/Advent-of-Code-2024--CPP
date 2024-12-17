//
// Created by perso on 17/12/2024.
//

#ifndef OUTINSTRUCTION_H
#define OUTINSTRUCTION_H
#include "Instruction.h"

namespace solutions {
  /**
   * The out instruction (opcode 5) calculates the value of its combo operand modulo 8,
   * then outputs that value. (If a program outputs multiple
   * values, they are separated by commas.)
   */
  class OUTInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override {
      return 5;
    }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      return getComboOperand( input, registerA, registerB, registerC) % 8;
    }

  };
}

#endif //OUTINSTRUCTION_H
