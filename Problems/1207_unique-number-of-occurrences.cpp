#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int>frequencies;
        for(auto i : arr){
            frequencies[i]++;
        }
        std::unordered_set<int> st;
        for(auto &[key,value] : frequencies){
            auto check = st.insert(value);
            if(check.second == false){return false;}
        }
        return true;

}