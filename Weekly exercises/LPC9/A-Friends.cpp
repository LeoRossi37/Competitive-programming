#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;

int dfs(int s){
    stack<int> st;
    st.push(s);
    vis[s] = 1;
    int cnt = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cnt++;
        for(int x : g[u]){
            if(!vis[x]){
                vis[x] = 1;
                st.push(x);
            }
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        g.assign(n + 1, vector<int>());
        vis.assign(n + 1, 0);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                ans = max(ans, dfs(i));
            }
        }
        cout << ans << '\n';
    }

    






}