#include <string>
#include <vector>
using namespace std;

// 纵向
class Solution1
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        const int len = strs.size();
        if (!len)
            return "";
        if (len == 1)
            return strs[0];
        // 纵向比较
        string ans = "";
        bool jump = true;
        int index = 0;
        string present = strs[0];
        while (jump)
        {
            if (index > int(present.size()) - 1)
            {
                jump = false;
                break;
            }
            present = strs[0];
            ans.push_back(present[index]);
            for (int i = 1; i < len; ++i)
            {
                present = strs[i];
                if (index > present.size() - 1)
                {
                    ans.pop_back();
                    jump = false;
                    break;
                }
                if (present[index] != ans.back())
                {
                    ans.pop_back();
                    jump = false;
                    break;
                }
            }
            ++index;
        }
        return ans;
    }
};
