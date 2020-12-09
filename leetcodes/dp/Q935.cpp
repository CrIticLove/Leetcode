#include <vector>
using namespace std;

class Solution
{
public:
    int knightDialer(int n)
    {
        const vector<vector<int>> trans{
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 9, 3},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {4, 2}};
        vector<int> dp;
        return 1;
    }
};
