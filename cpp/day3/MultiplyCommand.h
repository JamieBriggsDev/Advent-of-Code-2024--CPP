//
// Created by Jamie Briggs on 03/12/2024.
//

#ifndef MULTIPLYCOMMAND_H
#define MULTIPLYCOMMAND_H



class MultiplyCommand {
  int x;
  int y;
public:
  MultiplyCommand(int x, int y) {
    this->x = x;
    this->y = y;
  }
  long result() const {
    return x * y;
  }

  bool operator==(const MultiplyCommand &other) const { return x == other.x && y == other.y; }
};



#endif //MULTIPLYCOMMAND_H
