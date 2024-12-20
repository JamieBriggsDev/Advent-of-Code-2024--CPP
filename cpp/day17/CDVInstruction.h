//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef CDVINSTRUCTION_H
#define CDVINSTRUCTION_H
#include <cmath>


#include "Instruction.h"

namespace solutions {

  /**
   * The cdv instruction (opcode 7) works exactly like the adv instruction except
   * that the result is stored in the C register. (The numerator is still read from the A register.)
   */
  class CDVInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override { return 7; }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      int comboValue = getComboOperand(input, registerA, registerB, registerC);
      int numerator = registerA;
      int denominator = std::pow(2, comboValue);
      int newValue = numerator / denominator;
      registerC = newValue;
      return -1;
    }
};

} // solutions

#endif //CDVINSTRUCTION_H
