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
	void generator(vector<string>& ret, string str, int open, int close, int num){
		if(str.length() == num*2){
			ret.push_back(str);
		}
		else{
			if(open < num)
				generator(ret, str+"(", open+1, close, num);
			if(open > close)
				generator(ret, str+")", open, close+1, num);
		}
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> ret;
    	generator(ret, "", 0, 0, n);
    	return ret;
    }
};

int main()
{
	Solution sol;
	vector<string> result = sol.generateParenthesis(6);
	for(auto&& i : result)
		cout << i << '\n'; 
	cout << result.size() << '\n';
	return 0;
}