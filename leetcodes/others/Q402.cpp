#include <string>
using namespace std;

class Solution
{
public:
    // defeat 100%
    string removeKdigits(string num, int k)
    {
        const int len = num.length();
        const int kk = k;
        string ans = "";
        int j;
        if (k >= len)
            return "0";
        for (int i = 0; i < len; ++i)
        {
            j = ans.length() - 1;
            while (j >= 0 && k > 0)
            {
                if (ans[j] > num[i])
                {
                    ans.pop_back();
                    --j;
                    --k;
                    continue;
                }
                break;
            }
            ans.push_back(num[i]);
        }
        j = 0;
        while (ans[j] == '0')
            ++j;
        ans = ans.substr(j, len - kk);
        if (ans == "")
            return "0";
        return ans;
    }
};
