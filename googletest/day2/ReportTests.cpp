//
// Created by Jamie Briggs on 01/12/2024.
//


#include <gtest/gtest.h>

#include "../../cpp/day2/Report.h"

TEST(Report_Tests, ShouldLoadRawReportWithOneNumber) {
  // Given
  std::string rawReport = "2";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(1, subject->getReportContents().size());
  EXPECT_EQ(2, subject->getReportContents()[0]);
}

TEST(Report_Tests, ShouldLoadRawReportWithTwoNumbers) {
  // Given
  std::string rawReport = "1 3";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(2, subject->getReportContents().size());
  EXPECT_EQ(1, subject->getReportContents()[0]);
  EXPECT_EQ(3, subject->getReportContents()[1]);
}

TEST(Report_Tests, ShouldLoadRawReportWithManyLongNumbers) {
  // Given
  std::string rawReport = "12 36 321 1";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(4, subject->getReportContents().size());
  EXPECT_EQ(12, subject->getReportContents()[0]);
  EXPECT_EQ(36, subject->getReportContents()[1]);
  EXPECT_EQ(321, subject->getReportContents()[2]);
  EXPECT_EQ(1, subject->getReportContents()[3]);
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnTrueForTrajectoryWhenOneNumber) {
  // Given
  std::string rawReport = "12";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnTrueForTrajectoryWhenTwoNumbers) {
  // Given
  std::string rawReport = "12 30";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnTrueForTrajectoryWhenThreeNumbers) {
  // Given
  std::string rawReport = "12 30 45";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnFalseWhenNumbersIncreaseThenDecrease) {
  // Given
  std::string rawReport = "12 30 28";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnFalseWhenNumbersDecreaseThenIncrease) {
  // Given
  std::string rawReport = "12 6 10";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnTrueWhenLoadsOfNumbersIncreasing) {
  // Given
  std::string rawReport = "1 2 3 4 5 6 7 8 9 10";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnTrueWhenLoadsOfNumbersDescreasing) {
  // Given
  std::string rawReport = "10 9 8 7 6 5 4 3 2 1";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnFalseWhenTwoIdenticalNumbers) {
  // Given
  std::string rawReport = "1 2 2 3";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnFalseWhenTwoIdenticalNumbersAtStartOfReportIncreasing) {
  // Given
  std::string rawReport = "2 2 3 4";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToTrajectory_Tests, ShouldReturnFalseWhenTwoIdenticalNumbersAtStartOfReportDecreasing) {
  // Given
  std::string rawReport = "4 4 3 2";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToTrajectory());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWhenOneNumber) {
  // Given
  std::string rawReport = "2";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToDifference());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWhenTwoNumbersWith1Difference) {
  // Given
  std::string rawReport = "2 3";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToDifference());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWhenTwoNumbersWith2Difference) {
  // Given
  std::string rawReport = "2 4";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToDifference());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWhenTwoNumbersWith3Difference) {
  // Given
  std::string rawReport = "2 5";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToDifference());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWhenTwoNumbersWith4Difference) {
  // Given
  std::string rawReport = "2 6";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(false, subject->isSafeDueToDifference());
}

TEST(Report_IsSafeDueToDifference_Tests, ShouldReturnTrueWithFiveNumbers) {
  // Given
  std::string rawReport = "7 6 4 2 1";
  // When
  auto* subject = new solutions::Report(rawReport);
  // Then
  EXPECT_EQ(true, subject->isSafeDueToDifference());
}

TEST(Report_GetDampenerReports_Tests, ShouldReturnEmptyVectorWithOneNumber){
  // Given
  std::string rawReport = "1";
  auto* subject = new solutions::Report(rawReport);
  // When
  std::vector<solutions::Report> result = subject->getDampenerReports();
  // Then
  EXPECT_EQ(true, result.empty());
}

TEST(Report_GetDampenerReports_Tests, ShouldReturnTwoVectorsWithTwoNumbers){
  // Given
  std::string rawReport = "1 3";
  auto* subject = new solutions::Report(rawReport);
  // When
  std::vector<solutions::Report> result = subject->getDampenerReports();
  // Then
  EXPECT_EQ(2, result.size());
  EXPECT_EQ(1, result[0].getReportContents().size());
  EXPECT_EQ(1, result[1].getReportContents().size());

}