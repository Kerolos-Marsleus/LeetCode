#include <vector>



int findMiddleIndex(std::vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        const size_t n = nums.size();
        int curSum = 0;
        for(int i = 0; i < n; i++){
            int righSum = sum - curSum - nums[i];
            if(curSum == righSum){ return i;}
            curSum += nums[i];
        }
        return -1;
}


