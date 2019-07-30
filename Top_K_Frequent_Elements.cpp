#include <iostream>
#include <algorithm>
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        vector<pair<int, int>> arrayOfPairs;
        unordered_map<int, int> hashTable;
        for(int i=0 ; i<nums.size() ; ++i){
        	if(hashTable.find(nums.at(i)) != hashTable.end())
        		hashTable[nums.at(i)] += 1;
        	else
        		hashTable[nums.at(i)] = 1;
    	}
    	for(auto&& i : hashTable)
    		arrayOfPairs.push_back(i);

    	sort(arrayOfPairs.begin(), arrayOfPairs.end(), [=](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;});

    	for(int i=0 ; i<k ; ++i)
    		ret.push_back(arrayOfPairs[i].first);
    	return ret;
    }
};

int main()
{
	Solution sol;
	vector<int> input{1,1,1,2,2,2,2,2,2,3,4,4,4,4,4,4};
	vector<int> input2{1};
	int k = 3;
	vector<int> result = sol.topKFrequent(input, k);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}