#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> counter(26, 0);
        pair<int, int> maxnum(0, 1);
        int ans;
        for (char &c : tasks)
        {
            ++counter[c - 65];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (counter[i] > maxnum.first)
            {
                maxnum.first = counter[i];
                maxnum.second = 1;
            }
            else if (counter[i] == maxnum.first)
            {
                ++maxnum.second;
            }
        }
        ans = (maxnum.first - 1) * (n + 1) + maxnum.second;
        ans = max(ans, int(tasks.size()));
        return ans;
    }
};
