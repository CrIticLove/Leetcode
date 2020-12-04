#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        const int len = nums.size();
        if (len < 3)
            return false;
        unordered_map<int, int> counter;
        unordered_map<int, int> arrayTailCounter;
        for (int &num : nums)
        {
            ++counter[num];
        }
        for (int &num : nums)
        {
            if (counter[num] == 0)
                continue;
            // if already have array
            if (arrayTailCounter[num - 1] > 0)
            {
                --arrayTailCounter[num - 1];
                ++arrayTailCounter[num];
                --counter[num];
            }
            // if no exist array
            else
            {
                if (counter[num] > 0 && counter[num + 1] > 0 && counter[num + 2] > 0)
                {
                    --counter[num];
                    --counter[num + 1];
                    --counter[num + 2];
                    ++arrayTailCounter[num + 2];
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
