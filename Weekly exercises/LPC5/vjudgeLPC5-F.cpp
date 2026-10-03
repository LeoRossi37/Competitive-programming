#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;

long long vaiDar(long long base, long long exp, long long mod){
    long long res = 1;
    base%=mod;
    while(exp>0){
        if(exp & 1) res=(res*base%mod);
        base = (base * base) % mod;
        exp/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin >> a>> b>> c;
        long long expoente = vaiDar(b,c,M-1);
        long long x = vaiDar(a,expoente,M);
        cout << x << "\n";
    }




}