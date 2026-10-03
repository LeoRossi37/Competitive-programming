#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;

        long long sum=0;
        int height=0;
        for(int i=1; sum+i<=n;i++){
            sum+=i;
            height++;
        }
        cout << height << "\n";
        }



}