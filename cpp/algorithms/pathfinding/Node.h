//
// Created by perso on 10/12/2024.
//

#ifndef PATH_H
#define PATH_H
#include "../../core/Pair.h"

#include <vector>

#include "../../core/Orientation.h"

namespace core {

class Node : public Pair{
  int weight;
  // Pointer to all neighbour nodes
  std::vector<Node*> neighbourNodes;
  Orientation orientation;
  Node* parent = nullptr;
  long g = 0L;
  double h = 0L;
public:
  Node(int weight, int x, int y) : Pair(x, y), weight(weight) {}
  Node* copy() const {
    return new Node(*this);
  }
  int getWeight() const {
    return this->weight;
  }
  void addNeighbour(Node* path) {
    this->neighbourNodes.push_back(path);
  }
  void removeNeighbour(Node* path) {
    this->neighbourNodes.erase(std::remove(this->neighbourNodes.begin(), this->neighbourNodes.end(), path), this->neighbourNodes.end());
  }
  void setParent(Node* parent) {
    this->parent = parent;
  }
  Node* getParent() const {
    return this->parent;
  }
  void setOrientation(Orientation orientation) {
    this->orientation = orientation;
  }
  Orientation getOrientation() const {
    return this->orientation;
  }
  void setG(long g) {
    this->g = g;
  }
  [[nodiscard]] long getG() const {
    return this->g;
  }
  void setH(double h) {
    this->h = h;
  }
  [[nodiscard]] long getH() const {
    return this->h;
  }
  [[nodiscard]] double getF() const {
    return this->g + this->h;
  }
  [[nodiscard]] Pair getPosition() const {
    return static_cast<Pair>(*this);
  }
  [[nodiscard]] std::vector<Node *> getNeighbourNodes() const { return this->neighbourNodes; }
  [[nodiscard]] std::vector<Node *> createCopiesOfNeighbours() const {
    std::vector<Node *> copy;
    for (auto &node : this->neighbourNodes) {
      copy.push_back(new Node(*node));
    }
    return copy;
  }
  friend bool operator==(const Node &lhs, const Node &rhs) {
    return static_cast<const Pair &>(lhs) == static_cast<const Pair &>(rhs) && lhs.weight == rhs.weight &&
           lhs.neighbourNodes == rhs.neighbourNodes;
  }
  friend bool operator!=(const Node &lhs, const Node &rhs) { return !(lhs == rhs); }
};

} // day10

#endif //PATH_H
