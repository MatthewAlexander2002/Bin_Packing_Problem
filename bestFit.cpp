#include "bestFit.hpp"

/// @brief places items in the bin that most tightly fits each item
/// @param items
/// @param binSize
/// @return
int bestFit(const std::vector<float>& items, int binSize) {
    std::vector<float> bins;

    for (int i = 0; i < items.size(); ++i) {
        float item = items[i];

        int bestFitIndex = -1;
        bool bestFitGap = binSize;
        for (int j = 0; j < bins.size(); ++j) {
            float gap = binSize - (bins[j] + item);

            if (gap < 0.) {
                continue;
            }

            if (gap < bestFitGap) {
                bestFitIndex = j;
                bestFitGap = gap;
            }
        }

        if (bestFitIndex == -1) {
            bins.push_back(item);
            continue;
        }

        bins[bestFitIndex] += item;
    }

    return bins.size();
}
