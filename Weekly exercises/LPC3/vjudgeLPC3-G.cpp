#include <bits/stdc++.h>
using namespace std;

bool teste(vector<int> &vet, int n, int c, int dist) {
    int count = 1; 
    int ultimaPos = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i] - ultimaPos >= dist) {
            count++;
            ultimaPos = vet[i];
        }
    }
    return count >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        int esq = 0;
        int dir = arr[n - 1] - arr[0];
        int res = 0;
        while (esq <= dir) {
            int meio = esq + (dir - esq) / 2;

            if (teste(arr, n, c, meio)) {
                res = meio; 
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }
        cout << res << "\n";
    }




    
}