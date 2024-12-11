//
// Created by Jamie Briggs on 10/12/2024.
//

#include "Day10.h"

#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>

#include "../core/IncrementalPathFinder.h"
#include "../core/PathFinder.h"
#include "TopographicMap.h"

namespace solutions {
  std::string Day10::solvePartOne(const helper::SolutionInput *input) {
    core::TopographicMap map = core::TopographicMap(input->getTestInput());
    // Get all starting positions
    auto nodes = map.getStartingPositions();
    // Get all paths from positions
    vector<queue<core::Node*>> allPaths;

    core::IncrementalPathFinder pathFinder;

    std::map<core::Node*, int> trailHeadPoints;

    for (auto node: nodes) {
      // First add node to trailHeadPoints
      trailHeadPoints[node] = 0;
      // Next start map of found finishing nodes
      std::unordered_set<core::Node *> finishingNodes;
      // Next find all possible paths with starting node
      auto paths = pathFinder.findAllPaths(node);
      // Loop through each path, and find ones which end on a peak (i.e size of 10)
      for(auto path : paths) {
        if (path.size() == 10) {
          core::Node* destination = path.back();
          if(!finishingNodes.contains(destination)) {
            finishingNodes.insert(destination);
            trailHeadPoints[node]++;
          }
        }
      }
    }

    // Find sum of all values in trailHeadPoints
    int sum = 0;
    for (const auto &pair: trailHeadPoints) {
      sum += pair.second;
    }

    return std::to_string(sum);
  }
  std::string Day10::solvePartTwo(const helper::SolutionInput *input) { return "To Solve"; }
} // solutions