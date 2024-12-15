//
// Created by Jamie Briggs on 11/12/2024.
//

#include "Day07.h"

#include <iostream>
#include <string>
#include <vector>

#include "../helper/StringUtils.h"
#include "Equation.h"

using namespace std;

namespace solutions {
  std::string Day07::solvePartOne(const helper::SolutionInput *input) {
    vector<Equation> equations;
    for (const string &rawEquestion : input->getTestInput()) {
      auto splitEquation = helper::StringUtils::splitString(rawEquestion, ": ");
      long long answer = -1L;
      try {
        answer = stoll(splitEquation[0]);
      }catch (const std::exception& e) {
        std::cerr << "Could not perform stoll() on number " << splitEquation[0] << "." << std::endl;
        std::cerr << e.what() << std::endl;
      }
      vector<long long> numbers;
      auto rawNumbers = helper::StringUtils::splitString(splitEquation[1], " ");
      for (const auto& number : rawNumbers) {
        try {
          numbers.push_back(stoll(number));
        }catch (const std::exception& e) {
          std::cerr << "Could not perform stoll() on number " << number << "." << std::endl;
          std::cerr << e.what() << std::endl;
        }
      }
      Equation equation(answer, numbers);
      equations.push_back(equation);
    }

    long long totalTestValues = 0;
    for (Equation equation : equations) {
      auto possibleSolutions = equation.findPossibleSolutions();
      if (!possibleSolutions.empty()) {
        if (totalTestValues + equation.getAnswer() < totalTestValues) {
          std::cerr << "totalTestValues gone out of range!" << std::endl;
        }
        totalTestValues += equation.getAnswer();
      }
    }
    return to_string(totalTestValues);
  }
  std::string Day07::solvePartTwo(const helper::SolutionInput *input) {
    vector<Equation> equations;
    for (const string &rawEquestion : input->getTestInput()) {
      auto splitEquation = helper::StringUtils::splitString(rawEquestion, ": ");
      long long answer = -1L;
      try {
        answer = stoll(splitEquation[0]);
      }catch (const std::exception& e) {
        std::cerr << "Could not perform stoll() on number " << splitEquation[0] << "." << std::endl;
        std::cerr << e.what() << std::endl;
      }
      vector<long long> numbers;
      auto rawNumbers = helper::StringUtils::splitString(splitEquation[1], " ");
      for (const auto& number : rawNumbers) {
        try {
          numbers.push_back(stoll(number));
        }catch (const std::exception& e) {
          std::cerr << "Could not perform stoll() on number " << number << "." << std::endl;
          std::cerr << e.what() << std::endl;
        }
      }
      Equation equation(answer, numbers);
      equations.push_back(equation);
    }

    long long totalTestValues = 0;
    for (Equation equation : equations) {
      auto possibleSolutions = equation.findPossibleSolutions(true);
      if (!possibleSolutions.empty()) {
        if (totalTestValues + equation.getAnswer() < totalTestValues) {
          std::cerr << "totalTestValues gone out of range!" << std::endl;
        }
        totalTestValues += equation.getAnswer();
      }
    }
    return to_string(totalTestValues);
  }
} // solutions