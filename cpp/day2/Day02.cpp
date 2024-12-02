//
// Created by Jamie Briggs on 05/12/2023.
//

#include "Day02.h"

#include <iostream>
#include <vector>

#include "../helper/SolutionInput.h"
#include "Report.h"


using namespace std;


namespace solutions {
  string Day02::solvePartOne(const helper::SolutionInput *input) {

    vector<Report> reports;
    for(const auto& row : input->getTestInput()) {
      Report newReport = Report(row);
      reports.emplace_back(newReport);
    }

    int totalSafeReports = 0;

    for (Report report: reports) {
      bool is_safe_due_to_difference = report.isSafeDueToDifference();
      bool is_safe_due_to_trajectory = report.isSafeDueToTrajectory();
      if (is_safe_due_to_difference && is_safe_due_to_trajectory) {
        totalSafeReports++;
      }
    }

    return std::to_string(totalSafeReports);
  }


  string Day02::solvePartTwo(const helper::SolutionInput *input) {
    return "Yet to solve";
  }
} // namespace solutions
