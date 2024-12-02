//
// Created by Jamie Briggs on 02/12/2024.
//

#ifndef REPORT_H
#define REPORT_H
#include <queue>


namespace solutions {
  class Report {
    std::vector<int> reportContents;
  public:
    explicit Report(const std::string& reportRaw);
    std::vector<int> getReportContents() {
      return reportContents;
    }
    bool isSafeDueToTrajectory();
    bool isSafeDueToDifference();
  };
}



#endif //REPORT_H
