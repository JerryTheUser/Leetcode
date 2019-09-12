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
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
        	return 0;
        int slow = nums[0], fast = nums[0];
        do{
        	slow = nums[slow];
        	fast = nums[nums[fast]];
        }while(slow != fast);
    	fast = nums[0];
    	while(slow != fast){
    		slow = nums[slow];
    		fast = nums[fast];
    	}
    	return slow;
    }
};

int main(){
	Solution sol;
	vector<int> input{1,3,4,2,2}, input2{0};
	cout << sol.findDuplicate(input2) << '\n';
	return 0;
}