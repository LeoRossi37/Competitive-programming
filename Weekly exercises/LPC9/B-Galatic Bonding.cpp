#include <bits/stdc++.h>
using namespace std;

int n;
double d;
vector<pair<double,double>> v;
vector<vector<int>> g;
vector<int> vis;

double dist(pair<double,double> a, pair<double,double> b){
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
void dfs(int u){
    vis[u] = 1;
    for(int x : g[u]){
        if(!vis[x]) dfs(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> n >> d;
        v.assign(n, {0, 0});
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        g.assign(n, vector<int>());

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(dist(v[i], v[j]) <= d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vis.assign(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        cout << "Case " << k << ": " << ans << '\n';
    }

    




}