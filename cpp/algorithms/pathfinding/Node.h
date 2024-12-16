//
// Created by perso on 10/12/2024.
//

#ifndef PATH_H
#define PATH_H
#include "../../core/Pair.h"

#include <vector>

namespace core {

class Node : public Pair{
  int weight;
  // Pointer to all parent nodes (Parent being towards start
  std::vector<Node*> parentNodes;
public:
  Node(int weight, int x, int y) : Pair(x, y), weight(weight) {}
  int getWeight() const {
    return this->weight;
  }
  void addParent(Node* path) {
    this->parentNodes.push_back(path);
  }
  [[nodiscard]] Pair getPosition() const {
    return static_cast<Pair>(*this);
  }
  std::vector<Node *> getParentNodes() const { return this->parentNodes; }
  friend bool operator==(const Node &lhs, const Node &rhs) {
    return static_cast<const Pair &>(lhs) == static_cast<const Pair &>(rhs) && lhs.weight == rhs.weight &&
           lhs.parentNodes == rhs.parentNodes;
  }
  friend bool operator!=(const Node &lhs, const Node &rhs) { return !(lhs == rhs); }
};

} // day10

#endif //PATH_H
