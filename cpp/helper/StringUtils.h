//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <vector>

namespace helper {

class StringUtils {
public:
  static std::vector<std::string> splitString(std::string input, std::string delimiter);
  static int toInt(const std::string& input);
};

} // helper

#endif //STRINGUTILS_H
