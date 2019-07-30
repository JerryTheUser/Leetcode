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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> hashTable;
        for(int i=0 ; i<nums1.size() ; ++i){
        	if(hashTable.find(nums1.at(i)) != hashTable.end())
        		hashTable[nums1.at(i)] += 1;
        	else
        		hashTable[nums1.at(i)] = 1;
        }
        for(int j=0 ; j<nums2.size() ; ++j){
        	auto iter = hashTable.find(nums2.at(j));
        	if(iter != hashTable.end() && iter->second != 0){
        		ret.push_back(iter->first);
        		--iter->second;
        	}
        }
        return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> a{4,9,5};
	vector<int> b{9,4,9,8,4};
	vector<int> result = sol.intersect(a, b);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}