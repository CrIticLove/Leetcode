#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// 状态压缩
class Solution
{
public:
    pair<int, int> pr;
    int zero, one;
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); ++i)
        {
            //get 0 and 1s
            countFunc(strs[i]);
            for (int j = m; j >= 0; --j)
            {
                for (int k = n; k >= 0; --k)
                {
                    if (pr.first > j || pr.second > k)
                    {
                        dp[j][k] = dp[j][k];
                    }
                    else
                    {
                        dp[j][k] = max(dp[j][k], dp[j - pr.first][k - pr.second] + 1);
                    }
                }
            }
        }

        return dp[m][n];
    }

    void countFunc(const string &str)
    {
        //count nums of 0 and 1
        zero = 0, one = 0;
        for (auto &num : str)
        {
            if (num == '0')
                zero++;
            else
                one++;
        }
        pr = make_pair(zero, one);
    }
};

// 未压缩
class Solution_Without_Compress
{
public:
    int findMaxForm(const vector<string> &strs, int m, int n)
    {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        vector<int> count;
        for (int i = 1; i < strs.size() + 1; i++)
        {
            //get 0 and 1s
            count = countFunc(strs[i - 1]);
            for (int j = m; j >= 0; j--)
            {
                for (int k = n; k >= 0; k--)
                {
                    if (count[0] > j || count[1] > k)
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    else
                    {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - count[0]][k - count[1]] + 1);
                    }
                }
            }
        }

        return dp[strs.size()][m][n];
    }

    vector<int> countFunc(string str)
    {
        //count nums of 0 and 1
        int zero = 0, one = 0;
        for (auto &num : str)
        {
            if (num == '0')
                zero++;
            else
                one++;
        }
        return {zero, one};
    }
};
