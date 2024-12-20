//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef BXCINSTRUCTION_H
#define BXCINSTRUCTION_H
#include "Instruction.h"


namespace solutions {

  /**
  * The bxc instruction (opcode 4) calculates the bitwise XOR of
  * register B and register C, then stores the result in register
  * B. (For legacy reasons, this instruction reads an operand but ignores it.)
  */
  class BXCInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override { return 4; }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      int a = registerB;
      int b = registerC;
      int answer = a ^ b;
      registerB = answer;
      return -1;
    }
  };
} // namespace solutions

#endif // BXCINSTRUCTION_H
