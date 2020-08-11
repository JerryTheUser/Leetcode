#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Lower Bound
    int findIndex(vector<int>& table, int left, int right, int key){
        while(left < right){
            int mid = left + (right - left)/2;
            if(table[mid] < key)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        vector<int> table(nums.size(), 0);
        int len = 1;
        table[0] = nums[0];

        for(int i=1 ; i<nums.size() ; ++i){
            if(nums[i] > table[len-1])
                table[len++] = nums[i];
            else
                table[findIndex(table, 0, len, nums[i])] = nums[i];
        }
        return len;
    }
};

int main(){
    Solution sol;
    vector<int> input {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(input) << '\n';
    return 0;
}