#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long c;
};

bool cmp(Edge x, Edge y) {
    return x.c < y.c;
}

vector<int> parentt, sz;

int findSet(int v) {
    if (v == parentt[v]) return v;
    return parentt[v] = findSet(parentt[v]);
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return false;

    if (sz[a] < sz[b]) swap(a, b);

    parentt[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    sort(edges.begin(), edges.end(), cmp);
    parentt.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parentt[i] = i;
    }
    long long ans = 0;
    int used = 0;
    for (int i = 0; i < m; i++) {
        if (unite(edges[i].a, edges[i].b)) {
            ans += edges[i].c;
            used++;
        }
    }
    if (used != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
    }

    





}