//
// Created by Jamie Briggs on 05/12/2024.
//

#ifndef PAGEUPDATE_H
#define PAGEUPDATE_H

#include <string>
#include <vector>

#include "PageOrderingRules.h"

namespace day5 {

  class PageUpdate {
    std::vector<int> updates;
  protected:
    bool isNumberAfterTargetNumber(int numberToCheck, int targetNumber) const;
    bool isNumberBeforeTargetNumber(int numberToCheck, int targetNumber) const;
  public:
    explicit PageUpdate(const std::string& rawUpdates);
    [[nodiscard]] std::vector<int> getUpdates() const { return updates; }
    int getMiddleNumber() const;
    bool isInCorrectOrder(PageOrderingRules orderingRules) const;
  };

} // namespace day5

#endif // PAGEUPDATE_H
