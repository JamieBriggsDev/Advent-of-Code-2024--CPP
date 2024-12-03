//
// Created by Jamie Briggs on 03/12/2024.
//

#include "Computer.h"

#include <iostream>

#include <ostream>
#include <regex>
void Computer::loadMemory(const std::string &rawMemory) {
  // Defined regex for "mul(/d,/d)"
  // REGEX Explained:
  // - 1st Capturing Group: (mul\((\d+),(\d+)\))
  //  - 2nd Capturing Group (\d+)
  //  - 3rd Capturing Group (\d+)
  std::regex mulRegex(R"(mul\((\d+),(\d+)\))");
  auto wordsBegin = std::sregex_iterator(rawMemory.begin(), rawMemory.end(), mulRegex);
  auto wordsEnd = std::sregex_iterator();

  for (auto it = wordsBegin; it != wordsEnd; ++it) {
    const std::smatch& match = *it;
    int firstNumber = std::stoi(match[1].str());
    int secondNumber = std::stoi(match[2].str());
    std::string matchedString = match.str();
    this->commands.emplace(firstNumber, secondNumber);
  }
}
bool Computer::containsAnyCommands() const { return !this->commands.empty(); }
int Computer::totalCommands() const { return this->commands.size(); }
MultiplyCommand Computer::peekNextCommand() const { return this->commands.front(); }
MultiplyCommand Computer::popNextCommand() {
  const MultiplyCommand nextCommand = this->commands.front();
  this->commands.pop();
  return nextCommand;
}
