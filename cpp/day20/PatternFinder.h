//
// Created by perso on 19/12/2024.
//

#ifndef PATTERNFINDER_H
#define PATTERNFINDER_H
#include <string>
#include <vector>
#include <unordered_map>

#include "Pattern.h"

using namespace std;

namespace solutions {

class PatternFinder {
  PatternFinder() = default;
  static bool canFindPattern(Pattern patternDesign, vector<Pattern> towels, unordered_map<string, bool>& memos);
  static long long countWaysToFormPatter(Pattern patternDesign, vector<Pattern> towels, unordered_map<string, long long>& memos);
public:
  static bool patternCanBeMade(Pattern pattern, vector<Pattern> towels);
  static long long countTotalWaysPatternCanBeMade(Pattern pattern, vector<Pattern> towels);
};

} // solutions

#endif //PATTERNFINDER_H
