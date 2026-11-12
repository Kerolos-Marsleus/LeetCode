#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::size_t size = nums.size();
    std::vector<int> ans(nums.size());
    ans[0] = 1;
    
    for(std::size_t i = 1;  i < size; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    
    int product = 1;
    for(std::size_t i = size;i-- > 0;){
        ans[i] *= product;
        product *= nums[i];
    }

    return ans;
}