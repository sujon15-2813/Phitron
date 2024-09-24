#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll int N = 1e9;
vector<pair<ll int, ll int>> v[N];
ll int dis[N];

void dijkstra(ll int src)
{
    priority_queue<pair<ll int, ll int>, vector<pair<ll int,ll int>>, greater<pair<ll int, llint>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<ll int,ll int> parent = pq.top();
        pq.pop();
        ll int node = parent.second;
        ll int cost = parent.first;

        if (cost > dis[node])
            continue;

        for (pair<ll int,ll int> child : v[node])
        {
            ll int childNode = child.first;
            ll int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // Path relax
                dis[childNode] = cost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main()
{
    ll int n, e;
    cin >> n >> e;

    for (ll int i = 1; i <= n; i++)
    {
        v[i].clear();
        dis[i] = INT_MAX;
    }

    for (ll int i = 0; i < e; i++)
    {
         ll int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    ll int source;
    cin >> source;

    ll int T;
    cin >> T;

    while (T--)
    {
        ll int dest, max_cost;
        cin >> dest >> max_cost;

        for (ll int i = 1; i <= n; i++)
        {
            dis[i] = INT_MAX;
        }

        dijkstra(source);

        if (dis[dest] <= max_cost)
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
