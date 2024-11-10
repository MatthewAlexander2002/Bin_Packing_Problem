#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

/**
 * Solves the bin packing problem using the first fit decreasing algorithm
 * @param items Vector of item sizes to pack
 * @param binSize Maximum capacity of each bin
 * @return Minimum number of bins needed to pack all items
 */
int firstFitDecreasing(const std::vector<float>& items, int binSize) {
    // sort the items in decreasing order
    std::vector<float> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), std::greater<float>());

    // store the current fill of each bin
    std::vector<float> bins;

    for (float item : items) {
        // find the first bin that can accommodate the item
        int firstBin = -1;
        for (size_t i = 0; i < bins.size(); ++i) {
            if (bins[i] + item <= binSize) {
                firstBin = i;
                break;
            }
        }

        if (firstBin != -1) {
            // place the item in the first fitting bin
            bins[firstBin] += item;
        } else {
            // if no bin can accommodate the item, then create a new bin
            bins.push_back(item);
        }
    }

    return bins.size();
}
