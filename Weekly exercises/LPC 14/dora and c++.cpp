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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        long long a,b;
        cin >> n >> a >> b;
        vector<long long> c(n);
        long long g=mdc(a,b);
        for(int i=0; i<n; i++){
            cin >> c[i];
            c[i]%=g;
        }
        sort(c.begin(),c.end());
        long long maior=0;
        for(int i=1; i<n; i++){
            maior=max(maior,c[i]-c[i-1]);
        }
        maior=max(maior,c[0]+g-c[n-1]);

        cout << g-maior << '\n';
    }

    




    
}