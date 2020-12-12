#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        const int len = nums.size();
        if (len < 2)
            return len;
        // large代表到i为止的数列中，最后一项为上升项的摆动序列长度，small同理
        int large = 1, largeTemp;
        int small = 1, smallTemp;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                largeTemp = max(large, small + 1);
                smallTemp = small;
            }
            else if (nums[i] < nums[i - 1])
            {
                largeTemp = large;
                smallTemp = max(large + 1, small);
            }
            else
            {
                largeTemp = large;
                smallTemp = small;
            }
            large = largeTemp, small = smallTemp;
        }
        return max(large, small);
    }
};

class Solution_without_compress
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        const int len = nums.size();
        if (len < 2)
            return len;
        // large[i]代表到i为止的数列中，最后一项为上升项的摆动序列长度，small同理
        vector<int> large(len, 0);
        vector<int> small(len, 0);
        large[0] = small[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                large[i] = max(large[i - 1], small[i - 1] + 1);
                small[i] = small[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                large[i] = large[i - 1];
                small[i] = max(large[i - 1] + 1, small[i - 1]);
            }
            else
            {
                large[i] = large[i - 1];
                small[i] = small[i - 1];
            }
        }
        return max(large[len - 1], small[len - 1]);
    }
};

class Solution_another
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        const int len = nums.size();
        if (len < 2)
            return len;
        // large[i] 代表以nums[i]结尾的并且nums[i]为最后一个上升项的摆动序列的长度，small同理
        vector<int> large(len, 0);
        vector<int> small(len, 0);
        large[0] = small[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    large[i] = max(large[i], small[j] + 1);
                }
                else if (nums[i] < nums[j])
                {
                    small[i] = max(small[i], large[j] + 1);
                }
                else
                {
                    // nums[i] == nums[j]
                    large[i] = max(large[i], large[j]);
                    small[i] = max(small[i], small[j]);
                }
            }
        }
        return max(large[len - 1], small[len - 1]);
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> v{1, 7, 4, 9, 2, 5};
    solution.wiggleMaxLength(v);
}