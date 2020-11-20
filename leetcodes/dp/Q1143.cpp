#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int size1 = text1.size(), size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
        for (int i = 1; i <= size1; i++)
        {
            for (int j = 1; j <= size2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[size1][size2];
    }
};
