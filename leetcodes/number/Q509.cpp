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

class Solution_enumerate
{
public:
    const int f[31] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610,
                       987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};
    int fib(int n)
    {
        return f[n];
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
