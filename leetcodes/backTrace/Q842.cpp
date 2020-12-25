#include <string>
#include <vector>
using namespace std;

// 复制的官方答案 没解出来
class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev)
    {
        if (index == length)
        {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++)
        {
            if (i > index && S[index] == '0')
            {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX)
            {
                break;
            }
            if (list.size() >= 2)
            {
                if (curr < sum)
                {
                    continue;
                }
                else if (curr > sum)
                {
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr))
            {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};
