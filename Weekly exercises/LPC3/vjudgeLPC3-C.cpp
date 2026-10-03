#include <bits/stdc++.h>
using namespace std;

int buscaBinaria(int vet[], int n, int x){
    int esq = 0, dir = n - 1, meio;
    int res=-1;
    while(esq <= dir) {
        meio = esq + (dir-esq)/2;
        if (vet[meio] == x){
            res= meio;
            dir=meio-1;
        }else if (vet[meio] > x){ 
            dir = meio - 1;
        }else{
            esq = meio + 1;
        }
    }       
    return res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    for(int i=0; i< x; i++){
        int peniscleta;
        cin >> peniscleta;
        int ax = buscaBinaria(arr.data(),arr.size(), peniscleta);
        if(ax!=(-1)){
            cout << ax << "\n";
        }else{
            cout << "-1\n";
        }
    }


}