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
        vector<int> dp(4);
        dp[0] = -prices[0];
        dp[1] = 0;
        dp[2] = -prices[0];
        dp[3] = 0;
        for (int i = 1; i < len; ++i)
        {
            dp[3] = max(dp[3], dp[2] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = max(dp[0], -prices[i]);
        }
        return dp[3];
    }
};

class Solution_without_compress
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int len = prices.size();
        if (len < 2)
            return 0;
        vector<vector<int>> dp(len, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < len; ++i)
        {
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[len - 1][4];
    }
};
