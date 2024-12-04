//
// Created by Jamie Briggs on 04/12/2024.
//

#include "WordSearchRow.h"

#include <algorithm>
#include <utility>
WordSearchRow::WordSearchRow(std::string row) { this->row = std::move(row); }
int WordSearchRow::findTotalMatches(const std::string& word) {

    int totalMatches = 0;

    // Forward search
    size_t pos = row.find(word);
    while (pos != std::string::npos) {
        ++totalMatches;
        pos = row.find(word, pos + 1);
    }

    // Backward search
    std::string reversedRow = row;
    std::reverse(reversedRow.begin(), reversedRow.end());

    pos = reversedRow.find(word);
    while (pos != std::string::npos) {
        ++totalMatches;
        pos = reversedRow.find(word, pos + 1);
    }

    return totalMatches;
}
