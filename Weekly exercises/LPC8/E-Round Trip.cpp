#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> vis, parent;
int start_node = -1, end_node = -1;
bool dfs(int v, int p){
    vis[v] = 1;
    for(int u: adj[v]){
        if(u == p) continue;

        if(vis[u]){
            start_node = u;
            end_node = v;
            return true;
        }

        parent[u] = v;
        if(dfs(u, v)) return true;
    }

    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)) break;
        }
    }
    if(start_node == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> cycle;
    cycle.push_back(start_node);
    for(int v=end_node; v!=start_node; v=parent[v]){
        cycle.push_back(v);
    }
    cycle.push_back(start_node);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<"\n";
    for(int x:cycle) cout<<x<<" ";
    cout<<"\n";

    


    
}