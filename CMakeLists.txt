cmake_minimum_required(VERSION 3.27)
project(aoc2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc2024 main.cpp
        cpp/day1/Day01.cpp
        cpp/day1/Day01.h
        cpp/helper/FileReader.cpp
        cpp/helper/FileReader.h
        cpp/helper/SolutionInput.cpp
        cpp/helper/SolutionInput.h
        cpp/Day.h
        cpp/helper/AOCInitializer.cpp
        cpp/helper/AOCInitializer.h
        cpp/helper/StringUtils.cpp
        cpp/helper/StringUtils.h
)
