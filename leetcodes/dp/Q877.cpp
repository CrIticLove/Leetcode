#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        const int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = piles[i];
        }
        for (int l = 1; l < len; ++l)
        {
            for (int i = 0; i < len - l; ++i)
            {
                dp[i][i + l] = max((piles[i] - dp[i + 1][i + l]), (piles[i + l] - dp[i][i + l - 1]));
            }
        }
        return dp[0][len - 1] > 0;
    }
};

class Solution_Math
{
public:
    // 数学可得先手恒赢
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};
