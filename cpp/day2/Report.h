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
    explicit Report();
    void addNumber(int number) {
      this->reportContents.emplace_back(number);
    }
    std::vector<int> getReportContents() {
      return reportContents;
    }
    bool isSafeDueToTrajectory();
    bool isSafeDueToDifference();
    std::vector<Report> getDampenerReports();
  };
}



#endif //REPORT_H
