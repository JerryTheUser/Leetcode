#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(auto& num : nums){
            if(!((int(log10(num))+1)&1))
                ++ret;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> input {252};
    cout << sol.findNumbers(input) << '\n';
    return 0;
}