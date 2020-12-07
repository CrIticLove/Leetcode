#include <vector>
using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelf_width)
    {
        // height 0, width 1
        const int len = books.size();
        int spareSpace = shelf_width - books[0][1], thisLayerHeight = books[0][0];
        vector<int> dp(len, INT_MAX);
        dp[0] = books[0][1];
        vector<int> &book = books[0];
        for (int i = 1; i < len; ++i)
        {
            book = books[i];
            if (spareSpace < book[1])
            {
                dp[i] = dp[i - 1] + book[0];
                spareSpace = shelf_width - book[1];
                thisLayerHeight = book[0];
            } else {
                dp[i] = min(dp[i-1])
            }
        }
    }
};
