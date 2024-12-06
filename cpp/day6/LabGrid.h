//
// Created by Jamie Briggs on 06/12/2024.
//

#ifndef LABGRID_H
#define LABGRID_H
#include <unordered_set>
#include <utility>

#include "../core/Grid.h"
#include "../core/Orientation.h"
#include "../core/Pair.h"
#include "LabEntity.h"

namespace day6 {

  class LabGrid : public core::Grid<LabEntity *> {
  protected:
    std::vector<LabObstacle *> _obstacles;
    std::vector<core::Pair> obstaclesRunInto;
    LabGuard *_guard;
    core::Pair tempObstruction = core::Pair(-1, -1); // Unused
    LabEntity *convertToObject(const char c, const int x, const int y) override {
      if (c == '#') {
        auto *lab_obstacle = new LabObstacle(x, y);
        _obstacles.emplace_back(lab_obstacle);
        // Count the additional obstacle whilst creating one
        return lab_obstacle;
      }
      if (c == '^') {
        _guard = new LabGuard(x, y);
        return _guard;
      }
      return nullptr;
    }

  public:
    explicit LabGrid(std::vector<std::string> lines) { this->init(std::move(lines)); }
    [[nodiscard]] bool containsObstacle(int x, int y) const {
      return (x == tempObstruction.x && y == tempObstruction.y) || dynamic_cast<LabObstacle *>(grid[y][x]) != nullptr;
    }
    void setTemporaryObstruction(int x, int y) { tempObstruction = core::Pair(x, y); }
    [[nodiscard]] LabGuard *getGuard() const { return _guard; }
    [[nodiscard]] int totalObstacles() const { return _obstacles.size(); }
    std::vector<core::Pair> getObstaclesRunInto() const { return obstaclesRunInto; }
    /**
     * Moves the guard once space depending on orientation
     *  and other obstacles in it's path.
     *
     * @return If the guard has left the grid.
     */
    [[nodiscard]] bool moveGuard();

    void resetState();

    bool loopDetected();
  };

} // namespace day6


#endif // LABGRID_H
