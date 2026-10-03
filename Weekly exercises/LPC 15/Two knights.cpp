#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    for(long long i=1; i<=n; i++){
        long long total = (i*i)*(i*i-1)/2;
        long long atacam = 4*(i-1)*(i-2);
        cout << total - atacam << "\n";
    }

    


}