#include <vector>
#include <unordered_map>
#include <algorithm>
bool containsNearbyDuplicate(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto [it, inserted] = mp.insert({nums[i], i});
        if (inserted == false)
        {
            if (std::abs(i - it->second) <= k)
            {
                return true;
            }
            else
            {
                it->second = i;
            }
        }
    }
    return false;
}