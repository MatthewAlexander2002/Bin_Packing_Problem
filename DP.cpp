#include <vector>

//minimise dp[i] to the minium number of bins needed to place all items

int dynamicProgramming(const std::vector<float>& items, int binSize) {
    std::vector<int> dp(0, items.size());
    dp[0] = 0; //zero items, zero bins

    for (int i = 0; i < items.size(); ++i){
        std::vector<float> bins;
        float remainingCapacity = binSize;

        //try adding each item if it hasn't already been placed
        for(int j = 0; j < items.size(); ++j) {
            if(remainingCapacity >= items[j]){
                remainingCapacity -= items[j];
            } else {
                //make new bin if the item doesn't fit
                bins.push_back(binSize - items[j]);
            }
        }

        //update
        dp[i] = std::min(dp[i], static_cast<int>(items.size()));
    }

    return dp[items.size()-1];
}