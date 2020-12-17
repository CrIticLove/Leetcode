#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        const int len = nums.size();
        int temp;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] != i + 1)
            {
                if (nums[i] > 0 && nums[i] < len)
                {
                    // swap nums[i] nums[nums[i]-1]
                    if (nums[i] == nums[nums[i] - 1])
                        continue;
                    temp = nums[i];
                    nums[i] = nums[temp - 1];
                    nums[temp - 1] = temp;
                    --i;
                }
            }
        }
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return len + 1;
    }
};
