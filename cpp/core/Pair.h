//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef PAIR_H
#define PAIR_H
#include <functional>
#include <set>

namespace core {

  class Pair {
  public:
    int x = 0, y = 0;
    Pair() = default;
    Pair(int a, int b) : x(a), y(b) {}
    [[nodiscard]] int distance() const {
      int result = x - y;
      if (result < 0)
        result = -result;
      return result;
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




    bool operator==(const Pair &other) const { return (x == other.x) && (y == other.y); }
    Pair operator+(const Pair &other) const { return Pair(x + other.x, y + other.y); }
    Pair operator-(const Pair &other) const { return Pair(x - other.x, y - other.y); }
    bool operator<(const Pair &other) const {
      return (x < other.x) || (x == other.x && y < other.y);
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
