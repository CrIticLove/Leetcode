#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int ans = 0;
        int len = nums.size();
        if (len == 0)
        {
            nums.push_back(1);
            ++ans;
            ++len;
        }
        long long range = 1;
        int index = 0;
        while (range <= n)
        {
            if (index < len && nums[index] <= range)
            {
                range += nums[index];
                ++index;
            }
            else
            {
                range *= 2;
                ++ans;
            }
        }
        return ans;
    }
};
