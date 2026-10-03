#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int primeira = s[0] - 'a';
        int segunda = s[1] - 'a';
        int ans = primeira * 25 + segunda + 1;
        if(s[1] > s[0]){
            ans--;
        }
        cout << ans << "\n";
    }

    




}