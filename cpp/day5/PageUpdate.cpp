//
// Created by Jamie Briggs on 05/12/2024.
//

#include "PageUpdate.h"
#include <sstream>
#include <algorithm>

namespace day5 {
  bool PageUpdate::isNumberAfterTargetNumber(int numberToCheck, int targetNumber) const {
    // First find the index of the number to check
    int indexToCheck = std::find(updates.begin(), updates.end(), numberToCheck) - updates.begin();
    // Second find the index of the target number, and return if indexToCheck is larger
    return indexToCheck > std::find(updates.begin(), updates.end(), targetNumber) - updates.begin();
  }
  bool PageUpdate::isNumberBeforeTargetNumber(int numberToCheck, int targetNumber) const {
    // First find the index of the number to check
    int indexToCheck = std::find(updates.begin(), updates.end(), numberToCheck) - updates.begin();
    // Second find the index of the target number, and return if indexToCheck is smaller
    return indexToCheck < std::find(updates.begin(), updates.end(), targetNumber) - updates.begin();
  }

  PageUpdate::PageUpdate(const std::string &rawUpdates) {
    std::stringstream ss(rawUpdates);
    std::string item;
    while (std::getline(ss, item, ',')) {
      // Process each item
      // Convert and store in updates vector, if necessary
      updates.push_back(std::stoi(item)); // Assuming integers
    }
  }
  int PageUpdate::getMiddleNumber() const {
    // Logic behind this math:
    // 1.) 1,2,3,4,5 = 5 numbers
    // 2.) 5 + 1 = 6
    // 3.) 6 / 2 = 3 = 3rd position is the middle
    // 4.) 3 - 1 = 2 Which is the third position of an array starting at 0
    int middleIndex = ((this->updates.size() + 1) / 2) - 1;
    return this->updates[middleIndex];
  }
  bool PageUpdate::isInCorrectOrder(PageOrderingRules orderingRules) const {
    bool hadToBeCorrected = false;
    for (int pageCurrentlyCheckingIndex = 0; pageCurrentlyCheckingIndex < updates.size();
         pageCurrentlyCheckingIndex++) {
      for (int pageCurrentlyCrossReferencingIndex = 0; pageCurrentlyCrossReferencingIndex < updates.size();
           pageCurrentlyCrossReferencingIndex++) {
        // Skip if both indices are the same
        if (pageCurrentlyCheckingIndex == pageCurrentlyCrossReferencingIndex) {
          continue;
        }
        int pageNumberCurrentlyChecking = this->updates[pageCurrentlyCheckingIndex];
        int pageNumberCurrentlyCrossReferencing = this->updates[pageCurrentlyCrossReferencingIndex];

        // Before numbers
        if (pageCurrentlyCrossReferencingIndex < pageCurrentlyCheckingIndex) {
          if (!orderingRules.isSubjectNumberBeforeTargetNumber(pageNumberCurrentlyChecking,
                                                               pageNumberCurrentlyCrossReferencing)) {
            return false;
          }
        }
        // After numbers
        else {
          if (!orderingRules.isSubjectNumberAfterTargetNumber(pageNumberCurrentlyChecking,
                                                              pageNumberCurrentlyCrossReferencing)) {
            return false;
          }
        }
      }
    }
    return true;
  }
  void PageUpdate::fixOrder(PageOrderingRules orderingRules) {
    for (int pageCurrentlyCheckingIndex = 0; pageCurrentlyCheckingIndex < updates.size();
         pageCurrentlyCheckingIndex++) {
      for (int pageCurrentlyCrossReferencingIndex = 0; pageCurrentlyCrossReferencingIndex < updates.size();
           pageCurrentlyCrossReferencingIndex++) {
        // Skip if both indices are the same
        if (pageCurrentlyCheckingIndex == pageCurrentlyCrossReferencingIndex) {
          continue;
        }
        int pageNumberCurrentlyChecking = this->updates[pageCurrentlyCheckingIndex];
        int pageNumberCurrentlyCrossReferencing = this->updates[pageCurrentlyCrossReferencingIndex];

        // Before numbers
        if (pageCurrentlyCrossReferencingIndex < pageCurrentlyCheckingIndex) {
          if (!orderingRules.isSubjectNumberBeforeTargetNumber(pageNumberCurrentlyChecking,
                                                               pageNumberCurrentlyCrossReferencing)) {
            // Move before number to be after target index
            std::swap(updates[pageCurrentlyCheckingIndex], updates[pageCurrentlyCrossReferencingIndex]);
          }
        }
        // After numbers
        else {
          if (!orderingRules.isSubjectNumberAfterTargetNumber(pageNumberCurrentlyChecking,
                                                              pageNumberCurrentlyCrossReferencing)) {
            std::swap(updates[pageCurrentlyCheckingIndex], updates[pageCurrentlyCrossReferencingIndex]);
          }
        }
      }
    }
  }
} // namespace day5
