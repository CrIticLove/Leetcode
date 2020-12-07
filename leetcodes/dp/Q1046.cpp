#include <vector>
#include <queue>
using namespace std;

// 本题非dp 是大根堆 为了跟第二题放在一起所以归类在dp里
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        int first, second;
        while (pq.size() > 1)
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            first = first - second;
            pq.push(first);
        }
        return pq.top();
    }
};
