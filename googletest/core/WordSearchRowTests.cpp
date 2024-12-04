//
// Created by Jamie Briggs on 04/12/2024.
//

#include "../../cpp/core/WordSearchRow.h"


#include <gtest/gtest.h>

TEST(WordSearchRow_Tests, ShouldLoadString) {
  // Given
  std::string content = "Hello World!";
  // When
  auto* row = new WordSearchRow(content);
  // Then
  ASSERT_EQ("Hello World!", row->getContents());
}

TEST(WordSearchRow_FindInstances_Tests, ShouldReturnNoInstanced) {
  // Given
  std::string content = "Hello World!";
  auto* row = new WordSearchRow(content);
  // When
  int totalInstances = row->findTotalMatches("XMAS");
  // Then
  ASSERT_EQ(0, totalInstances);
}

TEST(WordSearchRow_FindInstances_Tests, ShouldReturnOneInstance) {
  // Given
  std::string content = "Hello XMASsWorld!";
  auto* row = new WordSearchRow(content);
  // When
  int totalInstances = row->findTotalMatches("XMAS");
  // Then
  ASSERT_EQ(1, totalInstances);
}

TEST(WordSearchRow_FindInstances_Tests, ShouldReturnTwoInstances) {
  // Given
  std::string content = "Hello XMASsWorlXMASd!";
  auto* row = new WordSearchRow(content);
  // When
  int totalInstances = row->findTotalMatches("XMAS");
  // Then
  ASSERT_EQ(2, totalInstances);
}

TEST(WordSearchRow_FindInstances_Tests, ShouldReturnThreeInstancesWithReversed) {
  // Given
  std::string content = "HellSAMXo XMASsWorlXMASd!";
  auto* row = new WordSearchRow(content);
  // When
  int totalInstances = row->findTotalMatches("XMAS");
  // Then
  ASSERT_EQ(3, totalInstances);
}

TEST(WordSearchRow_FindInstances_Tests, ShouldReturnFourInstancesWithReversed) {
  // Given
  std::string content = "HellSAMXo XMASsWoSAMXrlXMASd!";
  auto* row = new WordSearchRow(content);
  // When
  int totalInstances = row->findTotalMatches("XMAS");
  // Then
  ASSERT_EQ(4, totalInstances);
}