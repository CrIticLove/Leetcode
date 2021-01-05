#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        const int len = s.length();
        if (len < 3)
            return {};
        vector<vector<int>> ans;
        int start = 0, index = 1;
        for (; index < len; ++index)
        {
            if (s[index] ^ s[start])
            {
                if (index - start > 2)
                {
                    ans.push_back({start, index - 1});
                }
                start = index;
            }
        }
        if (len - start > 2 && s[start] == s[len - 1])
            ans.push_back({start, len - 1});
        return ans;
    }
};
