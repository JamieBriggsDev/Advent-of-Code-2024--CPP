//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef PAIR_H
#define PAIR_H
#include <cmath>
#include <functional>
#include <set>
#include <string>

namespace core {

  class Pair {
  public:
    long long x = 0, y = 0;
    Pair() = default;
    Pair(long long a, long long b) : x(a), y(b) {}
    [[nodiscard]] long long distance() const {
      long long result = x - y;
      if (result < 0)
        result = -result;
      return result;
    }

    [[nodiscard]] long long manhattanDistance(const Pair &other) const {
      return std::abs(x - other.x) + std::abs(y - other.y);
    }
    [[nodiscard]] double heuristicDistance(const Pair &other) const {
      return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool setContainsPair(std::set<Pair> pairs) {
      return pairs.contains(core::Pair(x, y));
      /*for (auto pair: pairs) {
        if (pair.x == x && pair.y == y) {
          return true;
        }
      }
      return false;*/
    }

    std::string toString() const {
      return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }




    bool operator==(const Pair &other) const { return (x == other.x) && (y == other.y); }
    Pair operator+(const Pair &other) const { return Pair(x + other.x, y + other.y); }
    void operator+=(const Pair &other) {
      x += other.x;
      y += other.y;
    }
    Pair operator-(const Pair &other) const { return Pair(x - other.x, y - other.y); }
    bool operator<(const Pair &other) const {
      return (x < other.x) || (x == other.x && y < other.y);
    }
    bool operator>(const Pair &other) const {
      return (x > other.x) || (x == other.x && y > other.y);
    }

  };

} // namespace core

// Hash specialization for core::Pair
namespace std {
  template<>
  struct hash<core::Pair> {
    std::size_t operator()(const core::Pair &p) const noexcept {
      // Simple hash combining using bitwise operators
      return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
  };
} // namespace std

#endif // PAIR_H
