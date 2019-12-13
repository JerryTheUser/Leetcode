#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int findTargetNumbers(vector<int>& nums, int S, int index){
        if(index == 0){
            if(nums[0] == S || nums[0] == -S){
                if(nums[0] == 0)
                    return 2;
                else
                    return 1;
            }    
        }
        else{
            int up = 0, down = 0;
            if(S < INT_MAX - nums[index])
                up = findTargetNumbers(nums, S+nums[index], index-1);
            if(S > INT_MIN + nums[index])
                down = findTargetNumbers(nums, S-nums[index], index-1);
            return up + down;
        }
        return 0;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetNumbers(nums, S, nums.size()-1);
    }
};
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};

int main(){
    Solution sol;
    vector<int> input{1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(input, target) << '\n';
    return 0;
}