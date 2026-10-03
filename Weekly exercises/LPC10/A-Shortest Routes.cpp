#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> grafo(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
    }
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> fila;
    dist[1] = 0;
    fila.push(make_pair(0, 1));
    while (!fila.empty()) {
        ll d = fila.top().first;
        int u = fila.top().second;
        fila.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < grafo[u].size(); i++) {
            int v = grafo[u][i].first;
            ll w = grafo[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                fila.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    






}