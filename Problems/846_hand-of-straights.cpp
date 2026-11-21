#include <vector>
#include <map>
bool isNStraightHand(std::vector<int> &hand, int groupSize)
{
    std::map<int, int> mp;
    int n = hand.size();
    if (n % groupSize != 0)
    {
        return false;
    }
    for (auto card : hand)
    {
        mp[card]++;
    }
    while (!mp.empty())
    {
        auto startIt = mp.begin();
        --startIt->second;
        
        for (int i = 1; i < groupSize; ++i)
        {
            auto it = mp.find(startIt->first + i);
            if (it == mp.end())
            {
                return false;
            }
            else
            {
                --it->second;
                if (it->second == 0)
                {
                    mp.erase(it);
                }
            }
        }
        if (startIt->second == 0)
        {
            mp.erase(startIt);
        }
    }
    return true;
}