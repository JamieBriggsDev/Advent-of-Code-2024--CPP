//
// Created by perso on 15/12/2024.
//

#include "DirectionQueue.h"

#include <iostream>

namespace solutions {
  DirectionQueue::DirectionQueue(vector<string> directions) {
    for (auto row: directions) {
      for (int i = 0; i < row.length(); i++) {
        switch (row[i]) {
          case '^':
            this->orientationQueue.push(core::Orientation::NORTH);
            break;
          case '>':
            this->orientationQueue.push(core::Orientation::EAST);
            break;
          case 'v':
            this->orientationQueue.push(core::Orientation::SOUTH);
            break;
          case '<':
            this->orientationQueue.push(core::Orientation::WEST);
            break;
          default:
            // Do nothing!
            std::cerr << "Unknown character: " << row[i] << std::endl;
            ;
        }
      }
    }
  }
  core::Orientation DirectionQueue::peekNext() const { return this->orientationQueue.front(); }
  void DirectionQueue::pop() { this->orientationQueue.pop(); }
  int DirectionQueue::size() const { return this->orientationQueue.size(); }
} // namespace solutions
