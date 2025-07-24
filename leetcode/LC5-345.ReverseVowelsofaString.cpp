
#include<iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        
        string retorno = s;
        string pila;
        int pPila;

        for(int i = 0 ; i < s.size() ; i++){
            if(isVowel(s[i])){
                pila += s[i];
                s[i] = '\x01'; // Caracter ASCII no imprimible (SOH)  
            }
        }

        pPila = 0;

        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] == '\x01'){
                retorno[i] = pila[pPila];
                pPila++;
            }
        }

        return retorno;
    }

    bool isVowel(char c){
        return ((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u') ||
                (c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'));
    }
}; 

int main()
{
    
    Solution sol;

    cout << sol.reverseVowels("IceCreAm");

    return 0;
}