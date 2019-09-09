#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> ret(T.size(), 0);
        for(int i=T.size()-1 ; i>-1 ; --i){
        	while(!stk.empty() && T[i] >= T[stk.top()])
        		stk.pop();
        	if(!stk.empty())
        		ret[i] = stk.top() - i;
        	stk.push(i);
        }
        return ret;
    }
};

int main(){
	Solution sol;
	vector<int> input{73, 74, 75, 71, 69, 72, 76, 73}, input2{89, 62, 70, 58, 47, 47, 46, 76, 100, 70}, result;
	
	result = sol.dailyTemperatures(input2);
	for(auto&& i : result)
		cout << i << ' ';
	cout << '\n';
	return 0;
}