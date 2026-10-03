#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, w;
    bool flag = true;
    while(cin >> t >> w){
        int n;
        cin >> n;
        vector<int> d(n), v(n);
        for(int i = 0; i < n; i++){
            cin >> d[i] >> v[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        for(int i = 1; i <= n; i++){
            int cost = 3 * w * d[i-1];
            for(int j = 0; j <= t; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= cost){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-cost] + v[i-1]);
                }
            }
        }
        int j = t;
        vector<int> x;
        for(int i = n; i >= 1; i--){
            int cost = 3 * w * d[i-1];
            if(j >= cost && dp[i][j] == dp[i-1][j-cost] + v[i-1]){
                x.push_back(i-1);
                j -= cost;
            }
        }
        reverse(x.begin(), x.end());
        if(!flag){ 
            cout << "\n";
        }
        flag = false;
        cout << dp[n][t] << "\n";
        cout << x.size() << "\n";
        for(int idx : x){
            cout << d[idx] << " " << v[idx] << "\n";
        }
    }









}