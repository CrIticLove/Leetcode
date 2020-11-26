#include <vector>
#include <algorithm>
using namespace std;

// 使用O(n) 桶排序
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int ans = 0;
        // create buckets
        vector<vector<int>> bucket(10, vector<int>());
        vector<int> numsCopy(nums);
        // get the max value digit
        int max = *max_element(nums.begin(), nums.end());
        int digit = 0;
        while (max > 0)
        {
            max /= 10;
            ++digit;
        }
        // bucket sort
        int temp, tempNum;
        for (int i = 0; i <= digit; ++i)
        {
            if (i != 0)
                numsCopy.clear();
            // pop all the buckets
            for (auto &vec : bucket)
            {
                for (auto &ele : vec)
                {
                    numsCopy.push_back(ele);
                }
                vec.clear();
            }
            for (auto &num : numsCopy)
            {
                // sort by present digit
                tempNum = num;
                for (int j = 0; j <= i; ++j)
                {
                    temp = tempNum % 10;
                    tempNum /= 10;
                }
                bucket[temp].push_back(num);
            }
        }

        // find max gap
        for (int i = 1; i < numsCopy.size(); ++i)
        {
            ans = std::max(numsCopy[i] - numsCopy[i - 1], ans);
        }
        return ans;
    }
};

// 不讲武德 使用排序
class Solution1
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int ans = 0;
        vector<int> numsCopy(nums);
        sort(numsCopy.begin(), numsCopy.end());
        for (int i = 1; i < numsCopy.size(); ++i)
        {
            ans = max(numsCopy[i] - numsCopy[i - 1], ans);
        }
        return ans;
    }
};