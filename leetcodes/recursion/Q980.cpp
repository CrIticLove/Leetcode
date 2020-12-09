#include <vector>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int height = grid.size(), width = grid[0].size();
        int posm, posn, total = 0;
        // data initialize
        vector<vector<int>> recursion(height + 2, vector<int>(width + 2, -1));
        for (int i = 1; i <= height; ++i)
        {
            for (int j = 1; j <= width; ++j)
            {
                recursion[i][j] = grid[i - 1][j - 1];
                if (grid[i - 1][j - 1] != -1)
                    ++total;
                if (grid[i - 1][j - 1] == 1)
                {
                    posm = i, posn = j;
                }
            }
        }
        tranverse(recursion, posm, posn, total);
        return ans;
    }

    void tranverse(vector<vector<int>> &recursion, int posm, int posn, int total)
    {
        if (recursion[posm][posn] == -1)
            return;
        --total;
        //if reach the end
        if (recursion[posm][posn] == 2)
        {
            if (total == 0)
            {
                ++total;
                ++ans;
                return;
            }
            else
            {
                ++total;
                return;
            }
        }

        //start tranverse
        recursion[posm][posn] = -1;
        tranverse(recursion, posm + 1, posn, total);
        tranverse(recursion, posm, posn + 1, total);
        tranverse(recursion, posm - 1, posn, total);
        tranverse(recursion, posm, posn - 1, total);
        recursion[posm][posn] = 0;
        ++total;
        return;
    }
};
