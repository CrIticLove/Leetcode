#include <vector>
using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        const int height = A.size(), width = A[0].size();
        if (width == 1)
        {
            return height;
        }
        int ans = height * pow(2, width - 1), ones, zeros;
        for (int j = 1; j < width; ++j)
        {
            ones = 0, zeros = 0;
            for (int i = 0; i < height; ++i)
            {
                // 原来是 if (A[i][j] + A[i][0] == 1) 逻辑做了合并但发现还是下面这种比较快
                if ((A[i][j] == 0 && A[i][0] == 1) || (A[i][j] == 1 && A[i][0] == 0))
                {
                    ++zeros;
                }
                else
                {
                    ++ones;
                }
            }
            //count the largest
            if (ones > zeros)
            {
                ans += ones * pow(2, width - j - 1);
            }
            else
            {
                ans += zeros * pow(2, width - j - 1);
            }
        }
        return ans;
    }
};
