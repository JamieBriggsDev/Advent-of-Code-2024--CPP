//
// Created by Jamie Briggs on 06/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#ifndef AOCINITIALIZER_H
#define AOCINITIALIZER_H
#include "SolutionInput.h"

namespace solutions {
  class Day;
}

namespace helper {

class AOCInitializer {
public:
  static solutions::Day* getDay(int dayNumber);
  static SolutionInput* getInput(int dayNumber);
  static SolutionInput* getInput(int dayNumber, bool test, int part);
};

} // helper

#endif //AOCINITIALIZER_H
