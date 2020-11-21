#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //  两数之和
    // mingGW报错时使用下面这个函数参数列表
    // vector<int> twoSum(const vector<int> &nums, int target)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto element = map.find(target - nums[i]);
            if (element != map.end())
            {
                return {i, element->second};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
