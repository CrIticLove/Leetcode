#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        string answer = "";
        int total = s.length();
        vector<int> bucket(26, 0);
        for (char c : s)
        {
            ++bucket[int(c - 97)];
        }
        bool forward = true;
        while (total)
        {
            if (forward)
            {
                for (int i = 0; i < 26; ++i)
                {
                    if (bucket[i] != 0)
                    {
                        answer += char(i + 97);
                        --bucket[i];
                        --total;
                    }
                }
            }
            else
            {
                for (int i = 25; i >= 0; --i)
                {
                    if (bucket[i] != 0)
                    {
                        answer += char(i + 97);
                        --bucket[i];
                        --total;
                    }
                }
            }
            forward = !forward;
        }
        return answer;
    }
};
