#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int countFive = 0, countTen = 0;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                ++countFive;
            }
            else if (bill == 10)
            {
                if (countFive == 0)
                {
                    return false;
                }
                else
                {
                    --countFive;
                    ++countTen;
                }
            }
            else
            {
                // bill == 20
                if (countFive == 0)
                {
                    return false;
                }
                else if (countTen == 0)
                {
                    countFive -= 3;
                    if (countFive < 0)
                    {
                        return false;
                    }
                }
                else
                {
                    --countTen;
                    --countFive;
                }
            }
        }
        return true;
    }
};
