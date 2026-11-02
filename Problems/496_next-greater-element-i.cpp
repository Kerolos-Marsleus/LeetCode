#include <vector>
#include <unordered_map>
#include <stack>
std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::unordered_map<int, int> mp;
            std::stack<int> s;
     for(int n : nums2){
         while(s.size() && s.top() < n){
             mp[s.top()] = n;
             s.pop();
         }
         s.push(n);
     }
     std::vector<int> ans;
     for(int elem : nums1){
         ans.push_back(mp.count(elem) ? mp[elem] : -1);
     }
     return ans;
}
    
