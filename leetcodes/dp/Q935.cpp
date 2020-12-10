#include <vector>
using namespace std;

class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
        {
            return 10;
        }
        const vector<vector<int>> trans{
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 9, 3},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {4, 2}};
        vector<long long> dp(10, 1);
        vector<long long> temp;
        for (int i = 2; i <= n; ++i)
        {
            temp = vector<long long>(10, 0);
            for (int j = 0; j < 10; ++j)
            {
                for (int num : trans[j])
                {
                    temp[num] += dp[j];
                    temp[num] %= 1000000007;
                }
            }
            dp = temp;
        }
        long long ansTemp = 0;
        for (long long num : dp)
        {
            ansTemp += num;
        }
        ansTemp %= 1000000007;
        return int(ansTemp);
    }
};
