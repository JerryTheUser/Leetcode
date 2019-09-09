#include <iostream>
#include <string>
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
    bool isValid(string s) {
        stack<char> stk;
        bool ret = true;
        for(auto&& i : s){
        	switch(i){
        		case '(':
        			stk.push('(');
        			break;
        		case '[':
        			stk.push('[');
        			break;
        		case '{':
        			stk.push('{');
        			break;
        		case ')':
        			if(stk.empty() || stk.top() != '(')
        				ret = false;
        			else
        				stk.pop();
        			break;
        		case ']':
        			if(stk.empty() || stk.top() != '[')
        				ret = false;
        			else
        				stk.pop();
        			break;
        		case '}':
        			if(stk.empty() || stk.top() != '{')
        				ret = false;
        			else
        				stk.pop();
        			break;
        		default:
        			ret = false;
        			break;
        	}
        }
        if(!stk.empty())
        	ret = false;
        return ret;
    }
};

int main()
{
	Solution sol;
	string str("()"), str2("()[]{}"), str3("(]"), str4("([)]"), str5("{[]}");
	cout << boolalpha << sol.isValid(str) << '\n';
	cout << boolalpha << sol.isValid(str2) << '\n';
	cout << boolalpha << sol.isValid(str3) << '\n';
	cout << boolalpha << sol.isValid(str4) << '\n';
	cout << boolalpha << sol.isValid(str5) << '\n';
	return 0;
}