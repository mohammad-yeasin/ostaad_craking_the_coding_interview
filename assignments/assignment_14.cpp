// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

// Time Complexity: O(n) and Space Complexity: O(1)
int maxProfit(std::vector<int>& prices) {
    int maxProfit = 0;
    int n = prices.size();

    if (n == 0) return 0; 

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}



int main() {
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(prices1) << std::endl; // Output: 7

    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    std::cout << maxProfit(prices2) << std::endl; // Output: 4

    std::vector<int> prices3 = {7, 6, 4, 3, 1};
    std::cout << maxProfit(prices3) << std::endl; // Output: 0

    return 0;
}
