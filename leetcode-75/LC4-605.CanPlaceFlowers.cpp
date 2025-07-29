
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        

        if(flowerbed.size() == 1){
            if((flowerbed[0] == 0 && n <= 1) || (flowerbed[0] == 1 && n == 0)){
                return true;
            }
            else    
                return false;
        }

        int i = 0;

        while(i < flowerbed.size() && n > 0){
            if(  (i == 0                                && flowerbed[i] == 0    && flowerbed[i+1] == 0) ||
                 (i == flowerbed.size()-1               && flowerbed[i] == 0    && flowerbed[i-1] == 0) ||
               (( i > 0 && i < flowerbed.size()-1)      && flowerbed[i] == 0    && flowerbed[i-1] == 0  && flowerbed[i+1] == 0) )
            {
                flowerbed[i] = 1;
                n--;
            }

            i++;
        }

        return (n==0);

    }
}; 



int main()
{
    
    Solution sol;
    vector<int> flowers = {1}; //n=1
    int n = 0;

    cout << sol.canPlaceFlowers(flowers,n);

    return 0;
}