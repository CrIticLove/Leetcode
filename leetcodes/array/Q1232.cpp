#include <vector>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int len = coordinates.size();
        if (len == 2)
            return true;
        for (int i = 1; i < len; ++i)
        {
            coordinates[i][0] -= coordinates[0][0];
            coordinates[i][1] -= coordinates[0][1];
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for (int i = 2; i < len; ++i)
        {
            if (A * coordinates[i][0] + B * coordinates[i][1] != 0)
                return false;
        }
        return true;
    }
};
