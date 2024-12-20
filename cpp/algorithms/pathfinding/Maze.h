//
// Created by perso on 16/12/2024.
//

#ifndef MAZE_H
#define MAZE_H
#include "../../core/Grid.h"
#include "Node.h"

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
    explicit Maze(vector<string> input);
    MazeTile *getTileInPosition(int x, int y) { return this->getGrid()[y][x]; }
    bool isTileWalkable(int x, int y) {
      auto tile = getTileInPosition(x, y);
      if (tile == nullptr) {
        return false;
      }
      return tile->getIsWalkable();
    }
    MazeTile* getStartTile() { return startTile; }
    MazeTile* getEndTile() { return endTile; }
    void printMaze(core::FinalPath finalPath);
  };

} // namespace solutions

#endif // MAZE_H
