#include <vector>
#include <queue>
std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for(int i = 0; i < k; i++){
            int distanceSquared =( points[i][0] *  points[i][0]) + (points[i][1] *  points[i][1]); 
            maxHeap.push({distanceSquared,i});
        }
        for(size_t i = k; i < points.size();++i){
            int distanceSquared =( points[i][0] *  points[i][0]) + (points[i][1] *  points[i][1]); 
            if(distanceSquared < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({distanceSquared,i});
            }
        }
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return ans;
}