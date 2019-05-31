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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> input;
        for(int i=0 ; i<numRows ; ++i){
            for(int j=0 ; j<=i ; ++j){
                if(j == 0 || j == i )
                    input.emplace_back(1);
                else
                    input.emplace_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            ret.emplace_back(input);
            input.clear();
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    for(auto&& i : ans){
        for(auto&& j : i)
            cout << j << ' ';
        cout << '\n';
    }
}