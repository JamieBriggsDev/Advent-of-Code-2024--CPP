cmake_minimum_required(VERSION 3.30.5)
# 'Google_test' is the subproject name
project(Google_tests)

set(CMAKE_CXX_STANDARD 23)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run
        ../cpp/helper/SolutionInput.h
        ../cpp/helper/SolutionInput.cpp
        ../cpp/helper/FileReader.cpp
        ../cpp/helper/FileReader.h
        ../cpp/helper/StringUtils.cpp
        ../cpp/helper/StringUtils.h
        ../cpp/core/Pair.h
        ../cpp/day1/Day01PairBuilder.cpp
        ../cpp/day1/Day01PairBuilder.h
        ../cpp/day2/Report.cpp
        ../cpp/day2/Report.h
        core/PairTests.cpp
        day1/Day01PairBuilderTests.cpp
        day2/ReportTests.cpp
        ../cpp/day3/Computer.cpp
        ../cpp/day3/Computer.h
        ../cpp/day3/MultiplyInstruction.h
        day3/ComputerTests.cpp
        ../cpp/day3/Instruction.h
        ../cpp/day3/DoInstruction.h
        ../cpp/day3/DontInstruction.h
        ../cpp/core/WordSearchRow.cpp
        ../cpp/core/WordSearchRow.h
        ../cpp/core/WordSearchGrid.h
        ../cpp/core/WordSearchGrid.cpp
        core/WordSearchRowTests.cpp
        core/WordSearchGridTests.cpp
        testHelper/InputUtils.cpp
        testHelper/InputUtils.h
        ../cpp/day4/MasSearchGrid.cpp
        ../cpp/day4/MasSearchGrid.h
        day4/MasSearchGridTests.cpp
        helper/SolutionHelperTests.cpp
        ../cpp/day5/PageOrderingRules.cpp
        ../cpp/day5/PageOrderingRules.h
        day5/PageOrderingRulesTests.cpp
        ../cpp/day5/PageUpdate.cpp
        ../cpp/day5/PageUpdate.h
        day5/PageUpdateTests.cpp
        ../cpp/core/Grid.h
        ../cpp/day6/LabGrid.cpp
        ../cpp/day6/LabGrid.h
        day6/LabGridTests.cpp
        ../cpp/core/Orientation.h
        day6/LabGuardTests.cpp
        ../cpp/day6/LabEntity.h
        ../cpp/day8/AntennaGrid.cpp
        ../cpp/day8/AntennaGrid.h
        day8/AntennaGridTests.cpp
        ../cpp/day9/DiskMap.cpp
        ../cpp/day9/DiskMap.h
        day9/DiskMapTests.cpp
        ../cpp/day9/File.h
        ../cpp/day10/Day10.cpp
        ../cpp/day10/Day10.h
        ../cpp/day10/TopographicMap.cpp
        ../cpp/day10/TopographicMap.h
        day10/TopographicMapTests.cpp
        ../cpp/core/Node.h
        ../cpp/core/Node.cpp
        ../cpp/core/PathFinder.h
        ../cpp/core/IncrementalPathFinder.cpp
        ../cpp/core/IncrementalPathFinder.h
        day10/IncrementalPathFinderTests.cpp
        ../cpp/day7/Day07.cpp
        ../cpp/day7/Day07.h
        ../cpp/day11/Day11.h
        ../cpp/day11/Day11.cpp
        ../cpp/day12/Day12.cpp
        ../cpp/day12/Day12.h
        ../cpp/day11/PebbleRow.cpp
        ../cpp/day11/PebbleRow.h
        day11/PebbleRowTests.cpp
        ../cpp/day12/FarmGrid.cpp
        ../cpp/day12/FarmGrid.h
        ../cpp/day12/Plant.cpp
        ../cpp/day12/Plant.h
        day12/FarmGridTests.cpp
        ../cpp/core/AocException.cpp
        ../cpp/core/AocException.h
        ../cpp/algorithms/ZoneFinderFloodFill.cpp
        ../cpp/algorithms/ZoneFinderFloodFill.h
        algorithms/ZoneFinderFloodFillTests.cpp
        ../cpp/algorithms/GridZones.h
        ../cpp/algorithms/Zone.cpp
        ../cpp/algorithms/Zone.h
        algorithms/ZoneTests.cpp
)

# Set optimization flags for Release configuration

target_link_libraries(Google_Tests_run gtest gtest_main)