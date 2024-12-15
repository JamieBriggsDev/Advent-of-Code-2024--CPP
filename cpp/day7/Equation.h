//
// Created by perso on 15/12/2024.
//

#ifndef EQUATION_H
#define EQUATION_H

#include <vector>
#include <string>

namespace solutions {

class Equation {
  long long answer;
  std::vector<long long> numbers;
public:
  Equation(const long long answer, std::vector<long long> numbers) {
    this->answer = answer;
    this->numbers = numbers;
  };
  /**
   * Finds possible solutions to the equation
   * @return a vector of strings showing the possible solutions to the equation.
   */
  std::vector<std::string> findPossibleSolutions(bool useConcatendationOperator = false);

  long long getAnswer() {
    return answer;
  }

  std::vector<long long> getNumbers() {
    return numbers;
  }
};

} // solutions

#endif //EQUATION_H
