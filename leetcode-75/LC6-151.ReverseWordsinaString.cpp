
#include<iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string retorno = "";
        stack<string> pila; 
        
        string pActual = "";

        int i = 0;

        while(i < s.length()){
            
            while(s[i] != ' ' && i < s.length()){
                
                pActual += s[i];
                i++;
            }

            while(s[i] == ' ' && i<s.length()){
                i++;
            }

            if(pActual !=""){
                pila.push(pActual);
                pActual = "";
            }
        }
        
        if(pila.size() > 0){
            retorno += pila.top();
            pila.pop();
        }

        while(pila.size() > 0){
            retorno += " " + pila.top();
            pila.pop();
        }

        return retorno;
    }
}; 

int main()
{    
    Solution sol;

    cout << sol.reverseWords("mundo hola   digo  siempre yo");
    cout <<"\n";
    cout << sol.reverseWords("  hello world  ");

    return 0;
}