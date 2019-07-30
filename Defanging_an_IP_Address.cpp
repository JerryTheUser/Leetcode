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
    string defangIPaddr(string address) {
		string ret;
		for(auto&& i : address){
			if(i == '.')
				ret += "[.]";
			else
				ret += i;
		}
		return ret;        
    }
};

int main()
{
	Solution sol;
	string str("255.100.50.0");
	cout << sol.defangIPaddr(str) << '\n';
	return 0;
}