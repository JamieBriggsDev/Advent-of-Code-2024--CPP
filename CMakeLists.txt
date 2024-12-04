cmake_minimum_required(VERSION 3.27)
project(aoc2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc2024 main.cpp
        cpp/day1/Day01.cpp
        cpp/day1/Day01.h
        cpp/day2/Day02.cpp
        cpp/day2/Day02.h
        cpp/day3/Day03.cpp
        cpp/day3/Day03.h
        cpp/helper/FileReader.cpp
        cpp/helper/FileReader.h
        cpp/helper/SolutionInput.cpp
        cpp/helper/SolutionInput.h
        cpp/Day.h
        cpp/helper/AOCInitializer.cpp
        cpp/helper/AOCInitializer.h
        cpp/helper/StringUtils.cpp
        cpp/helper/StringUtils.h
        cpp/core/Pair.h
        cpp/day1/Day01PairBuilder.cpp
        cpp/day1/Day01PairBuilder.h
        cpp/day2/Report.cpp
        cpp/day2/Report.h
        cpp/day3/Computer.h
        cpp/day3/Computer.cpp
        cpp/day3/MultiplyInstruction.h
        cpp/day3/DoInstruction.h
        cpp/day3/DontInstruction.h
        cpp/day4/WordSearchRow.cpp
        cpp/day4/WordSearchRow.h
        cpp/day4/Day04.cpp
        cpp/day4/Day04.h
        cpp/day4/WordSearchGrid.cpp
)
