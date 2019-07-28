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

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int newTarget;
        for(int i = 0 ; i<nums.size() ; ++i){
        	newTarget = target - nums[i];
        	for(int j = i+1 ; j < nums.size() ; ++j){
        		if(newTarget == nums[j]){
        			ret.push_back(i);
        			ret.push_back(j);
        			return ret;
        		}
        	}
        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int newTarget;
        unordered_map<int, int> hashTable;
        for(int i=0 ; i<nums.size() ; ++i){
        	newTarget = target - nums[i];
        	if(hashTable.find(newTarget) != hashTable.end())
        		return vector<int>({hashTable.find(newTarget)->second, i});
        	hashTable[nums[i]] = i;
        }
    }
};

int main(){
	Solution sol;
	int target = 6;
	vector<int> ret;
	vector<int> input {3, 2, 4};
	ret = sol.twoSum(input, target);
	for(auto&& i : ret)
		cout << i << ' ';
	cout << '\n';
	return 0;
}