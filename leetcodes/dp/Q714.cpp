#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        const int len = prices.size();
        if (len < 2)
            return 0;
        vector<int> dp(2);
        vector<int> dpTemp(2);
        dp[0] = 0;
        dp[1] = -prices[0];
        for (int i = 1; i < len; ++i)
        {
            dpTemp[0] = dp[0], dpTemp[1] = dp[1];
            dp[0] = max(dpTemp[0], dpTemp[1] + prices[i] - fee);
            dp[1] = max(dpTemp[1], dpTemp[0] - prices[i]);
        }
        return dp[0];
    }
};

class Solution_without_compress
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        const int len = prices.size();
        if (len < 2)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len - 1][0];
    }
};
