#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int count=0;
    for(int i=0; i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    for(int i=0; i<n; i+=2){
        count+=a[i+1]-a[i];
    }

    cout << count << "\n";

}