#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = 1e18;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        if (w < adj[a][b])
        {
            adj[a][b] = w;
        }
    }
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
            }
        }
    }
    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll x, y;
        cin >> x >> y;
        if (adj[x][y] != 1e18)
        {
            cout << adj[x][y] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}