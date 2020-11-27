#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, int> store;
        unordered_map<int, int>::iterator it;
        for (int num : nums)
        {
            it = store.find(num);
            if (it != store.end())
                return it->first;
            else
                store.insert(make_pair(num, 1));
        }
        return -1;
    }
};
