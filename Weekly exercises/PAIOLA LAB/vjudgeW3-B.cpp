#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t; i++){
        int x;
        int pos=0;
        cin >> x;
        for(int j=0; j<x; j++){
            char str[10];
            cin >> str;
            if(str=="LEFT"){
                pos--;
            }else if(str=="RIGHT"){
                pos++;
            }else if(str=="SAME AS"){
                pos+=2;
            }
        }
        printf("%d\n", pos);
        
    }
}