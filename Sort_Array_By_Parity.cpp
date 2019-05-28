#include <iostream>
#include <vector>
#include <string>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret;
        int size = A.size();
        for(auto&& i : A)
            if(!(i & 1))
                ret.push_back(i);
        for(auto&& j : A)
            if(j & 1)
                ret.push_back(j);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input{3,1,2,4};
    vector<int> output = sol.sortArrayByParity(input);
    for(auto&& i : output)
        cout << i << ' ';
    return 0;
}