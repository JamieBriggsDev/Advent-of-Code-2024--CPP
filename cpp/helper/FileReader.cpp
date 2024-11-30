//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "FileReader.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
using namespace helper;

SolutionInput* FileReader::readFile(const string& fileLocation) {
  vector<string> outputList;
  outputList.clear();

  ifstream myFile(fileLocation);

  string s;
  while (getline(myFile, s)) {
    outputList.push_back(s);
  }

  return new SolutionInput(outputList);
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
