//
// Created by Jamie Briggs on 20/12/2024.
//

#ifndef HASHCONFIG_H
#define HASHCONFIG_H

#include <utility>
#include <functional>

namespace std {
  template<>
  struct hash<std::pair<core::Pair, core::Pair>> {
    std::size_t operator()(const std::pair<core::Pair, core::Pair>& p) const {
      std::hash<int> hasher; // Example: hashing integers
      return hasher(p.first.x) ^ hasher(p.first.y) ^ hasher(p.second.x) ^ hasher(p.second.y);
    }
  };
}

#endif //HASHCONFIG_H
