//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#include "Day01.h"

#include <iostream>
#include <numeric>
#include <vector>

#include "../helper/NumberUtils.h"
#include "../helper/SolutionInput.h"

using namespace std;

namespace solutions {
    string Day01::solvePartOne(const helper::SolutionInput* input) {
        vector<int> calibrationValues;
        for (int i = 0; i < input->getTotalRowsInInput(); i++) {
            auto line = input->getTestInput()[i];
            vector<int> digits;
            for (const char character: line) {
                if (character >= '0' && character <= '9') {
                    digits.push_back(character-'0');
                }
            }
            calibrationValues.push_back(digits.front() * 10 + digits.back());
        }
        return to_string(helper::NumberUtils::totalSum(calibrationValues));
    }

    string Day01::solvePartTwo(const helper::SolutionInput* input) {
        const vector<string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        vector<int> calibrationValues;
        for (int i = 0; i < input->getTotalRowsInInput(); i++) {
            auto line = input->getTestInput()[i];
            int firstIndex = 1e9, firstValue = -1;
            int secondIndex = -1, secondValue = -1;
            for(char c = '1'; c <= '9'; c++) {
                if(int index = line.find(c); index >= 0 && index < line.length()) {
                    if(index < firstIndex) {
                        firstIndex = index;
                        firstValue = c - '0';
                    }
                    index = line.rfind(c);
                    if(index > secondIndex) {
                        secondIndex = index;
                        secondValue = c - '0';
                    }
                }
            }
            for(int j = 0; j < 9; j++) {
                if(int index = line.find(digits[j]); index >= 0 && index < line.length()) {
                    if(index < firstIndex) {
                        firstIndex = index;
                        firstValue = j + 1;
                    }
                    index = line.rfind(digits[j]);
                    if(index > secondIndex) {
                        secondIndex = index;
                        secondValue = j + 1;
                    }
                }
            }
            calibrationValues.push_back(firstValue * 10 + secondValue);
        }

        return to_string(helper::NumberUtils::totalSum(calibrationValues));
    }
} // solutions
