//
// Created by Jamie Briggs on 03/12/2024.
//

#include "Computer.h"

#include <iostream>

#include <ostream>
#include <regex>

#include "DoInstruction.h"
#include "DontInstruction.h"
void Computer::loadMemory(const std::string &rawMemory) {
  // Defined regex for "mul(/d,/d)"
  // REGEX Explained:
  // - 1st Capturing Group: (mul\((\d+),(\d+)\))
  //  - 2nd Capturing Group (\d+)
  //  - 3rd Capturing Group (\d+)
  std::regex mulRegex(R"((mul|do|don\'t)(\((\d+),(\d+)\)|\(\)))");
  auto wordsBegin = std::sregex_iterator(rawMemory.begin(), rawMemory.end(), mulRegex);
  auto wordsEnd = std::sregex_iterator();

  for (auto it = wordsBegin; it != wordsEnd; ++it) {
    // What type of command is it?
    const std::smatch &match = *it;
    auto command = match[1].str();
    if (command == "do") {
      commands.push(new DoInstruction());
    }
    if (command == "don't") {
      commands.push(new DontInstruction());
    }
    else if (command == "mul") {
      int firstNumber = std::stoi(match[3].str());
      int secondNumber = std::stoi(match[4].str());
      std::string matchedString = match.str();
      commands.push(new MultiplyInstruction(firstNumber, secondNumber));
    }
  }
}
bool Computer::containsAnyCommands() const { return !this->commands.empty(); }
int Computer::totalCommands() const { return this->commands.size(); }
Instruction *Computer::peekNextCommand() const { return this->commands.front(); }
Instruction *Computer::popNextCommand() {
  Instruction *nextCommand = this->commands.front();
  this->commands.pop();
  return nextCommand;
}
std::vector<Instruction *> Computer::peekAllCommands() const {
  std::vector<Instruction *> result;
  std::queue<Instruction *> tempQueue = this->commands;
  while (!tempQueue.empty()) {
    result.push_back(tempQueue.front());
    tempQueue.pop();
  }
  return result;
}
