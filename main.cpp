#include <vector>
#include <iostream>
#include "bestFit.hpp"
#include "DP.cpp"

void testBinPacking(const std::vector<float>& items, int binSize, int optimalBinSize) {
    std::cout << "Items: ";
    for (float item : items) {
        std::cout << item << " ";
    }
    std::cout << "\nBin size: " << binSize << std::endl;
    std::cout << "Optimal bin size: " << optimalBinSize << std::endl;
    std::cout << "Best Fit bin size: " << bestFit(items, binSize) << std::endl;
    // std::cout << "Dynamic Programming bin size: " << dynamicProgramming(items, binSize) << std::endl;
    //passes each array and the bin size to each function and prints out expected vs actual
}

int main() {
    //1 item, 1 bin
    testBinPacking({1}, 1, 1);
    //simple tests
    testBinPacking({2.5, 2.5, 2.5, 2.5}, 5, 2);
    testBinPacking({1.0, 2.0, 3.0, 4.0}, 5, 2);
    testBinPacking({4.0, 4.0, 4.0, 4.0}, 5, 4);
    testBinPacking({1.5, 1.5, 1.5, 1.5, 1.5}, 3, 3);
    testBinPacking({2.2, 3.3, 4.4, 5.5, 6.6}, 10, 3);
    testBinPacking({1.1, 1.2, 1.3, 1.4, 1.5, 1.6}, 3, 3);
    testBinPacking({7, 2, 5, 4, 3, 8}, 10, 3);
    testBinPacking({3.5, 2.5, 4.5, 1.5, 3.0, 2.0}, 7, 3);
    //complex tests
    testBinPacking({0.23, 0.45, 0.67, 0.89, 0.12, 0.34, 0.56, 0.78}, 1, 5);
    testBinPacking({0.12, 0.45, 0.78, 0.34, 0.89, 0.23, 0.67, 0.56, 0.91, 0.37, 0.48, 0.72}, 1, 8);
    testBinPacking({0.31, 0.75, 0.22, 0.59, 0.44, 0.86, 0.09, 0.68, 0.53, 0.19, 0.62, 0.47}, 1, 7);
    testBinPacking({0.08, 0.93, 0.29, 0.64, 0.71, 0.39, 0.57, 0.21, 0.85, 0.13, 0.54, 0.77}, 1, 7);
    testBinPacking({0.66, 0.25, 0.88, 0.41, 0.18, 0.73, 0.09, 0.52, 0.96, 0.34, 0.61, 0.43}, 1, 7);
    testBinPacking({0.17, 0.49, 0.95, 0.28, 0.62, 0.33, 0.81, 0.55, 0.26, 0.91, 0.13, 0.47}, 1, 7);

    return 0;
}