#include "DP.hpp"
#include <vector>
#include <limits>
#include <iostream>

// minimise dp[i] to the minium number of bins needed to place all items

int dynamicProgramming(const std::vector<float>& items, int binSize) {
    std::vector<int> dp(1 << items.size(), items.size()); //max num of bins
    dp[0] = 0; //zero items, zero bins

    for (int i = 0; i < (1 << items.size()); ++i){
        std::vector<float> bins(1, binSize); // Start with one bin

        //try adding each item if it hasn't already been placed
        for(int j = 0; j < items.size(); ++j) {
            if (i & (1 << j)) {
                bool packed = false;

                for (float& bin : bins) {
                    if (bin >= items[j]) {
                        bin -= items[j];
                        packed = true;
                        break;
                    }
                }

                if (!packed) {
                    bins.push_back(binSize - items[j]);
                }
            }
        }
        dp[i] = bins.size();

        // Try adding new items
        for (int j = 0; j < items.size(); ++j) {
            if (!(i & (1 << j))) {
                dp[i | (1 << j)] = std::min(dp[i | (1 << j)], dp[i]);
            }
        }

    }

    return dp[(1 << items.size()) - 1];
}