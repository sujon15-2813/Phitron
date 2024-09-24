#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int vis[N][N];
int dis[N][N];
int par[N][N];
char mz[N][N];
pair<int, int> path[N][N];
vector<pair<int, int>> moves={{1,0},{-1,0},{0,-1},{0,1}};
int n, m;
int sx, sy, ex, ey;
bool isValid(int i, int j)
{
    return !vis[i][j] and (i >= 0 and i < n) and (j >= 0 and j < m);
}
void bfs()
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    //vis[sx][sy] = 1;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
      //  cout << p.first <<  " " << p.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = p.first + moves[i].first;
            int cj = p.second + moves[i].second;

            if (isValid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = 1;
                path[ci][cj] = {moves[i].first, moves[i].second};
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
            char ch;
            cin >> ch;
            mz[i][j] = ch;
            if (ch == '#')
                vis[i][j] = 1;
            if (ch == 'D')
            {
                sx = i, sy = j;
            }
            if (ch == 'R')
            {
                ex = i, ey = j;
            }
        }
    }
    bfs();
   
    if (!vis[ex][ey])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mz[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    pair<int, int> des = {ex, ey};
    vector<pair<int, int>> ans;
    while (des.first != sx or des.second != sy)
    {
        ans.push_back({path[des.first][des.second]});
        if (des.first != ex or des.second != ey)
            mz[des.first][des.second] = 'X';
        des.first -= ans.back().first;
        des.second -= ans.back().second;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mz[i][j];
        }
        cout << endl;
    }
    return 0;
}