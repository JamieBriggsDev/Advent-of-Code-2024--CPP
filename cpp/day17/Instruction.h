//
// Created by Jamie Briggs on 17/12/2024.
//

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "../core/AocException.h"

class Instruction {
public:
  virtual ~Instruction() = default;
  virtual int getOpcodeNumber() const = 0;
  virtual int execute(int &registerA, int &registerB, int &registerC, int &instructionPointer,
                      const int input) const = 0;

  static int getComboOperand(const int input, const int registerA, const int registerB, const int registerC) {
    if (input < 4) {
      return input;
    }
    if (input == 4) {
      return registerA;
    }
    if (input == 5) {
      return registerB;
    }
    if (input == 6) {
      return registerC;
    }
    throw new core::AocException("Invalid operand value: " + input);
  }
};

#endif //INSTRUCTION_H
