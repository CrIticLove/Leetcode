#include <vector>
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        // 1 <= X <= 2*M, M = max(M, N)
        const int len = piles.size();
        int sum = 0;
        vector<vector<int>> dp(len, vector<int>(len + 1, 0));
        for (int i = len - 1; i >= 0; --i)
        {
            sum += piles[i];
            for (int M = 1; M <= len; ++M)
            {
                if (i + 2 * M >= len)
                {
                    // take all
                    dp[i][M] = sum;
                }
                else
                {
                    // take j piles from 1 to M
                    for (int X = 2 * M; X > 0; --X)
                    {
                        dp[i][M] = max(dp[i][M], sum - dp[i + X][max(M, X)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
