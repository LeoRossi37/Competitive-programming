#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

pair<int,int> bfs(int s){
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x : g[u]){
            if(dist[x] == -1){
                dist[x] = dist[u] + 1;
                q.push(x);
            }
        }
    }
    int mx = 0, node = s;
    for(int i = 1; i <= n; i++){
        if(dist[i] > mx){
            mx = dist[i];
            node = i;
        }
    }
    return {node, mx};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    g.assign(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    int a = bfs(1).first;
    int ans = bfs(a).second;
    cout << ans << '\n';

    


    

}