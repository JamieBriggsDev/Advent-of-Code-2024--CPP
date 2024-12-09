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
        cpp/core/WordSearchRow.cpp
        cpp/core/WordSearchRow.h
        cpp/core/WordSearchGrid.h
        cpp/core/WordSearchGrid.cpp
        cpp/day4/Day04.cpp
        cpp/day4/Day04.h
        cpp/day4/MasSearchGrid.h
        cpp/day4/MasSearchGrid.cpp
        cpp/day5/Day05.h
        cpp/day5/Day05.cpp
        cpp/day5/PageOrderingRules.cpp
        cpp/day5/PageOrderingRules.h
        cpp/day5/PageUpdate.cpp
        cpp/day5/PageUpdate.h
        cpp/day6/Day06.cpp
        cpp/day6/LabGrid.cpp
        cpp/day6/LabEntity.h
        cpp/day8/Day08.cpp
        cpp/day8/Day08.h
        cpp/day8/AntennaGrid.h
        cpp/day8/AntennaGrid.cpp
        cpp/day9/Day09.cpp
        cpp/day9/Day09.h
        cpp/day9/DiskMap.cpp
)
