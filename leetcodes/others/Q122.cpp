#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int len = prices.size();
        if (len == 0 || len == 1)
            return 0;
        int ans = 0, tempAns = 0;
        for (int end = 1; end < len; ++end)
        {
            if (prices[end] < prices[end - 1])
            {
                ans += tempAns;
                tempAns = 0;
            }
            else
            {
                tempAns += prices[end] - prices[end - 1];
            }
        }
        ans += tempAns;
        return ans;
    }
};
