#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while(k--){
        long long n, x, t;
        cin >> n >> x >> t;
        long long d = min(t/x, n-1);
        long long ans = d*n - (d*(d+1))/2;
        cout << ans << "\n";
    }

    

    
}