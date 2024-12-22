//
// Created by Jamie Briggs on 22/12/2024.
//

#ifndef SECRETMODIFIER_H
#define SECRETMODIFIER_H


namespace solutions {

  class SecretModifier {
  public:
    static long long mixValue(const long long value, const long long secret) { return secret ^ value; }
    static long long pruneValue(const long long secret) { return secret % 16777216; }
  };

} // namespace solutions


#endif // SECRETMODIFIER_H
