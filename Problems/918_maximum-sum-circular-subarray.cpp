#include <vector>


int maxSubarraySumCircular(std::vector<int>& nums) {
    int total = nums[0];

    int curr_max_sum = nums[0];
    int max_sum = nums[0];

    int curr_min_sum = nums[0];
    int min_sum = nums[0];

    for (std::size_t i = 1; i < nums.size(); ++i) {
        int x = nums[i];

        curr_max_sum = std::max(x, curr_max_sum + x);
        curr_min_sum = std::min(x, curr_min_sum + x);

        max_sum = std::max(max_sum, curr_max_sum);
        min_sum = std::min(min_sum, curr_min_sum);

        total += x;
    }

    if (max_sum < 0) {
        return max_sum;
    }

    return std::max(max_sum, total - min_sum);
}