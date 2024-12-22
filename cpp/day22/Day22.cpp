//
// Created by Jamie Briggs on 22/12/2024.
//

#include "Day22.h"

#include "SecretEvolver.h"
#include <iostream>

namespace solutions {
  std::string Day22::solvePartOne(const helper::SolutionInput *input) {
    long long result = 0l;

    for (const auto& initialSecretString: input->getTestInput()) {
      long long secret = stoll(initialSecretString);
      long long finalSecretValue = secret;
      for (int i = 0; i < 2000; i++) {
        finalSecretValue = SecretEvolver::evolveSecret(finalSecretValue);
      }
      std::cout << initialSecretString << ": " << finalSecretValue << std::endl;
      result += finalSecretValue;
    }
    return to_string(result);
  }
  std::string Day22::solvePartTwo(const helper::SolutionInput *input) { return "To solve"; }
} // namespace solutions
