#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> arr(n);
        int count=1;
        int minimo=INT_MAX;
        int maximo=0;
        cin >> arr[0];
        for(int j=1; j< n; j++){
            cin >> arr[j];
            if((arr[j]-arr[j-1])==2){
                count++;
            }else{
                minimo=min(minimo,count);
                maximo=max(maximo,count);
                count=1;
            }
        }
        minimo=min(minimo,count);
        maximo=max(maximo,count);

        cout << minimo << " " << maximo << "\n";
    }





}