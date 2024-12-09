//
// Created by perso on 09/12/2024.
//

#include <gtest/gtest.h>
#include "../testHelper/InputUtils.h"

#include "../../cpp/day10/DiskMap.h"

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
