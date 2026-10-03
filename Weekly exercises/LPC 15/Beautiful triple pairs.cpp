#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    const long long BASE = 1000001;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        unordered_map<long long, long long> mp12;
        unordered_map<long long, long long> mp13;
        unordered_map<long long, long long> mp23;
        unordered_map<long long, long long> mp123;
        long long ans = 0;
        for(int i=0; i<n-2; i++){
            long long x = a[i];
            long long y = a[i+1];
            long long z = a[i+2];
            long long chave12 = x*BASE + y;
            long long chave13 = x*BASE + z;
            long long chave23 = y*BASE + z;
            long long chave123 = (x*BASE + y)*BASE + z;
            ans += mp12[chave12];
            ans += mp13[chave13];
            ans += mp23[chave23];
            ans -= 3*mp123[chave123];
            mp12[chave12]++;
            mp13[chave13]++;
            mp23[chave23]++;
            mp123[chave123]++;
        }

        cout << ans << "\n";
    };





    
}