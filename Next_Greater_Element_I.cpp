#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> preprosess;
        if(nums2.size()!=0){
        	for(int i=0 ; i<nums2.size() ; ++i){
        		bool flag = true;
        		for(int j=i ; j<nums2.size() ; ++j){
        			if(nums2[j] > nums2[i]){
        				preprosess[nums2[i]] = nums2[j];
        				flag = false;
        				break;
        			}
        		}
        		if(flag)
        			preprosess[nums2[i]] = -1;
        	}
        	for(int i=0 ; i<nums1.size() ; ++i)
        		ret.push_back(preprosess[nums1[i]]);
        }
        return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> result, input1{4,1,2}, input2{1,3,4,2};
	result = sol.nextGreaterElement(input1, input2);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}