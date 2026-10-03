#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long esq = 1, dir = 2000000000;
        long long k = 1;
        while(esq <= dir){
            long long meio = (esq + dir)/2;
            if(meio*(meio-1)/2 <= n){
                k = meio;
                esq = meio + 1;
            }else{
                dir = meio - 1;
            }
        }
        long long tipos = k*(k-1)/2;
        long long resto = n - tipos;
        cout << k + resto << "\n";
    }

    


}