#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
const int N = 100;
bool vis[N][N];
ll dis[N][N];
vector<pair<int, int>> d = {{-2, 1},{-1, 2},{1, 2},{2, -1},{2, 1},{1, -2},{-1, -2},{-2, -1}};
ll n, m;
queue<pair<ll, ll>> q;
bool valid(ll i, ll j)
{
    if ((i < 0 || j < 0) || (i >= n || j >= m))
        return false;
    return true;
}
void bfs(ll si, ll sj)
{
    queue<pair<ll, ll>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        ll a = par.first;
        ll b = par.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            ll ci = a + d[i].first;
            ll cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll si, sj;
        cin >> si >> sj;
        ll ki, kj;
        cin >> ki >> kj;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[ki][kj] << endl;
    }
    return 0;
}