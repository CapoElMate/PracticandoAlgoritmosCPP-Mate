
#include<iostream>
#include <vector>
#include <ostream>

using namespace std;


class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ret;
        
        int size = nums.size();
        
        int left[size];
        int right[size];

        left[0] = 1;
        for(int i = 1; i < size; i++){
            left[i] = nums[i-1] * left[i-1];
        }

        right[size-1] = 1;
        for(int i = size-2; i >= 0; i--){
            right[i] = nums[i+1] * right[i+1];
        }
        
        for(int i = 0 ; i < size ; i++){
            ret.push_back(right[i] * left[i]);
        }

        return ret;
    }
};

int main()
{    
    Solution sol;
    vector<int> v = {1,2,3,4};

    vector<int> rtdo = sol.productExceptSelf(v);

    for(int i = 0; i<rtdo.size() ; i++)   {
        std::cout << rtdo.at(i) << ", ";
    }

    
    return 0;
}