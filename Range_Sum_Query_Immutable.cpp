#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> table;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;
        table.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; ++i)
            table.push_back(nums[i]+table.back());
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return table[j];
        else return table[j] - table[i-1];
    }
};