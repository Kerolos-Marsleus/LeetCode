#include <string>
#include <vector>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string str1;
    string str2;

    int n1 = word1.size();
    int n2 = word2.size();

    for(int i = 0; i < n1; ++i){
        str1 += word1[i];
    }
    for(int i = 0; i < n2; ++i){
        str2 += word2[i];
    }
    if(str1.size() != str2.size()) return false;
    int size = str1.size();
    for(int i = 0; i < size; ++i){
        if(str1[i] != str2[i])
            return false;
    }
    return true;

}