#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int u){
    vis[u] = 1;

    for(int x : g[u]){
        if(!vis[x]) dfs(x);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m != n){
        cout << "NO\n";
        return 0;
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "FHTAGN!\n";

    




    

}