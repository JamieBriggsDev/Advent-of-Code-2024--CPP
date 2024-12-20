//
// Created by Jamie Briggs on 19/12/2024.
//

#ifndef PATTERN_H
#define PATTERN_H

#include <string>

using namespace std;

namespace solutions {

class Pattern {
  string pattern;
public:
  Pattern(string pattern) {
    this->pattern = pattern;
  }
  string getPattern() {
    return pattern;
  }
};

} // solutions

#endif //PATTERN_H
