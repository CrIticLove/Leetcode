#include <vector>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        const int len = stones.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return stones[0];
        if (len == 2)
            return abs(stones[0] - stones[1]);
        int target = 0;
        for (int &stone : stones)
        {
            target += stone;
        }
        vector<int> compressedDp(target / 2 + 1, 0);
        vector<int> temp(target / 2 + 1, 0);
        for (int i = 1; i <= len; ++i)
        {
            for (int j = 1; j <= target / 2; ++j)
            {
                if (stones[i - 1] > j)
                {
                    temp[j] = compressedDp[j];
                }
                else
                {
                    temp[j] = max(compressedDp[j], compressedDp[j - stones[i - 1]] + stones[i - 1]);
                }
            }
            compressedDp = temp;
        }
        return target - 2 * compressedDp[target / 2];
    }
};

class Solution_Without_Compress
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        const int len = stones.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return stones[0];
        if (len == 2)
            return abs(stones[0] - stones[1]);
        int target = 0;
        for (int &stone : stones)
        {
            target += stone;
        }
        vector<vector<int>> dp(len + 1, vector<int>(target / 2 + 1, 0));
        for (int i = 1; i <= len; ++i)
        {
            for (int j = 1; j <= target / 2; ++j)
            {
                if (stones[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return target - 2 * dp[len][target / 2];
    }
};
