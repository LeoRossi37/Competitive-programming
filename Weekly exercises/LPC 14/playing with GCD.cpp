#include<bits/stdc++.h>
using namespace std;

long long mdc(long long a, long long b){
    while(b!=0){
        long long aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

long long mmc(long long a, long long b){
    return a/mdc(a,b)*b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        bool possivel=true;
        for(int i=1; i<n-1; i++){
            long long x=mmc(a[i-1],a[i]);
            long long y=mmc(a[i],a[i+1]);
            if(mdc(x,y)!=a[i]){
                possivel=false;
            }
        }
        if(possivel){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    




}