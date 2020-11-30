#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reorganizeString(string S)
    {
        const int len = S.size();
        int maxpos1, maxpos2;
        vector<int>::iterator temp1, temp2;
        string ans = "";
        vector<int> store(28, 0);
        for (char c : S)
        {
            ++store[c - 96];
        }
        maxpos1 = max_element(store.begin(), store.end()) - store.begin();
        if (store[maxpos1] > (len + 1) / 2)
            return ans;
        int i = 0;
        while (i < len)
        {
            maxpos1 = max_element(store.begin(), store.end()) - store.begin();
            ans.push_back(char(maxpos1 + 96));
            ++i;
            if (i >= len)
            {
                break;
            }
            temp1 = max_element(store.begin(), store.begin() + maxpos1);
            temp2 = max_element(store.begin() + maxpos1 + 1, store.end());
            maxpos2 = *temp1 > *temp2 ? temp1 - store.begin() : temp2 - store.begin();
            ans.push_back(char(maxpos2 + 96));
            ++i;
            --store[maxpos1];
            --store[maxpos2];
        }
        return ans;
    }
};
