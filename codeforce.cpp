#include<iostream>
using namespace std;

int nro;

int main(){
    cin >> nro; 
    
    if ( nro != 2 && nro % 2 == 0 )  
        cout << "YES";
    else 
        cout << "NO";
        
    return 0;
}