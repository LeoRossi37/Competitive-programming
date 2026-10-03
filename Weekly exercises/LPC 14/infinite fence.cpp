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

    int T;
    cin >> T;

    while(T--){
        long long r,b,k;
        cin >> r >> b >> k;

        if(r>b){
            swap(r,b);
        }

        long long d=mdc(r,b);

        if(b-d > (k-1)*r){
            cout << "REBEL\n";
        }else{
            cout << "OBEY\n";
        }
    }

    return 0;
}