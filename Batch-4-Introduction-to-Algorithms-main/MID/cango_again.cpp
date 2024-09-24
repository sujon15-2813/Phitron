#include <bits/stdc++.h>
#define ll long long int
#define INF 1e18
ll dis[1005];
using namespace std;
class Edge
{
public:
    ll u;
    ll v;
    ll c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    ll s;
    cin >> s;
    dis[s] = 0;
    ll t;
    cin >> t;
    while (t--)
    {
        ll d;
        cin >> d;
        for (int i = 1; i <= n; i++) 
        {
            for (Edge ed : EdgeList)
            {
                ll u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;
                if (dis[u] < INF && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c; // path relax
                }
            }
        }
        bool cycle = false; 
        for (Edge ed : EdgeList)
        {
            ll u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }
    return 0;
}