//
// Created by Jamie Briggs on 22/12/2024.
//

#ifndef BANANASELLINGUTIL_H
#define BANANASELLINGUTIL_H

namespace solutions {

  class BananaSellingUtil {
  public:
    static int getLastDigitNumber(const long long value) {
      return value % 10;
    }
    static int getDifferenceBetweenTwoNumbers(const int previous, const int current) {
      return current - previous;
    }

  };

}

#endif //BANANASELLINGUTIL_H
