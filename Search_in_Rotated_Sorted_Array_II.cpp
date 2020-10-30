#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int>& nums, int left, int right, int target){
        if(left > right) return false;
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return true;
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
                bool ret = binarySearch(nums, left, mid-1, target);
                if(!ret)
                    ret = binarySearch(nums, mid+1, right, target);
                return  ret;
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);   
    }
};
