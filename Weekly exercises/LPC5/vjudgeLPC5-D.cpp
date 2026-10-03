#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(int j=0; j<n;j++){
            cin >> arr[j];
        }
        int x = 0;
        for(int j = 0; j < n; j++){
            int count = 0;
            for(int k = j; k < n; k++){
                if(arr[k] <= arr[j]){
                    count++;
                }
            }
            x = max(x, count);
        }
        cout << n - x << "\n";
    }





}