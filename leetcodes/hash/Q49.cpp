#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> strMap;
        unordered_map<string, int>::iterator it;
        vector<vector<string>> ans;
        string tempStr;
        for (string &str : strs)
        {
            tempStr = str;
            sort(tempStr.begin(), tempStr.end());
            it = strMap.find(tempStr);
            if (it != strMap.end())
            {
                ans[it->second].push_back(str);
            }
            else
            {
                strMap.insert(make_pair(tempStr, ans.size()));
                ans.push_back({str});
            }
        }
        return ans;
    }
};
