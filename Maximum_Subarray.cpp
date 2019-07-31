#include <iostream>
#include <vector>
#include <climits>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = 0, accumulator = 0, max = INT_MIN;
        for(auto& i : nums){
        	accumulator += i;
        	if(max < i)
        		max = i;
        	if(accumulator < 0)
        		accumulator = 0;
        	if(ret < accumulator)
        		ret = accumulator;
        }
        if(max < 0)
        	ret = max;
        return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> input {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> input2 {-1, -2, -3, -1, -2, -1};
	cout << sol.maxSubArray(input2) << '\n';
	return 0;
}