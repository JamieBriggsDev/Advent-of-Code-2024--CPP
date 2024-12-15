//
// Created by perso on 15/12/2024.
//

#include "Equation.h"

#include <functional>
#include <iostream>
#include <math.h>

using namespace std;

namespace solutions {
  vector<string> Equation::findPossibleSolutions() {

    // Possible solutions:
    // When 2 Numbers and 1 operands: 2 (+, -)
    // When 3 Numbers and 2 operands: 4 (++,+*,*+,**)
    // When 4 Numbers and 3 operands: 8 (+++,*++,+*+,++*,**+,*+*, +**, ***)
    // The total possibilities are 2^operands.
    int totalPossibilities = this->getNumbers().size() - 1;

    std::vector<std::string> possibleOperands;

    // Recursive helper function
    function<void(int, std::string)> generatePossibleOperands = [&](int currentOperand, std::string currentOutcome) {
      if (currentOperand == totalPossibilities) {
        // Base case: reached the total number of possibilities
        possibleOperands.push_back(currentOutcome);
        return;
      }

      // Recursive calls: Add + or *
      generatePossibleOperands(currentOperand + 1, currentOutcome + "+");
      generatePossibleOperands(currentOperand + 1, currentOutcome + "*");
    };

    generatePossibleOperands(0, "");


    std::vector<std::string> results;

    for (auto & possibleOperand : possibleOperands) {
      long long possibleResult = this->getNumbers()[0];
      string possibleSolution = to_string(this->getAnswer()) + " = " + to_string(this->getNumbers()[0]);
      for (int i =1; i < this->getNumbers().size(); i++) {
        char operand = possibleOperand[i - 1];
        // Multiply
        if (operand == '+') {
          possibleResult += this->getNumbers()[i];
          possibleSolution += " + " + to_string(this->getNumbers()[i]);
        }
        // Multiply
        if (operand == '*') {
          possibleResult *= this->getNumbers()[i];
          possibleSolution += " * " + to_string(this->getNumbers()[i]);
        }
      }

      // Check if solution correct
      if (possibleResult == this->getAnswer()) {
        results.push_back(possibleSolution);
      }
    }


    return results;
  }
} // solutions