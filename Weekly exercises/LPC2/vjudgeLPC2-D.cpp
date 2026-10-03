#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;

        stack<int> pilha;
        stack<int> sum;
        bool flag = true;
        stringstream ss(line);
        vector<int> arr;
        int x;

        while(ss >> x){
            arr.push_back(x);
        }

        for(int i=0; i<arr.size(); i++){
            int a = arr[i];

            if(a < 0){
                int val = abs(a);
                if(!pilha.empty() && val >= pilha.top()){
                    flag = false;
                    break;
                }
                pilha.push(val);
                sum.push(0);
            } else {
                if(pilha.empty() || a != pilha.top()){
                    flag = false;
                    break;
                }
                if(sum.top() >= a){
                    flag = false;
                    break;
                }

                pilha.pop();
                sum.pop();
                if(!sum.empty()){
                    sum.top() += a;
                }
            }
        }

        if(!pilha.empty()) flag = false;

        if(!flag){
            cout << ":-( Try again.\n";
        } else {
            cout << ":-) Matrioshka!\n";
        }
    }
    return 0;
}