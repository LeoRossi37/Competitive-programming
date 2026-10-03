#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;
    vector<long long> arr(n);
    long long maior = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maior = max(maior, arr[i]);
    }
    long long esq = 0, dir = maior;
    long long resp = 0;

    while(esq <= dir){
        long long mid = (esq + dir) / 2;
        long long madeira = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > mid)
                madeira += arr[i] - mid;
        }
        if(madeira >= m){
            resp = mid;
            esq = mid + 1;
        }
        else{
            dir = mid - 1;
        }
    }

    cout << resp << "\n";



    
}