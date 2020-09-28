#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, bool> map;
    bool dfs(vector<int>& nums, int cur, int target) {
        if(target == 0) return true;
        if(cur == nums.size() || target < 0) return false;
        
        if(map.count(target)!=0)
            return map[target];
        
        bool ret = dfs(nums, cur+1, target-nums[cur]) || dfs(nums, cur+1, target);
        map[target] = ret;
        return ret;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum & 1) return false;
        sum = sum/2;
        return dfs(nums, 0, sum);
    }
};

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum & 1) return false;
        sum /= 2;
        vector<bool> table(sum+1, false);
        table[0] = true;
        for(auto& num : nums)
            for(int i=sum ; i>=num ; --i)
                table[i] = table[i] || table[i-num];
        return table[sum];
    }
};
*/

int main(){
    Solution sol;
    vector<int> input {1, 5, 11, 5};
    cout << boolalpha << sol.canPartition(input) << '\n';
    return 0;
}