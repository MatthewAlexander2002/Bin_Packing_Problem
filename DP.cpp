#include "DP.hpp"
#include <vector>
#include <limits>
#include <iostream>

/**
 * Solves the bin packing problem using dynamic programming with bitmasks
 * @param items Vector of item sizes to pack
 * @param binSize Maximum capacity of each bin
 * @return Minimum number of bins needed to pack all items
 */

// minimise dp[i] to the minium number of bins needed to place all items

int dynamicProgramming(const std::vector<float>& items, int binSize) {
    std::vector<int> dp(1 << items.size(), items.size()); //max num of bins
    dp[0] = 0; //zero items, zero bins

    // iterate through all possible item subsets using bitmasks
    for (int i = 0; i < (1 << items.size()); ++i){
        std::vector<float> bins(1, binSize); // Start with one bin

        // pack each item that's included in current subset
        for(int j = 0; j < items.size(); ++j) {
            if (i & (1 << j)) {
                bool packed = false;

                //try putting an item into an existing bin
                for (float& bin : bins) {
                    if (bin >= items[j]) {
                        bin -= items[j];
                        packed = true;
                        break;
                    }
                }

                //create new bin if the item didn't fit
                if (!packed) {
                    bins.push_back(binSize - items[j]);
                }
            }
        }
        dp[i] = bins.size();

        // update states by trying to add each unused item
        for (int j = 0; j < items.size(); ++j) {
            if (!(i & (1 << j))) { // if item j not in current subset
                dp[i | (1 << j)] = std::min(dp[i | (1 << j)], dp[i]);
            }
        }

    }

    return dp[(1 << items.size()) - 1];
}