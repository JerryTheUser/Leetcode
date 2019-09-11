#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	string nextString(string& str){
		string ret;
		int num = 1;
		char now = str[0];
		for(int i=1 ; i<str.size() ; ++i){
			if(str[i] != now){
				ret.append(to_string(num));
				ret.push_back(now);
				now = str[i];
				num = 1;
			}
			else
				++num;
		}
		ret.append(to_string(num));
		ret.push_back(now);
		return ret;
	}

	string countAndSay(int n) {
		string ret("1");
	    for(int i=1 ; i<n ; ++i)
	    	ret = nextString(ret);
	    return ret; 
	}
};

int main(){
	Solution sol;
	cout << sol.countAndSay(0) << '\n';
	cout << sol.countAndSay(1) << '\n';
	cout << sol.countAndSay(2) << '\n';
	cout << sol.countAndSay(3) << '\n';
	cout << sol.countAndSay(4) << '\n';
	cout << sol.countAndSay(5) << '\n';
	cout << sol.countAndSay(6) << '\n';
	return 0;
}