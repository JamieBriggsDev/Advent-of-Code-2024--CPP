//
// Created by Jamie Briggs on 22/12/2024.
//

#include "Day22.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "BananaSellingUtil.h"
#include "SecretEvolver.h"

namespace solutions {

  // Custom hash function for std::vector<int>
  struct VectorHash {
    std::size_t operator()(const std::vector<int> &vec) const {
      std::size_t hash = 0;
      for (int num: vec) {
        // Combine individual hashes using a common hash mix formula
        hash ^= std::hash<int>()(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
      }
      return hash;
    }
  };

  // Custom equality comparer for std::vector<int> (optional but recommended)
  struct VectorEqual {
    bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs) const { return lhs == rhs; }
  };

  std::string Day22::solvePartOne(const helper::SolutionInput *input) {
    long long result = 0l;

    for (const auto &initialSecretString: input->getTestInput()) {
      long long secret = stoll(initialSecretString);
      long long finalSecretValue = secret;
      for (int i = 0; i < 2000; i++) {
        finalSecretValue = SecretEvolver::evolveSecret(finalSecretValue);
      }
      std::cout << initialSecretString << ": " << finalSecretValue << std::endl;
      result += finalSecretValue;
    }
    return to_string(result);
  }
  std::string Day22::solvePartTwo(const helper::SolutionInput *input) {
    // Store a list of all possible differences to look out for
    std::unordered_set<std::vector<int>, VectorHash, VectorEqual> sequences;
    // Cache for bananas which could be sold during specific sequences
    std::unordered_map<int, std::unordered_map<std::vector<int>, int, VectorHash, VectorEqual>> bananasSoldCache;
    // Perform first loop of solution to get differences
    int buyerId = 0;
    for (const auto &buyerSecret: input->getTestInput()) {
      std::unordered_map<std::vector<int>, int, VectorHash, VectorEqual> buyerBananaCache;
    std:
      vector<int> differencesOfCurrentSecret;
      long long secret = stoll(buyerSecret);
      long long previousValue = 0l;
      long long finalSecretValue = secret;

      for (int i = 0; i < 2000; i++) {
        previousValue = finalSecretValue;
        finalSecretValue = SecretEvolver::evolveSecret(finalSecretValue);
        int bananasSold = BananaSellingUtil::getLastDigitNumber(finalSecretValue);
        // Get difference
        int difference =
            BananaSellingUtil::getDifferenceBetweenTwoNumbers(BananaSellingUtil::getLastDigitNumber(previousValue),
                                                              bananasSold);
        differencesOfCurrentSecret.push_back(difference);

        // Add to differences set if more than 4 added
        if (i >= 4) {
          std::vector<int> toAdd = {differencesOfCurrentSecret[i - 3], differencesOfCurrentSecret[i - 2],
                                    differencesOfCurrentSecret[i - 1], differencesOfCurrentSecret[i]};
          sequences.emplace(toAdd);
          // Add value of sequence to bananaSoldCache if not found
          if (!buyerBananaCache.contains(toAdd)) {
            buyerBananaCache[toAdd] = bananasSold;
          }
        }
      }

      // Remember bananas sold
      bananasSoldCache[buyerId] = buyerBananaCache;

      // Increment buyerId
      buyerId++;
    }

    vector<int> bestSequence;
    int bestBananasSold = 0;

    // Next, loop through each sequence, and see what the total bananas you can
    //  buy for each seller is.
    for (const auto &sequenceToFind: sequences) {

      int totalBananas = 0;

      // Loop through each buyer
      for(int i = 0; i < input->getTestInput().size(); i++) {
        totalBananas += bananasSoldCache[i][sequenceToFind];
      }

      if (totalBananas >= bestBananasSold) {
        bestSequence = sequenceToFind;
        bestBananasSold = totalBananas;
      }
    }


    return to_string(bestBananasSold);
  }
} // namespace solutions
