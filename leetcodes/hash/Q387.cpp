#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> v(26, -1);
        int ans = INT_MAX;
        char a = 'a';
        for (int i = 0; i < s.length(); ++i)
        {
            if (v[s[i] - a] > -1)
            {
                v[s[i] - a] = INT_MAX;
            }
            else
            {
                v[s[i] - a] = i;
            }
        }
        for (auto t : v)
        {
            if (t == -1)
                continue;
            ans = min(ans, t);
        }
        return ans < INT_MAX ? ans : -1;
    }
};
