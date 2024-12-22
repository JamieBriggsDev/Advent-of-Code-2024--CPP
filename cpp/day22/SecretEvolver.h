//
// Created by Jamie Briggs on 22/12/2024.
//

#ifndef SECRETEVOLVER_H
#define SECRETEVOLVER_H
#include "SecretModifier.h"

namespace solutions {

  class SecretEvolver {
  public:
    long long static evolveSecret(long long secret) {
      long long result = secret;
      // Step one: Calculate result of secret * 64, and then
      //  mix value into initial secret, and then prune.
      result = SecretModifier::mixValue(result, result * 64);
      result = SecretModifier::pruneValue(result);

      // Step two: Divide secret by 32, round the result down to the nearest int.
      //  Mix result into secret, and then prune.
      result = SecretModifier::mixValue(result, result / 32);
      result = SecretModifier::pruneValue(result);

      // Step three: Multiply number by 2048. Mix result into secret, and then prune.
      result = SecretModifier::mixValue(result, result * 2048);
      result = SecretModifier::pruneValue(result);
      return result;
    }
  };

} // namespace solutions

#endif // SECRETEVOLVER_H
