#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1)
    		return 0;
        int low = 0, high = nums.size()-1;
        bool move = true;
        while(low < high && move){
        	move = false;
        	if(nums[low] <= nums[low+1]){
        		++low;
        		move = true;
        	}
        	if(nums[high] >= nums[high-1]){
        		--high;
        		move = true;
        	}
        }
        if(low >= high)
        	return 0;
        int min = INT_MAX, max = INT_MIN;
        for(int i=low ; i<=high ; ++i){
        	if(nums[i] < min)
        		min = nums[i];
        	if(nums[i] > max)
        		max = nums[i];
        }
       	for(int i=0 ; i<=low ; ++i){
       		if(nums[i] > min){
       			low = i;
       			break;
       		}
       	}
       	for(int i=nums.size()-1 ; i>=high ; --i){
       		if(nums[i] < max){
       			high = i;
       			break;
       		}
       	}
        return high - low + 1;
    }
};

int main()
{
	Solution sol;
	vector<int> input{2, 6, 4, 8, 10, 9, 15}, input2{2, 1}, input3{0}, input4{}, input5{1, 2, 3, 3, 3};
	cout << sol.findUnsortedSubarray(input) << '\n';
	cout << sol.findUnsortedSubarray(input2) << '\n';
	cout << sol.findUnsortedSubarray(input3) << '\n';
	cout << sol.findUnsortedSubarray(input4) << '\n';
	cout << sol.findUnsortedSubarray(input5) << '\n';
	return 0;
}