//
// Created by Jamie Briggs on 05/12/2023.
//

#include "FileReader.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
using namespace helper;

SolutionInput* FileReader::readFile(const string& fileLocation) {
  vector<string> solutionInput;
  if (FILE *fp = fopen(fileLocation.c_str(), "r")) {
    char row[500];

    // This reads a line up to 500 characters long
    while (fscanf(fp, "%500s", &row) == 1) {
      solutionInput.emplace_back(row);
    }
    fclose(fp);
  }

  return new SolutionInput(solutionInput);
}

bool FileReader::fileExists(const std::string& fileLocation) {
  fstream f(fileLocation.c_str());
  bool good = f.good();
  f.close();
  return good;
}

void helper::FileReader::listFilesInDirectory(std::string directory) {
  std::cout << std::filesystem::current_path() << std::endl;
  for (const auto& entry: std::filesystem::directory_iterator(directory))
    std::cout << entry.path() << std::endl;
}
