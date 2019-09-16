#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i=0 ; i<nums.size() ; i+=2)
            ret += nums[i];
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input{1,4,3,2};
    cout << sol.arrayPairSum(input) << '\n';
    return 0;
}