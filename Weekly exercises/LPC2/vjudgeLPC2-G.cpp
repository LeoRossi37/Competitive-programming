#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int parity = (x%2);
        if(!st.empty() && st.top()==parity){
            st.pop();
        }else{
            st.push(parity);
        }

    }

    if(st.size()<=1){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }






}