//
// Created by Jamie Briggs on 04/12/2024.
//

#ifndef WORDSEARCHROW_H
#define WORDSEARCHROW_H
#include <regex>
#include <string>


class WordSearchRow {
std::string row;
public:
  explicit WordSearchRow(std::string row);
  int findTotalMatches(const std::string& word);
  std::string getContents() {
    return row;
  }
};



#endif //WORDSEARCHROW_H
