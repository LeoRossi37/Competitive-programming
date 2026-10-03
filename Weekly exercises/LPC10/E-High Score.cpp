#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Aresta {
    int a, b;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Aresta> arestas;
    vector<vector<int>> reverso(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        arestas.push_back({a, b, -x});
        reverso[b].push_back(a);
    }
    vector<int> pode(n + 1, 0);
    queue<int> fila;
    fila.push(n);
    pode[n] = 1;
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (int i = 0; i < reverso[u].size(); i++) {
            int v = reverso[u][i];
            if (!pode[v]) {
                pode[v] = 1;
                fila.push(v);
            }
        }
    }
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < arestas.size(); j++) {
            int a = arestas[j].a;
            int b = arestas[j].b;
            ll w = arestas[j].w;
            if (dist[a] == INF) continue;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
        }
    }
    for (int j = 0; j < arestas.size(); j++) {
        int a = arestas[j].a;
        int b = arestas[j].b;
        ll w = arestas[j].w;
        if (dist[a] == INF) continue;
        if (dist[b] > dist[a] + w && pode[b]) {
            cout << -1;
            return 0;
        }
    }
    cout << -dist[n];

    




    

}