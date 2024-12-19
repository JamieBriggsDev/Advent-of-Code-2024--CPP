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
  vector<Pattern> exampleLetterPatterns;
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
    for (string raw : examplePatternsRaw) {
      exampleLetterPatterns.push_back(getPattern(raw));
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

TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPattern1) {
  // Given
  Pattern toMatch = getPattern("bggr");
  // When
  int result = PatternFinder::countTotalWaysPatternCanBeMade(toMatch, exampleLetterPatterns);
  // Then
  ASSERT_EQ(1, result);
}


TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPattern2) {
  // Given
  Pattern toMatch = getPattern("brwrr");
  // When
  int result = PatternFinder::countTotalWaysPatternCanBeMade(toMatch, exampleLetterPatterns);
  // Then
  ASSERT_EQ(2, result);
}

TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPattern4) {
  // Given
  Pattern toMatch = getPattern("gbbr");
  // When
  int result = PatternFinder::countTotalWaysPatternCanBeMade(toMatch, exampleLetterPatterns);
  // Then
  ASSERT_EQ(4, result);
}

TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPattern6) {
  // Given
  Pattern toMatch = getPattern("rrbgbr");
  // When
  int result = PatternFinder::countTotalWaysPatternCanBeMade(toMatch, exampleLetterPatterns);
  // Then
  ASSERT_EQ(6, result);
}

TEST_F(PatternFinderTests, ShouldReturnCorrectAmountOfWaysToFormPatternEdgeCase) {
  // Given
  Pattern toMatch = getPattern("rrb");
  vector<Pattern> patterns = {getPattern("r"), getPattern("b")};
  // When
  int result = PatternFinder::countTotalWaysPatternCanBeMade(toMatch, patterns);
  // Then
  ASSERT_EQ(1, result);
}