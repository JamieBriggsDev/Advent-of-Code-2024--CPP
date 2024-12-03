//
// Created by Jamie Briggs on 02/12/2024.
//

#include "Report.h"

#include "../helper/StringUtils.h"

solutions::Report::Report(const std::string &reportRaw) {
  std::vector<std::string> splitReportRaw = helper::StringUtils::splitString(reportRaw, " ");
  for (const auto &item: splitReportRaw) {
    this->reportContents.push_back(helper::StringUtils::toInt(item));
  }
}
solutions::Report::Report() {
  // Empty constructor
}
bool solutions::Report::isSafeDueToTrajectory() {

  // Ensures that even two identical numbers at the start are caught
  if (this->reportContents[0] == this->reportContents[1]) {
    return false;
  }

  // Understand should numbers increase or decrease
  bool isIncreasing = this->reportContents[0] < this->reportContents[1];
  // Start with second number
  for (int i = 1; i < this->reportContents.size(); i++) {
    if (this->reportContents[i] <= this->reportContents[i - 1] == isIncreasing) {
        return false;
    }
  }

  return true;
}
bool solutions::Report::isSafeDueToDifference() {
  // Start with second number
  for (int i = 1; i < this->reportContents.size(); i++) {
    int a = this->reportContents[i - 1];
    int b = this->reportContents[i];
    int result = (a - b) < 0 ? (a - b) * -1 : (a - b);
    if (result < 1 || result > 3) {
      return false;
    }
  }
  return true;
}
std::vector<solutions::Report> solutions::Report::getDampenerReports() {
  std::vector<solutions::Report> dampenerReports;
  if(reportContents.size() <= 1) {
    return dampenerReports;
  }
  for(int i = 0; i < this->reportContents.size(); i++) {
    // Create a report with every number in existing report apart from
    //  report at index `i`
    Report report = Report();
    for(int ix = 0; ix < this->reportContents.size(); ix++) {
      if(ix != i) {
        report.addNumber(this->reportContents[ix]);
      }
    }
    dampenerReports.emplace_back(report);
  }
  return dampenerReports;
}
