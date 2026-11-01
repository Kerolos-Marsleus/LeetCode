#include <vector>
#include <math.h>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    const int n = prices.size();
    if(n <= 0)return 0;
    int lowest = prices[0];
    int max_profit = 0;
    for(int i = 1; i < n; i++){
        if(prices[i] < lowest){
            lowest = prices[i];
        }else{
            int dif = prices[i] - lowest;
            max_profit = std::max(max_profit, dif);
        }
    }
    return max_profit;
}