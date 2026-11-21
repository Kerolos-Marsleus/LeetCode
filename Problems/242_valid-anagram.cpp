#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{
    std::unordered_map<char, int> mp;

    for (auto &ch : s)
        mp[ch]++;
    for (auto &ch : t)
        mp[ch]--;

    for (auto &i : mp)
    {
        if (i.second != 0)
            return false;
    }
    return true;
}