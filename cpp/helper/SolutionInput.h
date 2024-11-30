//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#ifndef TESTINPUT_H
#define TESTINPUT_H
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace helper {

class SolutionInput {
    const vector<string> testInput;
public:
    SolutionInput(vector<string> input): testInput(std::move(input)){ }

    vector<string> getTestInput() const;
    [[nodiscard]] int getTotalRowsInInput() const {
        return testInput.size();
    };
};

}


#endif //TESTINPUT_H
