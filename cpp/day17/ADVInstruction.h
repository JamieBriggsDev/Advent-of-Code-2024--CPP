//
// Created by perso on 17/12/2024.
//

#ifndef ADVINSTRUCTION_H
#define ADVINSTRUCTION_H
#include <cmath>


#include "Instruction.h"

namespace solutions {

  /**
   * The adv instruction (opcode 0) performs division. The numerator is the
   * value in the A register. The denominator is found by raising 2 to
   * the power of the instruction's combo operand. (So, an operand of 2
   * would divide A by 4 (2^2); an operand of 5 would divide A by 2^B.)
   * The result of the division operation is truncated to an integer and
   * then written to the A register.
   */
  class ADVInstruction : public Instruction {
  public:
    int getOpcodeNumber() const override { return 0; }
    int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                const int input) const override {
      int comboValue = getComboOperand(input, registerA, registerB, registerC);
      int numerator = registerA;
      int denominator = std::pow(2, comboValue);
      int newValue = numerator / denominator;
      registerA = newValue;
      return -1;
    }
};

} // solutions

#endif //ADVINSTRUCTION_H
