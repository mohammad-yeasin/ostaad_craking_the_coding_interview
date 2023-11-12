#include <vector>
#include <algorithm>
#include <iostream>


// Time complexity: O(n^2)
// Space complexity: O(n)
int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    // Example usage:
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    std::vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};

    std::cout << "Example 1: " << lengthOfLIS(nums1) << std::endl;
    std::cout << "Example 2: " << lengthOfLIS(nums2) << std::endl;
    std::cout << "Example 3: " << lengthOfLIS(nums3) << std::endl;

    return 0;
}
