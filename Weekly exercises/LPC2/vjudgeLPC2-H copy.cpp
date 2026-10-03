#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        
        int i = 0, ops = 0;
        while(i < n){
            if(i + 1 >= n) break; // need at least 2 chars
            
            if(s[i] == '('){
                // "()" is regular, "((" is palindrome — both length 2, always valid
                ops++;
                i += 2;
            } else {
                // s[i] == ')'
                if(s[i+1] == ')'){
                    // "))" is a palindrome
                    ops++;
                    i += 2;
                } else {
                    // s[i] == ')', s[i+1] == '('
                    // Need prefix like )(...( which is a palindrome
                    // Shortest palindrome starting with ')(' needs form )(...)( or )()(
                    // Actually need to find shortest palindrome starting at i
                    // Pattern: ) ( ... ( ) won't work. 
                    // A palindrome starting with ')(' must end with '()'
                    // So we need s[i..j] where s[j]=')' won't work...
                    // Actually )( reversed is () — not equal, so ")(" of length 2 is NOT palindrome
                    // We need longer: check if s[i..i+3] = ")(()" No...
                    // For ")(" start, need length where s[i+k] mirrors s[i]
                    // Minimum: length 4 like ")(()" - not palindrome
                    // ")()(" - not palindrome  
                    // Only way: find j such that s[i..j] is reg. bracket seq starting with ')'
                    // That's impossible (reg seq must start with '(')
                    // So we need a palindrome: s[i] must equal s[j], s[i]=')'
                    // so s[j]=')', and s[i+1]='(' must equal s[j-1]='('
                    // Shortest: find next ')' at position j where s[i+1..j-1] is symmetric
                    // Simple greedy: find the next ')' that makes a palindrome
                    bool found = false;
                    // minimum palindrome starting ")(" has length >= 4: e.g. ")(()"? No.
                    // ")()(" no. How about "))(": not starting with ")(". 
                    // For ")(" we need s[i..j] palindrome, s[i]=')', s[j]=')'
                    // s[i+1]='(', s[j-1] must be '('
                    // Shortest valid: ")(()" length 4? reversed is ")((" no.
                    // ")(()": reversed ")((" - no. Let me think: 
                    // palindrome means s[i+k] = s[j-k]
                    // s[i]=')', s[i+1]='(' 
                    // length 4: s[i]s[i+1]s[i+2]s[i+3] = palindrome
                    // => s[i+3]=s[i]=')' and s[i+2]=s[i+1]='('
                    // So ")(()" — wait that's )( (  ) 
                    // s=")(()": s[0]=')',s[1]='(',s[2]='(',s[3]=')'
                    // palindrome check: s[0]=')' == s[3]=')' ✓, s[1]='(' == s[2]='(' ✓ YES!
                    // So ")(()" IS a palindrome of length 4!
                    for(int j = i+3; j < n; j += 2){
                        // need s[j]=')' and the whole thing is palindrome
                        // For it to be palindrome starting ")(" ending with "()"
                        // check full palindrome
                        bool isPalin = true;
                        int l = i, r = j;
                        while(l < r){
                            if(s[l] != s[r]){ isPalin = false; break; }
                            l++; r--;
                        }
                        if(isPalin){
                            ops++;
                            i = j + 1;
                            found = true;
                            break;
                        }
                    }
                    if(!found) break;
                }
            }
        }
        cout << ops << " " << (n - i) << "\n";
    }
}