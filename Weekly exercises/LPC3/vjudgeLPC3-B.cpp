#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int total=240-k;
    int count =0;
    bool f=false;
    for(int i=1;i<=n; i++){
        total-=5*i;
        if(total>=0){
            count ++;
        }else if(total==0){
            cout << count << "\n";
            f=true;
        }
    }
    if(!f){
        cout << count << "\n";
    }
    

}