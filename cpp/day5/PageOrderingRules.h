//
// Created by Jamie Briggs on 05/12/2024.
//

#ifndef PAGEORDERINGRULES_H
#define PAGEORDERINGRULES_H
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace day5 {

struct PageOrderingRuleSpec {
  std::unordered_set<int> pagesBefore;
  std::unordered_set<int> pagesAfter;
};

class PageOrderingRules {
 unordered_map<int, PageOrderingRuleSpec> rules;
public:
  unordered_map<int, PageOrderingRuleSpec> getRules() { return rules; }
  void importPageOrderingRule(const string& rawRule);
  bool isSubjectNumberAfterTargetNumber(int targetNumber, int subjectNumber);
  bool isSubjectNumberBeforeTargetNumber(int targetNumber, int subjectNumber);
};

}




#endif //PAGEORDERINGRULES_H
