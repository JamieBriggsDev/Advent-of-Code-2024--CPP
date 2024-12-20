//
// Created by Jamie Briggs on 19/12/2024.
//

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../../cpp/day19/PatternHolder.h"

using namespace std;

class PatternHolderTests : public ::testing::Test {
public:
  string basicTowels = "a, b, c, ab, bc, ac, abc";
  vector<string> designsToMatch = {"aaa", "ba", "cab", "abc", "c"};
};

TEST_F(PatternHolderTests, ShouldInitialize) {
  // Given
  // When
  solutions::PatternHolder holder(designsToMatch, basicTowels);
  // Then
  ASSERT_EQ(7, holder.getTowels().size());
  ASSERT_EQ(5, holder.getDesigns().size());
}