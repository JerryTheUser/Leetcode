#include <iostream>
#include <vector>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void oneSubset(vector<int>& nums, vector<vector<int>>& ret, vector<int> current, int index){
        if(index == nums.size()){
            ret.push_back(current);
            return;
        }
        else{
            oneSubset(nums, ret, current, index+1);
            current.push_back(nums[index]);
            oneSubset(nums, ret, current, index+1);
        }
        return;
    }

    void backTracking(vector<int>& nums, vector<vector<int>>& ret, vector<int> current, int index){
        ret.push_back(current);
        for(int i=index ; i<nums.size() ; ++i){
            current.push_back(nums[i]);
            backTracking(nums, ret, current, i+1);
            current.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> current;
        //oneSubset(nums, ret, current, 0);
        backTracking(nums, ret, current, 0);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input{1,2,3}, input2{};
    vector<vector<int>> result = sol.subsets(input);
    for(auto&& i : result){
        for(auto&& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}