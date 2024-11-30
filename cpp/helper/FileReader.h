//
// Created by Jamie Briggs on 05/12/2023.
// Copyright (c) 2023 jbriggs.dev All rights reserved.
//

#ifndef FILEREADER_H
#define FILEREADER_H
#include <list>
#include <string>

#include "SolutionInput.h"

namespace helper {
    class FileReader {
    public:
        static SolutionInput* readFile(const std::string& fileLocation);
        static bool fileExists(const std::string& fileLocation);
        static void listFilesInDirectory(std::string directory);
    };
}


#endif //FILEREADER_H
