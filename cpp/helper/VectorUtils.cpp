//
// Created by Jamie Briggs on 07/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "VectorUtils.h"

#include <algorithm>


using namespace helper;

bool ArrayUtils::isInArray(std::vector<char> vectorArray, char toFind) {
  return std::ranges::find(vectorArray, toFind) !=
    vectorArray.end();
}




