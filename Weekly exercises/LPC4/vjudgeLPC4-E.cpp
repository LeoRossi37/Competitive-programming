#include <bits/stdc++.h>
using namespace std;

void backtracking(int i, long long dif, vector<long long>&a, long long&asn ){
    if(i==a.size()){
        asn=min(asn,llabs(dif));
        return;
    }
    backtracking(i+1,dif+a[i],a,asn);
    backtracking(i+1,dif-a[i],a,asn);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    long long asn = LLONG_MAX;

    backtracking(0, 0, arr, asn);

    cout << asn << "\n";


}