#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, t;
    cin >> s >> t;
    vector<int> arr;
    for(int i=0; i<s;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }  
    while(t--){
    int x, y; 
    cin >> x >> y;
    int count=0;
    bool flag=true;
        for(int i=0; i<s && (flag);i++){
            if(arr[i]==x){
                count++;
            }
            if(count==y){
                cout << (i+1) << "\n";
                flag=false;
            }
        }
        if(flag){
            cout << "-1\n" ;
        }

    }



}