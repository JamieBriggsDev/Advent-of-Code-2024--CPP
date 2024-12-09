//
// Created by Jamie Briggs on 05/12/2024.
//

#include <string>


#include "Day05.h"

#include "PageOrderingRules.h"
#include "PageUpdate.h"


std::string solutions::Day05::solvePartOne(const helper::SolutionInput *input) {
  vector<vector<string>> inputs = input->getSplitTestInput("");
  day5::PageOrderingRules rules;
  for(const auto& rule : inputs[0]) {
    rules.importPageOrderingRule(rule);
  }

  vector<day5::PageUpdate*> updates;
  for(const auto& update : inputs[1]) {
    updates.emplace_back(new day5::PageUpdate(update));
  }

  int finalSum = 0;
  for(const auto& update : updates) {
    if(update->isInCorrectOrder(rules)) {
      finalSum+= update->getMiddleNumber();
    }
  }

  return std::to_string(finalSum);
}
std::string solutions::Day05::solvePartTwo(const helper::SolutionInput *input) {
  vector<vector<string>> inputs = input->getSplitTestInput("");
  day5::PageOrderingRules rules;
  for(const auto& rule : inputs[0]) {
    rules.importPageOrderingRule(rule);
  }

  vector<day5::PageUpdate*> updates;
  for(const auto& update : inputs[1]) {
    updates.emplace_back(new day5::PageUpdate(update));
  }

  int finalSum = 0;
  for(const auto& update : updates) {
    if(!update->isInCorrectOrder(rules)) {
      // Fix the order, and add the middle number
      update->fixOrder(rules);
      finalSum+= update->getMiddleNumber();
    }
  }

  return std::to_string(finalSum);
}
