#include <string>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        // senate is combination of R and D
        int numR = 0, numD = 0, index = 0, toRemoveR = 0, toRemoveD = 0;
        string radiant = "Radiant", dire = "Dire";
        const int len = senate.length();
        for (char c : senate)
        {
            if (c == 'D')
                ++numD;
            else
                ++numR;
        }
        while (true)
        {
            if (index == len)
                index = 0;
            if (senate[index] == 'N'){
                ++index;
                continue;
            }
            if (senate[index] == 'D')
            {
                if (toRemoveD > 0)
                {
                    senate[index] = 'N';
                    --toRemoveD, --numD, ++index;
                    continue;
                }
                else if (numR == 0)
                {
                    return dire;
                }
                else
                {
                    ++toRemoveR, ++index;
                    continue;
                }
            }
            else
            {
                if (toRemoveR > 0)
                {
                    senate[index] = 'N';
                    --toRemoveR, --numR, ++index;
                    continue;
                }
                else if (numD == 0)
                {
                    return radiant;
                }
                else
                {
                    ++toRemoveD, ++index;
                    continue;
                }
            }
        }
        return radiant + dire;
    }
};
