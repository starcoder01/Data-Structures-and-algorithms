// find the nth fibonacci

#include <bits/stdc++.h>
using namespace std;

// First Approach using memoization
int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

// second approach using tabulation
int fibonacci2(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// space optimization
int fibonacci3(int n)
{
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci(n, dp);
    cout << fibonacci2(n, dp);
    cout << fibonacci3(n);
}
