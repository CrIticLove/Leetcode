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

//  奇数筛
class Solution_odd
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        const int len = n / 2 - 1;
        vector<bool> vec(len, true);
        int temp;
        long long t;
        for (int i = 3; i < n; i += 2)
        {
            if (!(vec[(i - 3) / 2]))
                continue;
            if (isPrime(i))
            {
                for (t = (long long)(i) * (long long)(i); t <= n; t += 2 * i)
                {
                    vec[(t - 3) / 2] = false;
                }
            }
        }
        temp = 0;
        for (bool b : vec)
        {
            if (b)
            {
                ++temp;
            }
        }
        return temp + 1;
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
