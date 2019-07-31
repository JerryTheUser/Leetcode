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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i=0 ; i<nums.size() ; ){
        	if(nums[i]-1 == i)
        		++i;
        	else{
        		if(nums[i] != nums[nums[i]-1])
        			swap(nums[i], nums[nums[i]-1]);
        		else
        			++i;
        	}
        }

        for(int i=0 ; i<nums.size() ; ++i)
        	if(nums[i]-1 != i)
        		ret.push_back(i+1);
        return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> input {4,3,2,7,8,2,3,1};
	vector<int> result = sol.findDisappearedNumbers(input);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}