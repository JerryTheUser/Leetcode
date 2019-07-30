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
/*
    vector<int> countBits(int num) {
        if(num == 0)
        	return vector<int>{0};
        else if(num == 1)
        	return vector<int>{0, 1};
        else{
        	vector<int> ret{0, 1};
        	int index = 2, base = 2, iter = 0;
        	while(1){
        		while(iter != base){
        			ret.push_back(ret[iter]+1);
        			if(index == num)
        				return ret;
        			++iter;
        			++index;
        		}
        		base *= 2;
        		iter = 0;
        	}
        }
    }
*/
    vector<int> countBits(int num) {
        vector<int> numBits(num+1, 0);
        for(int i = 1; i <= num; i++)
            numBits[i] = (i % 2) + numBits[i/2];
        return numBits;
    }
};

int main()
{
	Solution sol;
	int target = 31;
	vector<int> result = sol.countBits(target);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}