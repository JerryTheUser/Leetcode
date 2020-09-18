#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int cur){
        vector<vector<int>> ret;
        int left = cur, right = nums.size()-1;
        int sum; 
        while(left < right){
            sum = nums[left] + nums[right];
            if(sum < target || left > cur && nums[left] == nums[left-1])
                ++left;
            else if(sum > target || right < nums.size()-1 && nums[right] == nums[right+1])
                --right;
            else
                ret.push_back(vector<int>{nums[left++], nums[right--]});
        }
        return ret;
    }

    vector<vector<int>> nSum(vector<int>& nums, int target, int cur, int n){
        vector<vector<int>> ret;
        if(cur == nums.size() || nums[cur] * n > target || nums.back() * n < target)
            return ret;
        if(n == 2)
            return twoSum(nums, target, cur);
        for(int i=cur ; i<nums.size() ; ++i){
            if(i == cur || nums[i] != nums[i-1]){
                for(auto& item : nSum(nums, target-nums[i], i+1, n-1)){
                    item.push_back(nums[i]);
                    ret.push_back(item);
                }
            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, target, 0, 4);
    }
};

int main(){
    Solution sol;
    vector<int> input {1, 0, -1, 0, -2, 2}; // -2 -1 0 0 1 2
    vector<vector<int>> results = sol.fourSum(input, 0);
    for(auto& result : results){
        for(auto& item : result){
            cout << item << ' ';
        }
        cout << '\n';
    }
    return 0;
}