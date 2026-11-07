#include <vector>

int maxSubArray(std::vector<int>& nums) {
     int max_sum = nums[0];
     int curr_sum = nums[0];
     std::size_t n = nums.size();
     for(std::size_t i = 1;i<n;i++){
        if(nums[i] > curr_sum + nums[i]){
            curr_sum = nums[i];
        }else{
            curr_sum += nums[i];
        }
        max_sum = std::max(max_sum, curr_sum);
     }   
     return max_sum;
}