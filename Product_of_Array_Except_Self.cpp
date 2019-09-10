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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret, left{1}, right{1};
        if(nums.size() == 0)
        	return ret;
        int tmp = nums[0];
        for(int i=0 ; i<nums.size()-1 ; ++i){
        	left.push_back(tmp);
        	tmp *= nums[i+1];
        }
        tmp = nums[nums.size()-1];
        for(int i=nums.size()-1 ; i>0; --i){
        	right.push_back(tmp);
        	tmp *= nums[i-1];
        }
        reverse(right.begin(), right.end());
        for(int i=0 ; i<nums.size() ; ++i)
        	ret.push_back(left[i] * right[i]);
        return ret;
    }
};

int main(){
	Solution sol;
	vector<int> input{1,2,3,4}, input2{2};
	vector<int> result = sol.productExceptSelf(input2);
	for(auto&& i : result){
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}