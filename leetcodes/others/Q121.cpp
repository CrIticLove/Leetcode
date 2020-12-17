#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int len = prices.size();
        if (len < 2)
            return 0;
        int small = 0, end = 1;
        int ans = 0;
        for (; end < len; ++end)
        {
            ans = max(ans, prices[end] - prices[small]);
            if (prices[end] <= prices[small])
                small = end;
        }
        return ans;
    }
};
