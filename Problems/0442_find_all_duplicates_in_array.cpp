#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                if(nums[abs(nums[i])-1] < 0){
                    res.push_back(abs(nums[i]));
                }else{
                    nums[abs(nums[i])-1] *= -1;
                }
            }else{
                if(nums[abs(nums[i])-1] < 0){
                    res.push_back(abs(nums[i]));
                }else{
                    nums[abs(nums[i])-1] *= -1;
                }
            }
        }
        return res;
}
int main(void){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = findDuplicates(nums);
}