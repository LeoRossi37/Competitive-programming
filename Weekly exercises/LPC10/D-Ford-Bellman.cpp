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
    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        arestas.push_back({a, b, w});
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
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << 30000 << " ";
        else cout << dist[i] << " ";
    }

    





}