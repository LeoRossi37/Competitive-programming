#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    char in, fim;
    long long n;
    cin >> in >> fim;
    cin >> n;
    
    int pos_in, pos_fim;
 
    if (in == 'v') pos_in = 0;
    else if (in == '>') pos_in = 1;
    else if (in == '^') pos_in = 2;
    else if (in == '<') pos_in = 3;
   
    if (fim == 'v') pos_fim = 0;
    else if (fim == '>') pos_fim = 1;
    else if (fim == '^') pos_fim = 2;
    else if (fim == '<') pos_fim = 3;
    
    int passos = n % 4;
    int horario = (pos_in + passos) % 4;
    int anti_horario = (pos_in - passos + 4) % 4;
    
    if (horario == pos_fim && anti_horario == pos_fim){
        cout << "undefined";
    }else if (anti_horario == pos_fim){
        cout << "cw";
    }
    else if (horario == pos_fim){
        cout << "ccw";
    }else{
        cout << "undefined";
    }
    return 0;
}