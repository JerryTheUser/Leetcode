#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(unsigned int i=0 ; i<nums.size() ; ++i){
            if((i>0) && nums[i] == nums[i-1])
                continue;
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0) ++l;
                else if(sum > 0) --r;
                else{
                    ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1]) ++l;
                    while(l<r && nums[r] == nums[r-1]) --r;
                    ++l; --r;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {-1,0,1,2,-1,-4}, input2 {0,0,0};
    vector<vector<int>> results = sol.threeSum(input2);
    for(auto& result : results){
        for(auto& item : result){
            cout << item << ' ';
        }
        cout << '\n';
    }
    return 0;
}