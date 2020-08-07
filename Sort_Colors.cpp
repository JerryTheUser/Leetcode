#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Two-pass algorithm
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>record (3, 0);
        for(auto&& num : nums)
            ++record[num];

        int acc=0;
        for(int i=0 ; i<3 ; ++i){
            for(int j=0 ; j<record[i] ; ++j){
                nums[acc] = i;
                ++acc;
            }
        }
    }
}
*/

// One-pass algorithm
// Dutch National Flag Problem
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, mid=0, right=nums.size()-1;
        
        while(mid<=right){
            if(nums[mid] == 0){
                swap(nums[mid], nums[left]);
                ++left;
                ++mid;
            }
            else if(nums[mid] == 1){
                ++mid;
            }
            else{
                swap(nums[mid], nums[right]);
                --right;
            }
        }
        return;
    }
};

int main(){
    Solution sol;
    vector<int> input {2,0,2,1,1,0};
    sol.sortColors(input);
    for(auto& i : input)
        cout << i << ' ';
    cout << '\n';
    return 0;
}