#include <vector>
#include <algorithm>
int firstMissingPositive(std::vector<int>& nums) {
       // start to make any number <= 0 or >= n to be n+1
       std::size_t n = nums.size();
       for(std::size_t i = 0; i < n; ++i){
        if(nums[i] <= 0 || nums[i] > n){
            nums[i] = n+1;
        }
       } 
       for(std::size_t i = 0; i < n;++i){
            if((abs(nums[i]) <= n)){
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            }
       }
       for(std::size_t i = 0; i < n; ++i){
        if(nums[i] > 0){
            return i+1;
        }
       }
       return n+1;
}