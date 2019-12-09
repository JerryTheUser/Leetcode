#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> table;
        for(int i=0 ; i<groupSizes.size() ; ++i){
            table[groupSizes[i]].push_back(i);
            if(table[groupSizes[i]].size() == groupSizes[i]){
                ret.push_back(table[groupSizes[i]]);
                table[groupSizes[i]].clear();
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {3,3,3,3,3,1,3};
    vector<vector<int>> result = sol.groupThePeople(input);
    
    for(auto&& i : result){
        for(auto&& j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}