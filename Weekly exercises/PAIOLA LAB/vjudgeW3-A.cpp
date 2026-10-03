#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    for(int j=1; j<=t; j++){
        char str[100];
        int count = 0;
        gets(str);
          for(int i=0; i<(int)strlen(str); i++){
            if(toupper(str[i])=='A' || toupper(str[i])=='D' || toupper(str[i])=='G' || toupper(str[i])=='J'
            || toupper(str[i])=='M' || toupper(str[i])=='P' || toupper(str[i])=='T' || toupper(str[i])=='W' || str[i]==' '){
                count++;
            }else if(toupper(str[i])=='B' || toupper(str[i])=='E' || toupper(str[i])=='H' || toupper(str[i])=='K'
            || toupper(str[i])=='N' || toupper(str[i])=='Q' || toupper(str[i])=='U' || toupper(str[i])=='X'){
                count+=2;
            }else if(toupper(str[i])=='C' || toupper(str[i])=='F' || toupper(str[i])=='I' || toupper(str[i])=='L'
            || toupper(str[i])=='O' || toupper(str[i])=='R' || toupper(str[i])=='V' || toupper(str[i])=='Y'){
                count+=3;
            }else if(toupper(str[i])=='S' || toupper(str[i])=='Z'){
                count+=4;
            }
        }
        cout << "Case #" << j << ": " << count << endl;
    }
}