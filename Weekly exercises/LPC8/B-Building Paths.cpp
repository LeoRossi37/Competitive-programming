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
    vector<int> vis(n+1,0);
    vector<int> reps;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            reps.push_back(i);
            stack<int> st;
            st.push(i);
            vis[i]=1;
            while(!st.empty()){
                int v=st.top(); st.pop();
                for(int u:adj[v]){
                    if(!vis[u]){
                        vis[u]=1;
                        st.push(u);
                }
                }
            }
        }
    }
    cout<<reps.size()-1<<"\n";
    for(int i=1;i<reps.size();i++){
        cout<<reps[i-1]<<" "<<reps[i]<<"\n";
    }

    






}