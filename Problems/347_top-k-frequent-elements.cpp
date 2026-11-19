#include <vector>
#include <unordered_map>
#include <algorithm>
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        int maxFrequency = 0;
        for(int i : nums){
            mp[i]++;
            maxFrequency = std::max(maxFrequency,mp[i]);
        }
        std::vector<std::vector<int>> buckets(maxFrequency + 1); 
        for(auto i : mp){
            buckets[i.second].push_back(i.first);
        }
        std::vector<int> ans;
        ans.reserve(k);
        for(int i = maxFrequency; i>=0 && ans.size() < k; i--){
            if(buckets[i].size() > 0){
                for(int j : buckets[i]){
                    ans.push_back(j);
                    if(ans.size() == k){
                        break;
                    }
                }
            }
        }
        return ans;
}