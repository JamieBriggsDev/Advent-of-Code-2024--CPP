//
// Created by perso on 19/12/2024.
//

#include "PatternFinder.h"

#include <iostream>
#include <unordered_map>

namespace solutions {

  bool PatternFinder::canFindPattern(Pattern patternDesign, vector<Pattern> towels,
                                     unordered_map<string, bool> &memos) {
    string design = patternDesign.getPattern();
    if (memos.find(design) != memos.end()) {
      return memos[design];
    }
    if (design.empty()) {
      return true;
    }

    for (Pattern towel: towels) {
      string pattern = towel.getPattern();
      if (design.rfind(pattern, 0) == 0) { // Matches prefix
        string remaining = design.substr(pattern.size());
        if (canFindPattern(remaining, towels, memos)) {
          memos[design] += 1;
          return true;
        }
      }
    }

    memos[design] = false;
    return false;
  }

  bool PatternFinder::patternCanBeMade(Pattern pattern, vector<Pattern> towels) {
    unordered_map<string, bool> memo;
    if (canFindPattern(pattern, towels, memo)) {
      std::cout << pattern.getPattern() << " can be made!" << std::endl;
      return true;
    }
    std::cout << pattern.getPattern() << " is impossible." << std::endl;
    return false;
  }
  long long PatternFinder::countWaysToFormPatter(Pattern patternDesign, vector<Pattern> towels,
                                           unordered_map<string, long long> &memos) {
    string design = patternDesign.getPattern();
    if (memos.find(design) != memos.end()) {
      return memos[design];
    }
    if (design.empty()) {
      return 1l;
    }

    long long totalWays = 0;

    for (Pattern towel: towels) {
      string pattern = towel.getPattern();
      if (design.rfind(pattern, 0) == 0) { // Matches prefix
        string remaining = design.substr(pattern.size());
        totalWays += countWaysToFormPatter(remaining, towels, memos);
      }
    }

    memos[design] = totalWays;
    return totalWays;
  }
  long long PatternFinder::countTotalWaysPatternCanBeMade(Pattern pattern, vector<Pattern> towels) {
    unordered_map<string, long long> memo;
    int totalWays = countWaysToFormPatter(pattern, towels, memo);
    if (totalWays > 0) {
      //std::cout << pattern.getPattern() << " can be made with " << totalWays << " permutations." << std::endl;
      return totalWays;
    }
    //std::cout << pattern.getPattern() << " is impossible." << std::endl;
    return 0;
  }
} // namespace solutions
