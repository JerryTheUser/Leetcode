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
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        for(int i=0 ; i<nums.size() ; ++i){
        	if(hashTable.find(nums[i]) != hashTable.end())
        		return true;
        	else
        		hashTable[nums[i]] = i;
        }
        return false;
    }
};

int main(){
	Solution sol;
	vector<int> input {1,1,1,3,3,4,3,2,4,2};
	vector<int> input2 {1,2,3,4};
	cout << boolalpha << sol.containsDuplicate(input2) << '\n';
	return 0;
}