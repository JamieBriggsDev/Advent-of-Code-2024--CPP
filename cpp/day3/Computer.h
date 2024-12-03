//
// Created by Jamie Briggs on 03/12/2024.
//

#ifndef COMPUTER_H
#define COMPUTER_H
#include <queue>

#include "MultiplyInstruction.h"


class Computer {
  std::queue<Instruction*> commands;
public:
  Computer() = default;
  void loadMemory(const std::string& rawMemory);
  [[nodiscard]] bool containsAnyCommands() const;
  [[nodiscard]] int totalCommands() const;
  [[nodiscard]] Instruction* peekNextCommand() const;
  Instruction* popNextCommand();
  [[nodiscard]] std::vector<Instruction*> peekAllCommands() const;
};



#endif //COMPUTER_H
