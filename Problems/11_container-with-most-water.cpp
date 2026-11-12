#include <vector>

int maxArea(std::vector<int>& height) {
    int l = 0; 
    int r = height.size() -1;
    std::size_t most_water = 0;
    std::size_t curr_water = 0;
    while(l < r){
        curr_water = std::min(height[l] , height[r]) * (r-l);
        most_water = (curr_water > most_water) ? curr_water : most_water;
        if(height[l] <= height[r]){
            ++l;
        }else{
            --r;
        }
    }
    return most_water;
}