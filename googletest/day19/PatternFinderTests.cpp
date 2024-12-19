//
// Created by perso on 19/12/2024.
//
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../../cpp/day20/PatternFinder.h"
#include "../../cpp/day20/PatternHolder.h"

using namespace std;
using namespace solutions;

class PatternFinderTests : public ::testing::Test {
  vector<string> singleLetterPatternsRaw = {"a", "b", "c"};
  vector<string> examplePatternsRaw = {"r", "wr", "b", "g", "bwu", "rb", "gb", "br"};
public:
  vector<Pattern> singleLetterPatterns;
  vector<string> basicPatterns = {"a", "b", "c", "ab", "bc", "ac", "abc"};
  static Pattern getPattern(const string &input) {
    return Pattern(input);
  }

  // Setup
  void SetUp() override {
    for (string raw : singleLetterPatternsRaw) {
      singleLetterPatterns.push_back(getPattern(raw));
    }
  }

};

TEST_F(PatternFinderTests, ShouldFindSingleCharacterPattern) {
  // Given
  Pattern toMatch = getPattern("a");
  // When
  bool result = PatternFinder::patternCanBeMade(toMatch, singleLetterPatterns);
  // Then
  ASSERT_TRUE(result);
}

TEST_F(PatternFinderTests, ShouldNotFindSingleCharacterPattern) {
  // Given
  Pattern toMatch = getPattern("d");
  // When
  bool result = PatternFinder::patternCanBeMade(toMatch, singleLetterPatterns);
  // Then
  ASSERT_FALSE(result);
}

TEST_F(PatternFinderTests, ShouldMakePatternWithMultipleTowels) {
  // Given
  Pattern toMatch = getPattern("abc");
  // When
  bool result = PatternFinder::patternCanBeMade(toMatch, singleLetterPatterns);
  // Then
  ASSERT_TRUE(result);
}

TEST_F(PatternFinderTests, ShouldMakePatternWithMultipleTowelsDuplicates) {
  // Given
  Pattern toMatch = getPattern("aaaabbbcccccc");
  // When
  bool result = PatternFinder::patternCanBeMade(toMatch, singleLetterPatterns);
  // Then
  ASSERT_TRUE(result);
}

TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPattern) {
  // Given
  Pattern toMatch = getPattern("gbbr");
  // When
  //int result = PatternFinder::patternCanBeMade(toMatch, singleLetterPatterns);
  // Then
  //ASSERT_TRUE(result);
}