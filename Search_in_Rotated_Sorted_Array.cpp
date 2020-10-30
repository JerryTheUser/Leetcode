#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return  mid;
        if(left > right) return -1;
        if(nums[left] < nums[mid]){
            if(target >= nums[left] && target < nums[mid])
                return binarySearch(nums, left, mid-1, target);
            else
                return binarySearch(nums, mid+1, right, target);
        }
        else if(nums[left] > nums[mid]){
            if(target <= nums[right] && target > nums[mid])
                return binarySearch(nums, mid+1, right, target);
            else
                return binarySearch(nums, left, mid-1, target);
        }
        else{
            if(nums[mid] != nums[right])
                return binarySearch(nums, mid+1, right, target);
            else{
                int ret = binarySearch(nums, left, mid-1, target);
                if(ret == -1)
                    ret = binarySearch(nums, mid+1, right, target);
                return  ret;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);     
    }
};

int main(){
    Solution sol;
    vector<int> input {4,5,6,7,0,1,2};
    cout << sol.search(input, 0) << '\n';
    return 0;
}