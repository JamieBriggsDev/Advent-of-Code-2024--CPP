//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef BDVINSTRUCTION_H
#define BDVINSTRUCTION_H
#include <cmath>


#include "Instruction.h"

namespace solutions {

  /**
   * The bdv instruction (opcode 6) works exactly like the adv instruction
   * except that the result is stored in the B register.
   * (The numerator is still read from the A register.)
   */
  class BDVInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override { return 6; }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      int comboValue = getComboOperand(input, registerA, registerB, registerC);
      int numerator = registerA;
      int denominator = std::pow(2, comboValue);
      int newValue = numerator / denominator;
      registerB = newValue;
      return -1;
    }
};

} // solutions

#endif //BDVINSTRUCTION_H
