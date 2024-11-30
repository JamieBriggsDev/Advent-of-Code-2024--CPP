//
// Created by Jamie Briggs on 07/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H
#include <vector>


namespace helper {


class ArrayUtils {
public:
  static bool isInArray(std::vector<char> vectorArray, char toFind);
  static int length(char array[]);
};

}


#endif //ARRAYUTILS_H
