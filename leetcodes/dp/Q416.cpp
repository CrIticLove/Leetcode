#include <vector>
#include <algorithm>
using namespace std;

// 状态压缩
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return false;
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        if (*max_element(nums.begin(), nums.end()) > sum)
            return false;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        dp[nums[0]] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (nums[i] <= j)
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[sum];
    }
};

// 未状态压缩
class Solution_Without_State_Compress
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return false;
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        if (*max_element(nums.begin(), nums.end()) > sum)
            return false;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (nums[i] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][sum];
    }
};
