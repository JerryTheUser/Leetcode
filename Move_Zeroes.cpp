#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;
using std::swap;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int index=0;
        for(i=0 ; i<nums.size()-1 ; ++i){
            if(nums[i] == 0){
                index = i+1;
                while(index<nums.size() && nums[index] == 0)++index;
                if(index>=nums.size())return;
                swap(nums[i],nums[index]);
            }
        }
    }

    void moveZeroes_opt(vector<int>& nums){
        int forward = 0;
        size_t size = nums.size();
        size_t i;
        for(i=0 ; i<size ; ++i){
            if(nums[i] == 0)
                ++forward;
            else{
                if(forward == 0)continue;
                else{
                    nums[i-forward] = nums[i];   
                }
            }
        }
        std::fill(nums.begin()+(size-forward),nums.end(),0);
    }
};

int main(){
    Solution sol;
    vector<int> input = {0,0,6,5,0,3,0,11,0,7,0,6,0,6,0,0};
    vector<int> input2 = {1,2,3,0,45,6,7,7,85,4,32,1};
    vector<int> input3 = {4,2,4,0,0,3,0,5,1,0};
    sol.moveZeroes_opt(input2);
    for(auto i : input2)
        cout << i << " ";
    cout << '\n';
    return 0;
}
