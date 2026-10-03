#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> g[MAXN];
bool vis[MAXN];
bool gov[MAXN];
int nodes, edgesCnt;
void dfs(int u) {
    vis[u] = true;
    nodes++;
    edgesCnt += g[u].size();

    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> capitals(k);
    for (int i = 0; i < k; i++) {
        cin >> capitals[i];
        gov[capitals[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int,int>> comps; 
    int extraNodes = 0;
    for (int c : capitals) {
        if (!vis[c]) {
            nodes = 0;
            edgesCnt = 0;
            dfs(c);
            comps.push_back({nodes, edgesCnt / 2});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            nodes = 0;
            edgesCnt = 0;
            dfs(i);
            extraNodes += nodes;
        }
    }
    int idx = 0;
    for (int i = 1; i < comps.size(); i++) {
        if (comps[i].first > comps[idx].first)
            idx = i;
    }
    comps[idx].first += extraNodes;
    long long maxEdges = 0;
    long long currentEdges = m;

    for (auto comp : comps) {
        maxEdges += 1LL * comp.first * (comp.first - 1) / 2;
    }
    cout << maxEdges - currentEdges << '\n';

    





}