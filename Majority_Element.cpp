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
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int acc = 0;
        int base = nums[0];
        for(int i=1 ; i<size ; ++i){
            if(nums[i] == base)
                ++acc;
            else{
                --acc;
                if(acc < 0){
                    base = nums[i];
                    acc = 0;
                }
            }
        }
        return base;
    }
};

int main(){
    Solution sol;
    vector<int> A = {3,2,2};
    vector<int> B = {2,2,1,1,1,1,2};
    cout << sol.majorityElement(A) << '\n';
    cout << sol.majorityElement(B) << '\n';
    return 0;
}