#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inEdge(numCourses);
        vector<int> ans;
        for (vector<int> req : prerequisites)
        {
            inEdge[req[0]]++;
        }
        vector<int> queue;
        for (int i = 0; i < inEdge.size(); ++i)
        {
            if (inEdge[i] == 0)
            {
                queue.push_back(i);
            }
        }
        while (queue.size() > 0)
        {
            int back = queue.back();
            queue.pop_back();
            ans.push_back(back);
            for (vector<int> req : prerequisites)
            {
                if (req[1] == back)
                {
                    inEdge[req[0]]--;
                    if (inEdge[req[0]] == 0)
                    {
                        queue.push_back(req[0]);
                    }
                }
            }
        }
        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};
