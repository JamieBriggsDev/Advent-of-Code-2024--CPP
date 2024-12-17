//
// Created by perso on 16/12/2024.
//

#ifndef MAZE_H
#define MAZE_H
#include "../algorithms/pathfinding/Node.h"
#include "../core/Grid.h"

#include <string>
#include <vector>

#include "MazeTile.h"

namespace core {
  struct FinalPath;
}
using namespace std;

namespace solutions {

  class Maze final : public core::Grid<MazeTile *> {
  protected:
    MazeTile* startTile;
    MazeTile* endTile;
    MazeTile* convertToObject(char c, int x, int y) override;
    vector<vector<bool>> walls;
  public:
    Maze(vector<string> input);
    core::Node *getTileInPosition(int x, int y) { return this->getGrid()[y][x]; }
    MazeTile* getStartTile() { return startTile; }
    MazeTile* getEndTile() { return endTile; }
    void printMaze(core::FinalPath finalPath);
  };

} // namespace solutions

#endif // MAZE_H
