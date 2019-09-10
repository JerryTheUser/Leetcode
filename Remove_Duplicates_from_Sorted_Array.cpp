#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        	return 0;
        int left = 0, right = 0;
        while(right < nums.size()){
        	while(nums[right] == nums[left]){
        		++right;
        		if(right >= nums.size())
        			return left+1;
        	}
        	++left;
        	swap(nums[left], nums[right]);
        	++right;
        }
        return left+1;
    }
};

int main(){
	Solution sol;
	vector<int> input{0,0,1,1,1,2,2,3,3,4}, input2{1};
	cout << sol.removeDuplicates(input2) << '\n';
	return 0;
}