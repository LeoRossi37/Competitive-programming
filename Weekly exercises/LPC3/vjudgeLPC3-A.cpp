#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    int maior=0;
    for(auto it: arr ){
        maior=max(maior, it.second);
    }

    cout << maior << " " << arr.size() << "\n";

}