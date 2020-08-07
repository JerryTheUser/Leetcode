#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i=0 ; i<nums.size() ; ++i)
            if(nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] *= -1;
            else
                ret.push_back(abs(nums[i]));
    
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {4,3,2,7,8,2,3,1};
    vector<int> output = sol.findDuplicates(input);
    for(auto& i : output)
        cout << i << ' ';
    cout << '\n';
    return 0;
}