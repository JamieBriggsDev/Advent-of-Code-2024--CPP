//
// Created by Jamie Briggs on 01/12/2024.
//

#ifndef PAIR_H
#define PAIR_H

namespace core {

class Pair {
  int a = 0, b = 0;
public:
  Pair(int a, double b) : a(a), b(b) {}
  [[nodiscard]] int distance() const {
    int result = a - b;
    if(result < 0) result = -result;
    return result;
  }

  bool operator==(const Pair &other) const { return (a == other.a) && (b == other.b); }
};

} // core

#endif //PAIR_H
