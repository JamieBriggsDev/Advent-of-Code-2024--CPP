//
// Created by perso on 15/12/2024.
//

#ifndef DIRECTIONQUEUE_H
#define DIRECTIONQUEUE_H

#include <queue>
#include <string>
#include <vector>

#include "../core/Orientation.h"

using namespace std;

namespace solutions {

class DirectionQueue {
protected:
  queue<core::Orientation> orientationQueue;
public:
  DirectionQueue(vector<string> directions);
  core::Orientation peekNext() const;
  void pop();
  int size() const;
};

} // solutions

#endif //DIRECTIONQUEUE_H
