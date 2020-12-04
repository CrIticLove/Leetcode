#include <vector>
using namespace std;

// 埃氏筛
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        vector<bool> isPrime(n, true);
        int ans = 0;
        int temp;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                ++ans;
                if ((long long)(i)*i < n)
                {
                    for (temp = i * i; temp < n; temp += i)
                    {
                        isPrime[temp] = false;
                    }
                }
            }
        }
        return ans;
    }
};

//  奇数筛
class Solution_Odd
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        vector<bool> isPrime(n / 2 - 1, true);
        int ans = 1;
        int temp;
        for (int i = 3; i < n; i += 2)
        {
            if (isPrime[(i - 3) / 2])
            {
                ++ans;
                if ((long long)(i)*i < n)
                {
                    for (temp = i * i; temp < n; temp += 2 * i)
                    {
                        isPrime[(temp - 3) / 2] = false;
                    }
                }
            }
        }
        return ans;
    }
};
