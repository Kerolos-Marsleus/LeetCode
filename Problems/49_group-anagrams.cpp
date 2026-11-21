#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string,std::vector<std::size_t>> mp;
        std::vector<std::vector<std::string>> ans;

        for(std::size_t i = 0; i < strs.size(); ++i){
            std::string key = strs[i];
            std::sort(key.begin(), key.end());
            mp[key].push_back(i);
        }
        for(const auto &[key,indices] : mp){
            ans.emplace_back();
            for(auto index : indices){
                ans.back().push_back(strs[index]);
            }
        }
        return ans;
}