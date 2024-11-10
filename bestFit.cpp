#include "bestFit.hpp"

/// @brief places items in the bin that most tightly fits each item
/// @param items
/// @param binSize
/// @return
int bestFit(const std::vector<float>& items, int binSize) {
    // how full each bin is, initially zero bins
    std::vector<float> bins;

    // take each bin one at a time
    for (int i = 0; i < items.size(); ++i) {
        float item = items[i];

        // find the bin with the least space that fits the item
        int bestFitIndex = -1;
        bool bestFitGap = binSize;
        for (int j = 0; j < bins.size(); ++j) {
            float gap = binSize - (bins[j] + item);

            // bin fits
            if (gap < 0.) {
                continue;
            }

            // better than previous bins
            if (gap < bestFitGap) {
                bestFitIndex = j;
                bestFitGap = gap;
            }
        }

        // if no bin was found open a new bin
        if (bestFitIndex == -1) {
            bins.push_back(item);
            continue;
        }

        // record the space used in the found bin
        bins[bestFitIndex] += item;
    }

    // return the number of bins used to fit all the items
    return bins.size();
}
