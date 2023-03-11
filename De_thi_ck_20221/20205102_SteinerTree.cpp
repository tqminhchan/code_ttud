#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
};

const int MAXN = 1005;

int parent[MAXN];

int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v)
{
    parent[find(u)] = find(v);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    int k;
    cin >> k;
    vector<int> R(k);
    for (int i = 0; i < k; i++)
    {
        cin >> R[i];
    }
    sort(R.begin(), R.end());
    vector<Edge> graph;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (binary_search(R.begin(), R.end(), u) && binary_search(R.begin(), R.end(), v))
        {
            graph.push_back(edges[i]);
        }
    }
    sort(graph.begin(), graph.end());
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int ans = 0;
    for (auto e : graph)
    {
        int u = e.u, v = e.v, w = e.w;
        if (find(u) != find(v))
        {
            merge(u, v);
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}