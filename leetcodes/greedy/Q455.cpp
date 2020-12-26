#include <vector>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, sPtr = 0, len = s.size();
        for (int perG : g)
        {
            while (true)
            {
                if (sPtr == len)
                    return ans;
                else if (s[sPtr] < perG)
                    ++sPtr;
                else
                    break;
            };
            ++ans;
            ++sPtr;
        }
        return ans;
    }
};
