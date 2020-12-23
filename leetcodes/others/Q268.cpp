#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums)
        {
            ans ^= num;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            ans ^= i;
        }
        return ans;
    }
};
