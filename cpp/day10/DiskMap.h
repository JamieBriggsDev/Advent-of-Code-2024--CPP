//
// Created by perso on 09/12/2024.
//

#ifndef DISKMAP_H
#define DISKMAP_H

#include <vector>
#include <string>

namespace solutions {
  class DiskMap {
    std::vector<int> unfilteredContents;

  public:
    DiskMap(std::string input) {
      for (const char number : input) {
        unfilteredContents.push_back(number - '0');
      }
    }
    [[nodiscard]] std::vector<int> getContents() {
      return unfilteredContents;
    }
  };
}


#endif //DISKMAP_H
