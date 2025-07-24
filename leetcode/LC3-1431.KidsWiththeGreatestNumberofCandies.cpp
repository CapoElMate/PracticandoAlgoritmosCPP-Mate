
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int max = 0; 
        vector<bool> rta;

        for(int c : candies){
            if(c > max)
                max = c;
        }

        for(int c : candies){            
            rta.push_back((c + extraCandies) >= max);            
        }
        
        return rta;
    }

    
};

/*
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
*/


int main(){
        
        Solution sol;
        vector<int> carams = {2,3,5,1,3};

        vector<bool> kwk = sol.kidsWithCandies(carams, 3);

        cout << boolalpha;
        cout << "[";
        for (bool i:  kwk)
            std::cout << i << ", ";

        cout << "]";

        return 0;
    }