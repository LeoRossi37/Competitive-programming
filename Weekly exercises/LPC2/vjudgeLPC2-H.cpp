#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        int a;
        string p;
        cin >> a >> p;

        int i = 0;
        int count = 0;

        while(i + 1 < a){
            if(p[i] == '(' || (p[i] == ')' && p[i+1] == ')')){
                i += 2;
            } 
            else{
                int j = i + 1;
                while(j < a && p[j] != ')'){
                    j++;
                }

                if(j == a){
                    break;
                }

                i = j + 1;
            }

            count++;
        }

        cout << count << " " << a - i << "\n";
    }





    
}