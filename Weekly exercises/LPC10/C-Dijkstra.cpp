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
        ll w;
        cin >> a >> b >> w;
        grafo[a].push_back(make_pair(b, w));
        grafo[b].push_back(make_pair(a, w));
    }
    vector<ll> dist(n + 1, INF);
    vector<int> pai(n + 1, -1);
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
                pai[v] = u;
                fila.push(make_pair(dist[v], v));
            }
        }
    }
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }
    vector<int> caminho;
    int atual = n;
    while (atual != -1) {
        caminho.push_back(atual);
        atual = pai[atual];
    }
    reverse(caminho.begin(), caminho.end());
    for (int i = 0; i < caminho.size(); i++) {
        cout << caminho[i] << " ";
    }

    





}