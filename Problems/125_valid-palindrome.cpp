#include <string>


bool isPalindrome(std::string s) {
        std::string str = "";
        for(int i=0; i<s.size(); ++i){
            if(isalnum(s[i])) str+=tolower(s[i]);
            
            
        }
        return str == std::string(str.rbegin(), str.rend());
    }