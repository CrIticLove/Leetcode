class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int f[3] = {0, 1, 1};
        for (int i = 3; i <= n; ++i)
        {
            f[0] = f[1];
            f[1] = f[2];
            f[2] = f[0] + f[1];
        }
        return f[2];
    }
};

class Solution_recursion
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n < 3)
        {
            return 1;
        }
        else
        {
            return fib(n - 1) + fib(n - 2);
        }
    }
};
