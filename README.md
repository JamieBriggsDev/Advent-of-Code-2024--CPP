# Advent of Code 2024

Welcome to my 2024 Advent of Code project! This year I will be doing it in C++. I do plan to do the solutions in another
language in perhaps another project, but this will be my main AoC.

There are some files which have existed since the beginning of 2024's AoC, and they're taken from 2023. They are essentially
core `helper` libraries which just help speed the process of working on a solution such as opening a file or code layout. 
This helps myself with focusing on working on the solution rather than project quality of life.

## Running the code
### CLion
If you would like to run this project locally, it is easiest to open the project in CLion as there are configurations 
which should already have been created.

### CMake
However, you can compile and run the project yourself using CMake.

```shell
# Create and open build directory
mkdir build
cd build

# Run CMake from the build directory to generate build files
cmake ..

# Build the application
make
```

Once the application is built, you can run the solutions via arguments passed.

```shell
# In ./build directory created in previous step
./aoc2024 1 # Runs solutions from day 1
./aoc2024 9 # Runs solutions form day 9
./aoc2024 1 --test # Runs solutions using test input within ../sample_input directory
```

## Project layout
There are 4 main directories within this project:
- `./cpp`: Contains source code for Advent of Code
- `./input`: Contains `.txt` files which hold the input for each puzzle. They should be labelled as `dayX.txt`.
- `./sample_input`: Similar to `./input`, but created based on the puzzle instructions or created by myself. They should be labelled as `dayX.txt`.
- `./puzzle`: Contains markdown files which have the puzzles copied into them.

## Days
Here are markdown files containing the various puzzles which need completing. They're essentially a copy and paste from
Advent of Code's website, but copying them and formatting to markdown helps me to more time to understand the puzzle which
needs solving.

| Day   | Link                        |
|-------|-----------------------------|
| Day 1 | [Day1.md](puzzle%2FDay1.md) |
| Day 2 | [Day2.md](puzzle%2FDay2.md) |
| Day 3 | [Day3.md](puzzle%2FDay3.md) |
| Day 4 | [Day4.md](puzzle%2FDay4.md) |