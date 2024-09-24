#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (mat[x].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(mat[x].rbegin(), mat[x].rend());
            for (int res : mat[x])
            {
                cout << res << " ";
            }
            cout << endl;
        }
    }
    return 0;
}