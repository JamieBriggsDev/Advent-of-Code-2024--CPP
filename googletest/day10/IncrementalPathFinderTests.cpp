//
// Created by Jamie Briggs on 10/12/2024.
//

#include <gtest/gtest.h>

#include "../../cpp/algorithms/pathfinding/IncrementalPathFinder.h"
#include "../../cpp/algorithms/pathfinding/Node.h"

using namespace std;
using namespace core;

TEST(IncrementalPathFinder_FindPath_Tests, ShouldReturnStackWithJustDestination) {
  // Given
  Node * start = new Node(9, 0, 0);
  IncrementalPathFinder pathFinder;
  // When
  auto stacks = pathFinder.findAllPaths(start);
  std::queue<Node*> result = stacks[0];
  // Then
  ASSERT_EQ(1, result.size());
  ASSERT_EQ(start, result.front());

  // Cleanup
  delete start;
}

TEST(IncrementalPathFinder_FindPath_Tests, ShouldReturnStackWithJustDestinationWhenStartNotLinked) {
  // Given
  Node * start = new Node(9, 0, 0);
  Node * second = new Node(8, 0, 1);
  IncrementalPathFinder pathFinder;
  // When
  std::queue<Node*> result = pathFinder.findAllPaths(start)[0];
  // Then
  ASSERT_EQ(result.size(), 1);
  ASSERT_EQ(start, result.front());

  // Cleanup
  delete start;
  delete second;
}

TEST(IncrementalPathFinder_FindPath_Tests, ShouldReturnStackWithJustDestinationWhenStartLinked) {
  // Given
  Node * start = new Node(9, 0, 0);
  Node * second = new Node(8, 0, 1);
  start->addNeighbour(second);
  IncrementalPathFinder pathFinder;
  // When
  std::queue<Node*> result = pathFinder.findAllPaths(start)[0];
  // Then
  ASSERT_EQ(result.size(), 2);

  ASSERT_EQ(start, result.front());
  result.pop();
  ASSERT_EQ(second, result.front());

  // Cleanup
  delete start;
  delete second;
}

TEST(IncrementalPathFinder_FindPath_Tests, ShouldReturnRouteWithThreeNodes) {
  // Given
  Node * start = new Node(9, 0, 0);
  Node * second = new Node(8, 0, 1);
  Node * third = new Node(7, 0, 1);
  start->addNeighbour(second);
  second->addNeighbour(third);
  IncrementalPathFinder pathFinder;
  // When
  std::queue<Node*> result = pathFinder.findAllPaths(start)[0];
  // Then
  ASSERT_EQ(result.size(), 3);

  ASSERT_EQ(start, result.front());
  result.pop();
  ASSERT_EQ(second, result.front());
  result.pop();
  ASSERT_EQ(third, result.front());

  // Cleanup
  delete start;
  delete second;
  delete third;
}


TEST(IncrementalPathFinder_FindPath_Tests, ShouldReturnTwoPaths) {
  // Given
  //   /--->e----> d
  // a -> b -> c -> d
  Node * a = new Node(0, 0, 1);
  Node * b = new Node(1, 1, 1);
  Node * e = new Node(1, 4, 1);
  Node * c = new Node(2, 2, 1);
  Node * d = new Node(3, 5, 1);
  a->addNeighbour(b);
  a->addNeighbour(e);
  b->addNeighbour(c);
  c->addNeighbour(d);
  e->addNeighbour(d);
  IncrementalPathFinder pathFinder;
  // When
  std::queue<Node*> resultOne = pathFinder.findAllPaths(a).at(0);
  std::queue<Node*> resultTwo = pathFinder.findAllPaths(a).at(1);
  // Then
  // Result One
  ASSERT_EQ(resultOne.size(), 3);
  ASSERT_EQ(a, resultOne.front());
  resultOne.pop();
  ASSERT_EQ(e, resultOne.front());
  resultOne.pop();
  ASSERT_EQ(d, resultOne.front());
  // Result Two
  ASSERT_EQ(resultTwo.size(), 4);
  ASSERT_EQ(a, resultTwo.front());
  resultTwo.pop();
  ASSERT_EQ(b, resultTwo.front());
  resultTwo.pop();
  ASSERT_EQ(c, resultTwo.front());
  resultTwo.pop();
  ASSERT_EQ(d, resultTwo.front());

  // Cleanup
  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
}