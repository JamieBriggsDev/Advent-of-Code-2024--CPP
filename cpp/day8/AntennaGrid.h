//
// Created by perso on 08/12/2024.
//

#ifndef ANTENNAGRID_H
#define ANTENNAGRID_H
#include <unordered_set>


#include "../core/Grid.h"
#include "../core/Pair.h"

namespace day8 {

  class Antenna : public core::Pair {
    const char identifier;
    ~Antenna() {}

  public:
    Antenna(const int x, const int y, char identifier) : core::Pair(x, y), identifier(identifier) {}
    [[nodiscard]] char getIdentifier() { return identifier; }
  };
  class AntennaGrid : public core::Grid<Antenna *> {
  private:
    std::unordered_map<char, std::vector<Antenna *>> antennas;

  protected:
    Antenna *convertToObject(char c, int x, int y) override;

  public:
    std::vector<char> getTypesOfAntennas() {
      std::vector<char> typesOfAntennas;
      typesOfAntennas.reserve(antennas.size());
      for (const auto &pair: antennas) {
        typesOfAntennas.push_back(pair.first);
      }
      return typesOfAntennas;
    }
    explicit AntennaGrid(std::vector<std::string> lines) { this->init(lines); }
    std::vector<core::Pair> getAntinodeLocations(char c);
    std::vector<core::Pair> getAntennaLocations();
  };

} // namespace day8

#endif // ANTENNAGRID_H
