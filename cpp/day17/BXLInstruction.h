//
// Created by perso on 17/12/2024.
//

#ifndef BXLINSTRUCTION_H
#define BXLINSTRUCTION_H
#include "Instruction.h"

namespace solutions {

  /**
  * The bxl instruction (opcode 1) calculates the bitwise XOR
  * of register B and the instruction's literal operand, then stores the result in register B.
  */
  class BXLInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override { return 1; }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      int a = registerB;
      int b = input;
      registerB = a ^ b; // Perform Bitwise XOR.
      return -1;
    }
  };

} // namespace solutions

#endif // BXLINSTRUCTION_H
