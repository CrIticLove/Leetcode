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
        vector<bool> vec(n, true);
        vec[0] = false, vec[1] = false;
        long long temp;
        for (long long i = 2; i < n; ++i)
        {
            if (!vec[i])
                continue;
            if (isPrime(i))
            {
                for (temp = i * i; temp <= n; temp += i)
                {
                    vec[temp] = false;
                }
            }
        }
        temp = 0;
        for (int i = 2; i < n; ++i)
        {
            if (vec[i])
                ++temp;
        }
        return temp;
    }

    bool isPrime(int n)
    {
        for (int i = 2; i * i < n; ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
