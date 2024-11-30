//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "NumberUtils.h"

#include <numeric>

int helper::NumberUtils::totalSum(std::vector<int> input) {
  return std::accumulate(std::begin(input), std::end(input), 0);
}
