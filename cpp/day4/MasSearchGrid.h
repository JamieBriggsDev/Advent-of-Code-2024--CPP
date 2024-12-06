//
// Created by Jamie Briggs on 04/12/2024.
//

#ifndef MASSEARCHGRID_H
#define MASSEARCHGRID_H
#include "../core/Pair.h"
#include "../core/WordSearchGrid.h"


class MasSearchGrid : public core::WordSearchGrid{
public:
  explicit MasSearchGrid(const std::vector<std::string> &rawRows) : WordSearchGrid(rawRows) {}
  int findTotalOccurrencesOfXMas();
};



#endif //MASSEARCHGRID_H
