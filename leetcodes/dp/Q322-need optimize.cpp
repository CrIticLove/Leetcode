#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        sort(coins.begin(), coins.end(), [](int a, int b) { return a > b; });
        if (coins[coins.size() - 1] > amount)
            return -1;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for (int i = 1; i * coins[0] <= amount; ++i)
        {
            dp[0][i * coins[0]] = i;
        }
        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i] <= j)
                {
                    //可以拿coins[i]的硬币
                    for (int k = 0; k <= j; k++)
                    {
                        if (dp[i - 1][k] != -1 && (j - k) % coins[i] == 0)
                        {
                            dp[i][j] = dp[i][j] == -1 ? (dp[i - 1][k] + (j - k) / coins[i])
                                                      : min(dp[i][j], dp[i - 1][k] + (j - k) / coins[i]);
                        }
                    }
                    for (int k = 1; k * coins[i] <= j; k++)
                    {
                        dp[i][k * coins[i]] = dp[i][k * coins[i]] == -1 ? k : min(dp[i][k * coins[i]], k);
                    }
                }
            }
        }
        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << setw(3) << j << ' ';
            }
            cout << endl;
        }
        return dp[coins.size() - 1][amount];
    }
};

int main()
{
    vector<int> ques{1, 2147483647};
    Solution solution;
    solution.coinChange(ques, 2);
}
