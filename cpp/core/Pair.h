//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef PAIR_H
#define PAIR_H
#include <functional>

namespace core {

class Pair {
public:
  int x = 0, y = 0;
  Pair() = default;
  Pair(int a, int b) : x(a), y(b) {}
  [[nodiscard]] int distance() const {
    int result = x - y;
    if(result < 0) result = -result;
    return result;
  }


  bool operator==(const Pair &other) const { return (x == other.x) && (y == other.y); }
};

} // core

// Hash specialization for core::Pair
namespace std {
  template <>
  struct hash<core::Pair> {
    std::size_t operator()(const core::Pair& p) const noexcept {
      // Simple hash combining using bitwise operators
      return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
  };
}

#endif //PAIR_H
