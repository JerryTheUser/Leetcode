#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_bound(vector<int>& nums, int target, bool lower){
        int left = 0, right = nums.size(), mid;
        int ret = -1;
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] == target){
                ret = mid;
                if(lower)
                    right = mid;
                else
                    left = mid+1;
            }
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid;
        }
        return ret;
    }

    vector<int> searchRange(vector<int>& nums, int target) {   
        int lower, upper;
        lower = find_bound(nums, target, true);
        upper = find_bound(nums, target, false);
        return vector<int>{lower, upper};
    }
};

int main(){
    Solution sol;
    vector<int> input {5,7,7,8,8,10};
    vector<int> result = sol.searchRange(input, 6);
    for(auto& i : result)
        cout << i << ' ';
    cout << '\n';
    return 0;
}