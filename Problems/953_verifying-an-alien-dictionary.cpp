#include <vector>
#include <string>
#include <algorithm>

bool isAlienSorted(std::vector<std::string> &words, std::string order)
{
    int mapping[26];
    for (int i = 0; i < 26; ++i)
    {
        mapping[order[i] - 'a'] = i;
    }
    for (std::string &w : words)
    {
        for (char &c : w)
        {
            c = mapping[c - 'a'];
        }
    }
    return std::is_sorted(words.begin(), words.end());
}