#include "DP.hpp"
#include <vector>
#include <limits>

//minimise dp[i] to the minium number of bins needed to place all items

int dynamicProgramming(const std::vector<float>& items, int binSize) {
    std::vector<int> dp(1 << items.size(), items.size()); //max num of bins
    dp[0] = 0; //zero items, zero bins

    for (int i = 0; i < (1 << items.size()); ++i){
        std::vector<float> bins;
        float remainingCapacity = binSize;

        //try adding each item if it hasn't already been placed
        for(int j = 0; j < items.size(); ++j) {
            if (!(i & (1 << j))) {
                if(remainingCapacity >= items[j]){
                    remainingCapacity -= items[j];
                } else {
                    //make new bin if the item doesn't fit
                    bins.push_back(binSize - items[j]);
                }
            }
        }

        //update
        dp[i] = std::min(dp[i], static_cast<int>(bins.size()));
    }

    return dp[(1 << items.size()) - 1];
}