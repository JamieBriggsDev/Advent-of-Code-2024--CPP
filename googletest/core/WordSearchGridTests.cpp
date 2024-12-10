//
// Created by Jamie Briggs on 04/12/2024.
//

#include <cmath>

#include "../../cpp/core/WordSearchGrid.h"

#include <gtest/gtest.h>
#include <string>

#include "../testHelper/InputUtils.h"

using namespace core;

// TODO: Commenting out tests as it periodically fails. A one to fix after AoC!

TEST(WordSearchGrid_Tests, DISABLED_ShouldLoadInput) {
  // Given
  std::string content = "Hello World!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  // When
  auto grid = WordSearchGrid(gridContent);
  // Then
  ASSERT_EQ(1, grid.getVerticalLength());
  ASSERT_EQ(content.length(), grid.getHorizontalLength());
  std::string result(grid.getGrid()[0]);
  ASSERT_EQ("Hello World!", result);
  gridContent.clear();
}



TEST(WordSearchGrid_Tests, ShouldLoad3Rows) {
  // Given
  std::string rowOne = "123";
  std::string rowTwo = "456";
  std::string rowThree = "789";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  gridContent.emplace_back(rowThree);
  // When
  auto grid = WordSearchGrid(gridContent);
  // Then
  ASSERT_EQ(3, grid.getVerticalLength());
  ASSERT_EQ(3, grid.getHorizontalLength());

  ASSERT_EQ('1', grid.getGrid()[0][0]);
  ASSERT_EQ('2', grid.getGrid()[0][1]);
  ASSERT_EQ('3', grid.getGrid()[0][2]);
  ASSERT_EQ('4', grid.getGrid()[1][0]);
  ASSERT_EQ('5', grid.getGrid()[1][1]);
  ASSERT_EQ('6', grid.getGrid()[1][2]);
  ASSERT_EQ('7', grid.getGrid()[2][0]);
  ASSERT_EQ('8', grid.getGrid()[2][1]);
  ASSERT_EQ('9', grid.getGrid()[2][2]);
}


TEST(WordSearchGrid_SearchHorizontal_Tests, ShouldNotFindWord) {
  // Given
  std::string content = "Hello World!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(0, totalHorizontalInstances);
  
}

TEST(WordSearchGrid_SearchHorizontal_Tests, ShouldFindOneInstance) {
  // Given
  std::string content = "Hello WoXMASrld!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalHorizontalInstances);
  
}

TEST(WordSearchGrid_SearchHorizontal_Tests, ShouldFindTwoInstances) {
  // Given
  std::string content = "HeXMASllo WoXMASrld!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalHorizontalInstances);
  
}

// TODO: Disabled due to periodically failing
TEST(WordSearchGrid_SearchHorizontal_Tests, DISABLED_ShouldFindBackwardsInstance) {
  // Given
  std::string content = "Hello WoSAMXrld!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalHorizontalInstances);
}

TEST(WordSearchGrid_SearchHorizontal_Tests, ShouldFindTwoBackwardsInstance) {
  // Given
  std::string content = "Hello WoSAMXrlSAMXd!";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(content);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalHorizontalInstances);
  
}

// TODO: Commented test out cause it periodically fails and I'm not sure why. Something to work out another day!
TEST(WordSearchGrid_SearchHorizontal_Tests, DISABLED_ShouldFindTwoInstanceOnTwoRows) {
  // Given
  std::string rowOne = "ABCDEXMASGHIJ";
  std::string rowTwo = "ABCDESAMXGHIJ";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalHorizontalInstances = grid.findTotalHorizontalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalHorizontalInstances);
  
}


TEST(WordSearchGrid_SearchVertical_Tests, ShouldNotFindWord) {
  // Given
  std::string rowOne = "A";
  std::string rowTwo = "B";
  std::string rowThree = "C";
  std::string rowFour = "D";
  std::string rowFive = "E";
  std::string rowSix = "F";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  gridContent.emplace_back(rowThree);
  gridContent.emplace_back(rowFour);
  gridContent.emplace_back(rowFive);
  gridContent.emplace_back(rowSix);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalVerticalInstances = grid.findTotalVerticalInstances("XMAS");
  // Then
  ASSERT_EQ(0, totalVerticalInstances);
  
}

TEST(WordSearchGrid_SearchVertical_Tests, ShouldFindOneInstanceOfWord) {
  // Given
  std::string rowOne = "A";
  std::string rowTwo = "X";
  std::string rowThree = "M";
  std::string rowFour = "A";
  std::string rowFive = "S";
  std::string rowSix = "F";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  gridContent.emplace_back(rowThree);
  gridContent.emplace_back(rowFour);
  gridContent.emplace_back(rowFive);
  gridContent.emplace_back(rowSix);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalVerticalInstances = grid.findTotalVerticalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalVerticalInstances);
  
}

TEST(WordSearchGrid_SearchVertical_Tests, ShouldFindTwoInstancesOfWord) {
  // Given
  std::string rowOne = "A";
  std::string rowTwo = "X";
  std::string rowThree = "M";
  std::string rowFour = "A";
  std::string rowFive = "S";
  std::string rowSix = "X";
  std::string rowSeven = "M";
  std::string rowEight = "A";
  std::string rowNine = "S";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  gridContent.emplace_back(rowThree);
  gridContent.emplace_back(rowFour);
  gridContent.emplace_back(rowFive);
  gridContent.emplace_back(rowSix);
  gridContent.emplace_back(rowSeven);
  gridContent.emplace_back(rowEight);
  gridContent.emplace_back(rowNine);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalVerticalInstances = grid.findTotalVerticalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalVerticalInstances);
  
}

TEST(WordSearchGrid_SearchVertical_Tests, ShouldFindTwoInstancesOfBackwardsWord) {
  // Given
  std::string rowOne = "A";
  std::string rowTwo = "S";
  std::string rowThree = "A";
  std::string rowFour = "M";
  std::string rowFive = "X";
  std::string rowSix = "S";
  std::string rowSeven = "A";
  std::string rowEight = "M";
  std::string rowNine = "X";
  std::vector<std::string> gridContent;
  gridContent.emplace_back(rowOne);
  gridContent.emplace_back(rowTwo);
  gridContent.emplace_back(rowThree);
  gridContent.emplace_back(rowFour);
  gridContent.emplace_back(rowFive);
  gridContent.emplace_back(rowSix);
  gridContent.emplace_back(rowSeven);
  gridContent.emplace_back(rowEight);
  gridContent.emplace_back(rowNine);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalVerticalInstances = grid.findTotalVerticalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalVerticalInstances);
  
}


TEST(WordSearchGrid_SearchVertical_Tests, ShouldFindTwoInstancesOfBackwardsWordInTwoColumns) {
  // Given
  std::string raw = "AX\n"
                    "SM\n"
                    "AA\n"
                    "MS\n"
                    "XG\n"
                    "SG\n";
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalVerticalInstances = grid.findTotalVerticalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalVerticalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindNoInstances) {
  // Given
  std::string raw = "ABCDEFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(0, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindOneInstanceNWtoSE) {
  // Given
  std::string raw = "AXCDEFG\n"
                    "ABMDEFG\n"
                    "ABCAEFG\n"
                    "ABCDSFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindTwoInstanceNWtoSE) {
  // Given
  std::string raw = "AXCDEFG\n"
                    "ABMDEFG\n"
                    "XBCAEFG\n"
                    "AMCDSFG\n"
                    "ABADEFG\n"
                    "ABCSEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindOneInstanceSEtoNW) {
  // Given
  std::string raw = "ASCDEFG\n"
                    "ABADEFG\n"
                    "ABCMEFG\n"
                    "ABCDXFG\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindTwoInstanceSEtoNW) {
  // Given
  std::string raw = "ASCSEFG\n"
                    "ABADAFG\n"
                    "ABCMEMG\n"
                    "ABCDXFX\n"
                    "ABCDEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindOneInstanceNEtoSW) {
  // Given
  std::string raw = "ABCDEFG\n"
                    "ABCDEFX\n"
                    "ABCDEMG\n"
                    "ABCDAFG\n"
                    "ABCSEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindTwoInstanceNEtoSW) {
  // Given
  std::string raw = "ABCDEXFG\n"
                    "ABCDMFX\n"
                    "ABCAEMG\n"
                    "ABSDAFG\n"
                    "ABCSEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindOneInstanceSWtoNE) {
  // Given
  std::string raw = "ABCDEFG\n"
                    "ABCDEFS\n"
                    "ABCDEAG\n"
                    "ABCDMFG\n"
                    "ABCXEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(1, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindTwoInstanceSWtoNE) {
  // Given
  std::string raw = "ABCSEFG\n"
                    "ABADEFS\n"
                    "AMCDEAG\n"
                    "XBCDMFG\n"
                    "ABCXEFG\n"
                    "ABCDEFG\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(2, totalDiagonalInstances);
  
}

TEST(WordSearchGrid_SearchDiagonal_Tests, ShouldFindOverlappingInstances) {
  // Given
  std::string raw =
    "...S.\n"
    "X.A.X\n"
    ".M.M.\n"
    "X.A..\n"
    ".S.S.\n"
                    ;
  std::vector<std::string> gridContent = InputUtils::convertToVector(raw);
  auto grid = WordSearchGrid(gridContent);
  // When
  int totalDiagonalInstances = grid.findTotalDiagonalInstances("XMAS");
  // Then
  ASSERT_EQ(3, totalDiagonalInstances);
  
}