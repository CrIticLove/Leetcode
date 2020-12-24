#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        const int len = ratings.size();
        if (len == 1)
            return 1;
        int ans = 0;
        vector<int> ascending(len, 0);
        vector<int> descending(len, 0);
        ascending[0] = 1;
        descending[len - 1] = 1;
        for (int i = 1; i < len; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                ascending[i] = ascending[i - 1] + 1;
            }
            else
            {
                ascending[i] = 1;
            }
            if (ratings[len - 1 - i] > ratings[len - i])
            {
                descending[len - 1 - i] = descending[len - i] + 1;
            }
            else
            {
                descending[len - 1 - i] = 1;
            }
        }
        for (int i = 0; i < len; ++i)
        {
            ans += max(ascending[i], descending[i]);
        }
        return ans;
    }
};
