#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0;
        int i;
        int size=nums.size();
        for(i=0 ; i<size ; ++i)
            ret ^= nums[i];
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> put{5,3,4,2,7,6,8,5,2,3,7,6,4};
    int Ta = sol.singleNumber(put);
    cout << Ta;
    return 0;
}
