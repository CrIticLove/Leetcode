#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int ans = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = matrix[i][j];
                    ans += dp[i][j];
                }
                else if (matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
