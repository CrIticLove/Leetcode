#include <vector>
#include <string>
using namespace std;

// 状态压缩 但速度慢
class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        const int len = stoneValue.size();
        vector<int> dp(4, 0);
        if (len == 1)
        {
            dp[0] = stoneValue[0];
            return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
        }
        else if (len == 2)
        {
            dp[1] = stoneValue[1];
            dp[0] = max(stoneValue[0] - dp[1], stoneValue[0] + stoneValue[1]);
            return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
        }

        dp[2] = stoneValue[len - 1];
        dp[1] = max(stoneValue[len - 2] - dp[2], stoneValue[len - 2] + stoneValue[len - 1]);
        dp[0] = max(stoneValue[len - 3] - dp[1],
                    max(stoneValue[len - 3] + stoneValue[len - 2] - dp[2],
                        stoneValue[len - 3] + stoneValue[len - 2] + stoneValue[len - 1]));
        for (int i = len - 4; i >= 0; --i)
        {
            dp[3] = dp[2], dp[2] = dp[1], dp[1] = dp[0];
            dp[0] = max(stoneValue[i] - dp[1],
                        max(stoneValue[i] + stoneValue[i + 1] - dp[2],
                            stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[3]));
        }
        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};

// 未状态压缩 速度快
class Solution_without_compress
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        const int len = stoneValue.size();
        vector<int> dp(len, 0);
        if (len == 1)
        {
            dp[0] = stoneValue[0];
            return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
        }
        else if (len == 2)
        {
            dp[1] = stoneValue[1];
            dp[0] = max(stoneValue[0] - dp[1], stoneValue[0] + stoneValue[1]);
            return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
        }

        dp[len - 1] = stoneValue[len - 1];
        dp[len - 2] = max(stoneValue[len - 2] - dp[len - 1], stoneValue[len - 2] + stoneValue[len - 1]);
        dp[len - 3] = max(stoneValue[len - 3] - dp[len - 2],
                          max(stoneValue[len - 3] + stoneValue[len - 2] - dp[len - 1],
                              stoneValue[len - 3] + stoneValue[len - 2] + stoneValue[len - 1]));
        for (int i = len - 4; i >= 0; --i)
        {
            dp[i] = max(stoneValue[i] - dp[i + 1],
                        max(stoneValue[i] + stoneValue[i + 1] - dp[i + 2],
                            stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]));
        }
        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};
