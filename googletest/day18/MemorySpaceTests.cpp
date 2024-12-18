//
// Created by perso on 18/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/day18/FreeByte.h"
#include "../../cpp/day18/MemorySpace.h"
#include "../testHelper/InputUtils.h"

using namespace std;
using namespace solutions;

class MemorySpaceTests : public ::testing::Test {

protected:
  vector<string> smallInput;

  void SetUp() override {
    smallInput = InputUtils::convertToVector("1,1\n"
                                             "1,2\n"
                                             "0,2\n");
  }
  void TearDown() override { smallInput.clear(); }
};

TEST_F(MemorySpaceTests, ShouldInitialize) {
  // Given
  // When
  algorithms::MemorySpace memorySpace(smallInput, 3);
  // Then
  ASSERT_EQ(3, memorySpace.getHorizontalLength());
  ASSERT_EQ(3, memorySpace.getVerticalLength());
  // Check Spaces
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[0][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[1][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[2][0]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[0][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[1][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[2][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[0][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[1][2]) != nullptr);
  EXPECT_TRUE(dynamic_cast<FreeByte*>(memorySpace.getGrid()[2][2]) != nullptr);
  // Check start
  EXPECT_EQ(core::Pair(0, 0), memorySpace.getStart()->getPosition());
  EXPECT_EQ(core::Pair(2, 2), memorySpace.getFinish()->getPosition());
}

TEST_F(MemorySpaceTests, ShouldDropBytes) {
  // Given
  algorithms::MemorySpace memorySpace(smallInput, 3);
  // When
  memorySpace.dropBytes(2);
  // Then
  ASSERT_EQ(3, memorySpace.getHorizontalLength());
  ASSERT_EQ(3, memorySpace.getVerticalLength());
  // Check Spaces
  EXPECT_TRUE(dynamic_cast<CorruptedByte*>(memorySpace.getGrid()[1][1]) != nullptr);
  EXPECT_TRUE(dynamic_cast<CorruptedByte*>(memorySpace.getGrid()[2][1]) != nullptr);
  EXPECT_EQ(2, memorySpace.getRemovedFreeBytes().size());
  // Check north neighbour
  EXPECT_EQ(2, dynamic_cast<FreeByte*>(memorySpace.getGrid()[0][1])->getNeighbourNodes().size());
  // Check west neighbour
  EXPECT_EQ(2, dynamic_cast<FreeByte*>(memorySpace.getGrid()[1][0])->getNeighbourNodes().size());
}
