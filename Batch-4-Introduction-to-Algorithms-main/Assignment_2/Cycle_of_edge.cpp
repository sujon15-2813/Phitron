#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1e5 + 5;
vector<int> adjacency[MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];

void dfs(int src, int &cycleCount)
{
    visited[src] = true;
    for (int neighbor : adjacency[src])
    {
        if (visited[neighbor] && neighbor != parent[src])
            cycleCount++;
        if (!visited[neighbor])
        {
            parent[neighbor] = src;
            dfs(neighbor, cycleCount);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    int cycleCount = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, cycleCount);
        }
    }

    cout << cycleCount / 2 << endl;
    return 0;
}
