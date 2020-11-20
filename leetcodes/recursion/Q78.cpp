#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> answer;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        helper(0, nums);
        return answer;
    }

    void helper(int current, vector<int> &nums)
    {
        if (current == nums.size())
        {
            answer.push_back(temp);
            return;
        }
        temp.push_back(nums[current]);
        helper(current + 1, nums);
        temp.pop_back();
        helper(current + 1, nums);
    }
};