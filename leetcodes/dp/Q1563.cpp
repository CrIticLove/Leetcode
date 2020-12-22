#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>
using namespace std;

class Solution
{
public:
    int stoneGameV(vector<int> &stoneValue)
    {
        const int len = stoneValue.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int suml, sumr;
        for (int l = 1; l < len; ++l)
        {
            for (int i = 0; i < len - l; ++i)
            {
                suml = 0;
                sumr = accumulate(stoneValue.begin() + i, stoneValue.begin() + i + l + 1, 0);
                for (int s = 0; s < l; ++s)
                {
                    suml += stoneValue[i + s];
                    sumr -= stoneValue[i + s];
                    // one part: dp[i][i+s] the other part: dp[i+s+1][i+l]
                    if (suml > sumr)
                    {
                        dp[i][i + l] = max(dp[i][i + l], sumr + dp[i + s + 1][i + l]);
                    }
                    else if (suml < sumr)
                    {
                        dp[i][i + l] = max(dp[i][i + l], suml + dp[i][i + s]);
                    }
                    else
                    {
                        dp[i][i + l] = max(dp[i][i + l], max(sumr + dp[i + s + 1][i + l], suml + dp[i][i + s]));
                    }
                }
            }
        }
        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << setw(4) << j;
            }
            cout << endl;
        }
        return dp[0][len - 1];
    }
};
