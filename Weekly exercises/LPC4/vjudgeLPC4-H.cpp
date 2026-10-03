#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    long long k;
    cin >> n >> m >> k;
    long long maxMoves = 1LL * (4LL*n*m - 2LL*n - 2LL*m);
    if(k > maxMoves){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<long long,string>> ans;
    for(int i = 0; i < n && k > 0; i++){
        if(m > 1){
            long long use = min(k, (long long)(m-1));
            if(use > 0){
                ans.push_back({use, "R"});
                k -= use;
            }
        }
        if(m > 1){
            long long use = min(k, (long long)(m-1));
            if(use > 0){
                ans.push_back({use, "L"});
                k -= use * 3;
            }
        }
        if(i != n-1){
            long long use = min(k, 1LL);
            if(use > 0){
                ans.push_back({use, "D"});
                k -= use;
            }
        }
    }
    if(k > 0){
        long long use = min(k, (long long)(n-1));
        if(use > 0){
            ans.push_back({use, "U"});
            k -= use;
        }
    }
    cout << ans.size() << "\n";
    for(auto &p : ans){
        cout << p.first << " " << p.second << "\n";
    }
    
    


    
}