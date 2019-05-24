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
    long sumAll(int size){
        return size * (size + 1) / 2;
    }
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        long real = sumAll(size);
        long acc =  0;
        for(auto& i : nums)
            acc += i;
        return real - acc;
    }
};

int main(){
    Solution sol;
    vector<int> A{9,6,4,2,3,5,7,0,1};
    cout << sol.missingNumber(A) << '\n';
    return 0;
}