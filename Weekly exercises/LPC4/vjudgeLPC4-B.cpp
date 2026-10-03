
#include <bits/stdc++.h>
using namespace std;

bool ehPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int prox=n+1;
    while(!ehPrimo(prox)){
        prox++;
    }
    if(prox==(m)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }



}