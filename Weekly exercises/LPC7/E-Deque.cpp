#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long  n;
    cin >> n;
    vector <long long > peniscleta(n);
    for(int i=0; i<n; i++)    cin >> peniscleta[i];
    vector<vector<long long>> dp(n, vector<long long>(n,0));
    for(int i=0; i< n;i++){
      dp[i][i]=peniscleta[i];
    }

    for(int i=2; i<=n; i++){
      for(int j=0; j+i-1<n;j++){
        int r=j+i-1;
        dp[j][r]= max(peniscleta[j]-dp[j+1][r], peniscleta[r]- dp[j][r-1]);
      }
    }

    cout << dp[0][n-1] << "\n";




}