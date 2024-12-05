//
// Created by Jamie Briggs on 05/12/2024.
//

#include "PageOrderingRules.h"

#include <string>
#include <regex>
#include <stdexcept>

using namespace day5;
void PageOrderingRules::importPageOrderingRule(const std::string &rawRule) {
  std::regex regexPattern(R"((\d+)\|(\d+))");
  std::smatch match;

  if (std::regex_search(rawRule, match, regexPattern) && match.size() == 3) {
    int firstNumber = std::stoi(match[1].str());
    int secondNumber = std::stoi(match[2].str());
    // First check if rules exists
    if (this->rules.find(firstNumber) == this->rules.end()) {
      this->rules[firstNumber] = PageOrderingRuleSpec();
    }
    if (this->rules.find(secondNumber) == this->rules.end()) {
      this->rules[secondNumber] = PageOrderingRuleSpec();
    }
    // Add rules
    this->rules[firstNumber].pagesAfter.emplace(secondNumber);
    this->rules[secondNumber].pagesBefore.emplace(firstNumber);
  } else {
    throw std::invalid_argument("Invalid rule format");
  }
}
bool PageOrderingRules::isSubjectNumberAfterTargetNumber(int targetNumber, int subjectNumber) {
  return this->getRules()[targetNumber].pagesAfter.contains(subjectNumber);
}
bool PageOrderingRules::isSubjectNumberBeforeTargetNumber(int targetNumber, int subjectNumber) {
  return this->getRules()[targetNumber].pagesBefore.contains(subjectNumber);
}

