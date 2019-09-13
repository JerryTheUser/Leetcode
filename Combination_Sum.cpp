#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

class Solution {
public:
    void subProblem(vector<vector<int>>& ret, vector<int> combination, vector<int>& candidates, int target, int start){
        if(target < 0)
            return;
        else if(target == 0){
            ret.push_back(combination);
            return;
        }
        else{
            for(int i=start ; i<candidates.size() && candidates[i] <= target ; ++i){
                combination.push_back(candidates[i]);
                subProblem(ret, combination, candidates, target-candidates[i], i);
                combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        subProblem(ret, combination, candidates, target, 0);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input{2,3,6,7}, input2{2,3,5};
    int target = 7, target2 = 8;
    vector<vector<int>> result = sol.combinationSum(input, target);
    for(auto&& i : result){
        for(auto&& j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}