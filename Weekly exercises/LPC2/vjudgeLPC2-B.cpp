#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    deque<int> dq;
    bool reverse=false;
    for(int i=0; i<n; i++){
        string peniscleta;
        int value;
        cin >> peniscleta;
        if(peniscleta=="reverse"){
            reverse=true;
        }
        if(peniscleta=="toFront"){
            cin >> value;
            if(!reverse)
            dq.push_front(value);
            else dq.push_back(value);
        }else if( peniscleta=="push_back"){
            cin >> value;
            if(reverse)
            dq.push_front(value);
            else dq.push_back(value);
        }else if(peniscleta=="front"){
            if(dq.empty() ){
                cout << "No job for Ada?\n";
            }else{
            int print=dq.front();
            cout<< print << "\n";
            dq.pop_front();
            }
        }else if(peniscleta=="back"){
            if(dq.empty() ){
                cout << "No job for Ada?\n";
            }else{
            int print=dq.back();
            cout<< print << "\n";
            dq.pop_back();
            }
        }
    }




}