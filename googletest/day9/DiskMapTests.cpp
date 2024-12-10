//
// Created by Jamie Briggs on 09/12/2024.
//

#include <gtest/gtest.h>
#include "../testHelper/InputUtils.h"

#include "../../cpp/day9/DiskMap.h"

TEST(DiskMap_Initialize_Tests, ShouldInitializeWithSingleFile) {
  // Given
  auto input = "3";
  // When
  auto diskMap = solutions::DiskMap(input);
  // Then
  auto contents = diskMap.getContents();
  ASSERT_EQ(1, contents.size());
  ASSERT_EQ(3, contents[0]);
}

TEST(DiskMap_Initialize_Tests, ShouldInitializeWithThreeItems) {
  // Given
  auto input = "321";
  // When
  auto diskMap = solutions::DiskMap(input);
  // Then
  auto contents = diskMap.getContents();
  ASSERT_EQ(3, contents.size());
  ASSERT_EQ(3, contents[0]);
  ASSERT_EQ(2, contents[1]);
  ASSERT_EQ(1, contents[2]);
}

TEST(DiskMap_GetVisualLayout_Tests, ShouldReturnWithNoEmptySpace) {
  // Given
  auto input = "3";
  // When
  auto diskMap = solutions::DiskMap(input);
  // Then
  auto contents = diskMap.getFileLocations();
  ASSERT_EQ(3, contents.size());

  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(3, contents[0]->fileSize);

  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(3, contents[1]->fileSize);

  ASSERT_EQ(0, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);
}

TEST(DiskMap_GetVisualLayout_Tests, ShouldReturnWithEmptySpace) {
  // Given
  auto input = "321";
  // When
  auto diskMap = solutions::DiskMap(input);
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 000..1
  ASSERT_EQ(6, contents.size());
  ASSERT_EQ(3, diskMap.getLeftMostEmptyIndex());
  ASSERT_EQ(5, diskMap.getRightMostFileIndex());
  ASSERT_FALSE(diskMap.hasCompletedDefrag());

  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(3, contents[0]->fileSize);

  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(3, contents[1]->fileSize);

  ASSERT_EQ(0, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);

  ASSERT_EQ(nullptr, contents[3]);
  ASSERT_EQ(nullptr, contents[4]);

  ASSERT_EQ(1, contents[5]->id);
  ASSERT_EQ(1, contents[5]->fileSize);
}

TEST(DiskMap_Defrag_Tests, ShouldDefragOnce) {
  // Given
  auto input = "321";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragStep();
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 0001..
  ASSERT_EQ(6, contents.size());
  ASSERT_EQ(4, diskMap.getLeftMostEmptyIndex());
  ASSERT_EQ(3, diskMap.getRightMostFileIndex());
  ASSERT_TRUE(diskMap.hasCompletedDefrag());

  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(3, contents[0]->fileSize);

  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(3, contents[1]->fileSize);

  ASSERT_EQ(0, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);

  ASSERT_EQ(1, contents[3]->id);
  ASSERT_EQ(1, contents[3]->fileSize);

  ASSERT_EQ(nullptr, contents[4]);
  ASSERT_EQ(nullptr, contents[5]);
}

TEST(DiskMap_Defrag_Tests, ShouldDefragOnceLonger) {
  // Given
  auto input = "324";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragStep();
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 0001.111.
  ASSERT_EQ(9, contents.size());
  ASSERT_EQ(4, diskMap.getLeftMostEmptyIndex());
  ASSERT_EQ(7, diskMap.getRightMostFileIndex());
  ASSERT_FALSE(diskMap.hasCompletedDefrag());

  // File one
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(3, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(3, contents[1]->fileSize);
  ASSERT_EQ(0, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);
  // File two
  ASSERT_EQ(1, contents[3]->id);
  ASSERT_EQ(4, contents[3]->fileSize);
  // Missing location
  ASSERT_EQ(nullptr, contents[4]);
  // File two continued
  ASSERT_EQ(1, contents[5]->id);
  ASSERT_EQ(4, contents[5]->fileSize);
  ASSERT_EQ(1, contents[6]->id);
  ASSERT_EQ(4, contents[6]->fileSize);
  ASSERT_EQ(1, contents[7]->id);
  ASSERT_EQ(4, contents[7]->fileSize);
  // Missing location
  ASSERT_EQ(nullptr, contents[8]);
}

TEST(DiskMap_Defrag_Tests, ShouldDefragTwiceLonger) {
  // Given
  auto input = "324";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragStep();
  diskMap.performDefragStep();
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 0001111..
  ASSERT_EQ(9, contents.size());
  ASSERT_EQ(7, diskMap.getLeftMostEmptyIndex());
  ASSERT_EQ(6, diskMap.getRightMostFileIndex());
  ASSERT_TRUE(diskMap.hasCompletedDefrag());

  // File one
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(3, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(3, contents[1]->fileSize);
  ASSERT_EQ(0, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);
  // File two
  ASSERT_EQ(1, contents[3]->id);
  ASSERT_EQ(4, contents[3]->fileSize);
  ASSERT_EQ(1, contents[4]->id);
  ASSERT_EQ(4, contents[4]->fileSize);
  ASSERT_EQ(1, contents[5]->id);
  ASSERT_EQ(4, contents[5]->fileSize);
  ASSERT_EQ(1, contents[6]->id);
  ASSERT_EQ(4, contents[6]->fileSize);
  // Missing location
  ASSERT_EQ(nullptr, contents[7]);
  ASSERT_EQ(nullptr, contents[8]);
}


TEST(DiskMap_DefragWholeFile_Tests, ShouldDefragOnce) {
  // Given
  auto input = "23123";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragFullFileStep();
  // Before should be 00...1..222
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 002221.....
  ASSERT_EQ(11, contents.size());
  ASSERT_FALSE(diskMap.hasFinishedFullDefrag());

  // File One
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(2, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(2, contents[1]->fileSize);
  // File Three
  ASSERT_EQ(2, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);
  ASSERT_EQ(2, contents[3]->id);
  ASSERT_EQ(3, contents[3]->fileSize);
  ASSERT_EQ(2, contents[4]->id);
  ASSERT_EQ(3, contents[4]->fileSize);
  // File Two
  ASSERT_EQ(1, contents[5]->id);
  ASSERT_EQ(1, contents[5]->fileSize);
  ASSERT_EQ(nullptr, contents[6]);
  ASSERT_EQ(nullptr, contents[7]);
}

TEST(DiskMap_DefragWholeFile_Tests, ShouldDefragTwiceAndFinish) {
  // Given
  auto input = "23123";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragFullFileStep();
  diskMap.performDefragFullFileStep();
  // Before should be 00...1..222
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 002221.....
  ASSERT_EQ(11, contents.size());
  ASSERT_TRUE(diskMap.hasFinishedFullDefrag());

  // File One
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(2, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(2, contents[1]->fileSize);
  // File Three
  ASSERT_EQ(2, contents[2]->id);
  ASSERT_EQ(3, contents[2]->fileSize);
  ASSERT_EQ(2, contents[3]->id);
  ASSERT_EQ(3, contents[3]->fileSize);
  ASSERT_EQ(2, contents[4]->id);
  ASSERT_EQ(3, contents[4]->fileSize);
  // File Two
  ASSERT_EQ(1, contents[5]->id);
  ASSERT_EQ(1, contents[5]->fileSize);
  ASSERT_EQ(nullptr, contents[6]);
  ASSERT_EQ(nullptr, contents[7]);
}

TEST(DiskMap_DefragWholeFile_Tests, ShouldNotDefragWhenNotEnoughSpace) {
  // Given
  auto input = "22123";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragFullFileStep();
  // Before should be 00..1..222
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 00..1..222 due to nothing happening
  ASSERT_EQ(10, contents.size());
  ASSERT_FALSE(diskMap.hasFinishedFullDefrag());

  // File One
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(2, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(2, contents[1]->fileSize);
  ASSERT_EQ(nullptr, contents[2]);
  ASSERT_EQ(nullptr, contents[3]);
  // File Two
  ASSERT_EQ(1, contents[4]->id);
  ASSERT_EQ(1, contents[4]->fileSize);
  ASSERT_EQ(nullptr, contents[5]);
  ASSERT_EQ(nullptr, contents[6]);
  // File Three
  ASSERT_EQ(2, contents[7]->id);
  ASSERT_EQ(3, contents[7]->fileSize);
  ASSERT_EQ(2, contents[8]->id);
  ASSERT_EQ(3, contents[8]->fileSize);
  ASSERT_EQ(2, contents[9]->id);
  ASSERT_EQ(3, contents[9]->fileSize);
}

TEST(DiskMap_DefragWholeFile_Tests, ShouldDefragTwice) {
  // Given
  auto input = "22123";
  auto diskMap = solutions::DiskMap(input);
  // When
  diskMap.performDefragFullFileStep();
  diskMap.performDefragFullFileStep();
  // Before should be 00..1..222
  // Then
  auto contents = diskMap.getFileLocations();
  // Should end 001....222 due to nothing happening
  ASSERT_EQ(10, contents.size());
  ASSERT_TRUE(diskMap.hasFinishedFullDefrag());

  // File One
  ASSERT_EQ(0, contents[0]->id);
  ASSERT_EQ(2, contents[0]->fileSize);
  ASSERT_EQ(0, contents[1]->id);
  ASSERT_EQ(2, contents[1]->fileSize);
  // File Two
  ASSERT_EQ(1, contents[2]->id);
  ASSERT_EQ(1, contents[2]->fileSize);
  ASSERT_EQ(nullptr, contents[3]);
  ASSERT_EQ(nullptr, contents[4]);
  ASSERT_EQ(nullptr, contents[5]);
  ASSERT_EQ(nullptr, contents[6]);
  // File Three
  ASSERT_EQ(2, contents[7]->id);
  ASSERT_EQ(3, contents[7]->fileSize);
  ASSERT_EQ(2, contents[8]->id);
  ASSERT_EQ(3, contents[8]->fileSize);
  ASSERT_EQ(2, contents[9]->id);
  ASSERT_EQ(3, contents[9]->fileSize);
}


