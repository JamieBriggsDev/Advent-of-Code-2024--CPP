//
// Created by perso on 17/12/2024.
//

#include "ChronospatialComputer.h"

#include <assert.h>

#include "../helper/StringUtils.h"
#include "ADVInstruction.h"
#include "BDVInstruction.h"
#include "BSTInstruction.h"
#include "BXCInstruction.h"
#include "BXLInstruction.h"
#include "CDVInstruction.h"
#include "JNZInstruction.h"
#include "OUTInstruction.h"

namespace solutions {
  ChronospatialComputer::ChronospatialComputer(std::vector<string> input) {
    const regex listsRegex("Register [A|B|C]: ([0-9]+)");

    // Get Register A
    smatch aMatch;
    regex_search(input[0], aMatch, listsRegex);
    assert(aMatch.size() == 2);
    this->a = stoi(aMatch[1]);

    // Get Register B
    smatch bMatch;
    regex_search(input[1], bMatch, listsRegex);
    assert(bMatch.size() == 2);
    this->b = stoi(bMatch[1]);

    // Get Register C
    smatch cMatch;
    regex_search(input[2], cMatch, listsRegex);
    assert(cMatch.size() == 2);
    this->c = stoi(cMatch[1]);

    // Load program
    const regex program("Program: ([0-9,]+)");
    smatch programMatch;
    regex_search(input[4], programMatch, program);
    assert(programMatch.size() == 2);
    std::vector<std::string> programVector = helper::StringUtils::splitString(programMatch[1], ",");
    this->program = std::vector<int>(programVector.size());
    for (int i = 0; i < programVector.size(); i++) {
      this->program[i] = stoi(programVector[i]);
    }

    // Register instructions
    instructions.push_back(new ADVInstruction());
    instructions.push_back(new BXLInstruction());
    instructions.push_back(new BSTInstruction());
    instructions.push_back(new JNZInstruction());
    instructions.push_back(new BXCInstruction());
    instructions.push_back(new OUTInstruction());
    instructions.push_back(new BDVInstruction());
    instructions.push_back(new CDVInstruction());
  }
  vector<int> ChronospatialComputer::run() {
    vector<int> output;

    while (instructionPointer < program.size()) {
      int iterationInstructionValue = this->instructionPointer;
      int opcodeNumber = program[instructionPointer];
      int opcodeInput = program[instructionPointer + 1];
      Instruction *instruction = getInstruction(opcodeNumber);
      int result = instruction->execute(a, b, c, instructionPointer, opcodeInput);
      if (result != -1) {
        output.emplace_back(result);
      }
      // This usually is not met during JNZInstruction if the A channel does not equal 0
      if (iterationInstructionValue == instructionPointer) {
        instructionPointer += 2;
      }
    }
    return output;
  }
  Instruction *ChronospatialComputer::getInstruction(int opcodeNumber) {
    for (auto instruction: instructions) {
      if (instruction->getOpcodeNumber() == opcodeNumber) {
        return instruction;
      }
    }
    throw new core::AocException("Instruction not found");
  }

} // namespace solutions
