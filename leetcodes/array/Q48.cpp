#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int s = matrix.size();
        int temp, i, j;
        for (i = 0; i < s - 1; ++i)
        {
            for (j = 0; j < s - 1 - i; ++j)
            {
                temp = matrix[s - 1 - j][s - 1 - i];
                matrix[s - 1 - j][s - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        for (i = 0; i < s / 2; ++i)
        {
            for (j = 0; j < s; ++j)
            {
                temp = matrix[s - 1 - i][j];
                matrix[s - 1 - i][j] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        return;
    }
};
