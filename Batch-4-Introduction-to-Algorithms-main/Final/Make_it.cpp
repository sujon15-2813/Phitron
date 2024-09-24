#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
bool dp[N];
bool go(int n)
{
    dp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (i >= 3 && dp[i - 3])
        {
            dp[i] = true;
        }
        else if (i % 2 == 0 && dp[i / 2])
        {
            dp[i] = true;
        }
    }
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (go(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
