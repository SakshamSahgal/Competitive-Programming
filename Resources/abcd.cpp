#include <bits/stdc++.h>
using namespace std;

// remember to use endl instead of \n for interactive problems.

int main()
{
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    int t;
    cin >> t;
    while (t)
    {

        t--;
    }
    return 0;
}

class Solution
{

public:
    static int dmin(vector<int> &dist, vector<bool> &sptSet, int n)
    {
        // Initialize min value
        int min = INT_MAX, min_index = -1;

        for (int v = 0; v < n; v++)
            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
            }

        return min_index;
    }

    vector<int> dijkstra(vector<vector<int>> &g, int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        vector<bool> sptSet(n, false);

        dist[src] = 0;

        for (int count = 0; count < n - 1; count++)
        {

            int u = dmin(dist, sptSet, n);

            sptSet[u] = true;
            for (int v = 0; v < n; v++)
            {
                if (!sptSet[v] && g[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v])
                    dist[v] = dist[u] + g[u][v];
            }
        }
        return dist;
    }
    vector<int> solve(int N, int Q, vector<vector<int>> &Edge,vector<vector<int>> &query)
    {

        vector<int> ans(query.size());
        vector<vector<int>> g(N, vector<int>(N));
        for (int i = 0; i < Edge.size(); i++)
        {
            int a = Edge[i][0];
            int b = Edge[i][1];

            g[a][b] = 1;
            g[b][a] = 1;

            for (i = 0; i < query.size(); i++)
            {
                a = query[i][0];
                b = query[i][1];

                g[a][b] = 0;
                g[b][a] = 0;

                vector<int> dist = dijkstra(g, 0, N);

                sort(dist.begin(), dist.end());
                ans[i] = dist[N - 1];
            }
        }
        return ans;
    }
};


void vector_printer( vector<long long int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}