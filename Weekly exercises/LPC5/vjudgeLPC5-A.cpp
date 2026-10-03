#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    
    cin >> q;
    for(int i=0;i<q;i++){
        long long n;
        long long a,b;
        cin >> n >> a >> b;
        long long total;
        if(b<2*a){
            total=(n/2)*b;
            if((n%2)!=0){
                total+=a;
            }
        }else if(b>=2*a){
            total=n*a;
        }

        cout << total << "\n";
    }



}