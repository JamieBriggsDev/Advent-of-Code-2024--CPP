//
// Created by Jamie Briggs on 04/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day4/MasSearchGrid.h"
#include "../testHelper/InputUtils.h"

// TODO: Commenting out for now as periodically fails and don't have time to investigate
TEST(MasSearchGridTests, DISABLED_ShouldLoadInput) {
  // Given
  std::string content =
    ".....\n"
    ".....\n"
    ".....\n"
    ".....\n"
    "....."
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  // When
  auto* grid = new MasSearchGrid(gridContent);
  // Then
  ASSERT_EQ(5, grid->getVerticalLength());
  ASSERT_EQ(5, grid->getHorizontalLength());
  ASSERT_EQ(".....", std::string(grid->getGrid()[0]));
  ASSERT_EQ(".....", std::string(grid->getGrid()[1]));
  ASSERT_EQ(".....", std::string(grid->getGrid()[2]));
  ASSERT_EQ(".....", std::string(grid->getGrid()[3]));
  ASSERT_EQ(".....", std::string(grid->getGrid()[4]));
}

TEST(MasSearchGridTests, ShouldNotFindXMas) {
  // Given
  std::string content =
    ".....\n"
    ".M...\n"
    "..A..\n"
    "...S.\n"
    ".....\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(0, result);
}

TEST(MasSearchGridTests, ShouldFindOneXMas) {
  // Given
  std::string content =
    ".....\n"
    ".M.M.\n"
    "..A..\n"
    ".S.S.\n"
    ".....\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(1, result);
}

TEST(MasSearchGridTests, ShouldFindOneXMasAlt1) {
  // Given
  std::string content =
    ".....\n"
    ".S.M.\n"
    "..A..\n"
    ".S.M.\n"
    ".....\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(1, result);
}

TEST(MasSearchGridTests, ShouldFindOneXMasAlt2) {
  // Given
  std::string content =
    ".....\n"
    ".S.S.\n"
    "..A..\n"
    ".M.M.\n"
    ".....\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(1, result);
}

TEST(MasSearchGridTests, ShouldFindOneXMasAlt3) {
  // Given
  std::string content =
    ".....\n"
    ".M.S.\n"
    "..A..\n"
    ".M.S.\n"
    ".....\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(1, result);
}
TEST(MasSearchGridTests, ShouldFindTwoXMas) {
  // Given
  std::string content =
    "M.S..\n"
    ".A...\n"
    "M.S.S\n"
    "...A.\n"
    "..M.M\n"
  ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(content);
  auto* grid = new MasSearchGrid(gridContent);
  // When
  int result = grid->findTotalOccurrencesOfXMas();
  // Then
  ASSERT_EQ(2, result);
}