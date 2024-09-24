#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[N][N];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.first, y = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;
            if ((valid(ci, cj) && !vis[ci][cj]) && a[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[x][y] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int Li = 0;
    int Lj = 0;
    int Ri = 0;
    int Rj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                Li = i;
                Lj = j;
            }
            else if (a[i][j] == 'B')
            {
                Ri = i;
                Rj = j;
            }
        }
    }
    bfs(Li, Lj);
    if (dis[Ri][Rj] > 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}