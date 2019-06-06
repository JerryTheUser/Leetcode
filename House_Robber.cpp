#include <iostream>
#include <vector>
#include <array>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = {0, 0, 0};
        int size = nums.size();
        for(int i=0 ; i<size ; ++i){
            dp.push_back(max(nums[i]+dp[i+1], nums[i]+dp[i]));
        }
        int ret = 0;
        for(auto&& i : dp)
            if(i > ret)
                ret = i;
        return ret;
    }
};
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int dp[size+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=1 ; i<size ; ++i){
            dp[i+1] = max(nums[i]+dp[i-1], dp[i]);
        }
        return dp[size];
    }
};

int main(void){
    vector<int> A{2,7,9,3,1};
    vector<int> B{1,9,2,1,7,1};
    vector<int> C{};
    vector<int> D{2,1,1,2};
    Solution sol;
    cout << sol.rob(C) << '\n';
    return 0;
}