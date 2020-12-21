#include <vector>
using namespace std;

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        const int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = nums[i];
        }
        for (int l = 1; l < len; ++l)
        {
            for (int i = 0; i < len - l; ++i)
            {
                dp[i][i + l] = max((nums[i] - dp[i + 1][i + l]), (nums[i + l] - dp[i][i + l - 1]));
            }
        }
        // 同分算A赢？ 反正题是这样
        return dp[0][len - 1] >= 0;
    }
};
