#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> q;
        std::vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            while(!q.empty() && (nums[q.back()] < nums[i])){
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() < i - k + 1) q.pop_front();
            if(i >= k-1) ans.push_back(nums[q[0]]);
        }
        return ans;
}