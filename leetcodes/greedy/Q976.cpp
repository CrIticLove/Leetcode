#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i)
        {
            if (A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};
