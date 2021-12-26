#include <bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
map<int, vector<int>> g;
long double ans = 0.0;
void DFS(int s, int d, long double prob, int p)
{
    for (auto i : g[s])
    {
        if (i != p)
        {
            long double j = g[s].size();
            if (s != 1)
                j--;
            DFS(i, d + 1, prob * 1.0 / j, s);
        }
    }
    if (g[s].size() == 1 && s != 1)
    {
        // is(v);
        // is(prob);
        long double num = d * 1.0;
        ans += (num * prob);
    }
}

signed main()
{
    //GO_FAST
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1, 0, 1, 0);
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}
