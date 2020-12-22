#include <vector>
using namespace std;

// 用int 比bool快很多
class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                if (!dp[i - j * j])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
