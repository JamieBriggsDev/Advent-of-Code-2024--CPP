//
// Created by Jamie Briggs on 03/12/2024.
//

#ifndef COMPUTER_H
#define COMPUTER_H
#include <queue>

#include "MultiplyCommand.h"


class Computer {
  std::queue<MultiplyCommand> commands;
public:
  Computer() = default;
  void loadMemory(const std::string& rawMemory);
  bool containsAnyCommands() const;
  int totalCommands() const;
  MultiplyCommand peekNextCommand() const;
  MultiplyCommand popNextCommand();
};



#endif //COMPUTER_H
