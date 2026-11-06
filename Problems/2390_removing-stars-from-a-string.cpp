#include <string>

std::string removeStars(std::string s) {
        std::string ans;
        for(int i =0; i < s.size(); i++){
            if((s[i] == '*') && ans.size() != 0 ){
                ans.pop_back();
            }else if(s[i] == '*' ){
                continue;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
}