#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;

int dfs(int u){
    if(p[u] == -1) return 1;
    return 1 + dfs(p[u]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    p.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i));
    }
    cout << ans << '\n';

    



    

}