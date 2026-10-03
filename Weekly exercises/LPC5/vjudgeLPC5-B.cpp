#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    for(int i=0; i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0, j=0,count=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            count++;
            i++;
            j++;
        }else if(b[j]<a[i]-k){
            j++;
        }else{
            i++;
        }
    }
    cout << count << "\n";



}