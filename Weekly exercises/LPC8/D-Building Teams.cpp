#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1,0);
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int v=q.front(); q.pop();

                for(int u:adj[v]){
                    if(color[u]==0){
                        color[u]=3-color[v];
                        q.push(u);
                    }
                    else if(color[u]==color[v]){
                        cout<<"IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<"\n";




}