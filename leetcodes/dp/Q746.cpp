#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        const int len = cost.size();
        vector<int> dp{0, cost[0], cost[1]};

        for (int i = 2; i < len; ++i)
        {
            dp[0] = dp[1], dp[1] = dp[2];
            dp[2] = min(dp[0] + cost[i], dp[1] + cost[i]);
        }
        return min(dp[1], dp[2]);
    }
};
