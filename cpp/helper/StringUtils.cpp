//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "StringUtils.h"

#include <algorithm>
#include <sstream>

using namespace std;

namespace helper {
  vector<string> StringUtils::splitString(string input, string delimiter) {
    string modifiedString = input;

    vector<string> output;

    size_t pos = 0;
    string token;
    while((pos = modifiedString.find(delimiter)) != string::npos) {
      token = modifiedString.substr(0, pos);
      output.push_back(token);
      modifiedString.erase(0, pos + delimiter.length());
    }

    output.push_back(modifiedString);

    return output;
  }

  int StringUtils::toInt(const std::string &input) {
    int output;

    stringstream strValue;
    strValue << input;
    strValue >> output;

    return output;
  }

  } // helper