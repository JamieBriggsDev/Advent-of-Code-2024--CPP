//
// Created by Jamie Briggs on 19/12/2024.
//

#ifndef PATTERNHOLDER_H
#define PATTERNHOLDER_H

#include <string>
#include <vector>

#include "../helper/StringUtils.h"
#include "Pattern.h"

namespace solutions {

class PatternHolder {
  vector<Pattern> towels;
  vector<Pattern> designsToMatch;
public:
  PatternHolder(vector<string> designsRaw, const string &towelsRaw) {
    for (string pattern : designsRaw) {
      Pattern p(pattern);
      designsToMatch.emplace_back(p);
    }

    
    for (string design : helper::StringUtils::splitString(towelsRaw, ", ")) {
      Pattern p(design);
      towels.emplace_back(p);
    }
  }

  vector<Pattern> getTowels() {
    return towels;
  }
  vector<Pattern> getDesigns() {
    return designsToMatch;
  }
};

} // solutions

#endif //PATTERNHOLDER_H
