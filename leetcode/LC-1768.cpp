#include<iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int wl1 = word1.length();
        int wl2 = word2.length();
        int minimo = min(wl1,wl2);

        string s;

        
        for (int i = 0; i < minimo; i++){
            
            s+=word1[i];
            s+=word2[i];
     
        }
        
        if(wl1 > wl2){
            s+= word1.substr(minimo,(wl1));
        }

        else{
            s+= word2.substr(minimo,(wl2));
        }


        return s;

    }
};


int main(){
    
    Solution sol;
    
    cout << sol.mergeAlternately("aaaa","bbbbb");


    return 0;
}
