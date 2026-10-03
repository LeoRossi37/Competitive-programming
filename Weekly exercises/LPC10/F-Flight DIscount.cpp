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
    vector<vector<pair<int, ll>>> reverso(n + 1);
    vector<tuple<int, int, ll>> arestas;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        reverso[b].push_back(make_pair(a, c));
        arestas.push_back(make_tuple(a, b, c));
    }
    vector<ll> dist1(n + 1, INF);
    vector<ll> dist2(n + 1, INF);
    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> fila;
    dist1[1] = 0;
    fila.push(make_pair(0, 1));
    while (!fila.empty()) {
        ll d = fila.top().first;
        int u = fila.top().second;
        fila.pop();
        if (d > dist1[u]) continue;
        for (int i = 0; i < grafo[u].size(); i++) {
            int v = grafo[u][i].first;
            ll w = grafo[u][i].second;
            if (dist1[v] > dist1[u] + w) {
                dist1[v] = dist1[u] + w;
                fila.push(make_pair(dist1[v], v));
            }
        }
    }
    dist2[n] = 0;
    fila.push(make_pair(0, n));
    while (!fila.empty()) {
        ll d = fila.top().first;
        int u = fila.top().second;
        fila.pop();
        if (d > dist2[u]) continue;
        for (int i = 0; i < reverso[u].size(); i++) {
            int v = reverso[u][i].first;
            ll w = reverso[u][i].second;
            if (dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                fila.push(make_pair(dist2[v], v));
            }
        }
    }
    ll resposta = INF;
    for (int i = 0; i < arestas.size(); i++) {
        int a = get<0>(arestas[i]);
        int b = get<1>(arestas[i]);
        ll c = get<2>(arestas[i]);

        resposta = min(resposta, dist1[a] + (c / 2) + dist2[b]);
    }
    cout << resposta;

    




    

}