#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> st;
        st.reserve(nums.size());
        for(auto i : nums){
            if(!st.insert(i).second){
                return true;
            }
        }
        return false;
}