#include <bits/stdc++.h>
using namespace std;

bool backtrack(int pos, long long sum, vector<int>& n, vector<int>& ans, vector<bool>& used, long long K){
    if(sum > K) return false;
    if(pos == 10){
        return true;
    }
    for(int d = 0; d <= 9; d++){
        if(!used[d]){
            used[d] = true;
            ans[pos] = d;

            if(backtrack(pos + 1, sum + 1LL * d * n[pos], n, ans, used, K)){
                return true;
            }
            used[d] = false;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        vector<int> n(10);
        for(int i = 0; i < 10; i++){
            cin >> n[i];
        }
        long long K;
        cin >> K;
        vector<int> ans(10);
        vector<bool> used(10, false);
        if(backtrack(0, 0, n, ans, used, K)){
            for(int i = 0; i < 10; i++){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }else{
            cout << -1 << "\n";
        }
    }





}