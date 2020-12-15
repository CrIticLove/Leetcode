#include <vector>
using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        vector<int> v;
        while (N > 0)
        {
            v.push_back(N % 10);
            N /= 10;
        }
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] < v[i + 1])
            {
                --v[i + 1];
                for (int j = 0; j < i + 1; ++j)
                {
                    v[j] = 9;
                }
            }
        }
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            ans = ans * 10 + v[i];
        }
        return ans;
    }
};
