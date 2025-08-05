#include<iostream>
#include <vector>
#include <ostream>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i,j,k;

        if(nums.size() < 3)
            return false;

        

        for (i = 0 ; i<nums.size()-2 ; i++){

            for ( j = i+1 ; j < nums.size()-1 ; j++){

                for ( k = j+1 ; k < nums.size() ; k++){

                    if((nums[i] < nums[j]) && ( nums[j] < nums[k])){
                        return true;
                    }
                    
                }  

            }

        }

        return false;

    }
};


/*
true [0,1,3]
true [10,12,13]
false [no triplets]
false [0,4,x][0,2,x][0,1,x] (one number missing)
*/