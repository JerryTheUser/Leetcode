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
	void generator(vector<vector<int>>& ret, vector<int>& ins, int index){
		if(index == ins.size()-1)
			ret.push_back(ins);
		else{
			for(int i=index ; i<ins.size(); ++i){
				swap(ins[index], ins[i]);
				generator(ret, ins, index+1);
				swap(ins[index], ins[i]);
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> ret;
    	generator(ret, nums, 0);
    	return ret;
    }
};

int main(){
	Solution sol;
	vector<int> input {1, 2, 3, 4, 5};
	vector<vector<int>> result = sol.permute(input);
	for(auto&& i : result){
		for(auto&& j : i)
			cout << j << ' ';
		cout << '\n';
	}
	cout << "Total numbers : " << result.size() << '\n';
	return 0;
}