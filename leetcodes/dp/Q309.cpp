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
        vector<int> dp(3);
        vector<int> dpTemp(3);
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[2] = 0;
        for (int i = 1; i < len; ++i)
        {
            dpTemp[0] = dp[0], dpTemp[1] = dp[1], dpTemp[2] = dp[2];
            dp[0] = max(dpTemp[0], dpTemp[2]);
            dp[1] = max(dpTemp[1], dpTemp[0] - prices[i]);
            dp[2] = dpTemp[1] + prices[i];
        }
        return max(dp[0], dp[2]);
    }
};
