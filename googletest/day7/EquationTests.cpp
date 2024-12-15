//
// Created by perso on 15/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day7/Equation.h"

TEST(Equation_Initialize_Tests, ShouldInitializeEquationWithTwoNumbers) {
  // Given
  long answer = 2;
  std::vector<long long> numbers = {1l, 1l};
  // When
  solutions::Equation equation(answer, numbers);
  // Then
  ASSERT_EQ(2, equation.getAnswer());
  ASSERT_EQ(numbers, equation.getNumbers());
}

TEST(Equation_FindPossibleSolutions_Tests, ShouldReturnEmptyListWhenNoPossibleSolutions) {
  // Given
  int answer = 5;
  std::vector<long long> numbers = {1l, 2l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(0, result.size());
}

TEST(Equation_FindPossibleSolutions_Tests, TwoNumbersShouldReturnOneSolutionAddition) {
  // Given
  int answer = 5;
  std::vector<long long> numbers = {2l, 3l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("5 = 2 + 3", result[0]);
}

TEST(Equation_FindPossibleSolutions_Tests, TwoNumbersShouldReturnOneSolutionMultiply) {
  // Given
  int answer = 6;
  std::vector<long long> numbers = {2l, 3l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("6 = 2 * 3", result[0]);
}

TEST(Equation_FindPossibleSolutions_Tests, TwoNumbersShouldReturnTwoSolutions) {
  // Given
  int answer = 4;
  std::vector<long long> numbers = {2l, 2l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(2, result.size());
  ASSERT_EQ("4 = 2 + 2", result[0]);
  ASSERT_EQ("4 = 2 * 2", result[1]);
}

TEST(Equation_FindPossibleSolutions_Tests, ThreeNumbersShouldReturnOneSolution) {
  // Given
  int answer = 75;
  std::vector<long long> numbers = {25l, 25l, 25l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("75 = 25 + 25 + 25", result[0]);
}

TEST(Equation_FindPossibleSolutions_Tests, MultipleNumbers) {
  // Given
  int answer = 292;
  std::vector<long long> numbers = {11l, 6l, 16l, 20l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("292 = 11 + 6 * 16 + 20", result[0]);
}

TEST(Equation_FindPossibleSolutions_Tests, ExampleOne) {
  // Given
  long long answer = 303269403;
  std::vector<long long> numbers = {678l, 71l, 700l, 9l, 3l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions();
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("292 = 11 + 6 * 16 + 20", result[0]);
}

TEST(Equation_FindPossibleSolutionsAdvanced_Tests, ExampleOne) {
  // Given
  long long answer = 156;
  std::vector<long long> numbers = {15l, 6l};
  solutions::Equation equation(answer, numbers);
  // When
  auto result = equation.findPossibleSolutions(true);
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ("156 = 15 || 6", result[0]);
}
