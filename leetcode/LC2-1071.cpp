
#include<iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        //si st1 = ABC y st2 = ABCABC => ABC+ABCABC es igual a ABCABC+ABC  -> OK
        //si st1 = AB y st2 = ABCABC => AB+ABCABC no es igual a ABCABC+AB  -> NO
        if((str1+str2) != (str2+str1)){
            return "";
        }

        int l1,l2;
        l1 = max(str1.length() , str2.length());
        l2 = min(str1.length() , str2.length());

        cout << gcd(l1,l2);

        return str1.substr(0,gcd(l1,l2));
    }

    int gcd(int x , int y){
        if(y != 0){
            gcd(y, x % y);
        }   
        else 
            return x;
    }

};




int main(){
    
    Solution sol;
    
    cout << "\"" + sol.gcdOfStrings("ABCABC","AfBC") + "\"\n"; // abc
    cout << "\"" + sol.gcdOfStrings("ABABAB","ABAB") + "\"\n"; // ab
    cout << "\"" + sol.gcdOfStrings("ABCABC","ABC") + "\"\n";  //tauxx
    //                                                           TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX
    cout << "\"" + sol.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX","TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX") + "\"\n" ;


    return 0;
}


/*

#include<iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string strChico,strGrande;
        
        if(str1.length() > str2.length()){
            strChico = str2;
            strGrande = str1;
        }
        else{
            strChico = str1;
            strGrande = str2;
        }

        string valorRet = "";

        stack<string> candidatos;

        int t = 1 ; 
        bool pass = true;


        //voy aumentando la cantidad de elementos comparados
        for(t = 1 ; t <= strChico.size() ; t++){
            //verifico hasta cuando los dos str son iguales. si son iguales con ese t lo guardo  en el stack.

            if(strChico.substr(0,t) == strGrande.substr(0,t)){
                // candidatos.push(strChico.substr(0,t));
                
                // if(strGrande.size() % strChico.substr(0,t).size() == 0 && strChico.substr(0,t).size() <  (strGrande.size() - strChico.substr(0,t).size())){
                //     return strChico.substr(0,t);
                // }

                if(strGrande.size() % t == 0){
                    
                    pass = true;

                    for(int i = t; pass && i<strGrande.size(); i+=t){
                        if(strChico.substr(0,t) != strGrande.substr(i,t)){
                            pass = false;
                        }
                    }

                    if(pass){
                        candidatos.push(strChico.substr(0,t));
                    }
                }
                

            }
            else //si hay algun valor incompatible, eso ya significa que los str no son divisibles.
                return "";

        }


        //ahora con los candidatos, empiezo desde el candidato mas grande y voy verificando si es compatible con el str grande.
        // string act ; 
        // for(int i = 0; i < candidatos.size() ; i++){
        //     act = candidatos.top(); //agarro el de mas arriba de la pila
        //     candidatos.pop();       //lo borro.

        //     if(strGrande.size() % act.size() == 0){
        //         return act;
        //     }

        // }


        return candidatos.top();
    }
};


int main(){
    
    Solution sol;
    
    cout << "\"" + sol.gcdOfStrings("ABCABC","AfBC") + "\"\n"; // abc
    cout << "\"" + sol.gcdOfStrings("ABABAB","ABAB") + "\"\n"; // ab
    cout << "\"" + sol.gcdOfStrings("ABCABC","ABC") + "\"\n";  //tauxx
    //                                                           TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX
    cout << "\"" + sol.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX","TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX") + "\"\n" ;


    return 0;
}


*/