
#include<iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string retorno = "";
        stack<string> pila; 
        
        string pActual = "";

        for(int i = 0 ; i < s.length() ;){
            
            while(s[i] != ' '){
                
                pActual += s[i];

                i++;
            }

            pila.push(pActual);
            pActual = "";

            while(s[i] == ' '){
                i++;
            }
        }


        for(int i = 0; i<pila.size() ; i++){
            cout << pila.top() + " \n";
            pila.pop();
        }

        if(pila.size() > 0){
            retorno += pila.top();
            pila.pop();
        }

        for(int i = 1; i<pila.size() ; i++){
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

    return 0;
}