#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        const int len = prices.size();
        if (len < 2)
        {
            return 0;
        }
        vector<vector<int>> dp = vector<vector<int>>(k + 1, vector<int>(2));
        for (auto &vec : dp)
        {
            vec[0] = 0;
            vec[1] = -prices[0];
        }
        int i = 1, j = 0;
        for (; i < len; ++i)
        {
            for (j = k; j > 0; --j)
            {
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i]);
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);
            }
            dp[0][1] = max(dp[0][1], -prices[i]);
            dp[0][0] = 0;
        }
        return dp[k][0];
    }
};

class Solution_Without_Compress
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        const int len = prices.size();
        if (len < 2)
        {
            return 0;
        }
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(k + 1, vector<int>(2)));
        for (auto &vec : dp[0])
        {
            vec[0] = 0;
            vec[1] = -prices[0];
        }
        int i = 1, j = 0;
        for (; i < len; ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], -prices[i]);
            for (j = 1; j <= k; ++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }
        return dp[len - 1][k][0];
    }
};
